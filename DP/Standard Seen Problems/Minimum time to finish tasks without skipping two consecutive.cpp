Minimum time to finish tasks without skipping two consecutive
Difficulty Level : Medium
 Last Updated : 24 May, 2018
Given time taken by n tasks. Find the minimum time needed to finish the tasks such that skipping of tasks is allowed, but can not skip two consecutive tasks.


Examples :

Input : arr[] = {10, 5, 7, 10}
Output : 12
We can skip first and last task and
finish these task in 12 min.

Input : arr[] = {10}
Output : 0
There is only one task and we can
skip it.

Input : arr[] = {10, 30}
Output : 10

Input : arr[] = {10, 5, 2, 4, 8, 6, 7, 10}
Output : 22
Expected Time Complexity is O(n) and extra space is O(1).

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
The given problem has the following recursive property.

Let minTime(i) be minimum time to finish till i’th task. It can be written as minimum of two values.



Minimum time if i’th task is included in list, let this time be incl(i)
Minimum time if i’th task is excluded from result, let this time be excl(i)
minTime(i) = min(excl(i), incl(i)) 
Result is minTime(n-1) if there are n tasks and indexes start from 0.

incl(i) can be written as below.

// There are two possibilities
// (a) Previous task is also included
// (b) Previous task is not included
incl(i) = min(incl(i-1), excl(i-1)) +
              arr[i] // Since this is inclusive 
                     // arr[i] must be included 
excl(i) can be written as below.


// There is only one possibility (Previous task must be
// included as we can't skip consecutive tasks.
excl(i) = incl(i-1)  
A simple solution is to make two tables incl[] and excl[] to store times for tasks. Finally return minimum of incl[n-1] and excl[n-1]. This solution requires O(n) time and O(n) space.

If we take a closer look, we can notice that we only need incl and excl of previous job. So we can save space and solve the problem in O(n) time and O(1) space. Below is C++ implementation of the idea.
filter_none
edit
play_arrow

brightness_4
// C++ program to find minimum time to finish tasks 
// such that no two consecutive tasks are skipped. 
#include <bits/stdc++.h> 
using namespace std; 
  
// arr[] represents time taken by n given tasks 
int minTime(int arr[], int n) 
{ 
    // Corner Cases 
    if (n <= 0) 
        return 0; 
  
    // Initialize value for the case when there 
    // is only one task in task list. 
    int incl = arr[0];  // First task is included 
    int excl = 0;       // First task is exluded 
  
    // Process remaining n-1 tasks 
    for (int i=1; i<n; i++) 
    { 
       // Time taken if current task is included 
       // There are two possibilities 
       // (a) Previous task is also included 
       // (b) Previous task is not included 
       int incl_new = arr[i] + min(excl, incl); 
  
       // Time taken when current task is not 
       // included.  There is only one possibility 
       // that previous task is also included. 
       int excl_new = incl; 
  
       // Update incl and excl for next iteration 
       incl = incl_new; 
       excl = excl_new; 
    } 
  
    // Return maximum of two values for last task 
    return min(incl, excl); 
} 
  
// Driver code 
int main() 
{ 
    int arr1[] = {10, 5, 2, 7, 10}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    cout << minTime(arr1, n1) << endl; 
  
    int arr2[] = {10, 5, 7, 10}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    cout << minTime(arr2, n2) << endl; 
  
    int arr3[] = {10, 5, 2, 4, 8, 6, 7, 10}; 
    int n3 = sizeof(arr3)/sizeof(arr3[0]); 
    cout << minTime(arr3, n3) << endl; 
  
    return 0; 
} 
