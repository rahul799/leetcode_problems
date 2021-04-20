
279. Perfect Squares
Medium

3832

226

Add to List

Share
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104



https://leetcode.com/problems/perfect-squares/discuss/486915/C%2B%2B279Perfect-Squares-BFS-Solution

class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
            {
                cntPerfectSquares[i] = 
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            }
        }
        
        return cntPerfectSquares.back();
    }
};







BFS Approach:




class Solution {
public:
    int numSquares(int n) {
        
        // Init
        unordered_set<int>  visited;
        queue<int>          q;
        vector<int>         vec; 
        int                 step = 1;
        
        for(int i = 1; i*i <= n; i++ )
        {
            if( i*i == n) return step;
            q.push(i*i);
            visited.insert(i*i); 
            vec.push_back(i*i);
        }                
           
        while( !q.empty() )
        {
            step += 1;
            int size = q.size();
            for (int i = 0 ; i < size; i++) 
            {            
                int num = q.front();                 
                for (auto key : vec) 
                { 
                    int sum = num + key;
                    if( sum == n) return step;
                    if( sum < n && !visited.count(sum) )
                    {                        
                        q.push(sum);
                        visited.insert(sum);                         
                    }
                } 
                q.pop();
            }
        }
        return -1;        
    }
};
