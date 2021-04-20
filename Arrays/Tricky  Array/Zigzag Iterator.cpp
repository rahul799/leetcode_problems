

281. Zigzag Iterator
Medium

427

22

Add to List

Share
Given two 1d vectors, implement an iterator to return their elements alternately.

 

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6] 
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,3,2,4,5,6].
 

Follow up:

What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].


Yet to  understand 

https://medium.com/@rebeccahezhang/leetcode-281-zigzag-iterator-a5ee60dd20ea



class ZigzagIterator {
    using Iter = vector<int>::iterator;
    queue<pair<Iter, Iter>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end())
            q.emplace(v1.begin(), v1.end());
        if (v2.begin() != v2.end())
            q.emplace(v2.begin(), v2.end());
    }

    int next() {
        auto t = q.front(); q.pop();
        int val = *t.first;
        if (++t.first != t.second)
            q.emplace(t);
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};









