
// Consider f_i:

// choose 1 as the root, we have 0 node for the left tree, i-1 for the
// right;
// choose 2 as the root, we have 1 node for the left tree, i-2 for the
// right;
// ...
// choose i as the root, we have i-1 nodes for the left tree, 0 for the



Unique Binary Search Trees
Medium

3550

130

Add to List

Share
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
   
   
   

class Solution {
public:
    int numTrees( int n ) {
        if( n == 0 ) return 1;
        vector<int> trees( n + 1);
        trees[0] = 1;
        trees[1] = 1;
        for( int i=2; i <= n; i++ ) {
            for( int j=0; j < i; j++ ) {
                trees[i] += trees[j]*trees[i-j-1];   
            }
        }
        return trees[n];
    }
};
