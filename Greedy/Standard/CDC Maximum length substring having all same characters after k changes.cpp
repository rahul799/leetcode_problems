

https://www.geeksforgeeks.org/maximum-length-substring-having-all-same-characters-after-k-changes/

Maximum length substring having all same characters after k changes
Difficulty Level : Hard
Last Updated : 08 Aug, 2019
We have a string of length n, which consist only UPPER and LOWER CASE characters and we have a number k (always less than n and greater than 0). We can make at most k changes in our string such that we can get a sub-string of maximum length which have all same characters.

Examples:

n = length of string
k = changes you can make
Input : n = 5 k = 2
        str = ABABA
Output : maximum length = 5
which will be (AAAAA)

Input : n = 6 k = 4
       str = HHHHHH
Output : maximum length=6
which will be(HHHHHH) 
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
We check for each character of English alphabet (both upper and lower cases one by one). We are basically looking for maximum length of sub-string that can be formed by each character and whichever character will form the sub-string of maximum length then that length will be our answer.

We check for maximum length of sub-string that can be formed by every character in a set of 52 characters (From ‘A’ to ‘Z’ and from ‘a’ to ‘z’).
For doing this we traverse whole string and whenever we find a different character, we increase the count.
If count becomes greater than k (at right index), we again start from 0th index and if we found different character we will decrease the count.
When count will be equal to k (at left index) then at that point the length will be rightIndex-leftIndex+1.
We repeat this process until we reach at the end of string and at that point we will return the maximum length.
We do this for all characters and finally return the maximum length.

// C++ program to find maximum length equal
// character string with k changes
#include <iostream>
using namespace std;
  
// function to find the maximum length of 
// substring having character ch
int findLen(string& A, int n, int k, char ch)
{
    int maxlen = 1;
    int cnt = 0;
    int l = 0, r = 0;
      
    // traverse the whole string
    while (r < n) {
      
        /* if character is not same as ch
           increase count */
        if (A[r] != ch)
            ++cnt;
  
        /* While  count > k  traverse the string
           again until count becomes less than k 
           and decrease the count when characters 
           are not same */
        while (cnt > k) {
            if (A[l] != ch)
                --cnt;
            ++l;
        }
  
        /* length of substring will be rightIndex -
           leftIndex + 1. Compare this with the maximum
           length and return maximum length */
        maxlen = max(maxlen, r - l + 1);
        ++r;
    }
    return maxlen;
}
  
// function which returns maximum length of substring
int answer(string& A, int n, int k)
{
    int maxlen = 1;
    for (int i = 0; i < 26; ++i) {
        maxlen = max(maxlen, findLen(A, n, k, i+'A'));
        maxlen = max(maxlen, findLen(A, n, k, i+'a'));
    }
    return maxlen;
}
  
// Driver code
int main()
{
    int n = 5, k = 2;
    string A = "ABABA";
    cout << "Maximum length = " << answer(A, n, k) << endl;
  
    n = 6, k = 4;
    string B = "HHHHHH";
    cout << "Maximum length = " << answer(B, n, k) << endl;
    return 0;
}


