



https://binarysearch.com/problems/Sum-of-Odd-Length-Medians


Sum of Odd Length Medians
Given a list of integers nums, return the sum of the medians of every odd-length sublist of the list.

Constraints

n ≤ 1,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 2]
Output
17
Explanation
Consider every sublist of odd length: [1], [3], [5], [2], [1, 3, 5], [3, 5, 2]

The sum of the medians is 1 + 3 + 5 + 2 + 3 + 3






Similar to 'Find Median in a Stream'.
Solve the question 'Find Median in a Stream' for all subarrays starting at index 0 \leq i < nums.length0≤i<nums.length.

Implementation
Use two heaps to solve the problem, one Min Heap and the other Max Heap as in the problem 'Median of a Stream'. These heaps are reinitialised for every 0 \leq i < nums.length0≤i<nums.length and then use for every i \leq j < nums.lengthi≤j<nums.length.

Time Complexity
There are total n^2n 
2
  subarrays and for each subarray we do insertion, delete and find max/min operations, which are all \log(n)log(n) operations. \mathcal{O}(n^2\log(n))O(n 
2
 log(n))

Space Complexity
At most nn elements will be stored in the heaps, so \mathcal{O}(n)O(n).

    
    
    int solve(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
        priority_queue<int> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;
        for (int j = i; j < nums.size(); j++) {
            maxq.push(nums[j]);
            while (maxq.size() - minq.size() >= 2) {
                minq.push(maxq.top());
                maxq.pop();
            }
            while (minq.size() && maxq.top() > minq.top()) {
                int a = maxq.top();
                maxq.pop();
                int b = minq.top();
                minq.pop();
                maxq.push(b);
                minq.push(a);
            }
            if (i % 2 == j % 2) {
                ret += maxq.top();
            }
        }
    }
    return ret;
}



int solve(vector<int>& nums) {
    int sz = nums.size(), res = 0;

    for (int i = 0; i < sz; ++i) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int j = i; j < sz; ++j) {
            minHeap.push(nums[j]);
            maxHeap.push(minHeap.top());
            minHeap.pop();

            if ((int)maxHeap.size() > (int)minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            if ((j - i + 1) % 2) res += minHeap.top();
        }
    }

    return res;
}
