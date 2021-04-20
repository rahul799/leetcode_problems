Hanging Banners
Question 211 of 909
You are given a list of list of integers intervals of the form [start, end] representing the starts and end points of banners you want to hang. Each banner needs at least one pin to stay up, and one pin can hang multiple banners. Return the smallest number of pins required to hang all the banners.

Note: The endpoints are inclusive, so if two banners are touching, e.g. [1, 3] and [3, 5], you can put a pin at 3 to hang both of them.

Constraints

n ≤ 100,000 where n is the length of intervals
Example 1
Input
intervals = [
    [1, 4],
    [4, 5],
    [7, 9],
    [9, 12]
]
Output
2
Explanation
You can put two pins at 4 and 9 to hang all the banners..

Example 2
Input
intervals = [
    [1, 10],
    [5, 10],
    [6, 10],
    [9, 10]
]
Output
1
Explanation
You can put one pin at 10.








Intuition
we have to hang every banner, so for each banner there must be an pin whose position is between banner[i][0] and banner[i][1] inclusively. we will sort the vector of banners by their ending position. Then we make sure that we take care of each banner in order.

So what position should we pick each time? We should pick as to the right as possible, because since banners are sorted, this gives you the best chance to pin down more banners. Therefore the position should always be banner[i][1] for the i_th banner.

This is exactly what I do in the for loop: check how many banners I can pin down with one pin aiming at the ending position of the current banner. Then I skip all these banners and start again from the next one (or the leftmost remaining one) that needs another pin.

Example:

banners = [[7,10], [1,5], [3,6], [2,4], [1,4]]
After sorting, it becomes:

banners = [[2,4], [1,4], [1,5], [3,6], [7,10]]
So first of all, we pin at position 4, we go through the array and see that all first 4 banners can be taken care of by this single pin. Then we need another pin for one last balloon. So the result should be 2.

bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
    public:
    int solve(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return n;
        sort(intervals.begin(), intervals.end(), comp);
        int l = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > l) {
                ans++;
                l = max(l, intervals[i][1]);
            }
        }
        return ans;
    }
};

int solve(vector<vector<int>>& p) {
    return (new Solution)->solve(p);
}

