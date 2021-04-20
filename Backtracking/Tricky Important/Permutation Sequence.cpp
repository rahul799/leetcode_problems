

https://leetcode.com/problems/permutation-sequence/



The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!




This problem is recursive like dynamic programming.
Kth Permutation sequence can be formed by choosing the 1st digit and then the rest of the digits one by one.
Visually:
1 + (permutations of rest of digits)
2 + (permutations of ...)
so on...

For N=3,
we have the permutations:
1|2,3
1|3,2
2|1,3
2|3,1
3|1,2
3|2,1

I put a bar "|" to separate first digit from the rest of digits.
There are a total of N! = 3! = 6 perms. Each 1st digit is "attached" to (n-1)! =2! = 2 permutations formed by rest of digits.
Thus , to choose 1st digit, simply calculate (k-1) / (n-1)! and use it to index into an array of digits 1,2,3,
Once 1st digit is chosen, we choose 2nd and so on recursively.

We remove 1st digit from the array of digits , so the remaining are the "rest of digits".
There are 2 ways to remove:

pull the chosen digit from its current place to the right place in the permutation and shift rest of digits accordingly. (this is the in-place method chosen in my code so left part is partially formed permuation and right part is the candidates)
mark the chosen digit as "used" so you don't use it again. (need an array of booleans to track)


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 0);
        vector<int> nums(n, 0);
        fact[0] = 1;
        for (int i=1;i<=n;i++){
            fact[i] = i * fact[i-1];
        }
        
        for (int i=0;i<n;i++){
            nums[i] = i+1;
        }
        
        string ans = "";
        int it = 1;
        k--;
        while (ans.size() < n){
            int digit_id = k / fact[n-it];
            int rows_excluded = digit_id * fact[n-it];
            int digit = nums[digit_id];
            ans += to_string(digit);
            k -= rows_excluded;
            nums.erase(nums.begin() + digit_id);
            it++;    
        }
        
        return ans;
        
    }
};
