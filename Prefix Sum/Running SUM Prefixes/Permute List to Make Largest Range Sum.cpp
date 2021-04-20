Permute List to Make Largest Range Sum
You are given a list of integers nums and a two-dimensional list of integers ranges. Each element in ranges contains [i, j], meaning to sum the numbers in nums between i to j inclusive.

Given that you can first permute nums in any order, return the maximum possible total of all range sums. Return the result mod 10 ** 9 + 7.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
0 ≤ m ≤ 100,000 where m is the length of ranges
Example 1
Input
nums = [1, 2, 3, 4, 5, 6]
ranges = [
    [0, 1],
    [1, 3]
]
Output
24
Explanation
If we permute the list to [5,6,4,3,2,1] then [5, 6] sums to 11 and [6, 4, 3] sums to 13.



here we want the total sum of all the query

what the question allows us to do before all the queries is generate a permutation according to the queries
so what we do is we put the maximum element on the index which is included in most of the range calls and do the same for all the remaining element's accordingly
but how do we get the index with the maximum frequency
a. if we do the brute force that is for total of m queries and reach has a range r (start to end) than in the worst case the complexity will be
10^5 * 10^510 
5
 ∗10 
5
  which will definitely TLE
b. so what we do is manipulate prefix sum's in a different way ( explained in example)
Implementation
here frequency_of_index represents the frequency of each index
for each range query
we add +1 from start of the range to the last of the array and subtract -1 from the range end  to the last of the array.
now we just calculate the total frequency of each index
now we sort bot the nums and the frequency_of_index and map each of them accordingly and add it in our answer
one last thing since the product is larger we take the mod.
Example #1
how does the prefix running sum works
when we want to increase the frequency of the range ii to jj we do
frequency_of_index[i] += 1 and frequency_of_index[j + 1] -= 1
what does it. represents ->
showing the condition whe frequency of each index is 0
[0,1,2.., i,   i+1,  i+2,   i+3, ,...., j-1,  j, j+1,..............., n-1, n]
         +1,   +1,   +1,     +1,  +1................................,+1,  +1]
                                                 -1, -1, -1, ...............]
which finally in the end result's to

[0,1,2,......i,............j,j+1,.............n-2,n-1] (indexes)
[0,0,0,..0,0,1,1,1.........1,0  ,.................]

Example #2
simulating how the code works.

let the size of array is 55.
initially the frequency_of_index array looks like [0,0,0,0,0]
suppose we have range calls like [[0,2], [1,4], [3,3]]
so what we do is
initailly the array is     [ 0,  0,  0,  0,    0 ]
after first call            +1          -1        
after second call            +1                 
after last call                         +1    -1        
now when we calculate the prefix running sum it's look's like
[ 1, 2, 2, 2, 1]
Time Complexity
\mathcal{O}(n \cdot \log n)O(n⋅logn) for sorting the array's

Space Complexity
\mathcal{O}(n)O(n) since linear space is used for maintaining the prefix frequency array





int solve(vector<int>& nums, vector<vector<int>>& ranges) {
    int n = nums.size(), ans = 0;
    vector<int> frequency_of_index(n, 0);
    for (vector<int>& range : ranges) {
        int start = range[0];
        int end = range[1] + 1;
        frequency_of_index[start] += 1;
        if (end != n) frequency_of_index[end] -= 1;
    }
    for (int i = 1; i < n; i++) frequency_of_index[i] += frequency_of_index[i - 1];
    sort(frequency_of_index.begin(), frequency_of_index.end());
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--) {
        ans = (ans + frequency_of_index[i] * nums[i]) % (1000000007);
    }
    return ans;
}

