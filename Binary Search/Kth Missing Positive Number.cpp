
1539. Kth Missing Positive Number
Easy

667

24

Add to List

Share
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length





The idea here is that :

Since all the number in the array are in increasing order , so If NONE of the elemts is missing then for each index i we should have the value (i+1). Here we are considering 0 based indexing.

But if some the elements upto any index is missing , then we can find the number of missing elements using above logic.

No of missing numbers at index i = (Current Value at index i ) - ( Correct Value as per contiguous sequence )
= A[i]-(i+1) // At any index i

Now , we can use binary search in this question by checking if number of missing number at mid is less than K , that means we need to check for Kth number on right side of mid.

Otherwise , if number of missing values is greater than K , then our missing number lies in left of the array

Time Complexity : O (log(n)) // Number of array elements
Space Complexity : O(1)

 int findKthPositive(vector<int>& A, int k) {
       int low = 0;
       int high = A.size()-1 ;
       int mid;
       while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] - (1 + mid) < k)  //A[m]-(m+1)   --> This gives umber of missing number before m'th index
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
