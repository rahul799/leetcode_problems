Adjacent Square Sums
Question 849 of 905
You are given a list of integers nums. Return the number of permutations of nums such that every pair of adjacent numbers' sum is a perfect square. Two permutations A and B are different if there's some index i where A[i] ≠ B[i].

Constraints

n ≤ 12 where n is the length of nums
Example 1
Input
nums = [8, 3, 1]
Output
2
Explanation
We have [8, 1, 3] and [3, 1, 8]








Intuition
Let's first handle the case where all integers are unique.

The brute-force approach enumerates all \mathcal{O}(N!)O(N!) permutations and takes linear time to verify that each adjacent pair of integers sums to a square.

To optimize this, note that for a prefix of the permutation, all that matters is every pair in the prefix has been matched, as well as what the last element in the prefix is so we can continue appending integers to the permutation.

Our DP state is therefore f(mask, index)f(mask,index) which is equal to the number of ways to generate a permutation using exactly the integers marked by mask, ending with the one at index, such that every adjacent pair of integers sums to a perfect square.

To handle the case where not all integers are distinct, we'll overcount each permutation by the number of equivalent permutations, which is simply \displaystyle\prod_{i} n_i! 
i
∏
​	
 n 
i
​	
 !, where n_in 
i
​	
  is the number of times ii appears in the permutation. Therefore, we divide by this value instead.

Implementation
Our DP state is captured by our two-dimensional vector where the first dimension is the bitmask of selected elements and the second one is the last element we use.

We sort the input list initially to easily count how many equivalent permutations there are.

The main DP transition is that we append a new element, so we need to confirm it is unused and that the sum of the last two integers sums to a perfect square.

Time Complexity
Our DP state has \mathcal{O}(N 2^N)O(N2 
N
 ) states and \mathcal{O}(N)O(N) transitions, for a time complexity of \mathcal{O}(N^2 2^N)O(N 
2
 2 
N
 ).

Space Complexity
The space complexity here is \mathcal{O}(N 2^N)O(N2 
N
 ) as observed by the dp vector
 
 
 
 
 
 
 
 
 
 
 
 
 
 int fact(int n) {
    int ret = 1;
    for (int i = 2; i <= n; i++) ret *= i;
    return ret;
}

bool issquare(int n) {
    int k = sqrt(n);
    return k * k == n;
}

int solve(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int scale = 1;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && nums[i] == nums[j]) j++;
        scale *= fact(j - i);
        i = j;
    }
    vector<vector<int>> dp(1 << n, vector<int>(n));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0 && issquare(nums[i] + nums[j])) {
                    dp[mask | (1 << j)][j] += dp[mask][i];
                }
            }
        }
    }
    return accumulate(dp.back().begin(), dp.back().end(), 0) / scale;
}
