Count substrings that starts with character X and ends with character Y


Count substrings that starts with character X and ends with character Y - GeeksforGeeks
Given a string str of n lowercase characters, the task is to count the number of substrings
of str starting with character X and ending with character Y.

Examples:
Input: str = "abbcaceghcak"
x = 'a', y = 'c'
Output: 5
abbc, abbcac, ac, abbcaceghc, aceghc
Input: str = "geeksforgeeks"
x = 'g', y = 'e'
Output: 6
Approach:
• Initialize two counters i.e. tot_count to count the total number of substrings and
count_x to count the number of strings that start with X.
• Start traversing the string.
• If the current character is X then increment the count of count_x.
• If the current character is Y, it means a string ends at Y so increment the count of
tot_count i.e.

Chapter 181. Count substrings that starts with character X and ends with character Y
tot_count = tot_count + count_x
It means that if there exists a Y then it will make a substring with all the X occurs
before Y in the string. So, add the count of X to the total count.
• Return total count.


C++
// C++ implementation to count substrings
// starting with character X and ending
// with character Y
#include <bits/stdc++.h>
using namespace std;
// function to count substrings starting with
// character X and ending with character Y
int countSubstr(string str, int n,
char x, char y)
{
// to store total count of
// required substrings
int tot_count = 0;
// to store count of character 'x'
// up to the point the string 'str'
// has been traversed so far
int count_x = 0;
// traverse 'str' form left to right
for (int i = 0; i < n; i++) {
// if true, increment 'count_x'
if (str[i] == x)
count_x++;
// if true accumulate 'count_x'
// to 'tot_count'
if (str[i] == y)
tot_count += count_x;
}
// required count
return tot_count;
}
// Driver code
int main()
{
string str = "abbcaceghcak";
int n = str.size();
char x = 'a', y = 'c';
cout << "Count = "
<< countSubstr(str, n, x, y);
return 0;
}
