





https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064497/Unravel-it-Layer-by-Layer




We can apply Binary Search on the Answer Space. The minimum lower bound after all operations have been performed is 1 while the maximum is 10^9. Suppose that the all the elements are less than or equal to max_allowed. Let's find out the minimum number of operations required to satisfy this constraint.

Let's solve for each array element individually. Say, we are solving for ele. By Euclid's Division Lemma, we have

ele = quotient*max_allowed + remainder
Suppose remainder is zero, implying ele = quotient*max_allowed. In other words, the element is made up of quotient blocks, where each block is of size max_allowed. Hence, at each step, we can unravel one layer of the box, resulting in a total of (quotient - 1) steps to completion.

Now, assume remainder is non-zero. Hence, in the first step of unraveling, we can split remainder in one half and quotient*remainder in other and then follow the steps in the previous paragraph for the second part.

To conclude, if rem == 0, the minimum operations required is quotient - 1, else, the minimum operations required is (quotient).

Once we are certain that a series of steps exist which can lead to every element being less than or equal to mid, we can simply discard 
the right half of the search space. If not, we can discard the left half.

The time complexity is O(N log(N)).

Extended Discussion : Why are we not splitting in half at each stage?

A simple counter example is an element with value 8, where the maximum allowed value is 3. If we split it into half, we get 4 and 4. Hence, we need 3 steps. However, if we split it into 6 + 2, we can be done in 2 steps.

But that was a counter example, what's the intuition? We have to realize that even if we split into 2 at each stage, we have to eventually make a cut which partitions it into sizes less than max_allowed. Hence, we'd have just wasted the split by 2 cuts. Hence, it's optimal to peel one layer as soon as possible.

Another way to look at it is, if you divide it into 2 equal halves at each stage, the tree would be a binary tree, hence, cost is counted for each node in the tree, which can be huge. However, if you follow the above algorithm, the tree would be linear (so, in other words, you only have to travel (roughly) one height, rather than all nodes of the old tree).

A yet another perspective : Visualize each box as a set of people. Suppose we want to ensure sizes of atmost max_allowed. We can interpret this situation as : You need to seat n people in benches, such that each bench has capacity atmost max_allowed. What is the minimum number of benches required? Now, it seems rather intuitive that you'd fill each bench to its full capacity, except possibly the last one. In other words
  
  
  


1760. Minimum Limit of Balls in a Bag
Medium

353

19

Add to List

Share
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

 

Example 1:

Input: nums = [9], maxOperations = 2
Output: 3
Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
Example 2:

Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2 an you should return 2.
Example 3:

Input: nums = [7,17], maxOperations = 2
Output: 7
 

Constraints:

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109








int get_cost(int val, int max_allow) {
    int quotient = val/max_allow;
    int rem = val % max_allow;
    return quotient + (rem == 0 ? -1 : 0);
}

class Solution {
public:
    int minimumSize(vector<int>& a, int max_op) {
        int low = 1, high = 1e9,res = -1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            long long need = 0;
            for(auto &ele : a)
                need += get_cost(ele, mid);
            
            if(need <= max_op) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return res;
    }
};
