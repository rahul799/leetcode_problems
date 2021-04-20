
823. Binary Trees With Factors
Medium


https://www.youtube.com/watch?v=GFAOtLFTibU&ab_channel=Codprac



610

74

Add to List

Share
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109









const int MOD=1000000007;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int n=(int) arr.size();
        map<int,long long > mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=1;
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    mp[arr[i]]+=(mp[arr[j]]*mp[arr[i]/arr[j]]) %MOD;
                    mp[arr[i]]%=MOD;
                }
            }
            
            ans=(ans+mp[arr[i]])%MOD;
        }
        return ans;
    }
};
