https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw?questionsetIndex=0




5-Star Review Percentage
You are given a two-dimensional list of integers reviews and a positive integer threshold. Each element reviews[i] contains [x, y] meaning product i had x number of 5-star reviews and a total of y reviews. All reviews are for one store.

Return the minimum number of additional 5-star reviews we need such that the percentage of 5-star reviews in the store is at least threshold. You can assume that it's possible to reach threshold% of 5-star reviews.

Constraints

1 ≤ n ≤ 100,000 where n is the length of reviews
0 ≤ threshold ≤ 100
Example 1
Input
reviews = [
    [4, 4],
    [1, 2],
    [3, 6]
]
threshold = 77
Output
6
Explanation
So in total there were 8 5-star reviews and a total of 12 reviews. To reach 77% 5-star reviews, we need 6 more 5-star reviews.

Example 2
Input
reviews = [
    [10, 20]
]
threshold = 50
Output
0
Explanation
We're already at 50% 5-star reviews.

Example 3
Input
reviews = [
    [1, 1]
]
threshold = 100
Output
0
Explanation
We're already at 100% 5-star reviews.

int solve(vector<vector<int>>& reviews, int t) {
    int n = reviews.size();
    int st5 = 0, trev = 0;
    for (auto& v : reviews) {
        st5 += v[0];
        trev += v[1];
    }
    if (t == 100 & st5 == trev) return 0;
    double x = (double)(st5 * 100 - trev * t) / (t - 100);
    return (ceil(x) < 0) ? (0) : (ceil(x));
}  
