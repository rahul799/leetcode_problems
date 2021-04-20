Mutual Followers
You are given a two-dimensional list of integers relations. Each element relations[i] contains [a, b] meaning that person a is following person b on Twitter.

Return the list of people who follow someone that follows them back, sorted in ascending order.

Constraints

0 ≤ n ≤ 100,000 where n is the length of relations
Example 1
Input
relations = [
    [0, 1],
    [2, 3],
    [3, 4],
    [1, 0]
]
Output
[0, 1]
Explanation
0 follows 1 and 1 follows 0.

Example 2
Input
relations = [
    [0, 1],
    [1, 2],
    [2, 3],
    [3, 0]
]
Output
[]
Explanation
There aren't any mutual followers.




vector<int> solve(vector<vector<int>>& relations) {
    vector<int> result;
    int n = relations.size();

    set<pair<int, int>> mp;
    set<int> ans;

    for (int i = 0; i < n; i++) {
        mp.insert({relations[i][0], relations[i][1]});
    }

    for (auto x : mp) {
        if (mp.find({x.second, x.first}) != mp.end()) {
            ans.insert(x.second);
            ans.insert(x.first);
        }
    }
    for (auto x : ans) result.push_back(x);

    return result;
}
