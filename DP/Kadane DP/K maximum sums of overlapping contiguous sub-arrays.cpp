


K maximum sums of overlapping contiguous sub-arrays
Difficulty Level : Hard
Given an array of Integers and an Integer value k, find out k sub-arrays(may be overlapping), which have k maximum sums.

Examples:

Input : arr = {4, -8, 9, -4, 1, -8, -1, 6}, k = 4
Output : 9 6 6 5


Input : arr = {-2, -3, 4, -1, -2, 1, 5, -3}, k= 3
Output : 7 6 5
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Using Kadane’s Algorithm we can find the maximum contiguous subarray sum of an array. But in the case Kadane’s Algorithm does not work. 
As whenever we hit an negative number in the array we set the max_ending_here variable to zero, hence we miss the possibilities for second and so on maximums.

Here we is an algorithm presented by Sung Eun Bae and Tadao Takaoka which computes the maximum sub-array sum problem in O(n) time 
and k maximum sub-array sum problem in O(k*n) time.



First we look at the problem of only maximum sub-array sum using this method:

Prerequisite:
1. Prefix sum array
2. Maximum subarray sum in O(n) using prefix sum

Method for k-maximum sub-arrays:

1. Calculate the prefix sum of the input array.
2. Take cand, maxi and mini as arrays of size k. 
3. Initialize mini[0] = 0 for the same reason as previous.
4. for each value of the prefix_sum[i] do
       (i). update cand[j] value by prefix_sum[i] - mini[j]
       (ii). maxi will be the maximum k elements of maxi and cand
       (iii). if prefix_sum is less than all values of mini, then 
              include it in mini and remove the maximum element from mini
       // After the ith iteration mini holds k minimum prefix sum upto
       // index i and maxi holds k maximum overlapping sub-array sums 
       // upto index i.
5. return maxi 
Throughout this calculation method, we keep maxi in non-increasing and mini in non-decreasing order.


// C++ program to find out k maximum sum of
// overlapping sub-arrays
#include <iostream>
#include <limits>
#include <vector>
  
using namespace std;
  
// Function to compute prefix-sum of the input array
vector<int> prefix_sum(vector<int> arr, int n)
{
    vector<int> pre_sum;
    pre_sum.push_back(arr[0]);
    for (int i = 1; i < n; i++) 
        pre_sum.push_back(pre_sum[i - 1] + arr[i]);    
    return pre_sum;
}
  
// Update maxi by k maximum values from maxi and cand
void maxMerge(vector<int>& maxi, vector<int> cand)
{
    // Here cand and maxi arrays are in non-increasing
    // order beforehand. Now, j is the index of the
    // next cand element and i is the index of next
    // maxi element. Traverse through maxi array.
    // If cand[j] > maxi[i] insert cand[j] at the ith
    // position in the maxi array and remove the minimum
    // element of the maxi array i.e. the last element
    // and increase j by 1 i.e. take the next element
    // from cand.
    int k = maxi.size();
    int j = 0;
    for (int i = 0; i < k; i++) {
        if (cand[j] > maxi[i]) {
            maxi.insert(maxi.begin() + i, cand[j]);
            maxi.erase(maxi.begin() + k);
            j += 1;
        }
    }
}
  
// Insert prefix_sum[i] to mini array if needed
void insertMini(vector<int>& mini, int pre_sum)
{
    // Traverse the mini array from left to right.
    // If prefix_sum[i] is less than any element
    // then insert prefix_sum[i] at that position
    // and delete maximum element of the mini array
    // i.e. the rightmost element from the array.
    int k = mini.size();
    for (int i = 0; i < k; i++) {
        if (pre_sum < mini[i]) {
            mini.insert(mini.begin() + i, pre_sum);
            mini.erase(mini.begin() + k);
            break;
        }
    }
}
  
// Function to compute k maximum overlapping sub-
// array sums
void kMaxOvSubArray(vector<int> arr, int k)
{
    int n = arr.size();
  
    // Compute the prefix sum of the input array.
    vector<int> pre_sum = prefix_sum(arr, n);
  
    // Set all the elements of mini as +infinite
    // except 0th. Set the 0th element as 0.
    vector<int> mini(k, numeric_limits<int>::max());
    mini[0] = 0;
  
    // Set all the elements of maxi as -infinite.
    vector<int> maxi(k, numeric_limits<int>::min());
  
    // Initialize cand array.
    vector<int> cand(k);
  
    // For each element of the prefix_sum array do:
    // compute the cand array.
    // take k maximum values from maxi and cand
    // using maxmerge function.
    // insert prefix_sum[i] to mini array if needed
    // using insertMini function.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
             if(pre_sum[i] < 0 && mini[j]==numeric_limits<int>::max())
           cand[j]=(-pre_sum[i])-mini[j];
         else cand[j] = pre_sum[i] - mini[j];
        }
        maxMerge(maxi, cand);
        insertMini(mini, pre_sum[i]);
    }
  
    // Elements of maxi array is the k
    // maximum overlapping sub-array sums.
    // Print out the elements of maxi array.
    for (int ele : maxi)
        cout << ele << " ";
    cout << endl;
}
  
// Driver Program
int main()
{
    // Test case 1
    vector<int> arr1 = { 4, -8, 9, -4, 1, -8, -1, 6 };
    int k1 = 4;
    kMaxOvSubArray(arr1, k1);
  
    // Test case 2
    vector<int> arr2 = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int k2 = 3;
    kMaxOvSubArray(arr2, k2);
    return 0;
}

Output:
9 6 6 5
7 6 5
Time Complexity: The ‘insertMini’ and ‘maxMerge’ functions runs in O(k) time and it takes O(k) time to update the ‘cand’ array. 
We do this process for n times. Hence, the overall time complexity is O(k*n)
