Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.


The idea is to use an auxiliary stack.

Create an empty stack.
One by one dequeue items from given queue and push the dequeued items to stack.
Enqueue the contents of stack at the back of the queue
Dequeue (size-k) elements from the front and enque them one by one to the same queue.


// C++ program to reverse first 
// k elements of a queue. 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to reverse the first 
K elements of the Queue */
void reverseQueueFirstKElements( 
	int k, queue<int>& Queue) 
{ 
	if (Queue.empty() == true
		|| k > Queue.size()) 
		return; 
	if (k <= 0) 
		return; 

	stack<int> Stack; 

	/* Push the first K elements 
	into a Stack*/
	for (int i = 0; i < k; i++) { 
		Stack.push(Queue.front()); 
		Queue.pop(); 
	} 

	/* Enqueue the contents of stack 
	at the back of the queue*/
	while (!Stack.empty()) { 
		Queue.push(Stack.top()); 
		Stack.pop(); 
	} 

	/* Remove the remaining elements and 
	enqueue them at the end of the Queue*/
	for (int i = 0; i < Queue.size() - k; i++) { 
		Queue.push(Queue.front()); 
		Queue.pop(); 
	} 
} 

/* Utility Function to print the Queue */
void Print(queue<int>& Queue) 
{ 
	while (!Queue.empty()) { 
		cout << Queue.front() << " "; 
		Queue.pop(); 
	} 
} 

// Driver code 
int main() 
{ 
	queue<int> Queue; 
	Queue.push(10); 
	Queue.push(20); 
	Queue.push(30); 
	Queue.push(40); 
	Queue.push(50); 
	Queue.push(60); 
	Queue.push(70); 
	Queue.push(80); 
	Queue.push(90); 
	Queue.push(100); 

	int k = 5; 
	reverseQueueFirstKElements(k, Queue); 
	Print(Queue); 
} 



Time Complexity: O(n+k).
Where ‘n’ is the total number of elements in the queue and ‘k’ is the number of elements to be reversed. This is because firstly the whole queue is emptied into the stack and after that first ‘k’ elements are emptied and enqueued in the same way.
Auxiliary Space :Use of stack to store values for the purpose of reversing-: O(n)
