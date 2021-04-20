


https://binarysearch.com/problems/Number-of-Swaps-to-Sort/editorials/2886346



Number of Swaps to Sort
Given a list of unique integers nums, return the minimum number of swaps needed to sort the list in ascending order.

Constraints

n ≤ 100,000 where n is length of nums.
Example 1
Input
nums = [3, 2, 1, 4]
Output
1
Explanation
We can swap 3 and 1.



Intuition
The idea is pretty simple. In order to find the minimum no of swaps, first sort the array itself and parallely store the indices of the original unsorted array as well. Once you have the sorted array along with the original indices, try to reach the original array order by making swaps and simultaneously count the number of swaps you had to make to get back the original array.

The sole reason you need to store and sort the array along with the indices is to essentially store the original order of the array in the indices so that you don't lose the ordering information completely after sorting.

Time Complexity: \mathcal{O}(n*log(n))O(n∗log(n))
Space Complexity: \mathcal{O}(n)O(n)

int solve(vector<int>& nums) {
    int i, n, index;
    int swaps = 0;

    n = nums.size();  // Get the array size

    vector<pair<int, int> > arr;
    // Store the array in the form of pairs(no,index) i.e store the index
    // along with the no.
    for (i = 0; i < n; i++) arr.push_back(make_pair(nums[i], i));

    // Sort the paired array according to no.
    sort(arr.begin(), arr.end());

    // Iterate over the indices
    for (i = 0; i < n; i++) {
        // While the current ith pair's index (arr[i].second) is not equal to i,
        // swap arr[i] and arr[arr[i].second]
        while (arr[i].second != i) {
            index = arr[i].second;
            swap(arr[i], arr[index]);
            swaps++;
        }
    }
    return swaps;
}






Approach 2:



Intuition
It is obvious that we should sort the array first. Then we will have matches and mismatches. How will we deal with the mismatches?

Implementation
We can use DSU to deal with the mismatches. For each mismatching pair, we add an edge to the DSU. In the end, we will count the number of connected components in the DSU, and the answer will be n-mn−m where mm is the number of CC.

Why does this work? Actually, each CC is exactly a cycle in this problem. And a cycle with kk elements will require k-1k−1 swaps.

Time Complexity
\mathcal{O}(n\log(n))O(nlog(n)) since we need to sort the array first.

Space Complexity
\mathcal{O}(n)O(n) since both the sorted array and the DSU take up \mathcal{O}(n)O(n) space.

struct UnionFind {
    int n;
    vector<int> parent, size;
    UnionFind(int n) {
        this->n = n;
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }

    void connect(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            if (size[fa] > size[fb]) {
                parent[fb] = fa;
                size[fa] += size[fb];
            } else {
                parent[fa] = fb;
                size[fb] += size[fa];
            }
            n--;
        }
    }
};

int solve(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) v.emplace_back(nums[i], i);
    sort(v.begin(), v.end());
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) uf.connect(v[i].second, i);
    return n - uf.n;
}
