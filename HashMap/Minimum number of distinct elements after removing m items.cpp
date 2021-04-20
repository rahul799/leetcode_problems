Minimum number of distinct elements after removing m items
Last Updated: 23-09-2017
Given an array of items, an i-th index element denotes the item id’s and given a number m, the task is to remove m elements such that there should be minimum distinct id’s left.Print the number of distinct id’s.

Examples:

Input : arr[] = { 2, 2, 1, 3, 3, 3} 
            m = 3
Output : 1
Remove 1 and both 2's.So, only 3 will be 
left that's why distinct id is 1.

Input : arr[] = { 2, 4, 1, 5, 3, 5, 1, 3} 
            m = 2
Output : 3
Remove 2 and 4 completely. So, remaining ids 
are 1, 3 and 5 i.e. 3


1- Count the occurrence of elements and store in the hash.
2- Sort the hash.
3- Start removing elements from hash.
4- Return the number of values left in the hash.






// C++ program for above implementation 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find distintc id's 
int distinctIds(int arr[], int n, int mi) 
{ 
	unordered_map<int, int> m; 
	vector<pair<int, int> > v; 
	int count = 0; 

	// Store the occurrence of ids 
	for (int i = 0; i < n; i++) 
		m[arr[i]]++; 

	// Store into the vector second as first and vice-versa 
	for (auto it = m.begin(); it != m.end(); it++) 
		v.push_back(make_pair(it->second, it->first)); 

	// Sort the vector 
	sort(v.begin(), v.end()); 

	int size = v.size(); 

	// Start removing elements from the beginning 
	for (int i = 0; i < size; i++) { 

		// Remove if current value is less than 
		// or equal to mi 
		if (v[i].first <= mi) { 
			mi -= v[i].first; 
			count++; 
		} 

		// Return the remaining size 
		else
			return size - count; 
	} 
	return size - count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 3, 1, 2, 3, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	int m = 3; 

	cout << distinctIds(arr, n, m); 
	return 0; 
} 
