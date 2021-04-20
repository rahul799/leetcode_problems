


https://binarysearch.com/problems/Maximum-Stack

Maximum Stack
Implement a maximum stack with the following methods:

MaximumStack() constructs a new instance of a maximum stack
append(int val) appends val to the stack
peek() retrieves the last element in the stack
max() retrieves the maximum value in the stack
pop() pops and returns the last element in the stack
popmax() pops and returns the last occurrence of the maximum value in the stack
You can assume that for peek, max, pop and popmax, the stack is non-empty when they are called.

Constraints

n ≤ 100,000 where n is the number of methods that will be called.
Example 1
Input
methods = ["constructor", "append", "append", "append", "peek", "max", "popmax", "max", "pop", "peek"]
arguments = [[], [1], [3], [2], [], [], [], [], [], []]`
Output
[null, null, null, null, 2, 3, 3, 2, 2, 1]
Explanation
We create a MaximumStack
Append 1 to the stack
Append 3 to the stack
Append 2 to the stack
Peek the top element which is 2
Max value of the stack so far is max(1, 3, 2) == 3
We pop the max value of 3
Max value of the stack is now max(1, 2) == 2
We pop the top element which is 2
Peek the top element which is now 1





Use two sets and keep an increasing id. One is used to store [id, val] pairs, while the other is used to store [val, id] pairs. For pop(), we pop from the first set
the pair with maximum id, get its value, and then erase the corresponding pair in the second set. For popmax(), we pop from the second set the pair with maximum value,
get its id, and then erase the corresponding pair in the first set.

Time complexity is O(\log N)O(logN) for append(), pop() and popmax(), and is O(1)O(1) for peek() and max().





class MaximumStack {
    int idx = 0;
    set<pair<int, int>, greater<>> st, aux;

    public:
    MaximumStack() {
    }

    void append(int val) {
        st.emplace(idx, val);
        aux.emplace(val, idx);
        idx++;
    }

    int peek() {
        if (st.empty()) return -1;
        return st.begin()->second;
    }

    int max() {
        if (aux.empty()) return -1;
        return aux.begin()->first;
    }

    int pop() {
        if (st.empty()) return -1;
        int id = st.begin()->first, ret = st.begin()->second;
        st.erase(st.begin());
        aux.erase({ret, id});
        return ret;
    }

    int popmax() {
        if (aux.empty()) return -1;
        int ret = aux.begin()->first, id = aux.begin()->second;
        aux.erase(aux.begin());
        st.erase({id, ret});
        return ret;
    }
};
