282. Expression Add Operators
Hard

1474

243

Add to List

Share
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]
Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]
Example 5:

Input: num = "3456237490", target = 9191
Output: []
 

Constraints:

0 <= num.length <= 10
num only contain digits.











class Solution {
private:
    int sLen;
    void traverse(const string s, int pos, long current, long pre, int sum, string path, vector<string>& v)
    {
        if(sLen == pos) { if(current == sum) v.push_back(path); return ; }
        long num = 0;
        for(int i = pos; i < sLen; ++i)
        {
            if(i-pos>0 && s[pos]=='0') return ;
            string t = s.substr(pos, i-pos+1);
            num = 10*num + s[i]-'0';
            if(num > INT_MAX) return ;
            if(pos == 0) traverse(s, i+1, num, num, sum, t, v);
            else
            {
                traverse(s, i+1, current+num, num, sum, path+"+"+t, v);
                traverse(s, i+1, current-num, -num, sum, path+"-"+t, v);
                traverse(s, i+1, current-pre+pre*num, pre*num, sum, path+"*"+t, v);
                
                //'*'is not same to '+-', we should plus "last" that we shouldn't have + or -.(* with high priority)
            }
        }
    }
public:
    vector<string> addOperators(string s, int target) {
        sLen = s.length();
        vector<string> v;
        traverse(s, 0, 0, 0, target, "", v);
        return v;
    }
};
