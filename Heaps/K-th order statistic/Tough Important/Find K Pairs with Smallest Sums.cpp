






373. Find K Pairs with Smallest Sums
Medium

1723

118

Add to List

Share
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]



Optimised COde Yet to Understand



#define sz(v) ((int)(v).size())
typedef pair<int, pair<int, int>> ppii;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = sz(nums1);
        int m = sz(nums2);
        vector<vector<int>> res;
        if(n == 0 || m == 0) return res;
        k = min(k, m*n);
        priority_queue<ppii, vector<ppii>, greater<ppii>> pq;
        vector<int> dp(n, -1);
        int i = 0, j = 0;
        while(sz(pq) < k){
            dp[i] = max(dp[i], j);
            pq.push({nums1[i] + nums2[j], {i, j}});
            if(i == n-1){
                i = 0;
                j++;
                continue;
            }
            i++;
        }
        int curi, curj;
        while(sz(pq)){
            if(sz(res) == k) break;
            ppii p = pq.top();
            curi = p.second.first, curj = p.second.second;
            pq.pop();
            res.push_back({nums1[curi], nums2[curj]});
            if(dp[curi] != m-1){
                dp[curi] += 1;
                pq.push({nums1[curi] + nums2[dp[curi]], {curi, dp[curi]}});
            }
        }
        return res;
    }
};





class Solution {
public:
        
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j]; // create a max heap
                if(pq.size()<k)pq.push({sum,{nums1[i],nums2[j]}});
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


