Find the nearest smaller numbers on left side in an array


ind the nearest smaller numbers on left side in an array
Last Updated: 19-06-2019
Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.
Examples:

Input:  arr[] = {1, 6, 4, 10, 2, 5}
Output:         {_, 1, 1,  4, 1, 2}
First element ('1') has no element on left side. For 6, 
there is only one smaller element on left side '1'. 
For 10, there are three smaller elements on left side (1,
6 and 4), nearest among the three elements is 4.

Input: arr[] = {1, 3, 0, 2, 5}
Output:        {_, 1, _, 0, 2}


Below is stack based algorithm

Let input sequence be 'arr[]' and size of array be 'n'

1) Create a new empty stack S

2) For every element 'arr[i]' in the input sequence 'arr[]',
   where 'i' goes from 0 to n-1.
    a) while S is nonempty and the top element of 
       S is greater than or equal to 'arr[i]':
           pop S
    
    b) if S is empty:
           'arr[i]' has no preceding smaller value
    c) else:
           the nearest smaller value to 'arr[i]' is 
           the top element of S

    d) push 'arr[i]' onto S


// C++ implementation of efficient algorithm to find 
// smaller element on left side 
#include <iostream> 
#include <stack> 
using namespace std; 

// Prints smaller elements on left side of every element 
void printPrevSmaller(int arr[], int n) 
{ 
	// Create an empty stack 
	stack<int> S; 

	// Traverse all array elements 
	for (int i=0; i<n; i++) 
	{ 
		// Keep removing top element from S while the top 
		// element is greater than or equal to arr[i] 
		while (!S.empty() && S.top() >= arr[i]) 
			S.pop(); 

		// If all elements in S were greater than arr[i] 
		if (S.empty()) 
			cout << "_, "; 
		else //Else print the nearest smaller element 
			cout << S.top() << ", "; 

		// Push this element 
		S.push(arr[i]); 
	} 
} 

/* Driver program to test insertion sort */
int main() 
{ 
	int arr[] = {1, 3, 0, 2, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printPrevSmaller(arr, n); 
	return 0; 
} 
