




645. Set Mismatch
Easy

1077

418

Add to List

Share
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104







vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1])swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1)return {nums[i], i + 1};
        }
    }

















Since all those O(1) space solutions are modying the input array, here is an idea that doesn't do that:

Take for example [1 2 3 2 5 6], and all numbers [1 2 3 4 5 6].
In binary: [001 010 011 010 101 110], [001 010 011 100 101 110].

Now, if we XOR the 2 arrays, we will get the XOR of our duplicate and missing number, because our duplicate number would appear 3 times (2 times in input array and 1 time in all number array), and the missing number 1 time (1 time in all number array). In our case, missing ^ duplicate = 110.

Now, we know the missing and duplicate number are different in the first and second most significant bits (110). So let's take the last one: 110 -> get last 1 -> 010.

Then, we go through the arrays once again and split them in 2 categories, if they have that bit set or not:
(x & 010) != 0: [010 011 010 110], [010 011 110] -> XOR all of them and we get 010.
(x & 010) == 0: [001 101], [001 100 101] -> XOR all of them and we get 100.

010 and 100 (2 and 4) are our duplicate and missing numbers, but we don't know which is which. Just go one more time through the array to see which one we can find, in our case: 010. So 2 is the duplicate, and 4 the missing one.

The downside is, of course, that we do 3 passes, but it is still, O(n) time.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int p = 0, acc1 = 0, acc2 = 0;
        // Get the xor of missing and duplicate numbers
        for (unsigned i = 0; i < nums.size(); ++i)
            p ^= (i + 1) ^ nums[i];

        p &= -p; // We'll use only the last significant set bit

        // Split the numbers in 2 categories and xor them
        for (unsigned i = 0; i < nums.size(); ++i)
        {
            ((nums[i] & p) == 0) ? acc1 ^= nums[i] : acc2 ^= nums[i];
            (((i + 1) & p) == 0) ? acc1 ^= i + 1 : acc2 ^= i + 1;
        }

        // Determine which is the duplicate number
        for (auto n : nums)
            if (n == acc1)
                return {acc1, acc2};
        return {acc2, acc1};
    }
};
