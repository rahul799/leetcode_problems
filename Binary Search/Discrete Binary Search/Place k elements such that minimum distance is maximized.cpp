

https://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/



Place k elements such that minimum distance is maximized



Given an array representing n positions along a straight line. Find k (where k <= n) elements from the array such that the maximum distance between any two 
(consecutive points among the k points)
is maximized.



An Efficient Solution is based on Binary Search. We first sort the array. Now we know maximum possible value result is arr[n-1] – arr[0] (for k = 2). We 
do binary search for maximum result for given k. We start with middle of maximum possible result. If middle is a feasible solution, we search on right half of
mid. Else we search is left half. To check feasibility, we place k elements under given mid distance



// C++ program to find largest minimum distance
// among k points.
#include <bits/stdc++.h>

using namespace std;

// Returns true if it is possible to arrange
// k elements of arr[0..n-1] with minimum distance
// given as mid.
bool isFeasible(int mid, int arr[], int n, int k)
{
	// Place first element at arr[0] position
	int pos = arr[0];

	// Initialize count of elements placed.
	int elements = 1;

	// Try placing k elements with minimum
	// distance mid.
	for (int i=1; i<n; i++)
	{
		if (arr[i] - pos >= mid)
		{
			// Place next element if its
			// distance from the previously
			// placed element is greater
			// than current mid
			pos = arr[i];
			elements++;

			// Return if all elements are placed
			// successfully
			if (elements == k)
			return true;
		}
	}
	return 0;
}

// Returns largest minimum distance for k elements
// in arr[0..n-1]. If elements can't be placed,
// returns -1.
int largestMinDist(int arr[], int n, int k)
{
	// Sort the positions
	sort(arr,arr+n);

	// Initialize result.
	int res = -1;

	// Consider the maximum possible distance
	int left = 1, right = arr[n-1];

	// left is initialized with 1 and not with arr[0] 
	// because, minimum distance between each element 
	// can be one and not arr[0]. consider this example: 
	// arr[] = {9,12} and you have to place 2 element
	// then left = arr[0] will force the function to
	// look the answer between range arr[0] to arr[n-1], 
	// i.e 9 to 12, but the answer is 3 so It is required 
	// that you initialize the left with 1

	// Do binary search for largest minimum distance
	while (left < right)
	{
		int mid = (left + right)/2;

		// If it is possible to place k elements
		// with minimum distance mid, search for
		// higher distance.
		if (isFeasible(mid, arr, n, k))
		{
			// Change value of variable max to mid iff
			// all elements can be successfully placed
			res = max(res, mid);
			left = mid + 1;
		}

		// If not possible to place k elements, search
		// for lower distance
		else
			right = mid;
	}

	return res;
}

// Driver code
int main()
{
	int arr[] = {1, 2, 8, 4, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << largestMinDist(arr, n, k);
	return 0;
}
