


https://binarysearch.com/problems/Delete-Integers-In-Ascending-Order?



Delete Integers In Ascending Order
You are given a list of unique integers nums and want to delete each number in ascending order.

Return the indices of numbers in order of their deletion.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [3, 5, 1, 4, 2]
Output
[2, 3, 0, 1, 0]
Explanation
We delete the numbers in this order:

Delete 1 at index 2 and now we have [3, 5, 4, 2]
Delete 2 at index 3 and now we have [3, 5, 4]
Delete 3 at index 0 and now we have [5, 4]
Delete 4 at index 1 and now we have [5]
Delete 5 at index 0 and now we have [



The first part of the code is a "textbook" Fenwick tree implementation. Supposing that we are (conceptually) maintaining an array of length n, the function 
update(i, n, amount) adds amount to the ith slot, and query(i,j) calculates the sum of the 
elements in the interval [i,j).





To solve the actual problem, we just need to figure out in which order the elements are deleted, which we do with a sort; then we repeatedly calculate the index of 
each deleted element, and update the Fenwick tree to reflect the "deletion".

Time Complexity

struct FenwickTree{
    int N;
    vector<int> bit;
    FenwickTree(int n){
        N = n;
        bit.resize(N+1, 0);
    }
    void add(int idx, int x){
        for (; idx <= N; idx += idx&(-idx)) bit[idx] += x;
    }
    int get(int idx){
        int sum = 0;
        for (; idx > 0; idx -= idx&(-idx)) sum += bit[idx];
        return sum;
    }
};

vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    map<int, int > idx;
    for (int i = 0 ; i < n; i++){
        idx[nums[i]] = i + 1; 
    }
    vector<int > ans;
    FenwickTree ft(n+1);
    for (auto x : idx){
        int val = x.second;
        ans.push_back(val - 1 - ft.get(val-1));
        ft.add(val, 1);
    }
    return ans;

}
