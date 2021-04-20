

493. Reverse Pairs
Hard

1203

135

Add to List

Share
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.



class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int s, int e) {
        if(s>=e)return 0;
        int mid = s + (e - s)/2;
        int cnt = mergeSort(nums, s, mid) + mergeSort(nums, mid + 1, e);
        for(int i = s,j = mid + 1;i <= mid;i++) {
            while(j<=e && nums[i] > long(nums[j]) * 2)j++;
            cnt += j - (mid + 1);
        }
        sort(nums.begin() + s, nums.begin() + e + 1);
        return cnt;
    }
};






Approach 1: Brute Force
Intuition

Do as directed in the question. We can simply check all the pairs if they are important reverse pairs or not.

Algorithm

Iterate over ii from 00 to \text{size} - 1size−1
Iterate over jj from 00 to i - 1i−1
If \text{nums[j]} > 2 * \text{nums[i]}nums[j]>2∗nums[i], increment \text{count}count

Complexity Analysis

Time complexity: O(n^2)O(n 
2
 )

We iterate over all the possible pairs wherein (i<ji<j) in the array which is O(n^2)O(n 
2
 )
Space complexity: O(1)O(1) only constant extra space is required for nn, countcount etc.

Trivia

The above code can be expressed as one-liner in Python:


Herein, we iterate over all the pairs and store the boolean values for \text{nums[i]}>2*\text{nums[j]}nums[i]>2∗nums[j]. Finally, we count the number of \text{true}true in the array and return the result.


Approach 2: Binary Search Tree
Intuition

In Approach 1, for each element ii, we searched the subarray [0,i)[0,i) for elements such that their value is greater than 2*\text{nums[i]}2∗nums[i]. In the previous approach, the search is linear. However, we need to make the process efficient. Maybe, memoization can help, but since, we need to compare the elements, we cannot find a linear DP solution.

Observe that the indices of the elements in subarray [0,i)[0,i) don't matter as we only require the count. So, we can sort the elements and perform binary search on the subarray. But, since the subarray keeps growing as we iterate to the next element, we need a data structure to store the previous result as well as to allow efficient searching(preferably O(\log n)O(logn)) - Binary Search Tree(BST) could be a good bet.

Refreshing BST

BST is a rooted binary tree, wherein each node is associated with a value and has 2 distinguishable sub-trees namely leftleft and rightright subtree. The left subtree contains only the nodes with lower values than the parent's value, while the right subtree conatins only the nodes with greater values than the parent's value.

Voila!

This is exactly what is required. So, if we store our elements in BST, then we can search the larger elements thus eliminating the search on smaller elements altogether.

Algorithm

Define the \text{Node}Node of BST that stores the \text{val}val and pointers to the \text{left}left and \text{right}right. We also need a count of elements(say \text{count\_ge}count_ge) in the subtree rooted at the current node that are greater than or equal to the current node's \text{val}val. \text{count\_ge}count_ge is initialized to 1 for each node and \text{left}left, \text{right}right pointers are set to \text{NULL}NULL.

We define the \text{insert}insert routine that recursively adds the given \text{val}val as an appropriate leaf node based on comparisons with the Node.valNode.val. Each time, the given valval is smaller than Node.valNode.val, we increment the \text{count\_ge}count_ge and move the valval to the right subtree. While, if the valval is equal to the current NodeNode, we simply increment the \text{count\_ge}count_ge and exit. While, we move to the left subtree in case (\text{val}<\text{Node.val})(val<Node.val).

We also require the searchsearch routine that gives the count of number of elements greater than or equal to the \text{target}target. In the \text{search}search routine, if the headhead is NULL, return 0. Otherwise, if \text{target}==\text{head.val}target==head.val, we know the count of values greater than or equal to the \text{target}target, hence simply return \text{head.count\_ge}head.count_ge. In case, \text{target}<\text{head.val}target<head.val, the ans is calculated by adding \text{Node.count\_ge}Node.count_ge and recursively calling the \text{search}search routine with \text{head.left}head.left. And if \text{target}>\text{head.val}target>head.val, ans is obtained by recursively calling the \text{search}search routine with \text{head.right}head.right.

Now, we can get to our main logic:

Iterate over ii from 00 to (size-1)(size−1) of \text{nums}nums :
Search the existing BST for \text{nums[i]} * 2 + 1nums[i]∗2+1 and add the result to \text{count}count
Insert \text{nums[i]}nums[i] to the BST, hence updating the \text{count\_ge}count_ge of the previous nodes
Current
1 / 15

Complexity analysis

Time complexity: O(n^2)O(n 
2
 )
