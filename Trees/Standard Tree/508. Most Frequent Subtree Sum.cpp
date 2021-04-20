

508. Most Frequent Subtree Sum
Medium

870

145

Add to List

Share
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.









class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // here map will store sum corresponding to it's frequency
        unordered_map<int, int> mp;
        int  maxFreq = 0;
        vector<int> result;
         helper( root, mp, maxFreq );
        
        for( auto& i : mp ){
            if (i.second == maxFreq)
                result.push_back(i.first);
        }
        
        return result;
            }
    int helper(TreeNode * root, unordered_map<int, int> &mp, int& maxFreq){
        if(!root) return 0;
        
        int left = helper(root->left, mp, maxFreq);
        int right = helper(root->right, mp, maxFreq);
        
        int sum = left + right + root->val;
        mp[sum]++;
        maxFreq =  max(mp[sum], maxFreq );
        
        return sum;
        
    }
    
};
