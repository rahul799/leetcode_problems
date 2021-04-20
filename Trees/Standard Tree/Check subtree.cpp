Check subtree



Problems
A tree S is a subtree of a tree T if S consists of a node and all its descendants from T.
Given two binary trees with head reference as T and S having at most N nodes. Check if S is a subtree of T.


Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4

Output: 1
Explanation: S is a subtree of T.

Example 2:

Input:
T:     10          S:   10
      /   \            /
    20     30         20
   /  \   
  40   50

Output: 0
Explanation: 
S does not have all the descendants of 
10 from T. S is not a subtree of T.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSubtree() which takes two nodes T and S as input parameter and returns true if S is a subtree of T, else returns false.


Expected Time Complexity: O(N2) where N is the number of nodes. 
Expected Auxiliary Space: O(Height of the Tree).


Constraints:
1 <= Number of nodes <= 104
1 <= Value of nodes <= 104











/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */



bool areIdentical(Node * root1, Node *root2)  
{  
    /* base cases */
    if (root1 == NULL && root2 == NULL)  
        return true;  
  
    if (root1 == NULL || root2 == NULL)  
        return false;  
  
    /* Check if the data of both roots is  
    same and data of left and right  
    subtrees are also same */
    return (root1->data == root2->data &&  
            areIdentical(root1->left, root2->left) &&  
            areIdentical(root1->right, root2->right) );  
}  
  
  
/* This function returns true if S  
is a subtree of T, otherwise false */
bool isSubtree(Node *T, Node *S)  
{  
    /* base cases */
    if (S == NULL)  
        return true;  
  
    if (T == NULL)  
        return false;  
  
    /* Check the tree with root as current Node */
    if (areIdentical(T, S))  
        return true;  
  
    /* If the tree with root as current  
    Node doesn't match then try left  
    and right subtrees one by one */
    return isSubtree(T->left, S) ||  
        isSubtree(T->right, S);  
}  



