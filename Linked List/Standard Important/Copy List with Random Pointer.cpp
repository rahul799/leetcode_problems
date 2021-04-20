




https://leetcode.com/problems/copy-list-with-random-pointer/




138. Copy List with Random Pointer
Medium

4618

789

Add to List

Share
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.
 

Constraints:

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* temp=head;
        
        //creates mapping of cloned list using original list
        while(temp)
        {
            Node* newNode= new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
            
        }
        
        //assigning random pointers
        temp=head;
        while(temp)
        {
            if(temp->random)
            {
               temp->next->random= temp->random->next;   
            }
            temp=temp->next->next;
        }
        
        //restore the original linked list
        Node* newHead= head->next;
        Node* temp2=head->next;
        temp=head;
        
        while(temp  && temp2)
        {
            Node* currN=temp2->next;
            temp->next=currN;
            if(currN)
            {
                temp2->next=currN->next;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        
        return newHead;
    }
};






Simple Steps of Solution :

create one node curresponding to each node with same value.
map them with curresponding nodes using unordered_map
iterate over the list and assing the curresponding node of each node's next and random nodes
than return node currsponding to head node.
 Node * copyRandomList(Node * head) {
     unordered_map < Node * , Node * > record;
     auto temp = head;
     Node * newList;
     while (temp) {
         record[temp] = new Node(temp -> val);
         temp = temp -> next;
     }
     temp = head;
     while (temp) {
         record[temp] -> next = record[temp -> next];
         record[temp] -> random = record[temp -> random];
         temp = temp -> next;
     }
     return record[head];
 }
