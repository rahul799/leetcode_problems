
1664. Ways to Make a Fair Array
Medium

287

5

Add to List

Share
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

 

Example 1:

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:

Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: You cannot make a fair array after removing any index.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104





if you look at constrains then its not possible to do that question in n^2 time.

so i think about prefix sum so here is my thought process.
first i make left and right array and make prefix sum of odd and even
I think I should directly jump over example.

example 
array = [6, 1, 7, 4, 1]
left    = [6, 1, 13, 5, 14] in this i seprate even index and odd index
         = [6, 1, 6+7, 1+4, 6+7+1] look carefully i separate even and odd position

right = [14, 5, 8, 4, 1]
            [6+7+1, 4+1, 7+1, 4, 1] similar thing in reverse order 
			
		    now suppose you pick 7 and want to remove it then the next even element that present in array become odd and next odd element become even
			now last total sum before 7 for even is 6 // it came from left prefix
			now last total sum before 7 for odd index is 1//it came form left prefix 
			now total sum after 7 for even is 4// see right and try to relate after removing 7 from right array we can pick 4 as it become even index now
			now total sum after 7 for odd is 1 // now 1 in right is become odd after removing 7. 
			
			at last just check if they are equal or not.
      
      
      
  class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        if(nums.size()==1)return 1;
        
        int n=nums.size();
        vector<int>l(n,0),r(n,0);
        l[0]=nums[0];
        l[1]=nums[1];
        for(int i=2;i<n;i++)
            l[i]=l[i-2]+nums[i];
        
        r[n-1]=nums[n-1];
        r[n-2]=nums[n-2]; 
        for(int i=n-3;i>=0;i--)
            r[i]=r[i+2]+nums[i];

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int ev=0,od=0;
            ev+=i-2>=0?l[i-2]:0;
            od+=i-1>=0?l[i-1]:0;
            ev+=i+1<n?r[i+1]:0;
            od+=i+2<n?r[i+2]:0;
            if(ev==od)ans++;
        }
        return ans;
    }
};




Clean implementation:



class Solution {
public:
    int waysToMakeFair(vector<int>& arr) {
        int n = arr.size();
        int oddsum = 0,evensum = 0,ans = 0;
        vector<int>odd(n),even(n);
        for(int i=n-1 ; i>=0 ; i--)                               //store the odd and even indexed values sum from right to left.
        {
            if(i&1) oddsum += arr[i];
            else evensum += arr[i];
            odd[i] = oddsum;
            even[i] = evensum;
        }
        oddsum = evensum = 0;                                       //running sum for odd and even indexed values sum from left to right.
        for(int i=0 ; i<n-1 ; i++)
        {
            if(oddsum+even[i+1] == evensum+odd[i+1]) ans++;           //if index i is deleted then odd[i] becomes even[i] and vice versa.
            if(i&1) oddsum += arr[i];
            else evensum += arr[i];
        }
        if(oddsum == evensum) ans++;                        //for the last case for example in array [1,1,1] for the last index.
        return ans;
    }
};
