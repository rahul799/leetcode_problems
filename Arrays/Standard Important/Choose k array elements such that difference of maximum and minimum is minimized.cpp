

Choose k array elements such that difference of maximum and minimum is minimized

https://www.geeksforgeeks.org/k-numbers-difference-maximum-minimum-k-number-minimized/


Choose k array elements such that difference of maximum and minimum is minimized
Difficulty Level : Easy
Last Updated : 15 Jul, 2019
Given an array of n integers and a positive number k. We are allowed to take any k integers from the given array. The task is to find the minimum possible value of the difference between maximum and minimum of K numbers.

Examples:

Input : arr[] = {10, 100, 300, 200, 1000, 20, 30}
        k = 3
Output : 20
20 is the minimum possible difference between any
maximum and minimum of any k numbers.
Given k = 3, we get the result 20 by selecting 
integers {10, 20, 30}.
max(10, 20, 30) - max(10, 20, 30) = 30 - 10 = 20.

Input : arr[] = {1, 2, 3, 4, 10, 20, 30, 40, 
                                   100, 200}.
        k = 4      
Output : 3
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
The idea is to sort the array and choose k continuous integers. Why continuous? let the chosen k integers be arr[0], arr[1],,..arr[r], arr[r+x]…, arr[k-1], all in increasing order but not continuous in the sorted array. This means there exists an integer p which lies between arr[r] and arr[r+x],. So if p is included and arr[0] is removed, then the new difference will be arr[r] – arr[1] whereas old difference was arr[r] – arr[0]. And we know arr[0] <= arr[1] <= ..<= arr[k-1] so minimum difference reduces or remain same. If we perform same procedure for other p like number, we get the minimum difference.

Algorithm to solve the problem:

Sort the Array.
Calculate the maximum(k numbers) – minimum(k numbers) for each group of k consecutive integers.
Return minimum of all values obtained in step 2.
Below is the implementation of above idea :




// C++ program to find minimum difference of maximum
// and minimum of K number.
#include<bits/stdc++.h>
using namespace std;
  
// Return minimum difference of maximum and minimum
// of k elements of arr[0..n-1].
int minDiff(int arr[], int n, int k)
{
    int result = INT_MAX;
  
    // Sorting the array.
    sort(arr, arr + n);
  
    // Find minimum value among all K size subarray.
    for (int i=0; i<=n-k; i++)
        result = min(result, arr[i+k-1] - arr[i]);
  
    return result;
}
  
// Driven Program
int main()
{
    int arr[] = {10, 100, 300, 200, 1000, 20, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
  
    cout << minDiff(arr, n, k) << endl;
    return 0;
}
