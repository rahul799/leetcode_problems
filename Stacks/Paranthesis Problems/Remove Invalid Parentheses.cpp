

301. Remove Invalid Parentheses
Hard

2987

136

Add to List

Share
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]

An important thing to observe in the above diagram is that there are multiple ways of reaching the same solution i.e. say the optimal number of parentheses to be 
removed to make the original expression valid is K. We can remove multiple different sets of K brackets that will eventually give us the same final expression. But, 
each valid expression should be recorded only once. We have to take care of this in our solution. Note that there are other possible ways of reaching one of the two
valid expressions shown above. We have simply shown 3 ways each for the two valid expressions.

Coming back to our problem, the question that now arises is, how to decide which of the parentheses to remove?

Since we don't know which of the brackets can possibly be removed, we try out all the options!

For every bracket we have two choices:

Either it can be considered a part of the final expression OR
It can be ignored i.e. we can delete it from our final expression.
Such kind of problems where we have multiple options and we have no strategy or metric of deciding greedily which option to take, we try out all of the options and 
see which ones lead to an answer. These type of problems are perfect candidates for the programming paradigm, Recursion.

Algorithm

Initialize an array that will store all of our valid expressions finally.
Start with the leftmost bracket in the given sequence and proceed right in the recursion.
The state of recursion is defined by the index which we are currently processing in the original expression. Let this index
be represented by the character i. Also, we have two different variables left_count and right_count that represent the number
of left and right parentheses we have added to our expression till now. These are the parentheses that were considered.
If the current character i.e. S[i] (considering S is the expression string) is neither a closing or an opening parenthesis, 
then we simply add this character to our final solution string for the current recursion.
However, if the current character is either of the two brackets i.e. S[i] == '(' or S[i] == ')', then we have two options.
    We can either discard this character by marking it an invalid character or we can consider this bracket to be a part of 
    the final expression.
When all of the parentheses in the original expression have been processed, we simply check if the expression represented by
expr i.e. the expression formed till now is valid one or not. The way we check if the final expression is valid or not is by
looking at the values in left_count and right_count. For an expression to be valid left_count == right_count. If it is indeed
valid, then it could be one of our possible solutions.
Even though we have a valid expression, we also need to keep track of the number of removals we did to get this expression. 
    This is done by another variable passed in recursion called rem_count.
Once recursion finishes we check if the current value of rem_count is < the least number of steps we took to form a valid
expression till now i.e. the global minima. If this is not the case, we don't record the new expression, else we record it.
One small optimization that we can do from an implementation perspective is introducing some sort of pruning in our algorithm. 
    Right now we simply go till the very end i.e. process all of the parentheses and when we are done processing all of them,
we check if the expression we have can be considered or not.

We have to wait till the very end to decide if the expression formed in recursion is a valid expression or not. Is there a way for us to cutoff from some of the
recursion paths early on because they wouldn't lead to a solution? The answer to this is Yes! The optimization is based on the following idea.

For a left bracket encountered during recursion, if we decide to consider it, then it may or may not lead to an invalid final expression. It may lead to an
invalid expression eventually if there are no matching closing bracket available afterwards. But, we don't know for sure if this will happen or not.

However, for a closing bracket, if we decide to keep it as a part of our final expression (remember for every bracket we have two options, either to keep it or to remove
it and recurse further) and there is no corresponding opening bracket to match it in the expression till now, then it will definitely lead to an invalid expression no
matter what we do afterwards.

e.g.

( (  ) ) )
In this case the third closing bracket will make the expression invalid. No matter what comes afterwards, this will
give us an invalid expression and if such a thing happens, we shouldn't recurse further and simply prune the recursion tree.

That is why, in addition to having the index in the original string/expression which we are currently processing and 
the expression string formed till now, we also keep track of the number of left and right parentheses. Whenever we keep
a left parenthesis in the expression, we increment its counter. For a right parenthesis, we check if right_count < left_count. 
   If this is the case then only we consider that right parenthesis and recurse further. Otherwise we don't as we know it 
  will make the expression invalid. 
  This simple optimization saves a lot of runtime.



class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int cntL = 0, cntR = 0;
        
        for (const char& c: s) {           
            if (c == '(') cntL++; 
            if (c == ')') {
                if (cntL > 0) cntL--;
                else cntR++;
            }
        }
        
        vector<string> res; 
        
        helper(s, 0, cntL, cntR, res);
        
        return res;
    }
    
    void helper(string s, int start, int cntL, int cntR, vector<string>& res) {
        if (cntL == 0 && cntR == 0) {
            if (isValid(s)) res.push_back(s);
        }
        
        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' && cntL > 0) {
                string ss = s.substr(0, i) + s.substr(i + 1);
                helper(ss, i, cntL - 1, cntR, res);
            }
            if (s[i] == ')' && cntR > 0) {
                string ss = s.substr(0, i) + s.substr(i + 1);
                helper(ss, i, cntL, cntR - 1, res);
            }
        }
    }
    
    bool isValid(string s) {
        int count = 0;
        
        for (const char& c: s) {
            if (c == '(') count++;
            if (c == ')') {
                if (count == 0) return false;
                else count--;
            }
        }
        
        return count == 0;
    }
};










class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remove_left=0, remove_right=0, pair=0;
        /*** use the unordered_set to deal with the duplicate cases ***/
        unordered_set<string> result;
        /***  calculate the remained # of left and right parentheses  ***/
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')   remove_left++;
            else if(s[i]==')'){
                if(remove_left > 0) remove_left--;
                else    remove_right++;
            }
        }
        help(0, 0, remove_left, remove_right, s, "", result);
        /*** change the unordered_set to vector ***/
        return vector<string>(result.begin(), result.end());
    }
    
    /***
    pair : record the () pair count in the solution
    index : record the cur-position int the string s
    remove_left : the number of left parentheses needed to delete
    remove_right : the number of right parentheses needed to delete
    s : origninal input string    solution : the current produced string
    result : stores all the satisfied solution string
    ***/
    void help(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& result){
        /***   end condition       ***/
        if(index==s.size()){
            /*** check whether the remained string solution is right  ***/
            if(pair==0 && remove_left==0 && remove_right==0)    result.insert(solution);
            return;
        }
        /***    left-half-parentheses     ***/
        if(s[index]=='('){
            /***    remove the left-half-parentheses     ***/
            if(remove_left > 0)     help(pair, index+1, remove_left-1, remove_right, s, solution, result);
            /***    keep  the  left-half-parentheses     ***/
            help(pair+1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        /***    right-half-parentheses     ***/
        else if(s[index]==')'){
            /***    remove the right-half-parentheses     ***/
            if(remove_right > 0)     help(pair, index+1, remove_left, remove_right-1, s, solution, result);
            /***    keep  the  right-half-parentheses     ***/
            if(pair > 0) help(pair-1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        /***    other-characters     ***/
        else{
            help(pair, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
    }
};
