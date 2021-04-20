

https://binarysearch.com/problems/Largest-Distance-Pair


basic problem without mod
if it was
maximize a[i] - a[j] + b[i] - b[j] + i - j
just return diff of
max(a[i] + b[i] + i ) - min(a[i] + b[i] + i) for all i

i didn't understand this ^
So what happens is, we need two indices with the largest difference looking at every index, calculating the value, how to get the largest difference in a list of numbers ??
MAX - MIN ;)

Implementation
problem with mod!
okay but what about abs()
non mathematical intuition:
you realize that abs() makes the above logic fail...
now we cannot assume the - sign which makes it tricky, the observation is b[i] will have + or - and a[i] will have + or - ( ignore 'i' because index always positive)

So let's just try all four combinations!
{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
after selecting the combination we just do the MAX - MIN method described above

Time Complexity
\mathcal{O}(n)O(n) since we are just doing 4 passes over the list with each combination ;)

Space Complexity
\mathcal{O}(1)O(1) no extra spaced is used when doing this


const vector<pair<int, int> > sign_pairs{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int solve(vector<int>& a, vector<int>& b) {
    int res = 0;
    for (pair<int, int> signs : sign_pairs) {
        int maximum = INT_MIN, minimum = INT_MAX;
        int as = signs.first, bs = signs.second;
        for (int i = 0; i < a.size(); i++) {
            maximum = max(as * a[i] + bs * b[i] + i, maximum);
            minimum = min(as * a[i] + bs * b[i] + i, minimum);
        }
        res = max(res, maximum - minimum);
    }
    return res;
}
