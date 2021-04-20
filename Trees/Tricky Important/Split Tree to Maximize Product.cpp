Split Tree to Maximize Product
Question 895 of 1000
Given a binary tree root, consider deleting an edge in the tree so that the tree becomes disjoint with two trees. Then, take the sum of each subtree
and multiply the two numbers. Return the largest such product we can get after deleting one edge.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize


Output
50
Explanation
If we delete the 3 - 5 edge, then we can have (1 + 2 + 3 + 4) * 5 = 50




When an edge is deleted from the tree, the lower node of the deleted edge retains its subtree.

Therefore, assuming we have the sum of all values in the entire tree, then the product attained when deleting an edge is equal to (sum of values in subtree rooted at lower node) * (total sum - sum of values in subtree rooted at lower node).

We can then brute force over all of the edges.

Implementation
We first get the sum of all nodes in the tree with the getSum function. The sum of all nodes in the tree is equal to the sum of the root value plus the sum of the values in the left and right subtrees.

We then brute force over all edges as described above. getProduct returns the pair of values <sum of all values in the subtree rooted at the current node, best product attainable if we only delete edges where the lower node is in the given subtree>.

We call this function recursively and then use the formula above, propagating the sum and the best product.

Time Complexity
We DFS through the tree twice, so the runtime is \mathcal{O}(N)O(N)





void dfs(Tree* root, int &total_sum){
    if(root == nullptr)
        return;
    
    total_sum += root->val;
    dfs(root->left, total_sum);
    dfs(root->right, total_sum);
}

int MaxProd(Tree* root, int total_sum, int &result){
    if(root == nullptr)
        return 0;
    
    int sum = root->val + MaxProd(root->left, total_sum, result) + MaxProd(root->right, total_sum, result);
    result = max(result, sum * (total_sum - sum));
    return sum;
}

int solve(Tree* root) {
        int total_sum = 0;
        int result = 0;
        dfs(root, total_sum);
        MaxProd(root, total_sum, result);
        return result;    
}
