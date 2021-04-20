Merging K Sorted Lists
Question 164 of 978
Given a list of sorted lists of integers, merge them into one large sorted list.





The general approach would be to push() all the elements in the heap and pop() until its empty.

This would take O( kn log kn)

Why log kn ? Because we are inserting all the elements in the heap together. (We consider in worst case there can be kn elements.)

Now can we reduce the time complexity from O(kn log kn) to O(kn log k) ?

Yes ,

We can use approach similar to TWO POINTER method , in this case ( n -Pointer Method ) . Create an array of pointers and point it to the 0th element of each array. We put all the 0th elements of the lists in the heap.

We then pop from the heap (min heap) and put it to the ans array. Now the element which is popped we will increase the pointer of that array and push into the heap that element belonging to the corresponding pointer.

Now , this method will take O(kn log k).

Why kn ?
Because at most there can be kn elements. we will push and pop kn elements .

Why log k ?
Because to push and pop every element we now need log k because the max size of the heap will be now k . This is because there are k sorted arrays and at any time there can at most be k elements in the heap.





Constraints

0 ≤ n * m ≤ 100,000 where n and m are the number of rows and columns in lists
Example 1
Input
lists = [
    [],
    [],
    [10, 12],
    [],
    [3, 3, 13],
    [3],
    [10],
    [0, 7]
]
Output
[0, 3, 3, 3, 7, 10, 10, 12, 13]




vector<int> solve(vector<vector<int>>& lists) {
    priority_queue<pii, vector<pii>, greater<pii>> heap;

    int n = lists.size();
    vector<int> ans;

    vector<int> ptr(n, 0);

    for (int i = 0; i < lists.size(); i++) {
        if (ptr[i] < lists[i].size()) {
            heap.push(make_pair(lists[i][ptr[i]], i));
        }
    }

    while (!heap.empty()) {
        ans.push_back(heap.top().first);
        int idx = heap.top().second;
        heap.pop();

        if (++ptr[idx] < lists[idx].size()) heap.push(make_pair(lists[idx][ptr[idx]], idx));
    }
    return ans;
}
