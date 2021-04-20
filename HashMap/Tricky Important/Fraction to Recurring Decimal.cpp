

166. Fraction to Recurring Decimal
Medium

1030

2113

Add to List

Share
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
Example 4:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
Example 5:

Input: numerator = 1, denominator = 5
Output: "0.2"
 

Constraints:

-231 <= numerator, denominator <= 231 - 1
denominator != 0






class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long deno = denominator;
        if(num==0) return "0";
        bool isNeg = false;
        if(num<0 && deno<0){
            num=abs(num);
            deno=abs(deno);
        }
        else if(num<0) {
            isNeg = true;
            num = abs(num);
        }
        else if(deno<0) {
            isNeg = true;
            deno = abs(deno);
        }
        long long q = num/deno;
        string ans = to_string(q);
        long long rem = num%deno;
        if(rem==0) {
            if(isNeg) return "-"+ans;
            return ans;
        }
        unordered_map<int,int> m;
        m[rem]=0;
        int count = 1;
        string str = "";
        while(rem!=0) {
            rem = rem* 10;
            q = rem/deno;
            str+=to_string(q);
            rem=rem%deno;
            if(m.find(rem)!=m.end()){
                str = str.substr(0,m[rem]) + "(" + str.substr(m[rem]) + ")";
                break;
            }
            m[rem]=count;
            count++;
        }
        if(isNeg) return "-"+ans+"."+str;
        return ans+"."+str;
    }
}; 


















// class Solution {
// public:
//     string fractionToDecimal(int numerator, int denominator) {
//         if (!numerator) {
//             return "0";
//         }
//         string ans;
//         if (numerator > 0 ^ denominator > 0) {
//             ans += '-';
//         }
//         long n = labs(numerator), d = labs(denominator), r = n % d;
//         ans += to_string(n / d);
//         if (!r) {
//             return ans;
//         }
//         ans += '.';
//         unordered_map<long, int> rs;
//         while (r) {
//             if (rs.find(r) != rs.end()) {
//                 ans.insert(rs[r], "(");
//                 ans += ')';
//                 break;
//             }
//             rs[r] = ans.size();
//             r *= 10;
//             ans += to_string(r / d);
//             r %= d;
//         }
//         return ans;
//     }
// };
