Count minimum number of fountains to be activated to cover the entire garden
Difficulty Level : Hard
 Last Updated : 27 Oct, 2020
There is a one-dimensional garden of length N. In each position of the N length garden, a fountain has been installed. Given an array a[]such that a[i] describes the coverage limit of ith fountain. A fountain can cover the range from the position max(i – a[i], 1) to min(i + a[i], N). In beginning, all the fountains are switched off. The task is to find the minimum number of fountains needed to be activated such that the whole N-length garden can be covered by water.

Examples:

Input: a[] = {1, 2, 1}
Output: 1
Explanation:
For position 1: a[1] = 1, range = 1 to 2
For position 2: a[2] = 2, range = 1 to 3
For position 3: a[3] = 1, range = 2 to 3
Therefore, the fountain at position a[2] covers the whole garden.
Therefore, the required output is 1.

Input: a[] = {2, 1, 1, 2, 1} 
Output: 2 

 
Approach: The problem can be solved using Dynamic Programming. Follow the steps below to solve the problem: 



traverse the array and for every array index, i.e. ith fountain, find the leftmost fountain up to which the current fountain covers.
Then, find the rightmost fountain that the leftmost fountain obtained in the above step covers up to and update it in the dp[] array.
Initialize a variable cntFount to store the minimum number of fountains that need to be activated.
Now, traverse the dp[] array and keep activating the fountains from the left that covers maximum fountains currently on the right and increment cntFount by 1. Finally, print cntFount as the required answer.
Below is the implementation of the above approach.

C++14
filter_none
edit
play_arrow

brightness_4
// C++ program to implement
// the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to find minimum
// number of fountains to be
// activated
int minCntFoun(int a[], int N)
{
 
    // dp[i]: Stores the position of
    // rightmost fountain that can
    // be covered by water of leftmost
    // fountain of the i-th fountain
    int dp[N];
 
    // Stores index of leftmost fountain
    // in the range of i-th fountain
    int idxLeft;
 
    // Stores index of rightmost fountain
    // in the range of i-th fountain
    int idxRight;
 
    // Traverse the array
    for (int i = 0; i < N; i++) {
        idxLeft = max(i - a[i], 0);
        idxRight = min(i + (a[i] + 1), N);
        dp[idxLeft] = max(dp[idxLeft],
                          idxRight);
    }
 
    // Stores count of fountains
    // needed to be activated
    int cntfount = 1;
 
    idxRight = dp[0];
 
    // Stores index of next fountain
    // that needed to be activated
    int idxNext;
 
    // Traverse dp[] array
    for (int i = 0; i < N; i++) {
        idxNext = max(idxNext,
                      dp[i]);
 
        // If left most fountain
        // cover all its range
        if (i == idxRight) {
            cntfount++;
            idxRight = idxNext;
        }
    }
 
    return cntfount;
}
 
// Driver Code
int main()
{
    int a[] = { 1, 2, 1 };
    int N = sizeof(a) / sizeof(a[0]);
    cout << minCntFoun(a, N);
}
