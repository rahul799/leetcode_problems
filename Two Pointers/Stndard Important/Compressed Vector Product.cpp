Compressed Vector Product




You are given two integer lists a and b where each list represents a vector in run-length encoded form. For example, a vector [1, 1, 1, 1, 2, 2, 2, 2, 2] is
represented as [4, 1, 5, 2]. (There are 4 ones and 5 twos.)

Return the dot product of the two vectors a and b.

The dot product of a vector [x1, x2, ..., xn] and [y1, y2, ..., yn] is defined to be x1 * y1 + x2 * y2 + ... + xn * yn.

Constraints

1 ≤ n ≤ 200,000 where n is the length of a
1 ≤ m ≤ 200,000 where m is the length of b
Example 1
Input
a = [4, 1, 5, 2]
b = [9, 2]
Output
28
Explanation
a • b = [1, 1, 1, 1, 2, 2, 2, 2, 2] • [2, 2, 2, 2, 2, 2, 2, 2, 2








int solve(vector<int>& a, vector<int>& b) {
    int a1, b1;
    long long int sum = 0;

    a1 = b1 = 0;
    while (a1 < a.size()) {
        if (a[a1] == b[b1]) {
            sum += a[a1] * a[a1 + 1] * b[b1 + 1];
            a1 += 2;
            b1 += 2;
        } else if (a[a1] > b[b1]) {
            a[a1] -= b[b1];
            sum += b[b1] * a[a1 + 1] * b[b1 + 1];
            b1 += 2;
        } else {
            b[b1] -= a[a1];
            sum += a[a1] * a[a1 + 1] * b[b1 + 1];
            a1 += 2;
        }
    }
    return sum;
}
