There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4




// our target is  to bring down the time complexity from O(N3) to O(N2)



class Solution {
public:
	int numTeams(vector<int>& arr) {
		int count = 0;
		int len = arr.size();
		for (int j = 0; j < len; j++) {
            
            // number of elements on the left/ right of element which are smaller/ larger 
			int leftSmaller = 0, rightLarger = 0;
			int leftLarger = 0, rightSmaller = 0;
			for (int i = 0; i < j; i++) {
				if (arr[i] < arr[j]) {
					leftSmaller++;
				} else if (arr[i] > arr[j]) {
					leftLarger++;
				}
			}
			for (int k = j + 1; k < len; k++) {
				if (arr[j] < arr[k]) {
					rightLarger++;
				} else if (arr[j] > arr[k]) {
					rightSmaller++;
				}
			}       // number of elements on left smaller and right larger 
			count += leftSmaller * rightLarger + leftLarger * rightSmaller;
            
            
		}

		return count;
	}
};
