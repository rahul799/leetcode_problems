


Kth Largest Numbers From Stream
Implement a data structure with the following methods:

KthLargestStream(int[] nums, int k) which constructs the instance.
int add(int val) which adds val to nums and returns the k (0-indexed) largest value in nums
Constraints

1 ≤ n ≤ 100,000 where n is the length of nums
0 ≤ m ≤ 100,000 where m is the number of calls to add
Example 1
Input
methods = ["constructor", "add", "add", "add", "add"]
arguments = [[[1, 2, 4, 3], 3], [5], [6], [7], [8]]`
Output
[null, 2, 3, 4, 5]
Explanation
s = KthLargestStream([1,2,4,3],3)
s.add(5) == 2 # Stream has [1, 2, 3, 4, 5]
s.add(6) == 3 # Stream has [1, 2, 3, 4, 5, 6]
s.add(7) == 4 # Stream has [1, 2, 3, 4, 5, 6, 7]
s.add(8) == 5 # Stream has [1, 2, 3, 4, 5, 6, 7, 8



Intuition
Since the add function will be called several times, we need a quick way to return the k^{th}k 
th
  largest element. A heap, specifically a min-heap would work well for the following reasons:

It has a \mathcal{O}(\log n )O(logn) complexity for insertions and \mathcal{O}(1)O(1) for extracting the minimum element (ignoring the rebalancing that happens)

If we only store PP elements, the P^{th}P 
th
  largest element will be at the top of the heap

Thus, we use a min-heap and keep its capacity at k + 1. Why k + 1 and not k? The question says that k is based on a zero index, so we have to have one more element to get the k^{th}k 
th
  largest element

Any time the capacity of the heap exceeds k + 1, we pop an element from the heap and thereby update the new k^{th}k 
th
  largest element

Implementation
The constructor initializes the min-heap with k + 1 largest elements from the input array
The add method first inserts the new val into the heap, and then if the heaps capacity exceeds k + 1, we pop the heap to bring it back to size
The top of the heap is the k^{th}k 
th
  largest element which can be returned
Time Complexity
\mathcal{O}(N \times \log k )O(N×logk) for the construction where NN is the number of elements in the input array
\mathcal{O}(\log k)O(logk) for the add function since the new value needs to be inserted into the heap before we return the k^{th}k 
th
  largest element
Space Complexity
\mathcal{O}(\log k )O(logk) since we store k+1 elements in the heap

class KthLargestStream {
    public:
    KthLargestStream(vector<int>& nums, int k) {
        K = k + 1;
        for (auto& num : nums) {
            pq.push(num);
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }

        return pq.top();
    }

    private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
};
