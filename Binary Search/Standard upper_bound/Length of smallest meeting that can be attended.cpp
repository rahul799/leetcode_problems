Length of smallest meeting that can be attended


Given a 2D array arr[][] of the form {start, end} representing the start and end time of N meetings, also given two arrays entrance[] and exist[] representing 
the opening and closing times of the meeting room respectively, the task is to find the minimum time for which a meeting can be attended. If it is not possible
to attend any meeting, then 
print -1


Input: arr[][] = {{15, 19}, {5, 10}, {7, 25}}, entrance[] = {4, 13, 25, 2}, exist[] = {10, 21}
Output: 6
Explanation:
Meeting 1: Enter at the time 13, attend the meeting in the interval (15, 19) and exit at the time 21. Therefore, total time spent in the meeting = 21 – 13 = 8.
Meeting 2: Enter at the time 4, attend the meeting in (5, 10) and exit at the time 10. Therefore, total time spent in the meeting = 10 – 4 = 6.
Meeting 3: Enter at the time 4, attend the meeting in the interval (7, 25). But after the time 25 there is no closing time. Therefore, total time spent is infinite.
Therefore, minimum units of time that can be spent to attend a meeting is 6.

Input: arr[][] = {{1, 2}}, entrance[] = {1, 2}, exist[] = {3, 4}
Output: 2




Naive Approach: The simplest approach to solve this problem is to traverse arr[][] and for each interval {starti, endi}, find the value which just smaller than or equal to arr[i][0] in the array entrance[]. Also, find the value which is just greater than or equal to arr[i][1] in the array exist[]. Finally, print the minimum time to attend exactly one meeting.
Time Complexity: O(N*max(P, M)), where M and P are the size of entrance[]and exist[] arrays.
Auxiliary Space: O(1)

Efficient Approach: To optimize the above approach the idea is to use Sorting Algorithm and Binary Search technique.
Follow the steps below to solve the problem:





Sort the arrays entrance[] and exist[] in increasing order.
Initialize a variable ans to store the minimum time to attend exactly one meeting.
Traverse the array and for each interval of the meetings, find the value which is just smaller than or equal to starti in the entrance[] array using upper_bound and find the value which is just greater than or equal to endiin the exist[] array using lower_bound.
Finally, print the minimum time to attend exactly one meeting





// C++ program to implement 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum time to 
// attend exactly one meeting 
int minTime(int meeting[][2], int n, 
		vector<int> entrance, int m, 
			vector<int> &exit, int p) 
{ 

	// Stores minimum time to attend 
	// exactly one meeting 
	int ans = INT_MAX; 

	// Sort entrance[] array 
	sort(entrance.begin(), entrance.end()); 

	// Sort exit[] time 
	sort(exit.begin(), exit.end()); 

	// Traverse meeting[][] 
	for (int i = 0; i < n; i++) { 
		
		// Stores start time of 
		// current meeting 
		int u = meeting[i][0]; 
		
		// Stores end time of 
		// current meeting 
		int v = meeting[i][1]; 

		// Find just greater value of 
		// u in entrance[] 
		auto it1 
		= upper_bound(entrance.begin(), 
					entrance.end(), u); 

		// Find just greater or equal value 
		// of u in entrance[] 
		auto it2 
			= lower_bound(exit.begin(), 
						exit.end(), v); 

		// Stores enter time to attend 
		// the current meeting 
		int start = it1 
			- entrance.begin() - 1; 
				
				
		// Stores exist time after 
		// attending the meeting	 
		int end = it2 - exit.begin(); 

		// Update start lies in range [0, m -1] 
		// and end lies in the range [0, p - 1] 
		if (start >= 0 && start < m && 
						end >= 0 && end < p) 
							
			// Update ans			 
			ans = min(ans, 
				exit[end] - entrance[start]); 
	} 

	// Return answer 
	return ans >= INT_MAX ? -1 : ans; 
} 

// Driver Code 
int main() 
{ 

	// Stores interval of meeting 
	int meeting[][2] 
		= { { 15, 19 }, { 5, 10 }, { 7, 25 } }; 

	// Stores entrance timings 
	vector<int> entrance = { 4, 13, 25, 2 }; 

	// Stores exit timings 
	vector<int> exit = { 10, 25 }; 

	// Stores total count of meetings 
	int n = (sizeof(meeting)) 
			/ sizeof(meeting[0]); 

	// Stores total entrance timings 
	int m = entrance.size(); 

	// Stores total exit timings 
	int p = exit.size(); 

	// Minimum time 
	cout << minTime(meeting, n, entrance, 
							m, exit, p) 
		<< endl; 
	return 0; 
}
