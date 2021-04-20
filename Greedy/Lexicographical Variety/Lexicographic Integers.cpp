
https://binarysearch.com/problems/N-Lexicographic-Integers

 Lexicographic Integers
Question 414 of 987
Given an integer n, return first n integers sorted in lexicographic order.

Example 1
Input
n = 12
Output
[1, 10, 11, 12, 2, 3, 4, 5, 6, 7, 8, 9]










vector<int> solve(int n) {
    int c = 1;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(c);
        c = c * 10;
        while (c > n) {
            c /= 10;
            c++;
        //     also, edge case is such that we have 19 + 1 = 20 => (20/10) 2. we check this by %10.
            while (c % 10 == 0) c /= 10;
        }
    }
    return vec;
}
