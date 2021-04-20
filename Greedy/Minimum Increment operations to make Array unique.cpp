
Minimum Increment operations to make Array unique



https://www.geeksforgeeks.org/minimum-increment-operations-to-make-array-unique/



Given an array A[] of integers. In one move you can choose any element A[i], and increment it by 1. The task is to return the minimum number of moves needed 
to make every value in the array
A[] unique.


// C++ Implementation of above approach
#include <bits/stdc++.h>

using namespace std;

// function to find minimum increment required
int minIncrementForUnique(vector<int> A)
{

	// collect frequency of each element
	unordered_map<int, int> mpp;

	for(int i:A) mpp[i]++;

	// taken is to keep count 
	// of duplicate items
	int taken=0, ans=0;

	for (int x = 0; x < 100000; x++)
	{
		
		// If number is present 
		// multiple times
		if (mpp[x] >= 2){
		taken += mpp[x]-1;
		ans -= x*(mpp[x]-1);
		}
		
		// If there is no x in the array
		else if(taken > 0 and mpp[x] == 0)
		{
			ans += x;
			taken--;
		}
	}

	// return answer
	return ans;
}

// Driver code
int main()
{
	vector<int> A = {3, 2, 1, 2, 1, 7};
	
	// Function Call
	cout << minIncrementForUnique(A);
	
	return 0;
}

// This code is contributed by mohit kumar 29
