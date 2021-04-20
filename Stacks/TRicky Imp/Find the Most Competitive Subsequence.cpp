
1673. Find the Most Competitive Subsequence
Medium

344

17

Add to List

Share
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

 

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length
Accepted


ntuition
Use a mono incrasing stack.


Explanation
Keep a mono incrasing stackas result.
If current element a is smaller then the last element in the stack,
we can replace it to get a smaller sequence.

Before we do this,
we need to check if we still have enough elements after.
After we pop the last element from stack,
we have stack.size() - 1 in the stack,
there are A.size() - i can still be pushed.
if stack.size() - 1 + A.size() - i >= k, we can pop the stack.

Then, is the stack not full with k element,
we push A[i] into the stack.

Finally we return stack as the result directly.


Complexity
Time O(n)
Space O(k)









 vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
                stack.pop_back();
            if (stack.size() < k)
                stack.push_back(A[i]);
        }
        return stack;
    }
