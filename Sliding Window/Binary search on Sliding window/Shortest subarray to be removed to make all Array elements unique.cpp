Shortest subarray to be removed to make all Array elements unique
Difficulty Level : Hard
 Last Updated : 14 Sep, 2020
Given an array arr[] containing N elements, the task is to remove a subarray of minimum possible length from the given array such that all remaining elements are pairwise distinct. Print the minimum possible length of the subarray.
Examples:



https://www.geeksforgeeks.org/shortest-subarray-to-be-removed-to-make-all-array-elements-unique/



Input: N = 5, arr[] = {1, 2, 1, 2, 3} 
Output: 2 
Explanation: 
Remove the sub array {2, 1} to make the elements distinct. 

Input: N = 5, arr[] = {1, 2, 3, 4, 5} 
Output: 0 
Explanation: 
Elements are already distinct.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The naive approach for this problem is to simply check for all the possible subarrays and find the length of the smallest subarray after removal of which all the elements in the array become pairwise distinct. 

Time complexity: O(N3) 


Basically what we need to do is to make all array elements distinct to make them pair wise distinct


Efficient Approach:

Let ans be the length of the minimum subarray that on removing from the given array, makes the elements of the array unique.
We can easily observe that if all array elements become distinct after removing a subarray of length ans, then this condition is also true for all values greater than ans.
This means that the solution for this problem is a monotonically increasing function and we can apply binary search on the answer.
Now, for a particular length K of subarray, we can check if elements of prefix and suffix of all sub arrays of length K are pairwise distinct or not.
We can do this by using a sliding window technique.
Use a hash map to store the frequencies of elements in prefix and suffix, on moving the window forward, increment frequency of the last element of prefix and decrement frequency of the first element of suffix.
Below is the implementation of the above approach:


// C++ program to make array elements  
// pairwise distinct by removing at most  
// one subarray of minimum length  
  
#include <bits/stdc++.h>  
using namespace std;  
  
// Function to check if elements of  
// Prefix and suffix of each sub array  
// of size K are pairwise distinct or not  
bool check(int a[], int n, int k)  
{  
    // Hash map to store frequencies of  
    // elements of prefix and suffix  
    map<int, int> m;  
  
    // Variable to store number of  
    // occurrences of an element other  
    // than one  
    int extra = 0;  
  
    // Adding frequency of elements of suffix  
    // to hash for subarray starting from first  
    // index  
    // There is no prefix for this sub array  
    for (int i = k; i < n; i++)  
        m[a[i]]++;  
  
    // Counting extra elements in current Hash  
    // map  
    for (auto x : m)  
        extra += x.second - 1;  
  
    // If there are no extra elements return  
    // true  
    if (extra == 0)  
        return true;  
  
    // Check for remaining sub arrays  
  
    for (int i = 1; i + k - 1 < n; i++) {  
  
        // First element of suffix is now  
        // part of subarray which is being  
        // removed so, check for extra elements  
        if (m[a[i + k - 1]] > 1)  
            extra--;  
  
        // Decrement frequency of first  
        // element of the suffix  
        m[a[i + k - 1]]--;  
  
        // Increment frequency of last  
        // element of the prefix  
        m[a[i - 1]]++;  
  
        // Check for extra elements  
        if (m[a[i - 1]] > 1)  
            extra++;  
  
        // If there are no extra elements  
        // return true  
        if (extra == 0)  
            return true;  
    }  
  
    return false;  
}  
  
// Function for calculating minimum  
// length of the subarray, which on  
// removing make all elements pairwise  
// distinct  
int minlength(int a[], int n)  
{  
    // Possible range of length of subarray  
    int lo = 0, hi = n + 1;  
  
    int ans = 0;  
  
    // Binary search to find minimum ans  
    while (lo < hi) {  
  
        int mid = (lo + hi) / 2;  
  
        if (check(a, n, mid)) {  
            ans = mid;  
            hi = mid;  
        }  
        else
            lo = mid + 1;  
    }  
  
    return ans;  
}  
  
// Driver code  
int main()  
{  
    int a[5] = { 1, 2, 1, 2, 3 };  
  
    int n = sizeof(a) / sizeof(int);  
  
    cout << minlength(a, n);  
}  
Output: 
2
Time Complexity: O(N * log(N)), where N is the size of the array.
