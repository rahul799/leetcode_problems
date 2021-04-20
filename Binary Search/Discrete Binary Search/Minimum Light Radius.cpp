Minimum Light Radius
You are given a list of integers nums representing coordinates of houses on a 1-dimensional line. You have 3 street lights that you can put anywhere on the coordinate line and a light at coordinate x lights up houses in [x - r, x + r], inclusive. Return the smallest r required such that we can place the 3 lights and all the houses are lit up.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [3, 4, 5, 6]
Output
0.5
Explanation
If we place the lamps on 3.5, 4.5 and 5.5 then with r = 0.5 we can light up all 4 houses.




bool possible(long int d, vector<int>& nums) {
    int left = 0;
    int count = 0;
    while (left < nums.size()) {
        left = upper_bound(nums.begin(), nums.end(), nums[left] + d) - nums.begin();
        count++;
    }
    return count <= 3;
}

double solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    long int left = 0;
    long int right = INT_MAX;
    long int mid;  // diameter
    while (left < right) {
        mid = left + (right - left) / 2;
        if (!possible(mid, nums)) {
            left = mid + 1;
        } else
            right = mid;
    }
    return (left * 1.0) / 2;
}




int need(vector<int>& v, double r) {
    int ret = 0;
    for (int i = 0; i < v.size();) {
        ret++;
        double upto = v[i] + 2 * r;
        int j = i + 1;
        while (j < v.size() && v[j] <= upto) j++;
        i = j;
    }
    return ret;
}

double solve(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    double lhs = 0;
    double rhs = nums.back() - nums[0];
    for (int qq = 0; qq < 40; qq++) {
        double mid = (lhs + rhs) / 2;
        if (need(nums, mid) <= 3)
            rhs = mid;
        else
            lhs = mid;
    }
    return rhs;
}

