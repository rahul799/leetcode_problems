

https://www.youtube.com/watch?v=aVZcIRPuJ78&ab_channel=TECHDOSE


https://drive.google.com/file/d/1s5hhvtgbmapeQX637hOBnzVy5K11OIMD/view


SIMPLE SOLUTION:-
// C++ program to find XOR without using ^ 
#include <iostream> 
using namespace std; 

// Returns XOR of x and y 
int myXOR(int x, int y) 
{ 
	int res = 0; // Initialize result 
	
	// Assuming 32-bit Integer 
	for (int i = 31; i >= 0; i--)					 
	{ 
	// Find current bits in x and y 
	bool b1 = x & (1 << i); 
	bool b2 = y & (1 << i); 
		
		// If both are 1 then 0 else xor is same as OR 
		bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);		 

		// Update result 
		res <<= 1; 
		res |= xoredBit; 
	} 
	return res; 
} 

// Driver program to test above function 
int main() 
{ 
int x = 3, y = 5; 
cout << "XOR is " << myXOR(x, y); 
return 0; 
} 

EFFICIENT SOLUTION:-
// C++ program to find XOR without using ^ 
#include <iostream> 
using namespace std; 

// Returns XOR of x and y 
int myXOR(int x, int y) 
{ 
return (x | y) & (~x | ~y); 
} 

// Driver program to test above function 
int main() 
{ 
int x = 3, y = 5; 
cout << "XOR is " << myXOR(x, y); 
return 0; 
} 
