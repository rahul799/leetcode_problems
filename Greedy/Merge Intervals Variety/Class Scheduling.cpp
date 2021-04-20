
https://binarysearch.com/problems/Class-Scheduling





Class Scheduling
You are given a two-dimensional list of integers times where each list has two numbers [start, end], representing the start and end time of a course.

Return the maximum number of courses you can take assuming you can only take one course at a time and the start of a course needs to be later than the end of the last course.

Constraints

n ≤ 100,000 where n is the length of times
Example 1
Input
times = [
    [2, 5],
    [5, 8],
    [6, 7],
    [8, 10]
]
Output
3
Explanation
We can take these courses [[2, 5], [6, 7], [8, 10]]


int solve(vector<vector<int>>& times) {
    sort(times.begin(), times.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });
    int ans = 0, end = -1;
    for (auto i : times) {
        if (end < i[0]) {
            end = i[1];
            ans++;
        }
    }
    return ans;
}
