Stack Using Linked List


The major problem with the stack implemented using an array is, it works only for a fixed number of data values. That means the amount of data must be specified at 
the beginning of the implementation itself. Stack implemented using an array is not suitable, when we don't know the size of data which we are going to use. 
A stack data structure can be 
implemented by using a linked list data structure. The stack implemented using linked list can work for an unlimited number of values. That means, stack 
implemented using linked list works for the variable size of data. So, there is no need to fix the size at the beginning of the implementation. The Stack 
implemented using linked list can organize as many data values as we want.

In linked list implementation of a stack, every new element is inserted as 'top' element. That means every newly inserted element is pointed by 'top'. Whenever 
we want to remove an element from the stack, simply remove the node which is pointed by 'top' by moving 'top' to its previous node in the list. The next field 
of the first element must be always NULL

http://www.btechsmartclass.com/data_structures/stack-using-linked-list.html

Stack Operations using Linked List
To implement a stack using a linked list, we need to set the following things before implementing actual operations.

Step 1 - Include all the header files which are used in the program. And declare all the user defined functions.
Step 2 - Define a 'Node' structure with two members data and next.
Step 3 - Define a Node pointer 'top' and set it to NULL.
Step 4 - Implement the main method by displaying Menu with list of operations and make suitable function calls in the main method.
push(value) - Inserting an element into the Stack
We can use the following steps to insert a new node into the stack...

Step 1 - Create a newNode with given value.
Step 2 - Check whether stack is Empty (top == NULL)
Step 3 - If it is Empty, then set newNode → next = NULL.
Step 4 - If it is Not Empty, then set newNode → next = top.
Step 5 - Finally, set top = newNode.
pop() - Deleting an Element from a Stack
We can use the following steps to delete a node from the stack...

Step 1 - Check whether stack is Empty (top == NULL).
Step 2 - If it is Empty, then display "Stack is Empty!!! Deletion is not possible!!!" and terminate the function
Step 3 - If it is Not Empty, then define a Node pointer 'temp' and set it to 'top'.
Step 4 - Then set 'top = top → next'.
Step 5 - Finally, delete 'temp'. (free(temp)).
display() - Displaying stack of elements
We can use the following steps to display the elements (nodes) of a stack...

Step 1 - Check whether stack is Empty (top == NULL).
Step 2 - If it is Empty, then display 'Stack is Empty!!!' and terminate the function.
Step 3 - If it is Not Empty, then define a Node pointer 'temp' and initialize with top.
Step 4 - Display 'temp → data --->' and move it to the next node. Repeat the same until temp reaches to the first node in the stack. (temp → next != NULL).
Step 5 - Finally! Display 'temp → data ---> NULL'








// C++ program to Implement a stack 
//using singly linked list 
#include <bits/stdc++.h> 
using namespace std; 

// Declare linked list node 

struct Node 
{ 
	int data; 
	struct Node* link; 
}; 

struct Node* top; 

// Utility function to add an element 
// data in the stack insert at the beginning 
void push(int data) 
{ 
	
	// Create new node temp and allocate memory 
	struct Node* temp; 
	temp = new Node(); 

	// Check if stack (heap) is full. 
	// Then inserting an element would 
	// lead to stack overflow 
	if (!temp) 
	{ 
		cout << "\nHeap Overflow"; 
		exit(1); 
	} 

	// Initialize data into temp data field 
	temp->data = data; 

	// Put top pointer reference into temp link 
	temp->link = top; 

	// Make temp as top of Stack 
	top = temp; 
} 

// Utility function to check if 
// the stack is empty or not 
int isEmpty() 
{ 
	return top == NULL; 
} 

// Utility function to return top element in a stack 
int peek() 
{ 
	
	// Check for empty stack 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 

// Utility function to pop top 
// element from the stack 
void pop() 
{ 
	struct Node* temp; 

	// Check for stack underflow 
	if (top == NULL) 
	{ 
		cout << "\nStack Underflow" << endl; 
		exit(1); 
	} 
	else
	{ 
		
		// Top assign into temp 
		temp = top; 

		// Assign second node to top 
		top = top->link; 

		// Destroy connection between 
		// first and second 
		temp->link = NULL; 

		// Release memory of top node 
		free(temp); 
	} 
} 

// Function to print all the 
// elements of the stack 
void display() 
{ 
	struct Node* temp; 

	// Check for stack underflow 
	if (top == NULL) 
	{ 
		cout << "\nStack Underflow"; 
		exit(1); 
	} 
	else
	{ 
		temp = top; 
		while (temp != NULL) 
		{ 

			// Print node data 
			cout << temp->data << "-> "; 

			// Assign temp link to temp 
			temp = temp->link; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	
	// Push the elements of stack 
	push(11); 
	push(22); 
	push(33); 
	push(44); 

	// Display stack elements 
	display(); 

	// Print top element of stack 
	cout << "\nTop element is "
		<< peek() << endl; 

	// Delete top elements of stack 
	pop(); 
	pop(); 

	// Display stack elements 
	display(); 

	// Print top element of stack 
	cout << "\nTop element is "
		<< peek() << endl; 
		
	return 0; 
} 

// This code is contributed by Striver 
