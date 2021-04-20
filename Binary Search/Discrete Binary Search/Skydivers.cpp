Skydivers


You are given a list of integers nums where each value represents a group of people looking to skydive together. You are also given k representing the number of days 
the skydiving facility is open for.

Return the minimum capacity of the plane you need to be able to fulfill all requests in k days. Note that requests should be fulfilled in the order they were given and a 
plane can only have one flight per day.

Constraints

n ≤ 10,000 where n is the length of nums.
Example 1
Input
nums = [13, 17, 30, 15, 17]
k = 3
Output
32
Explanation
A 32 person airplane can group the requests by [13, 17], [30], [15, 17].




bool check(vector<int>& a, int capacity, int k) {
    int days = 1;

    int currentCap = 0;

    for (int i = 0; i < a.size(); i++) {
        if (currentCap + a[i] <= capacity) {
            currentCap += a[i];
        } else {
            days++;
            currentCap = a[i];
        }
        if (a[i] > capacity) return false;
    }

    return days <= k;
}


int solve(vector<int>& a, int k) {
    int n = a.size();

    int low = 0;
    int high = 0;
    for (int x : a) {
        high += x;
    }
    int mid = 0;

    while (low < high) {
        mid = (low + high) / 2;

        if (check(a, mid, k)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
