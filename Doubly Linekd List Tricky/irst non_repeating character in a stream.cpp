
https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/


https://www.youtube.com/watch?v=KnWqCfIfHX0&t=346s&ab_channel=TECHDOSE


Approach:



Create an empty DLL. Also create two arrays inDLL[] and repeated[] of size 256. inDLL is an array of pointers to DLL nodes. repeated[] is a boolean array, repeated[x] is true if x is repeated two or more times, otherwise false. inDLL[x] contains a pointer to a DLL node if character x is present in DLL, otherwise NULL.
Initialize all entries of inDLL[] as NULL and repeated[] as false.
To get the first non-repeating character, return character at head of DLL.
Following are steps to process a new character ‘x’ in a stream. 
If repeated[x] is true, ignore this character (x is already repeated two or more times in the stream)
If repeated[x] is false and inDLL[x] is NULL (x is seen first time). Append x to DLL and store address of new DLL node in inDLL[x].
If repeated[x] is false and inDLL[x] is not NULL (x is seen second time). Get DLL node of x using inDLL[x] and remove the node. Also, mark inDLL[x] as NULL and repeated[x] as true.



 


// A C++ program to find first 
// non-repeating character 
// from a stream of characters 
#include <iostream> 
#define MAX_CHAR 256 
using namespace std; 

// A linked list node 
struct node { 
	char a; 
	struct node *next, *prev; 
}; 

// A utility function to append a character x at the end 
// of DLL. Note that the function may change head and tail 
// pointers, that is why pointers to these pointers are passed. 
void appendNode(struct node** head_ref, struct node** tail_ref, 
				char x) 
{ 
	struct node* temp = new node; 
	temp->a = x; 
	temp->prev = temp->next = NULL; 

	if (*head_ref == NULL) { 
		*head_ref = *tail_ref = temp; 
		return; 
	} 
	(*tail_ref)->next = temp; 
	temp->prev = *tail_ref; 
	*tail_ref = temp; 
} 

// A utility function to remove a node 'temp' fromt DLL. 
// Note that the function may change head and tail pointers, 
// that is why pointers to these pointers are passed. 
void removeNode(struct node** head_ref, struct node** tail_ref, 
				struct node* temp) 
{ 
	if (*head_ref == NULL) 
		return; 

	if (*head_ref == temp) 
		*head_ref = (*head_ref)->next; 
	if (*tail_ref == temp) 
		*tail_ref = (*tail_ref)->prev; 
	if (temp->next != NULL) 
		temp->next->prev = temp->prev; 
	if (temp->prev != NULL) 
		temp->prev->next = temp->next; 

	delete (temp); 
} 

void findFirstNonRepeating() 
{ 
	// inDLL[x] contains pointer to 
	// a DLL node if x is present 
	// in DLL. If x is not present, then inDLL[x] is NULL 
	struct node* inDLL[MAX_CHAR]; 

	// repeated[x] is true if x is repeated two or more times. 
	// If x is not seen so far or x is seen only once. then 
	// repeated[x] is false 
	bool repeated[MAX_CHAR]; 

	// Initialize the above two arrays 
	struct node *head = NULL, *tail = NULL; 
	for (int i = 0; i < MAX_CHAR; i++) { 
		inDLL[i] = NULL; 
		repeated[i] = false; 
	} 

	// Let us consider following stream and see the process 
	char stream[] = "geeksforgeeksandgeeksquizfor"; 
	for (int i = 0; stream[i]; i++) { 
		char x = stream[i]; 
		cout << "Reading " << x << " from stream n"; 

		// We process this character only if it has not occurred 
		// or occurred only once. repeated[x] is true if x is 
		// repeated twice or more.s 
		if (!repeated[x]) { 
			// If the character is not in DLL, then add this at 
			// the end of DLL. 
			if (inDLL[x] == NULL) { 
				appendNode(&head, &tail, stream[i]); 
				inDLL[x] = tail; 
			} 
			else // Otherwise remove this character from DLL 
			{ 
				removeNode(&head, &tail, inDLL[x]); 
				inDLL[x] = NULL; 
				repeated[x] = true; // Also mark it as repeated 
			} 
		} 

		// Print the current first non-repeating character from 
		// stream 
		if (head != NULL) 
			cout << "First non-repeating character so far is "
				<< head->a << endl; 
	} 
} 

/* Driver program to test above function */
int main() 
{ 
	findFirstNonRepeating(); 
	return 0; 
} 
