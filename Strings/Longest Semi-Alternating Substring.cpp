Longest Semi-Alternating Substring

You are given a string S of length N containing only characters 'a' and 'b'. A substring (contiguous fragment) of S is called a semi-alternating substring if it
does not contain three identical consecutive characters. In other words, it does not contain either 'aaa' or 'bbb' substrings. Note that whole S is its own substring.
Write a function:
class Solution { public int solution(String S); }
which, given a string S, returns the length of the longest semi-alternating substring of S.
Examples:
Given S = 'baaabbabbb', your function should return 7, which is the length of 'aabbabb', the longest semi-alternating substring.
Given S = 'babba', your function should return 5, since whole S is semi-alternating.
Given S = 'abaaaa', your function should return 4, because the first four letters of S create a semi-alternating substring.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..200,000];
string S consists only of the characters 'a' and/or 'b'.
Solution:
This task is similar to the task String Without 3 Identical Consecutive Letters but here we need to find a longest substring which doesn’t contain three identical consecutive
characters and return it’s length.
In order to do this lets make two counters count and result. Count will keep length of the current substring which we processing and result will keep length of 
the longest substring we found. Then we need to pass through the given string and count it’s characters in the count. If we meet three identical consecutive characters 
we have to save length of the current processing substring in the result as a longest substring in case the count is bigger than the result. Then we have to reset the
count and start to count length of the current substring from 1.
When the whole string is processed just return the saved counter of the longest substring.




C++ code:
int solution(const string & s) {
    const int MAX_COUNT = 3;
    int s_len = s.length();
    if(s_len < MAX_COUNT) { return s_len; }
    int count = 1, result = 1;
    // Scan whole string and count it's characters.
    for(int i = 1; i < s_len - 1; ++i) {
        // If we meet 3 consecutive characters
        if((s[i-1] == s[i]) && (s[i+1] == s[i])) {
            // save the counter as result if it is 
            // bigger than the previous result
            result = max(result,count+1);
            // and drop the counter to 1
            count = 1;
        }
        else { count++; }
    }
    // return maximal result
    return max(result,count+1);
}
