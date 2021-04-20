Vertical Lines in Binary Tree
Question 1 of 4
Given a binary tree root, return the number of unique vertical lines that can be drawn such that every node has a line intersecting it. Each left child is angled at 45 degrees to its left, while the right child is angled at 45 degrees to the right.

For example, root and root.left.right are on the same vertical line.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
1

2

4

3

5

Output
5
Explanation
There's a unique vertical line over every node.



    
    
    
    
 https://binarysearch.com/room/Weekly-Contest-37-u2kU8duwTB?questionsetIndex=0

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */




void dfs(Tree* t, int d, int& L, int& R) {
    if (t == NULL) return;
   L = min(L, d);
   R = max(R, d);
   cout << " left" << L <<  " " << "right" << " " << R;
   
   
    dfs(t->left, d - 1, L , R);
    dfs(t->right, d + 1, L, R);
}
int solve(Tree* root) {
        
int L = 0, R = 0;
   
    dfs(root, 0, L, R);
    return R - L + 1;
}








/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */


 static int R , static L ;

void dfs(Tree* t, int d) {
    if (t == NULL) return;
   L = min(L, d);
   R = max(R, d);
   
   
    dfs(t->left, d - 1);
    dfs(t->right, d + 1);
}
int solve(Tree* root) {
        
L = 0, 
   
    dfs(root, 0);
    return R - L + 1;
}
