Lego Towers
You are given a list of positive integers heights, representing the heights of lego towers, and a positive integer k. You want to pick k lego towers and make them all the same height by adding more bricks, but using as few bricks as possible. Return the minimum number of bricks needed to pick k towers and make them the same height.

Constraints

n ≤ 100,000 where n is the length of heights
0 < k
Example 1
Input
heights = [4, 7, 31, 14, 40]
k = 3
Output
17
Explanation
We can pick 4, 7, and 14 which requires 17 bricks to make the same height.

Example 2
Input
heights = [4, 4, 2, 4, 4]
k = 5
Output
2
Explanation
We have to pick all 5 towers and use 2 bricks here.



Intuition
To ensure, that we pick up k such towers for which, we need minimum bricks to make them equal, we need to choose k closest towers, closest means, close by height. So we sort the array and use a sliding window of length k, and for each window we calculate the total number of bricks required. We actually have to make all the heights equal to the greatest height in the window. We can use a prefix sum or running sum to get the total height of all towers in the window and subtract it from k*(greatest height in window) to get the number of bricks needed for that window. we will return the minimum them for all windows of size k.

int solve(vector<int>& heights, int k) {
    if (heights.size() == 0) {
        return 0;
    }
    sort(heights.begin(), heights.end());
    int n = heights.size();
    int prefix[n];
    prefix[0] = heights[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + heights[i];
    }
    int i = 0;
    int j = k - 1;
    int ans = INT_MAX;
    while (j < n) {
        int sum;
        if (i >= 1) {
            sum = prefix[j] - prefix[i - 1];
        } else {
            sum = prefix[j];
        }
        int diff = (heights[j] * k) - sum;
        ans = min(ans, diff);
        i++;
        j++;
    }
    return ans;
}
