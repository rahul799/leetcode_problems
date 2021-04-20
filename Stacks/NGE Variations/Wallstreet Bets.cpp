Wallstreet Bets
You are given a list of non-negative integers prices representing the daily stock prices of a company in chronological order. Return a list of the same length where the value at index i is the minimum number of days you would have to wait until you make a profit. If there's no way to make a profit the value should be 0.

Constraints

n ≤ 100,000 where n is the length of prices
Example 1
Input
prices = [3, 2, 4, 8, 6, 5]
Output
[2, 1, 1, 0, 0, 0]






vector<int> solve(vector<int>& prices) {
    // next greater
    stack<int> s;
    int n = prices.size();
    vector<int> res(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = (s.top() - i);
        }
        s.push(i);
    }

    return res;
}
