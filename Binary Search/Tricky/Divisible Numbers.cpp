Divisible Numbers



You are given integers n, a, b, and c. Return the nth (0-indexed) term of the sorted sequence of integers divisible by a, b or c.

Note that by convention the first term of any sequence always starts with 1.

Example 1
Input
n = 8
a = 2
b = 5
c = 7
Output
12
Explanation
The first 9 terms of the sequence are [1, 2, 4, 5, 6, 7, 8, 10, 12]







Intuition
Imagine just nth multiple of a -> simply a*n right?

because there are a*n/a (n) numbers that are divisible by n upto that point

At a Number N

How many elements divisible by a?
N/a

by b?
N/b

by c?
N/c

A U B U C = all these BUT BUT BUT

If a = 2 , b =4 -> we will count the multiples of 4 twice!!!!!

So, just subtract the count of N/2 HOW DID WE GET 2 ? ?

LCM OF a,b ie A intersection B Set of Numbers!!!!

So now like A U B U C formula ....
A + B + C - A ∩ B - B ∩ C - A ∩ C + A ∩ B ∩ C (SET theory formula!)

Implementation
So now binary search to find nth value ie. there are n values less than this value in the guessed answer,

then if too many , right becomes guess , too little left becomes guess , standard BSTA binarysearch the answer (check comments)

-> best article on binary search with a universal template leetcode. com/discuss/general-discussion/786126/python-powerful-ultimate-binary-search-template-solved-many-problems

Time Complexity
\mathcal{O}(\log n )O(logn) for binarysearch all other maths operations are constant

Space Complexity
\mathcal{O}(1)O(1) maybe i could cache lcm answers? but it is anyways constant..

class Solution {
    public:
    int lcm(int x, int y) {
        return x * y / __gcd(x, y);
    }

    int a, b, c;

    int lesser(int n) {
        // how many elements less than it?
        return n / a + n / b + n / c - n / lcm(a, b) - n / lcm(b, c) - n / lcm(a, c) +
               n / lcm(a, lcm(b, c));
    }

    int solve(int n, int a, int b, int c) {
        this->a = a, this->b = b, this->c = c;

        int l = 1, r = INT_MAX;

        while (l < r) {
            int guess = l + (r - l) / 2;

            // i want the first value with >=n elements lesser than it!
            if (lesser(guess) >= n) {
                r = guess;
            } else {
                l = guess + 1;
                // guess is not the answer! +1 it
            }
        }

        return l;
    }
};

int solve(int n, int a, int b, int c) {
    return (new Solution())->solve(n, a, b, c);
}
