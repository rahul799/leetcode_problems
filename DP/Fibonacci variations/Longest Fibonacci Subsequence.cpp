https://leetcode.com/problems/count-of-smaller-numbers-after-self/

https://binarysearch.com/problems/Longest-Fibonacci-Subsequence/editorials/2746553

Find length of longest Fibonacci like subsequence
Last Updated: 16-09-2020
Given a strictly increasing array A of positive integers where, 



. The task is to find the length of the longest Fibonacci-like subsequence of A. If such subsequence does not exist, return 0.

Examples:
 

Input: A = [1, 3, 7, 11, 12, 14, 18] 
Output: 3 
Explanation: 
The longest subsequence that is Fibonacci-like: [1, 11, 12]. Other possible subsequences are [3, 11, 14] or [7, 11, 18].



Input: A = [1, 2, 3, 4, 5, 6, 7, 8] 
Output: 5 
Explanation: 
The longest subsequence that is Fibonacci-like: [1, 2, 3, 5, 8].



Approach 1:

Since we want the longest subsequence, we have to check each and every pair which can start a Fibonacci Sequence, so we pick all pairs (i,j) that can start a sequence and check the longest sequence they can make. We also maintain a hashmap for every entry with its index.

For every pair we check if we can start off a Fibonacci sequence, if the sum of the pair members (nums[i]+nums[j]) is found in the hashmap, we update the pair value to include the original pair's second entry and the sum. We do this recursively until we see that (nums[i]+nums[j]) is not found in the hashmap. We update the count 'c' of how many times we could extend the sequence.

We have 'mxcnt' to maintain the maximum value c takes.

Now, if 'mxcnt' is non zero, we return 'mxcnt+2' to include the original two members of the pair that started off the sequence. Otherwise we return 0 as no pair could start off a sequence.




Intuition
dp solution

We use a 2-d array dp[i][j] to store the max length if there exists a Fibonacci array which ends with index i and index j.

Then, we extend our dp by iterating all i-j pairs. The default value in dp should be 2 as all i-j pairs have at least two elements.

Time O(N^2)
Space O(N^2)

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 2));
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++) mp[nums[i]] = i;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int target = nums[i] + nums[j];
                if (mp.count(target)) {
                    int x = mp[target];
                    dp[j][x] = max(dp[j][x], dp[i][j] + 1);
                    ans = max(ans, dp[j][x]);
                }
            }
        }
        // for (auto row : dp) {
        //     for (auto n : row) cout << n << " ";
        //     cout << endl;
        // }
        return ans;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}







#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int finder(int i, int j, unordered_map<int, int>& mp, vector<int>& nums) {
        int c = 0;
        if (mp.find(nums[i] + nums[j]) != mp.end()) {
            int k = mp[nums[i] + nums[j]];
            c++;
            c = c + finder(j, k, mp, nums);
        }
        return c;
    }

    int solve(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[nums[i]] = i;

        int mxcnt = 0;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) mxcnt = max(mxcnt, finder(i, j, mp, nums));

        return (mxcnt == 0) ? 0 : mxcnt + 2;
    }
};


int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}





