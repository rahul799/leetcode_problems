
https://www.geeksforgeeks.org/counting-inversions/


Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) 




// C++ program to Count Inversions 
// in an array 
#include <bits/stdc++.h> 
using namespace std; 

int getInvCount(int arr[], int n) 
{ 
	int inv_count = 0; 
	for (int i = 0; i < n - 1; i++) 
		for (int j = i + 1; j < n; j++) 
			if (arr[i] > arr[j]) 
				inv_count++; 

	return inv_count; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << " Number of inversions are "
		<< getInvCount(arr, n); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 






The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index 
for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays 
are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion 
in the second half and the number of inversions by merging the two.
	
	
	
// C++ program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 
  
int _mergeSort(int arr[], int temp[],  
                 int left, int right); 
int merge(int arr[], int temp[], int left,  
                   int mid, int right); 
  
/* This function sorts the  
   input array and returns the  
number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function  
  that sorts the input array and  
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[],  
                 int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp,  
                                left, mid); 
        inv_count += _mergeSort(arr, temp,  
                             mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left,  
                           mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, 
          int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int ans = mergeSort(arr, n); 
    cout << " Number of inversions are " << ans; 
    return 0; 
} 
	
	
	
	
The base case of recursion is when there is only one element in the given half.
Print the answe








