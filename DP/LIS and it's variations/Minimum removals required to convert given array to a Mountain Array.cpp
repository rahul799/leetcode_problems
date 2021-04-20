Minimum removals required to convert given array to a Mountain Array

https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/






Given an array arr[] consisting of N integers​​​, the task is to find the minimum number of array elements required to be removed to to make the given array a mountain array.

A mountain array has the following properties:

Length of the array ≥ 3.
There exists some index i (0-based indexing) with 0 < i < N – 1 such that:
arr[0] < arr[1] < … < arr[i – 1] < arr[i]
arr[i] > arr[i + 1] > … > arr[arr.length – 1].
Examples:

Input: arr[] = {1, 3, 1} 
Output: 0
Explanation: The array itself is a mountain array. Therefore, no removal is required.

Input: arr[] = {2, 1, 1, 5, 6, 2, 3, 1}
Output: 3
Explanation: Removing arr[0], arr[1] and arr[5] modifies arr[] to {1, 5, 6, 3, 1}, which is a mountain array.



Approach: The idea is to solve this problem using Bottom-Up Dynamic Programming approach. Follow the steps below to solve the problem:

If the length of the given array is less than 3, then the array cannot be converted to a mountain array.
Otherwise, traverse the array and for every ith element (0 < i < N), find the length of increasing subsequence in the subarrays {arr[0], …, arr[i – 1]} and store it in an array, say leftIncreasing[].
Similarly, find the length of the increasing subsequence in the subarray {arr[i+1], …., arr[N-1]} for every ith element (0 < i < N), and store it in an array, say rightIncreasing[].
Find the index i (0 < i < N) which satisfies following conditions:
First compulsory condition is the peak condition, which is leftIncreasing[i] > 0 and rightIncreasing[i] > 0.
Among all indices, If leftIncreasing[i] + rightIncreasing[i] is maximum, that index is the peak of the mountain array, say X.
Return the result as N – (X + 1), adding one to bring array index to length.
Illustration:

Consider the array arr[] = {4, 3, 6, 4, 5}
Therefore, leftIncreasing[] = {0, 0, 1, 1, 2} & rightIncreasing[] = {2, 1, 1, 0, 0}.
There is only one index i = 2 (0-based indexing), for which leftIncreasing[2] > 0 and rightIncreasing[2] > 0.
Therefore, X = leftIncreasing[2] + rightIncreasing[2] = 2.
Therefore, required answer = N – (X + 1) = 5 – (2 + 3)= 2.
One of the possible solution can be {4, 6, 5} i.e. removing 3 (arr[1]) and 4(arr[3]).




class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>l(nums.size(),1);
        vector<int>r(nums.size(),1);
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && l[i]<l[j]+1)
                    l[i]=l[j]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j] && r[i]<r[j]+1)
                    r[i]=r[j]+1;
            }
        }
        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(l[i]+r[i]-1>ans)
                ans=l[i]+r[i]-1;
        }
        cout<<ans<<endl;
        return nums.size()-ans;
    }
};





	class Solution {
	public:
		int minimumMountainRemovals(vector<int>& nums) {
			int n = nums.size();
			multiset<int> lis;
			vector<int> dp1(n),dp2(n);
			for(int i = 0; i < nums.size(); i++)
			{
				if(lis.empty())lis.insert(nums[i]);
				else
				{
					auto it = lis.lower_bound(nums[i]);
					if(it != lis.end())lis.erase(it);
					lis.insert(nums[i]);
				}
				dp1[i] = i + 1 - lis.size();
			}

			lis.clear();
			for(int i = nums.size()-1; i >=0; i--)
			{

				if(lis.empty())lis.insert(nums[i]);     
				else
				{
					auto it = lis.lower_bound(nums[i]);
					if(it != lis.end())lis.erase(it);  
					lis.insert(nums[i]);
				} 
				dp2[i] = nums.size()-i-lis.size();
			}

			int ans = n;

			for(int i = 1; i < nums.size()-1; i++)
			{
				ans = min(ans,dp1[i] + dp2[i]);
			}
			return ans;
		}
	};











// Java program of the above approach 

import java.io.*; 
import java.util.*; 

class GFG { 

	// Utility function to count array 
	// elements required to be removed 
	// to make array a mountain array 
	public static int minRemovalsUtil( 
		int[] arr) 
	{ 
		int result = 0; 
		if (arr.length < 3) { 
			return -1; 
		} 

		// Stores length of increasing 
		// subsequence from [0, i-1] 
		int[] leftIncreasing 
			= new int[arr.length]; 

		// Stores length of increasing 
		// subsequence from [i + 1, n - 1] 
		int[] rightIncreasing = new int[arr.length]; 

		// Iterate for each position up to 
		// N - 1 to find the length of subsequence 
		for (int i = 1; i < arr.length; i++) { 

			for (int j = 0; j < i; j++) { 

				// If j is less than i, then 
				// i-th position has leftIncreasing[j] 
				// + 1 lesser elements including itself 
				if (arr[j] < arr[i]) { 

					// Check if it is the maximum 
					// obtained so far 
					leftIncreasing[i] 
						= Math.max( 
							leftIncreasing[i], 
							leftIncreasing[j] + 1); 
				} 
			} 
		} 

		// Search for increasing subsequence from right 
		for (int i = arr.length - 2; i >= 0; i--) { 
			for (int j = arr.length - 1; j > i; j--) { 
				if (arr[j] < arr[i]) { 
					rightIncreasing[i] 
						= Math.max(rightIncreasing[i], 
								rightIncreasing[j] + 1); 
				} 
			} 
		} 

		// Find the position following the peak 
		// condition and have maximum leftIncreasing[i] 
		// + rightIncreasing[i] 
		for (int i = 0; i < arr.length; i++) { 
			if (leftIncreasing[i] != 0
				&& rightIncreasing[i] != 0) { 
				result = Math.max( 
					result, leftIncreasing[i] 
								+ rightIncreasing[i]); 
			} 
		} 

		return arr.length - (result + 1); 
	} 

	// Function to count elements to be 
	// removed to make array a mountain array 
	public static void minRemovals(int[] arr) 
	{ 
		int ans = minRemovalsUtil(arr); 

		// Print the answer 
		System.out.println(ans); 
	} 

	// Driver Code 
	public static void main(String[] args) 
	{ 
		// Given array 
		int[] arr = { 2, 1, 1, 5, 6, 2, 3, 1 }; 

		// Function Call 
		minRemovals(arr); 
	} 
}

