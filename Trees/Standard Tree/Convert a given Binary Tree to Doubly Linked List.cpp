
https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/



Convert a given Binary Tree to Doubly Linked List | Set 4

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers 
respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must 
be head node of the DLL.


//Doing a reverse Inorder traversal
void BSTDLL(Node* root,Node **head)
{
if(root == NULL) return;
BSTDLL(root->right,head);
if(*head == NULL)
{
*head = root;
(*head)->left = NULL;
(*head)->right = NULL;
}
else
{
(*head)->left = root;
root->right = (*head);
(*head) = (*head)->left;  'shift head pt for further processing'
}
BSTDLL(root->left,head);
}
void BSTDLLUtil(Node **root)
{
Node *head = NULL;
BSTDLL(*root,&head);
head->left = NULL;
*root = head;
}

'basically we are having root and head ptr
headptr points to next  element and root current''
