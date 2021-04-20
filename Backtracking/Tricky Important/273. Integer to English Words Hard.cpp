273. Integer to English Words
Hard




https://leetcode.com/problems/integer-to-english-words/



Share
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 

Constraints:

0 <= num <= 231 - 1










class Solution { 
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string>thousands({"", " Thousand", " Million", " Billion"});
        string res = "";
        int i = 0;
        while(num){
            if(num % 1000) res = helper(num % 1000) + thousands[i] + (res.size() ? " " : "") + res;
            num /= 1000;
            i++;
        }
        return res;
    }
    
    string helper(int num){
        vector<string>lessThan20({"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"});
        vector<string>tens({"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});
        if(num >= 100) return lessThan20[num / 100] + " Hundred" + (num % 100 ? " ": "") + helper(num % 100);
        else if(num >= 20) return tens[num / 10] + (num % 10 ? " ": "") + helper(num % 10);
        else return lessThan20[num];
    }
};
