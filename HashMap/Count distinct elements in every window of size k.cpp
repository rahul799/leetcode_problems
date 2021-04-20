Count distinct elements in every window of size k
Last Updated: 27-06-2020
Given an array of size n and an integer k, return the count of distinct numbers in all windows of size k.
Example:

Input: arr[] = {1, 2, 1, 3, 4, 2, 3};
       k = 4
Output: 3 4 4 3

Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3

Input: arr[] = {1, 2, 4, 4};
       k = 2
Output: 2 2 1

Explanation:
First window is {1, 2}, count of distinct numbers is 2
First window is {2, 4}, count of distinct numbers is 2
First window is {4, 4}, count of distinct numbers is 1



Algorithm:
1. Create an empty hash map. Let the hash map be hM.
2. Initialize the count of distinct element as dist_count to 0.
3. Traverse through the first window and insert elements of the first window to hM. The elements are used as key and their counts as the value in hM. Also, keep updating dist_count

Traverse through the remaining array (or other windows).
Remove the first element of the previous window.
If the removed element appeared only once, remove it from hM and decrease the distinct count, i.e. do “dist_count–“
else (appeared multiple times in hM), then decrement its count in hM
Add the current element (last element of the new window)
If the added element is not present in hM, add it to hM and increase the distinct count, i.e. do “dist_count++”
Else (the added element appeared multiple times), increment its count in hM








// An efficient C++ program to 
// count distinct elements in 
// every window of size k 
#include <iostream> 
#include <map> 
using namespace std; 

void countDistinct(int arr[], int k, int n) 
{ 
	// Creates an empty hashmap hm 
	map<int, int> hm; 

	// initialize distinct element count for current window 
	int dist_count = 0; 

	// Traverse the first window and store count 
	// of every element in hash map 
	for (int i = 0; i < k; i++) { 
		if (hm[arr[i]] == 0) { 
			dist_count++; 
		} 
		hm[arr[i]] += 1; 
	} 

	// Print count of first window 
	cout << dist_count << endl; 

	// Traverse through the remaining array 
	for (int i = k; i < n; i++) { 
		// Remove first element of previous window 
		// If there was only one occurrence, then reduce distinct count. 
		if (hm[arr[i - k]] == 1) { 
			dist_count--; 
		} 
		// reduce count of the removed element 
		hm[arr[i - k]] -= 1; 

		// Add new element of current window 
		// If this element appears first time, 
		// increment distinct element count 

		if (hm[arr[i]] == 0) { 
			dist_count++; 
		} 
		hm[arr[i]] += 1; 

		// Print count of current window 
		cout << dist_count << endl; 
	} 
} 

int main() 
{ 
	int arr[] = { 1, 2, 1, 3, 4, 2, 3 }; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	int k = 4; 
	countDistinct(arr, k, size); 

	return 0; 
} 
// This solution is contributed by Aditya Goel 

vector<int> solve(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) {
        mp[nums[i]]++;
    }
    vector<int> vec;
    vec.push_back(mp.size());
    int p = 0, n = nums.size();
    mp[nums[p]]--;
    if (mp[nums[p]] == 0) {
        mp.erase(nums[p]);
    }
    p = 1;
    for (int i = k; i < n; i++) {
        mp[nums[i]]++;
        vec.push_back(mp.size());
        mp[nums[p]]--;
        if (mp[nums[p]] == 0) mp.erase(nums[p]);
        p++;
    }
    return vec;
}


