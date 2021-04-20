


556. Next Greater Element III
Medium

993

246

Add to List

Share
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1



class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

// e.g. 3761 --> swap   6731  --> done in reversal step  6137    


class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;
        // start from right
        // find the number x which is smaller than the next one
        for(; i >= 0; i--){
            if(s[i] < s[i + 1]) break;
        }
        // if it doesn't exist, return -1
        if(i < 0) return -1;
        // find the number x' in the right side which is just greater than x
        for(int j = s.size() - 1; j > i; j--){
            if(s[j] > s[i]){
                swap(s[i], s[j]);
                break;
            }
        }
        // reverse right side to make it in increasing order
        // e.g. 3761 --> swap   6731  --> done in reversal step  6137    
        reverse(s.begin() + i + 1, s.end());
        long res = stol(s);
        return res > INT_MAX? -1 : res; // check if the result is longer than 32-bits
    }
};




/**
 * 1. a max number has the property of decreasing in every digit: 9876
 * 2. find the first non-max substring from the right; ex. in 1234(59876), 59876 is the first non-max substring from the right
 * 3. sort the max part of 5(9876), by reverse, becames 5(6789);
 * 4. flip 5,6, becames 65789; because 6 is the next smallest digit than 5, in 56789;
 * 5. incase of 66789, you got flip 6 with 7 to make it 76689, to make it bigger.
 */
// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         string s = to_string(n);
//         if (s.length() == 1) {
//             return -1;
//         }
//         /* find the first decreasing digit from the right, eg: 59876, 5 is the first decreasing digit */
//         int i = s.length() - 2; // 21 -> i = 0; 59876 -> i = 3
//         for (; i >= 0 && s[i] >= s[i + 1]; i--) { }
//         if (i == -1) {  // if a decreasing digit cannot be find, the number cannot be larger.
//             return -1;
//         }
//         reverse(s.begin() + i + 1, s.end());
//         for (int j = i + 1; j < s.length(); j++) {
//             if (s[j] > s[i]) {
//                 swap(s[i], s[j]);
//                 break;
//             }
//         }
//         long next = stol(s);
//         return next == n || next > INT_MAX ? -1 : next;
//     }
// };








