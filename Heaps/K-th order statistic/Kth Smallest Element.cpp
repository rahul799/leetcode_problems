Kth Smallest Element
Question 175 of 931
Given a list of unsorted integers nums, and an integer k, return the kth (0-indexed) smallest element in the list.

This should be done in \mathcal{O}(n)O(n) time.

Constraints

0 ≤ k < n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [5, 3, 8, 2, 0]
k = 2
Output
3
Explanation
When sorted the numbers are [0, 2, 3, 5, 8] and index 2's value is 3.



O(n) approach : yet to understand!


Using some variation of QuickSort

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start], j = end;
    for (int i=start+1; i<=j;) {
        if (nums[i] >= pivot)  swap(nums[i], nums[j--]);
        else i++;
    }
    swap(nums[start], nums[j]);
    return j;
}

int solve(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = partition(nums, l, r);
        if (m == k)  return nums[m];
        else if (m < k)  l = m + 1;    
        else  r = m - 1; 
    }
    return nums[l];
}
