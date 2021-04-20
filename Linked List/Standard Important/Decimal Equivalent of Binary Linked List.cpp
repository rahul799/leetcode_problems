Decimal Equivalent of Binary Linked List


Given a singly linked list of 0s and 1s find its decimal equivalent.

   Input  : 0->0->0->1->1->0->0->1->0
   Output : 50   

   Input  : 1->0->0
   Output : 4
The decimal Value of an empty linked list is considered as 0.

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Initialize the result as 0. Traverse the linked list and for each node, multiply the result by 2 and add the node’s data to it.

filter_none
edit
play_arrow

brightness_4
// C++ Program to find decimal value of  
// binary linked list  
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list Node */
class Node  
{  
    public: 
    bool data;  
    Node* next;  
};  
  
/* Returns decimal value of binary linked list */
int decimalValue(Node *head)  
{  
    // Initialized result  
    int res = 0;  
  
    // Traverse linked list  
    while (head != NULL)  
    {  
        // Multiply result by 2 and add  
        // head's data  
        res = (res << 1) + head->data;  
  
        // Move next  
        head = head->next;  
    }  
    return res;  
}  
  
// Utility function to create a new node.  
Node *newNode(bool data)  
{  
    Node *temp = new Node;  
    temp->data = data;  
    temp->next = NULL;  
    return temp;  
}  
  
/* Driver program to test above function*/
int main()  
{  
    /* Start with the empty list */
    Node* head = newNode(1);  
    head->next = newNode(0);  
    head->next->next = newNode(1);  
    head->next->next->next = newNode(1);  
  
    cout << "Decimal value is "
        << decimalValue(head);  
  
    return 0;  
}  
  
