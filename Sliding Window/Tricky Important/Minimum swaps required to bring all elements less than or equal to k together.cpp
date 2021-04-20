Minimum swaps required to bring all elements less than or equal to k together
Difficulty Level : Medium
 Last Updated : 19 Jul, 2018
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Input:  arr[] = {2, 1, 5, 6, 3}, k = 3
Output: 1

Explanation: 
To bring elements 2, 1, 3 together, swap 
element '5' with '3' such that final array
will be-
arr[] = {2, 1, 3, 6, 5}

Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
Output: 2
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
A simple solution is to first count all elements less than or equals to k(say ‘good’). Now traverse for every sub-array and swap those elements whose value is greater than k. Time complexity of this approach is O(n2)

A simple approach is to use two pointer technique and sliding window.

Find count of all elements which are less than or equals to ‘k’. Let’s say the count is ‘cnt’
Using two pointer technique for window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
Repeat step 2, for every window of length ‘cnt’ and take minimum of count ‘bad’ among them. This will be the final answer.

// C++ program to find minimum swaps required 
// to club all elements less than or equals 
// to k together 
#include <iostream> 
using namespace std; 
  
// Utility function to find minimum swaps 
// required to club all elements less than 
// or equals to k together 
int minSwap(int *arr, int n, int k) { 
      
    // Find count of elements which are 
    // less than equals to k 
    int count = 0; 
    for (int i = 0; i < n; ++i) 
        if (arr[i] <= k) 
            ++count; 
      
    // Find unwanted elements in current 
    // window of size 'count' 
    int bad = 0; 
    for (int i = 0; i < count; ++i) 
        if (arr[i] > k) 
            ++bad; 
      
    // Initialize answer with 'bad' value of 
    // current window 
    int ans = bad; 
    for (int i = 0, j = count; j < n; ++i, ++j) { 
          
        // Decrement count of previous window 
        if (arr[i] > k) 
            --bad; 
          
        // Increment count of current window 
        if (arr[j] > k) 
            ++bad; 
          
        // Update ans if count of 'bad' 
        // is less in current window 
        ans = min(ans, bad); 
    } 
    return ans; 
} 
  
// Driver code 
int main() { 
      
    int arr[] = {2, 1, 5, 6, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout << minSwap(arr, n, k) << "\n"; 
      
    int arr1[] = {2, 7, 9, 5, 8, 7, 4}; 
    n = sizeof(arr1) / sizeof(arr1[0]); 
    k = 5; 
    cout << minSwap(arr1, n, k); 
    return 0; 
} 
