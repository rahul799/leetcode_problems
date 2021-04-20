
https://www.geeksforgeeks.org/partitioning-a-linked-list-around-a-given-value-and-keeping-the-original-order/


Partitioning a linked list around a given value and keeping the original order
Last Updated: 25-02-2020
Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and finally nodes with value greater than or equal to x. The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.

Examples:

Input : 1->4->3->2->5->2->3, 
        x = 3
Output: 1->2->2->3->3->4->5

Input : 1->4->2->10 
        x = 3
Output: 1->2->4->10

Input : 10->4->20->10->3 
        x = 3
Output: 3->10->4->20->10




Initialize first and last nodes of below three linked lists as NULL.
Linked list of values smaller than x.
Linked list of values equal to x.
Linked list of values greater than x.
Now iterate through the original linked list. If a node’s value is less than x then append it at the end of smaller list. If the value is equal to x, then at the end of equal list. And if value is greater, then at the end of greater list.
Now concatenate three lists.



// C++ program to partition a linked list around a 
// given value. 
#include<bits/stdc++.h> 
using namespace std; 

/* Link list Node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// A utility function to create a new node 
Node *newNode(int data) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = data; 
	new_node->next = NULL; 
	return new_node; 
} 

// Function to make two separate lists and return 
// head after concatinating 
struct Node *partition(struct Node *head, int x) 
{ 
	/* Let us initialize first and last nodes of 
	three linked lists 
		1) Linked list of values smaller than x. 
		2) Linked list of values equal to x. 
		3) Linked list of values greater than x.*/
	struct Node *smallerHead = NULL, *smallerLast = NULL; 
	struct Node *greaterLast = NULL, *greaterHead = NULL; 
	struct Node *equalHead = NULL, *equalLast = NULL; 

	// Now iterate original list and connect nodes 
	// of appropriate linked lists. 
	while (head != NULL) 
	{ 
		// If current node is equal to x, append it 
		// to the list of x values 
		if (head->data == x) 
		{ 
			if (equalHead == NULL) 
				equalHead = equalLast = head; 
			else
			{ 
				equalLast->next = head; 
				equalLast = equalLast->next; 
			} 
		} 

		// If current node is less than X, append 
		// it to the list of smaller values 
		else if (head->data < x) 
		{ 
			if (smallerHead == NULL) 
				smallerLast = smallerHead = head; 
			else
			{ 
				smallerLast->next = head; 
				smallerLast = head; 
			} 
		} 
		else // Append to the list of greater values 
		{ 
			if (greaterHead == NULL) 
				greaterLast = greaterHead = head; 
			else
			{ 
				greaterLast->next = head; 
				greaterLast = head; 
			} 
		} 

		head = head->next; 
	} 

	// Fix end of greater linked list to NULL if this 
	// list has some nodes 
	if (greaterLast != NULL) 
		greaterLast->next = NULL; 

	// Connect three lists 

	// If smaller list is empty 
	if (smallerHead == NULL) 
	{ 
		if (equalHead == NULL) 
			return greaterHead; 
		equalLast->next = greaterHead; 
		return equalHead; 
	} 

	// If smaller list is not empty 
	// and equal list is empty 
	if (equalHead == NULL) 
	{ 
		smallerLast->next = greaterHead; 
		return smallerHead; 
	} 

	// If both smaller and equal list 
	// are non-empty 
	smallerLast->next = equalHead; 
	equalLast->next = greaterHead; 
	return smallerHead; 
} 

/* Function to print linked list */
void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while (temp != NULL) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 

// Driver program to run the case 
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = newNode(10); 
	head->next = newNode(4); 
	head->next->next = newNode(5); 
	head->next->next->next = newNode(30); 
	head->next->next->next->next = newNode(2); 
	head->next->next->next->next->next = newNode(50); 

	int x = 3; 
	head = partition(head, x); 
	printList(head); 
	return 0; 
} 
