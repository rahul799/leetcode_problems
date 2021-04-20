Given an array of positive integers, sort the array in decreasing order of count of set bits in binary representations of array elements.
For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort. 
For example, if input array is {3, 5}, then output array should also be {3, 5}. Note that both 3 and 5 
have same number set bits.



Most optimised Approach : Counting Sort based


This problem can be solved in O(n) time. The idea is similar to counting sort.

Note: There can be minimum 1 set-bit and only a maximum of 31set-bits in any integer.

Steps (assuming that an integer takes 32 bits):

Create a vector “count” of size 32. Each cell of count i.e., count[i] is another vector that stores all the elements whose set-bit-count is i
Traverse the array and do following for each element:
Count the number set-bits of this element. Let it be ‘setbitcount’
count[setbitcount].push_back(element)
Traverse ‘count’ in reverse fashion(as we need to sort in non-increasing order) and modify the array.



// C++ program to sort an array according to 
// count of set bits using std::sort() 
#include <bits/stdc++.h> 
using namespace std; 

// a utility function that returns total set bits 
// count in an integer 
int countBits(int a) 
{ 
	int count = 0; 
	while (a) 
	{ 
		if (a & 1 ) 
			count+= 1; 
		a = a>>1; 
	} 
	return count; 
} 

// Function to sort according to bit count 
// This function assumes that there are 32 
// bits in an integer. 
void sortBySetBitCount(int arr[],int n) 
{ 
	vector<vector<int> > count(32); 
	int setbitcount = 0; 
	for (int i=0; i<n; i++) 
	{ 
		setbitcount = countBits(arr[i]); 
		count[setbitcount].push_back(arr[i]); 
	} 

	int j = 0; // Used as an index in final sorted array 

	// Traverse through all bit counts (Note that we 
	// sort array in decreasing order) 
	for (int i=31; i>=0; i--) 
	{ 
		vector<int> v1 = count[i]; 
		for (int i=0; i<v1.size(); i++) 
			arr[j] = v1[i]; 
      j++;
	} 
} 

// Utility function to print an array 
void printArr(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	sortBySetBitCount(arr, n); 
	printArr(arr, n); 
	return 0; 
} 































Approach 2: Auxiliary Space : O(1)
Time complexity : O(n log n)




// C++ program to sort an array according to 
// count of set bits using std::sort() 
#include <bits/stdc++.h> 

using namespace std; 

// a utility function that returns total set bits 
// count in an integer 
int countBits(int a) 
{ 
	int count = 0; 
	while (a) 
	{ 
		if (a & 1 ) 
			count+= 1; 
		a = a>>1; 
	} 
	return count; 
} 

// custom comparator of std::sort 
int cmp(int a,int b) 
{ 
	int count1 = countBits(a); 
	int count2 = countBits(b); 

	// this takes care of the stability of 
	// sorting algorithm too 
	if (count1 <= count2) 
		return false; 
	return true; 
} 

// Function to sort according to bit count using 
// std::sort 
void sortBySetBitCount(int arr[], int n) 
{ 
	stable_sort(arr, arr+n, cmp); 
} 

// Utility function to print an array 
void printArr(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	sortBySetBitCount(arr, n); 
	printArr(arr, n); 
	return 0; 
} 
