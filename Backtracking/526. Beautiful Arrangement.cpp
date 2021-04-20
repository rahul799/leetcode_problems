

https://leetcode.com/problems/beautiful-arrangement/


526. Beautiful Arrangement
Medium

1205

213

Add to List

Share
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful 
arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1






class Solution {
public:
    int countArrangement(int n) {
        if (n == 1) return 1;
        used.resize(n,false);
        
        backtrack(n, 1);
        return res;
    }
private:
    int res = 0;
    vector<bool> used;
    //vector<int> track;
    void backtrack(int n, int idx)
    {
        if (idx > n)
        {
            res++;
            return;
        }
        
        for (int i = 1; i <= n;i++)
        {
            if (used[i-1]) continue;
            used[i-1] = true;
            if (i%idx == 0 || idx%i == 0)
            {
                //track.push_back(i);
                backtrack(n,idx+1);
                //track.pop_back();
            }
            used[i-1] = false;
        }
    }
    
};
