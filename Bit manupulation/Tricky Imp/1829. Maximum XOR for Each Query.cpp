
https://leetcode.com/problems/maximum-xor-for-each-query/discuss/1163057/Easy-O(N)-Solution-w-Explanation-or-Max-XOR-2maximumBit-1


1829. Maximum XOR for Each Query
Medium

48

4

Add to List

Share
You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,1,3], maximumBit = 2
Output: [0,3,2,3]
Explanation: The queries are answered as follows:
1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
4th query: nums = [0], k = 3 since 0 XOR 3 = 3.
Example 2:

Input: nums = [2,3,4,7], maximumBit = 3
Output: [5,2,6,5]
Explanation: The queries are answered as follows:
1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
4th query: nums = [2], k = 5 since 2 XOR 5 = 7.
Example 3:

Input: nums = [0,1,2,2,5,7], maximumBit = 3
Output: [4,3,6,4,6,7]
 

Constraints:

nums.length == n
1 <= n <= 105
1 <= maximumBit <= 20
0 <= nums[i] < 2maximumBit
nums​​​ is sorted in ascending order.
  
  
  
  
We need to realize that maximum XOR for a query can always be made equal to 2^maximumBit - 1. For this it's also necessary to notice this constraint -

0 <= nums[i] < 2^maximumBit
How is maximum always 2^maximumBit - 1 ?

It is given that all elements of the nums are in the range [0, 2^maximumBit - 1]. And, after xor-ing the whole nums array, we will always have a final value (lets call it XOR) in between [0, 2^maximumBit - 1].

Now, we can xor this value with any number from the range [0, 2^maximumBit - 1]. To maximize it, we can always choose a value from that range which when xor-ed with XOR(above obtained value), will maximize it to 2^maximumBit - 1.

Some Examples:
Here, XOR will denote the xor of all elements of original nums array.

Let maximumBit = 3.
Our range will be from [0, 7]. Now, if - 

1. XOR = 1 (001) :  we can choose to xor it with 6 so that maximum xor for query will become '2^maximumBit - 1 = 7'
	   ^ 6 (110)
	   ----------
		    111
			
2. XOR = 2 (010) :  we can choose to xor it with 5 so that maximum xor for query will become '2^maximumBit - 1 = 7'
	   ^ 5 (101)
	   ----------
		    111

3. XOR = 3 (011) :  we can choose to xor it with 4 
	   ^ 4 (100)
	   ----------
		    111
			
4. XOR = 4 (100) :  we can choose to xor it with 3
	   ^ 3 (011)
	   ----------
		    111	
			
And so on for any other cases, we can choose a value to maximize xor to '2^maximumBit-1'
  
  
  
  
1829. Maximum XOR for Each Query
Medium

48

4

Add to List

Share
You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:

Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,1,3], maximumBit = 2
Output: [0,3,2,3]
Explanation: The queries are answered as follows:
1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
4th query: nums = [0], k = 3 since 0 XOR 3 = 3.
Example 2:

Input: nums = [2,3,4,7], maximumBit = 3
Output: [5,2,6,5]
Explanation: The queries are answered as follows:
1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
4th query: nums = [2], k = 5 since 2 XOR 5 = 7.
Example 3:

Input: nums = [0,1,2,2,5,7], maximumBit = 3
Output: [4,3,6,4,6,7]
 

Constraints:

nums.length == n
1 <= n <= 105
1 <= maximumBit <= 20
0 <= nums[i] < 2maximumBit
nums​​​ is sorted in ascending order.






class Solution {
public:
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
	int n = size(nums), XOR = 0;
	vector<int> ans(n);
	for(auto& num : nums) XOR ^= num;
        XOR ^= (1 << maximumBit) - 1; 
	ans[0] = XOR; // 2^maximumBit - 1
	for(int i = 1; i < n; i++)
		ans[i] = XOR ^= nums[n - i];            
	return ans;
}
};
