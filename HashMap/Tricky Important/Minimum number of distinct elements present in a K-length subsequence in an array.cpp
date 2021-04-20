


Minimum number of distinct elements present in a K-length subsequence in an array



Minimum number of distinct elements present in a K-length subsequence in an array
Last Updated : 17 Mar, 2021
Given an array A[] consisting of N integers and an integer K, the task is to count the minimum number of distinct elements present in a subsequence of length K of the given array, A.

Examples:

Input: A = {3, 1, 3, 2, 3, 4, 5, 4}, K = 4
Output: 2
Explanation: The subsequence of length 4 containing minimum number of distinct elements is {3, 3, 3, 4}, consisting of 2 distinct elements, i.e. {3, 4}.

Input: A = {3, 1, 3, 2, 3, 4, 5, 4}, K = 5
Output: 2
Explanation: The subsequence of length 5 containing minimum number of distinct elements is {3, 3, 3, 4, 4}, consisting of 2 distinct elements, i.e. {3, 4}.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The simplest approach is to generate all subsequences of length K and for each subsequence, find the number of distinct elements present in them. Finally, print the minimum number of distinct elements present.
Time Complexity: O(K * NK)
Auxiliary Space: O(N)

Efficient Approach: The above approach can be optimized using Hashing. Follow the steps below to solve the problem:



Store the frequencies of all elements in the given array, A[] in a HashMap, say M.
Traverse the hashmap, M and push the frequencies in another array, say V.
Sort the array V in decreasing order.
Initialize two variables, cnt and len as 0, to store the required result and the length of the subsequence thus formed.
Traverse the array V[] using a variable, say i
If the value of len ≥ K, then break out of the loop.
Otherwise, increment the value of len by V[i] and cnt by 1.
After completing the above steps, print the value of cnt as the result.
Below is the implementation of the above approach:

C++

// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to count the minimum number 
// of distinct elements present in any 
// subsequence of length K of the given array 
void findMinimumDistinct(int A[], int N, int K) 
{ 
  
    // Stores the frequency 
    // of each array element 
    unordered_map<int, int> mp; 
  
    // Traverse the array 
    for (int i = 0; i < N; i++) 
  
        // Update frequency 
        // of array elements 
        mp[A[i]]++; 
  
    // Store the required result 
    int count = 0; 
  
    // Store the length of the 
    // required subsequence 
    int len = 0; 
  
    // Store the frequencies 
    // in decreasing order 
    vector<int> counts; 
  
    // Travere the map 
    for (auto i : mp) 
  
        // Push the frequencies 
        // into the HashMap 
        counts.push_back(i.second); 
  
    // Sort the array in decreasing order 
    sort(counts.begin(), counts.end(), 
         greater<int>()); 
  
    // Add the elements into the subsequence 
    // starting from one with highest frequency 
    for (int i = 0; i < counts.size(); i++) { 
  
        // If length of subsequence is >= k 
        if (len >= K) 
            break; 
        len += counts[i]; 
        count++; 
    } 
  
    // Print the result 
    cout << count; 
} 
  
// Driver Code 
int main() 
{ 
    int A[] = { 3, 1, 3, 2, 3, 4, 5, 4 }; 
    int K = 4; 
  
    // Store the size of the array 
    int N = sizeof(A) / sizeof(A[0]); 
  
    // Function Call to count minimum 
    // number of distinct elmeents 
    // present in a K-length subsequence 
    findMinimumDistinct(A, N, K); 
  
    return 0; 
}
