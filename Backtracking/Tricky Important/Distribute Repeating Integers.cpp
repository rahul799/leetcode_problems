
1655. Distribute Repeating Integers
Hard

82

9

Add to List

Share
You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

The ith customer gets exactly quantity[i] integers,
The integers the ith customer gets are all equal, and
Every customer is satisfied.
Return true if it is possible to distribute nums according to the above conditions.

 

Example 1:

Input: nums = [1,2,3,4], quantity = [2]
Output: false
Explanation: The 0th customer cannot be given two different integers.
Example 2:

Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
Example 3:

Input: nums = [1,1,2,2], quantity = [2,2]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
Example 4:

Input: nums = [1,1,2,3], quantity = [2,2]
Output: false
Explanation: Although the 0th customer could be given [1,1], the 1st customer cannot be satisfied.
Example 5:

Input: nums = [1,1,1,1,1], quantity = [2,3]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [1,1,1].
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= 1000
m == quantity.length
1 <= m <= 10
1 <= quantity[i] <= 105
There are at most 50 unique values in nums.








Given there are at most 50 unqiue values, and at most 10 customers.
It's a sign that we could do a backtrack.
​
The idea is to


count the occurance of each number
sort the customers' order quantities DESC
do a backtrack with DFS on the nubmers that are enough to be distributed to customers

Counting the occurance of each number in input array;
​
Leave only quantity.size() amount of the most frequently met numbers;
Sort quantity in descending order for better performance;
Run backtrack;
Return true, if backtrack found at least 1 solution, otherwise return false.
​




class Solution {
public:
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> mp;
         for(auto x: nums)
             mp[x]+=1;
         vector<int> v;
        for(auto x:mp)
            v.push_back(x.second);
       sort(quantity.rbegin(), quantity.rend());
        return dfs(0,quantity,v);
       
    }
    
    
    bool dfs(int i,vector<int>& q,vector<int> &v)
    {
        
        if(i>=q.size())
            return true;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]>=q[i])
            {   
                v[j]-=q[i];
                if(dfs(i+1,q,v))
                    return true;
                v[j]+=q[i];
            }
        }
        return false;
    }
} ;
