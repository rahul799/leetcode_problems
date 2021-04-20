1130. Minimum Cost Tree From Leaf Values
Medium

1641

126

Add to List

Share
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

 

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).



	
	Approach towards the solution is to partition the leaf nodes at all possible places, calculate the cost for each partition and return the minimum sum of both part.

Non-leaf cost from any subarray from i to j (product of two maximum val) is always same. No matter how you partition the subarray.

We split the leaf nodes Ai, Ai+1, ..... , Aj-1, Aj between Ak and Ak+1 where i<k<j then compute the sub problem for Ai, .... , Ak and Ak+1, ... , Aj and add both result plus the cost of multiplying two largest value in Ai, ... , Aj.

         leaf nodes :  [3,4,2,5,3,7]
         We can partition it in following ways:
         [3] | [4,2,5,3,7]
         [3,4] | [2,5,3,7]
         [3,4,2] | [5,3,7]
         [3,4,2,5] | [3,7]
         [3,4,2,5,3] | [7]
Since we can see overlapping subproblems easily.
1. [3,4] | [2,5,3,7] ---> [3,4] || [2] | [5,3,7]
2. [3,4,2] | [5,3,7] 

[5,3,7] is example of overlapping subproblem.
We can use a 2D array to store minimum non-leaf sum from any index i to j to avoid solving repeatedly.

Question is similar like MIXTURES on SPOJ, this explaination may help.
		 
		 
		 
		 
		 
		 
		 

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,0,n-1,dp);
    }
    
    int solve(vector<int>&arr, int low, int high,vector<vector<int>> &dp){
        // if we have a single leaf node, then smallest possible sum
        // of non-leaf node is zero.
        if(low == high) return 0;
        
        // dp[i][j] --> smallest possible sum of value of each non-leaf node of
        // subarray from i to j both inclusive
        if(dp[low][high] != -1) return dp[low][high];
        
        // priority_queue is being used to find two max values in range [i...j]
        priority_queue<int> pq(arr.begin()+low, arr.begin()+high+1);
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
		
        // maxProduct hold product of two maximum values in given range
        int maxProduct = a*b;
        
        int minSum = INT_MAX;
        for(int i=low; i<high; i++){
            minSum = min(minSum, solve(arr,low,i,dp) + solve(arr,i+1,high,dp));
        }
        return dp[low][high] = minSum + maxProduct;
    }
};
