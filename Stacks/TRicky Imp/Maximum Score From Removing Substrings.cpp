

1717. Maximum Score From Removing Substrings
Medium

116

11

Add to List

Share
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.



class Solution {
public:
int getScore(string str, int val, stack<char>&st, char first, char second ){
    int ans=0;
    for(int i=0;i<str.length();i++){
        if(st.empty()){
            st.push(str[i]);
        }else if(str[i]==second && st.top()==first){
            st.pop();
            ans+=val;
        }else{
            st.push(str[i]);
        }
    }
    return ans;
}

int maximumGain(string str, int x, int y) {
    int score=0;
    stack<char>st;
    if(x>y){
         string str2="";
        score+=getScore(str, x, st, 'a', 'b');
        while(!st.empty()){
            str2+=st.top();
            st.pop();
        }
        reverse(str2.begin(), str2.end());
        score+=getScore(str2, y, st, 'b','a');
    }else{
        string str2="";
        score+=getScore(str, y, st, 'b','a');
        while(!st.empty()){
            str2+=st.top();
            st.pop();
        }
        reverse(str2.begin(), str2.end());
        score+=getScore(str2, x, st, 'a', 'b');   
    }
    return score;
}
};
