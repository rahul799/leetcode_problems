https://binarysearch.com/problems/Costly-Flight-of-Stairs/editorials/1807501


https://binarysearch.com/problems/Bunnyhopping



You are given a list of integers nums and an integer k. The nums list represents the costs of landing at each index. You must start at index 0 
and end at the last index of nums. In each step you can move from some position X to any position up to k steps away.

You want to minimize the sum of the costs of the positions you land at. What is this minimum sum



int solve(vector<int>& nums, int k) {
    int n = nums.size();
    deque<pair<int, int>> dq;
    dq.push_back({nums[0], 0});
    for (int i = 1; i < n; ++i) {
        while (!dq.empty() && (i - dq.front().second) > k) dq.pop_front();
        int curr = nums[i];
        if (!dq.empty()) curr += dq.front().first;
        while (!dq.empty() && dq.back().first >= curr) dq.pop_back();
        dq.push_back({curr, i});
    }
    return dq.back().first;
}
