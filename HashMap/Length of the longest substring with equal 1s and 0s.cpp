Length of the longest substring with equal 1s and 0s
Difficulty Level : Medium
 Last Updated : 31 Dec, 2020
Given a binary string. We need to find the length of the longest balanced substring. A substring is balanced if it contains an equal number of 0 and 1.

Examples:  

Input : input = 110101010
Output : Length of longest balanced
         sub string = 8

Input : input = 0000
Output : Length of longest balanced
         sub string = 0
         
         
         
  #include<bits/stdc++.h>
using namespace std;
 
// Returns length of the longest substring 
// with equal number of zeros and ones.
int stringLen(string str)
{
    // Create a map to store differences
    // between counts of 1s and 0s.
    map<int, int> m;
     
    // Initially difference is 0.
    m[0] = -1;   
     
    int count_0 = 0, count_1 = 0;
    int res = 0;
    for (int i=0; i<str.size(); i++)
    {
        // Keeping track of counts of
        // 0s and 1s.
        if (str[i] == '0')
            count_0++;
        else
            count_1++;
             
        // If difference between current counts
        // already exists, then substring between
        // previous and current index has same
        // no. of 0s and 1s. Update result if this
        // substring is more than current result.
        if (m.find(count_1 - count_0) != m.end())
            res = max(res, i - m[count_1 - count_0]);
             
        // If current difference is seen first time.        
        else
            m[count_1 - count_0] = i;
    }
 
    return res;
}
 
// driver function
int main()
{
    string str = "101001000";
    cout << "Length of longest balanced"
            " sub string = ";
    cout << stringLen(str);
    return 0;
}
