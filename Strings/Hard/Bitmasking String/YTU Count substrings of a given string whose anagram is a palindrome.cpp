

Asked in interview YET TO Understand 
https://www.geeksforgeeks.org/count-substrings-of-a-given-string-whose-anagram-is-a-palindrome/?ref=rp



Count substrings of a given string whose anagram is a palindrome
Difficulty Level : Hard
 Last Updated : 29 Sep, 2020
Given a string S of length N containing only lowercase alphabets, the task is to print the count of substrings of the given string whose anagram is palindromic.

Examples:

Input: S = “aaaa”
Output: 10
Explanation:
Possible substrings are {“a”, “a”, “a”, “a”, “aa”, “aa”, “aa”, “aaa”, “aaa”, “aaaa”}. Since all substrings are have palindromic anagrams, the required answer is 10.

Input: S = “abc”
Output: 3

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The idea is to generate all substrings of the given string and for each substring, check whether its anagram is a palindrome or not. Keep increasing the count of substrings for which the above condition is found to be true. Finally, print the count of all such substrings. 
Time Complexity: O(N3)
Auxiliary Space: O(N)

Bit Masking Approach: The idea is to generate the masks of 26-bit numbers as there are 26 characters. Also, observe that if the anagram of some string is a palindrome, then the frequencies of its characters except at most one character must be even. 
Follow the steps below to solve the problem:



Traverse the string and initialize a variable X = 0 at each index.
From every ithe index, traverse the string over a range of indices [i, N – 1], and for each character S[j], calculate Bitwise XOR of X and 2(S[j] – ‘a’), where 0th bit represents if the frequency of a is odd, 1st bit represents if the frequency of b is odd, and so on.
Then, check if X & (X – 1) is equal to 0 or not. If found to be true, then increment the count by 1. 
 
Illustration: 
Suppose, X = (0001000)2 
=> (X – 1) will be represented as (0000111)2. 
Therefore, X & (X – 1) = 0

Once the above steps are exhausted, print the count obtained.
Below is the implementation of the above approach:

filter_none
edit
play_arrow

brightness_4
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to print count of substrings
// whose anagrams are palindromic
void countSubstring(string s)
{
    // Stores the answer
    int res = 0;
 
    // Iterate over the string
    for (int i = 0;
         i < s.length(); i++) {
 
        int x = 0;
 
        for (int j = i;
             j < s.length(); j++) {
 
            // Set the current character
            int temp = 1 << s[j] - 'a';
 
            // Parity update
            x ^= temp;
            if ((x & (x - 1)) == 0)
                res++;
        }
    }
 
    // Print the final count
    cout << res;
}
 
// Driver Code
int main()
{
    string str = "aaa";
 
    // Function Call
    countSubstring(str);
 
    return 0;
}
Output
6
Time Complexity: O(N2)
Auxiliary Space: O(N) 

Efficient Approach: To optimize the above Bit Masking technique, the idea is to use a Map. Follow the steps below to solve the problem: 

Initialize a map to store the frequencies of the masks. Initialize a variable X = 0.
Traverse the string and for every ith index, calculate Bitwise XOR of X and 2(S[j] – ‘a’) and update the answer by adding the frequency of the current value of X in the Map because if any substring from 0 to j has the same mask as that of X, which is a mask for substring from 0 to i, then substring S[j + 1, i] will have even frequencies, where j < i.
Also add the frequencies of masks X xor 2k, where, 0 ≤ k < 26. After that, increment the frequency of X by 1.
Repeat the above steps for each index of the given string.
After traversing the given string, print the required answer.
Below is the implementation of the above approach: 

filter_none
edit
play_arrow

brightness_4
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to get the count of substrings
// whose anagrams are palindromic
void countSubstring(string s)
{
    // Store the answer
    int answer = 0;
 
    // Map to store the freq of masks
    unordered_map<int, int> m;
 
    // Set frequency for mask
    // 00...00 to 1
    m[0] = 1;
 
    // Store mask in x from 0 to i
    int x = 0;
    for (int j = 0; j < s.length(); j++) {
        x ^= 1 << (s[j] - 'a');
 
        // Update answer
        answer += m[x];
        for (int i = 0; i < 26; ++i) {
            answer += m[x ^ (1 << i)];
        }
 
        // Update frequency
        m[x] += 1;
    }
 
    // Print the answer
    cout << answer;
}
 
// Driver Code
int main()
{
    string str = "abab";
 
    // Function Call
    countSubstring(str);
    return 0;
}
Output
7
Time Complexity: O(N)
Auxiliary Space: O(N)
