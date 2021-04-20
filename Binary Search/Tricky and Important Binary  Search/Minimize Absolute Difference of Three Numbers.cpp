



Minimize Absolute Difference of Three Numbers
Question 3 of 4
Given three integer lists a, b and c, find the minimum possible abs(a[i] - b[j]) + abs(b[j] - c[k]) for any i, j and k.

Constraints

1 ≤ n ≤ 100,000 where n is the length of a
1 ≤ m ≤ 100,000 where m is the length of b
1 ≤ k ≤ 100,000 where k is the length of c
Example 1
Input
a = [1, 8, 5]
b = [2, 9]
c = [5, 4]
Output
3
Explanation
We can pick a[0], b[0] and c[1]





int lower(vector<int>& b, int x) {
    int l = 0, r = b.size() - 1;
    int lw = b[0];
    while (l < r) {
        int mid = (l + r) / 2;
        if (b[mid] <= x) {
            lw = b[mid];
            l = mid + 1;
        } else {
            r = mid ;
        }
    }
    return lw;
}
int upper(vector<int>& b, int x) {
    int l = 0, r = b.size() - 1;
    int lw = b[r];
    while (l < r) {
        int mid = (l + r) / 2;
        if (b[mid] >= x) {
            lw = b[mid];
            r = mid ;
        } else {
            l = mid + 1;
        }
    }
    return lw;
}

int solve(vector<int>& a, vector<int>& b, vector<int>& c) {
    int mn = (int)1e9 + 10;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (auto x : a) {
        int b1 = lower(b, x);  // nearest lower to x;
        int b2 = upper(b, x);  // nearest greater to x;
        int c1, c2, c3, c4;
        c1 = lower(c, b1);  // nearest lower to b1;
        c2 = upper(c, b1);  // nearest greater to b1;
        c3 = lower(c, b2);  // nearest lower to b2;
        c4 = upper(c, b2);  // nearest greater to b2;

        int temp;
        temp = abs(x - b1) + abs(b1 - c1);
        mn = min(temp, mn);
        temp = abs(x - b1) + abs(b1 - c2);
        mn = min(temp, mn);
        temp = abs(x - b2) + abs(b2 - c3);
        mn = min(temp, mn);
        temp = abs(x - b2) + abs(b2 - c4);
        mn = min(temp, mn);
    }
    return mn;
}
