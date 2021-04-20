


https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/





Important observation 1: We need to find the minimum number of integers missing in arr such that target can be a subsequence
of arr. Or in other words, we need to find the maximum number of integers in target such that they already form a subsequence 
of arr. Then we’ll know that the remaining integers will have to be inserted in arr. Or in simpler words, we need to find the 
length of longest common subsequence between target and arr.

Important observation 2: Normally finding the longest common subsequence is an O(n * m) problem. But here, we have 
additional information, which is that target has distinct integers. This allows us to create a reverse index, in which 
we can store the index at which an integer appears in target. Now the problem becomes finding the longest subsequence in 
arr such that the corresponding indices of those integers in target are strictly increasing. This is the longest increasing 
subsequence problem that can be solved in O(nlogn). We can ignore the integers that do not occur in the target array.

Time complexity: O(n log(m)) because of the binary search, where n = length of arr, and m = length of target.


Idea

It's easy to see that our target is to find longest common subsequence (LCS) between target and arr. Once we found 
the LCS, the number of operations is simply len(target) - len(LCS).

From LC 1143, we know that the optimal solution to find LCS (DP) has a time complexity of O(MN), which is too slow for 
this problem. Thus, we must be missing some important information here.

Reading through the problem constraint again, we see that target contains no duplicates. Therefore, the value and index of
the elements in target have an one-to-one mapping relationship.

Using this informaiton, we can map all the values in arr to their corresponding index in target. If a value is not existed
in target, we just skip it. Now the LCS between target and arr is the same as the Longest Increasing Subsequence (LIS) of 
the index array A.

We have effectively converted the LCS problem to a LIS problem, and we can apply the optimal solution of LC300 (Patience 
sorting) to solve it in O(NlogN) time.



class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mapping;
        int i = 0;
        for (auto& num : target)
            mapping[num] = ++i;
        
        vector<int> A;
        for (int& num : arr)
            if (mapping.find(num) != mapping.end())
                A.push_back(mapping[num]);
        return target.size() - lengthOfLIS(A);
    }
private:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> piles;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(piles.begin(), piles.end(), nums[i]);
            if (it == piles.end())
                piles.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return piles.size();
}
};







class Solution {
public:
    vector<int> ans;
    
    void bin(int lo, int hi, int num) {
        if(lo == hi) {
            ans[lo] = num;
            return;
        }
        int mid = (lo + hi) / 2;
        if(ans[mid] < num) bin(mid + 1, hi, num);
        else bin(lo, mid, num);
    }
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> idx;
        for(int i = 0; i < target.size(); i++) {
            idx[target[i]] = i;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(idx.find(arr[i]) == idx.end()) continue;
            int num = idx[arr[i]];
            if(ans.size() == 0 || num > ans.back()) {
                ans.push_back(num);
            }
            else {
                bin(0, ans.size() - 1, num);
            }
        }
        
        return (target.size() - ans.size());
    }
};