The best case complexity for BST is O(\log n)O(logn) for search as well as insertion, wherein, the tree formed is complete binary tree
Whereas, in case like [1,2,3,4,5,6,7,8,...], insertion as well as search for an element becomes O(n)O(n) in time, since, the tree is skewed in only one direction, and hence, is no better than the array
So, in worst case, for searching and insertion over n items, the complexity is O(n*n)O(n∗n)
Space complexity: O(n)O(n) extra space for storing the BST in \text{Node}Node class.

Approach 3: BIT
Intuition

The problem with BST is that the tree can be skewed hence, making it O(n^2)O(n 
2
 ) in complexity. So, need a data structure that remains balanced. We could either use a Red-black or AVL tree to make a balanced BST, but the implementation would be an overkill for the solution. We can use BIT (Binary Indexed Tree, also called Fenwick Tree) to ensure that the complexity is O(n\log n)O(nlogn) with only 12-15 lines of code.

BIT Overview:

Fenwick Tree or BIT provides a way to represent an array of numbers in an array(can be visualized as tree), allowing prefix/suffix sums to be calculated efficiently(O(\log n)O(logn)). BIT allows to update an element in O(\log n)O(logn) time.

We recommend having a look at BIT from the following link before getting into details:

https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
So, BIT is very useful to accumulate information from front/back and hence, we can use it in the same way we used BST to get the count of elements that are greater than or equal to 2 * \text{nums[i]} + 12∗nums[i]+1 in the existing tree and then adding the current element to the tree.

Algorithm

First, lets review the BIT \text{query}query and \text{update}update routines of BIT. According to the convention, \text{query}query routine goes from \text{index}index to 00, i.e., \text{BIT[i]}BIT[i] gives the sum for the range [0,index][0,index], and \text{update}update updates the values from current \text{index}index to the end of array. But, since, we require to find the numbers greater than the given index, as and when we update an index, we update all the ancestors of the node in the tree, and for \text{search}search, we go from the node to the end.

The modified \text{update}update algorithm is:

update(BIT, index, val):
  while(index > 0):
    BIT[index] += val
    index -= (index & (-index))
Herein, we find get the next index using: \text{index -= index \& (-index)}index -= index & (-index), which is essentially subtracting the rightmost 1 from the \text{index}index binary representation. We update the previous indices since, if an element is greater than the index

And the modified \text{query}query algorithm is:

query(BIT,index):
  sum=0
  while(index<BIT.size):
    sum+=BIT[index]
    index+=(index&(-index))
Herein, we find get the next index using: \text{index += index \& (-index)}index += index & (-index). This gives the suffix sum from indexindex to the end.

So, the main idea is to count the number of elements greater than 2*\text{nums[i]}2∗nums[i] in range [0,i)[0,i) as we iterate from 00 to \text{size-1}size-1. The steps are as follows:


Complexity analysis

Time complexity: O(n\log n)O(nlogn)
In \text{query}query and \text{update}update operations, we see that the loop iterates at most the number of bits in \text{index}index which can be at most nn. Hence, the complexity of both the operations is O(\log n)O(logn)(Number of bits in nn is \log nlogn)
The in-built operation \text{lower\_bound}lower_bound is binary search hence O(\log n)O(logn)
We perform the operations for nn elements, hence the total complexity is O(n\log n)O(nlogn)
Space complexity: O(n)O(n). Additional space for \text{BITS}BITS array

Approach 4: Modified Merge Sort
Intuition

In BIT and BST, we iterate over the array, dividing the array into 3 sections: already visited and hence added to the tree, current node and section to be visited. Another approach could be divide the problem into smaller subproblems, solving them and combining these problems to get the final result - Divide and conquer. We see that the problem has a great resemblance to the merge sort routine. The question is to find the inversions such that \text{nums[i]}>2 * \text{nums[j]}nums[i]>2∗nums[j] and i<ji<j. So, we can easily modify the merge sort to count the inversions as required.

Mergesort

Mergesort is a divide-and-conquer based sorting technique that operates in O(n\log n)O(nlogn) time. The basic idea to divide the array into several sub-arrays until each sub-array is single element long and merging these sublists recursively that results in the final sorted array.

Algorithm


dex

Complexity analysis

Time complexity: O(n\log n)O(nlogn)

In each step we divide the array into 2 sub-arrays, and hence, the maximum times we need to divide is equal to O(\log n)O(logn)
Additional O(n)O(n) work needs to be done to count the inversions and to merge the 2 sub-arrays after sorting. Hence total time complexity is O(n\log n)O(nlogn)
Space complexity: O(n)O(n). Additional space for storing LL and RR arrays
