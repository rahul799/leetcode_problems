
Poly Knapsack


https://binarysearch.com/problems/Poly-Knapsack

Question 438 of 987
You are given two lists of integers weights and values which have the same length and an integer capacity. weights[i] and values[i] represent the weight and value of the ith item.

Given that you can take at most capacity weights, and that you can take any number of copies for each item, return the maximum amount of value you can get.

Constraints

n ≤ 250 where n is the length of weights and values
capacity ≤ 250
Example 1
Input
weights = [1, 2, 3]
values = [1, 5, 3]
capacity = 5
Output
11




// int solve(vector<int>& weights, vector<int>& values, int capacity) {
    
// }



// Intuition
// The problem is just simple if you've already solved the Rod Cutting Problem. The idea is to first find the maximum profit that could be made by each and every individual items in the list and then to figure out the same after their combinations with themselves and their neighbours.

// So initialize an empty array 'dp' of size capacity. Then figure out the maximum profit made by each object, which is done in our first loop.

// The second loop tells about the maximum profit that could be made by each combinations of objects. You could conserve the time by starting 'start' from zero and loop till half the value of the index at that weight,



int solve(vector<int>& weights, vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1);
    int n = weights.size();
    for (int i = 0; i < values.size(); ++i) {
        int w = weights[i], v = values[i];
        for (int j = w; j <= capacity; ++j) dp[j] = max(dp[j], dp[j - w] + v);
    }
    return dp[capacity];
}
