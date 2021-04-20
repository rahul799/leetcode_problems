386. Lexicographical Numbers
Medium

739

92

Add to List

Share
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104
 

Follow up: Could you optimize your solution to use O(n) runtime and O(1) space?
  
  
  
  
  class Solution {
	// store the values as members (you can also pass referance)
    vector<int> res; // store this so we don't need to concatenate vectors
    int max;
    void dfs(int i)
    {
        if(i > max) // check to make sure it's not larger than max
            return;
        res.push_back(i); 
        // we push back current first because:
        // children of a number is always larger lexicographically
        // example: 123 is lexicographically smaller than 1231, 1232, etc
        
        int shift = i * 10; 
        // we shift it so it becomes 
	    // <number>0
	    // for example 123 becomes 1230
        for(int i = 0; i < 10; i++)
            dfs(shift + i); // call recursion with its children
    }
public:
    vector<int> lexicalOrder(int n) {
        max = n; // set max value
        for(int i = 1; i < 10; i++) // iterate throught all starting vals (can't start with 0)
            dfs(i);
        return res;
    }
};


