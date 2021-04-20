

Count of unique pairs (arr[i], arr[j]) such that i < j






https://www.geeksforgeeks.org/count-of-unique-pairs-arri-arrj-such-that-i-j/




Given an array arr[], the task is to print the count of unique pairs (arr[i], arr[j]) such that i < j.

Examples: 

Input: arr[] = {1, 2, 1, 4, 5, 2} 
Output: 11 
The possible pairs are (1, 2), (1, 1), (1, 4), (1, 5), (2, 1), (2, 4), (2, 5), (2, 2), (4, 5), (4, 2), (5, 2)

Input: arr[] = {1, 2, 3, 4} 
Output: 6 
The possible pairs are (1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4) 


Naive approach: The easiest way is to iterate through every possible pair and if it satisfies the condition, then add it to a set. Then, we can return the size of the 
set as our answer.





Time Complexity: O(n2) 


Efficient Approach: Every element arr[i] can form a pair with the element arr[j] if i < j. But (arr[i], arr[j]) should be unique therefore for every 
unique arr[i], possible pairs will be equal to the number of distinct numbers in the sub-array arr[i + 1], arr[i + 2], …, arr[n – 1]. So for every arr[i], we will
find the unique elements from right to left. For this task, it is easy to keep track of the elements visited by using a Hash Tablle. In this way, we will have unique
arr[i] for every unique arr[j]. Now, we will sum these values for every unique arr[i] which is the desired count of pairs.

Below is the implementation of the above approach: 

C++
filter_none
edit
play_arrow

brightness_4
// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;
 
// Function to return the count
// of unique pairs in the array
int getPairs(int a[], int n)
{
    set<int> visited1;
 
    // un[i] stores number of unique elements
    // from un[i + 1] to un[n - 1]
    int un[n] ;
 
    // Last element will have no unique elements
    // after it
    un[n - 1] = 0;
 
    // To count unique elements after every a[i]
    int count = 0;
     // auto pos = s.find(3); 
 
     // prints the set elements 
     // cout << "The set elements after 3 are: "; 
     // for (auto it = pos; it != s.end(); it++) 
    // cout << *it << " "
    for (int i = n - 1; i > 0; i--)
    {
 
        // If current element has already been used
        // i.e. not unique
        auto pos = visited1.find(a[i]); 
        if (pos != visited1.end())
            un[i - 1] = count;
        else
            un[i - 1] = ++count;
 
        // Set to true if a[i] is visited
        visited1.insert(a[i]);
    }
 
    set<int>visited2;
 
    // To know which a[i] is already visited
    int answer = 0;
    for (int i = 0; i < n - 1; i++) 
    {
 
        // If visited, then the pair would
        // not be unique
        auto pos = visited2.find(a[i]); 
        if (pos != visited2.end())
            continue;
 
        // Calculating total unqiue pairs
        answer += un[i];
 
        // Set to true if a[i] is visited
        visited2.insert(a[i]);
    }
    return answer;
}
 
// Driver code
int main()
{
    int a[] = { 1, 2, 2, 4, 2, 5, 3, 5 };
    int n = sizeof(a)/sizeof(a[0]);
 
    // Print the count of unique pairs
    cout<<(getPairs(a, n));
}


