

Dropped Sensor Metric




You are given two lists of integers a and b representing sensor metrics. Each list contains unique integers and a ≠ b. One of the lists 
contains accurate sensor metrics but the other one is faulty. In the faulty list one number that wasn't the last number was dropped and a fake 
value was appended to the end of the list. Return the number that was dropped.

Constraints

2 ≤ n ≤ 100,000 where n is the length of a and b
Example 1
Input
a = [1, 2, 3]
b = [2, 3, 5]
Output
1
Explanation
The accurate metrics come from a = [1, 2, 3].

Example 2
Input
a = [5, 4, 2, 1, 6]
b = [5, 4, 3, 2, 1]
Output
3
Explanation
The accurate metrics come from b = [5, 4, 3, 2, 1].








int solve(vector<int>& a, vector<int>& b) {
    int l = 0, r = 0;
    int n = a.size();
    while (l < n) {
        if (a[l] != b[r]) {
            if (a[l + 1] == b[r]) {
                return a[l];
            } else
                return b[r];
        }
        l++;
        r++;
    }
    return -1;
}
