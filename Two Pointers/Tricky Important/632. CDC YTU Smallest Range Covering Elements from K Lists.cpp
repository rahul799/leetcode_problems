


632. Smallest Range Covering Elements from K Lists
Hard

1380

26

Add to List

Share
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
Example 3:

Input: nums = [[10,10],[11,11]]
Output: [10,11]
Example 4:

Input: nums = [[10],[11]]
Output: [10,11]
Example 5:

Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
Output: [1,7]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing orde









class Solution 
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            
                vec.push_back({nums[i][j],i});    //creating vector of pair with    
        }
        sort(vec.begin(),vec.end());
        unordered_map<int,int> mp;
        vector<int> ans;
        int k=0,slow=0;   
        for(int i=0;i<vec.size();i++)
        {
            if(!mp[vec[i].second])
            {
            mp[vec[i].second]++;
            k++;
            }
            else if(mp[vec[i].second])
            {
            mp[vec[i].second]++;
            }
            if(k==nums.size())
            {
                while(mp[vec[slow].second]>1)
                {
                    mp[vec[slow].second]--;
                    slow++;
                }
                if(ans.empty())
                {
                    ans=vector<int>{vec[slow].first,vec[i].first};
                }
                else if((ans[1]-ans[0])>(vec[i].first-vec[slow].first))
                {
                    ans[0]=vec[slow].first;
                    ans[1]=vec[i].first;
                }
            }
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int high=INT_MIN;
        int low;
        int n=nums.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //first will be value
        // second will be index of row
        // third will be index of col
        for(int i=0;i<n;i++){
            high=max(high,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        low=pq.top().first;
        vector<int> res{low,high};
        while(pq.size()==n){
            auto it=pq.top();pq.pop();
            int val=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            if(col+1<nums[row].size()){
                pq.push({nums[row][col+1],{row,col+1}});
                high=max(high,nums[row][col+1]);
                low=pq.top().first;
                if(high-low<res[1]-res[0]){
                    res[1]=high;
                    res[0]=low;
                }
            }
        }
        return res;
    }
};

