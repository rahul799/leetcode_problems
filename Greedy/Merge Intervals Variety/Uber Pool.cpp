


Uber Pool
Question 254 of 939
You are given a two-dimensional integer list requested_trips containing [start_x, end_x, num_passengers], and an integer capacity. Each requested trip asks to pick up num_passengers passenger at start_x and drop them off at end_x. You also have a car with the given capacity, and start at x = 0.

Given that you'd like to pick up every passenger and can only move right, return whether you can pick up and drop off everyone.

Constraints

n ≤ 100,000 where n is the length of requested_trips
Example 1
Input
trips = [
    [1, 30, 2],
    [3, 5, 3],
    [5, 9, 3]
]
capacity = 6
Output
true







// Intuition
// Sweep line across all the pickup and drop points.
// When you have pickup increase counter.
// When you have drop point decrease the counter.
// If counter increases more than the capacity then its not possible and return false;
// Else return true.



bool solve(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> helper;
    for (auto& v : trips) {
        helper.emplace_back(v[0], v[2]);
        helper.emplace_back(v[1], -v[2]);
    }
    sort(helper.begin(), helper.end());

    for (auto& p : helper) {
        capacity -= p.second;
        if (capacity < 0) return false;
    }
    return true;
}
