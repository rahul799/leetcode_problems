
Tree Coloring
You are given a binary tree root where the value of each node represents its color. In the tree there are at most 2 colors. Return whether it's possible to swap the colors of the nodes any number of times so that no two adjacent nodes have the same color.

    
    
    https://binarysearch.com/problems/Tree-Coloring



Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize

0

Output
true
Explanation
We can color the root with 0, the next level 1s, third level 0s and fourth level 1s

Example 2
Input
Visualize
root =
5

9

5

9

Output
false
Explanation
There's no way to color the nodes so that no two adjacent nodes have the same color.




int dfs(Tree *root, int color) {
    if (!root) return 0;
    return color + dfs(root->left, 1 - color) + dfs(root->right, 1 - color);
}

void countNodes(Tree *root, int firstColor, int &firstCount, int &secondCount) {
    if (!root) return;

    if (root->val == firstColor)
        ++firstCount;
    else
        ++secondCount;

    countNodes(root->left, firstColor, firstCount, secondCount);
    countNodes(root->right, firstColor, firstCount, secondCount);
}

bool solve(Tree *root) {
    if (!root) return true;

    int req = dfs(root, 1), firstColor = root->val, firstCount = 0, secondCount = 0;
    countNodes(root, firstColor, firstCount, secondCount);
    return req == firstCount || req == secondCount;
}



// To satisfy the question's condition we need to colour each level alternatively so that the children never have the same colour as their parent. So the first level would be colour 1, second would be colour 2, third would be colour 1 again and so on. So we count the total number of nodes of each colour, and we count the total number of nodes in odd and even levels of tree. If the number of nodes of odd and even levels correspond to the number of nodes of colour 1 and colour 2, the answer would be yes, otherwise no.

int r;
int cnt1 = 0, cnt2 = 0;

void dfs(Tree* root, int same) {
    if (root == NULL) return;

    if (same) {
        if (root->val != r) cnt1++;
        dfs(root->left, same ^ 1);
        dfs(root->right, same ^ 1);
    } else {
        if (root->val == r) cnt2++;
        dfs(root->left, same ^ 1);
        dfs(root->right, same ^ 1);
    }
}

bool solve(Tree* root) {
    if (root == NULL) return true;
    r = root->val;
    cnt1 = 0, cnt2 = 0;
    dfs(root, 0);

    if (cnt1 == cnt2) return true;

    cnt1 = 0, cnt2 = 0;
    dfs(root, 1);

    if (cnt1 == cnt2) return true;

    return false;
}
