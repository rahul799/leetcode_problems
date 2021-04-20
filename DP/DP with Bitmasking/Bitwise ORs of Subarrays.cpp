[LeetCode] 898. Bitwise ORs of Subarrays Bitwise ORs of Subarrays

We have an array `A` of non-negative integers.
For every (contiguous) subarray  B = [A[i], A[i+1], ..., A[j]] (with  i <= j), we take the bitwise OR of all the elements in  B, obtaining a result  A[i] | A[i+1] | ... | A[j].

Return the number of possible results. (Results that occur more than once are only counted once in the final answer.)

Example 1:

Input: [0]
Output: 1
Explanation:
There is only one possible result: 0.
Example 2:

Input: [1,1,2]
Output: 3
Explanation:
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
Example 3:

Input: [1,2,4]
Output: 6
Explanation:
The possible results are 1, 2, 3, 4, 6, and 7.
Note:

1 <= A.length <= 50000
0 <= A[i] <= 10^9

This is a very interesting question. It is said that we are given an array with non-negative numbers in it, asking us how many different values ​​can be produced by all continuous sub-arrays. Although this is just a Medium question, the intuition tells the blogger that violently traversing all the sub-arrays, and one by one'or' will produce a lot of repeated operations, and it should be TLE without accident. Therefore, the blogger’s first instinct is whether to create an array similar to the accumulation and the same, and then quickly calculate the total'or' value of any interval, try it, although the accumulation'or' array can be established, but the correct interval total cannot be obtained The'or' value, the blogger even tried the'exclusive OR', but it was still wrong and had to give up. In fact, the correct solution to this question is quite clever, and it feels not easy to think of it all at once. Here I mainly refer to [the post of the online god zhoubowei](https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss /165859/C%2B%2B-O(kN)-solution), for example, for example, the array [0, 3, 4, 6, 5], written in binary is [001, 011, 100, 110, 101 ], the method of generating sub-arrays is similar to that of generating sub-sets [Subsets] (http://www.cnblogs.com/grandyang/p/4309345.html), but since the sub-arrays must be continuous, the number is compared There are fewer sets. The method of generating is to add the current number to the existing set, and add a new set with only the current number each time. The sequence is as follows:
[001]
[001 011] [011]
[001 011 100] [011 100] [100]
[001 011 100 110] [011 100 110] [100 110] [110]
[001 011 100 110 101] [011 100 110 101] [100 110 101] [110 101] [101]
We can see that there is only one set [001] at the beginning, and then for the number 011, first put it into the existing set and become [001 011], and then create a new set of your own [011], for the following numbers It's all the same operation. In the end we have 5 different sets, which represent all the sub-arrays. We calculate the total'or' value for each set, and we can get:

001
011 011
111 111 100
111 111 110 110
111 111 111 111 101
As mentioned earlier, it would be very inefficient to "or" each set one by one. In fact, there may be many duplicate values ​​in it, so only one duplicate value needs to be kept. In fact, it can be changed. to make:

001
011
111 100
111 110
111 101
In this way, the number is reduced a lot, making the calculation efficiency greatly improved. The specific approach is to first create two HashSets, res and cur, and then traverse the array A. For each traversed number, first generate its own set tmp, and then traverse all the numbers in the set cur, and set the current The number is ORed with each number in cur and stored in tmp. Since HashSet can automatically remove the repetition, only different values ​​are stored in tmp, and then all values ​​in tmp are assigned to cur, and then all in cur The value is added to the result res. Since the result res is also a HashSet, it can also be automatically de-duplicated. The last remaining in res is the total'or' value of all the different sub-arrays, see the code as follows:


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur;
        for (int i : A) {
            unordered_set<int> tmp = {i};
            for (int j : cur) tmp.insert(i | j);
            cur = tmp;
            for (int j : cur) res.insert(j);
        }
        return res.size();
    }
};
