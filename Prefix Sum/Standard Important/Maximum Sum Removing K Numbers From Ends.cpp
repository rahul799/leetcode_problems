


Maximum Sum Removing K Numbers From Ends
You are given a list of integers nums and integer k. Return the maximum sum of elements that you can remove given that you must
pop exactly k times, where each pop can be from the left or the right end.

Constraints

k ≤ n ≤ 100,000 where n is length of nums.
Example 1
Input
nums = [1, 3, 4, 2, 0]
k = 2
Output
4
Explanation
We take the 1 and the 3

Example 2
Input
nums = [3, 1, 1, 1, 13, -1, 0]
k = 4
Output
15
Explanation
We take 3 from the left and 0, -1, 13 from the right.




We will do an exhaustive search for all different combination of front + back using sliding window/ prefix-suffix sums
First, add up k elements from the front
for 0 to k , subtract nums[k-i-1] from the front, and add nums[nums.length-i-1] from the end
Time O(k)
Space O(1)





int solve(vector<int>& nums, int k) {
          int psum = 0, ssum = 0;
        for (int i = 0; i < k; i++) {
            psum += nums[i];
        }
        int res = psum;
        for (int i = 0; i < k; i++) {
            psum -= nums[k - 1 - i];
            ssum += nums[nums.size() - 1 - i];
            res = max(res, psum + ssum);
        }
        return res;
    }
    
