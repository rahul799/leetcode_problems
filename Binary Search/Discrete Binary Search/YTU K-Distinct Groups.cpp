

https://binarysearch.com/problems/K-Distinct-Groups


K-Distinct Groups
You are given a list of integers counts where counts[i] represents the number of items that exist of type i. You are also given an integer k. Return the maximum number of groups of size k we can have given that each group must have items of distinct types.

Constraints

n ≤ 100,000 where n is the length of counts
k ≤ n
Example 1
Input
counts = [3, 3, 2, 5]
k = 2
Output
6
Explanation
Let's name the four item types [a, b, c, d] respectively. We can have the following groups of two where all elements are distinct types:

(a, d)
(b, d)
(a, b)
(a, b)
(c, d)
(c, d)
Example 2
Input
counts = [3, 2, 4]
k = 3
Output
2
Explanation
Let's name the three item types [a, b, c] respectively. We can only have these groups of three where all elements are distinct types:

(a, b, c)
(a, b, c)
We cannot use (a, c, c) since there are two cs.
