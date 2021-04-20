




Remove Smallest Peaks in Order
You are given a list of unique integers nums. Return a new list created by repeatedly removing the smallest peak from nums and appending to a resulting list. A number nums[i] is called a peak if

nums[i] > nums[i + 1] if i = 0
nums[i - 1] < nums[i] if i = n - 1
nums[i - 1] < nums[i] > nums[i + 1] otherwise
If a list has one element, then that element is considered to be a peak.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [3, 5, 1, 4, 2]
Output
[4, 2, 5, 3, 1]
Explanation
We remove 4 and get [3, 5, 1, 2]
We remove 2 and get [3, 5, 1]
We remove 5 and get [3, 1]
We remove 3 and get [1]
We remove 1 and get []
Example 2
Input
nums = [5, 6, 7]
Output
[7, 6, 5]
Explanation
We remove 7 and get [5, 6]
We remove 6 and get [5]
We remove 5 and get []
Example 3
Input
nums = [3, 2, 1]
Output
[3, 2, 1]











Find all peaks. Remove each peak, check adjacent elements and add them in case they are the new peaks.

Implementation
This approach uses sets and doesn't need a priority queue.

Since deleting elements from the middle of a vector is expensive, we can save the available indices in a set and find the previous and next available ones.

Have a set dedicated to peaks. Initially traverse array and identify all peaks - store that in a set (default sorted in increasing order of value). Then, pick each peak, add it to return vector. Check adjacent elements. If there is an element before and after that adjacent element, then see if this element could become a peak. If so, add it to set and repeat.

Time Complexity
\mathcal{O}(n \log n )O(nlogn)Main loop goes through each element, insertion and accessing set is O(log n)

Space Complexity
\mathcal{O}(n)O(n) Maps, sets and the return array - which hold n elements at most







vector<int> solve(vector<int>& a) {
    set<int> ind;                // Available indices
    set<int> s;                  // Sorted peaks
    unordered_map<int, int> mp;  // Map[value] = index
    int i, n = a.size();
    for (i = 0; i < n; i++) {
        ind.insert(i);
        mp[a[i]] = i;
        bool good = true;
        if (i && a[i - 1] > a[i]) good = false;
        if (i < n - 1 && a[i] < a[i + 1]) good = false;
        if (good) s.insert(a[i]);
    }
    vector<int> ret;
    for (i = 0; i < n; i++) {
        int x = *s.begin(), k = mp[x], before = -1, nxt = -1;
        auto cur = ind.lower_bound(k);
        if (cur != ind.begin()) before = *(prev(cur));
        if (next(cur) != ind.end()) nxt = *(next(cur));
        s.erase(x);
        ind.erase(cur);
        ret.push_back(x);
        if (before > -1 && nxt > -1) {
            if (a[before] > a[nxt]) {
                auto bb = ind.lower_bound(before);
                if (bb == ind.begin() || a[*prev(bb)] < a[before]) s.insert(a[before]);
            } else {
                auto nn = ind.upper_bound(nxt);
                if (nn == ind.end() || a[*nn] < a[nxt]) s.insert(a[nxt]);
            }
        } else if (before > -1) {
            auto bb = ind.lower_bound(before);
            if (bb == ind.begin() || a[*prev(bb)] < a[before]) s.insert(a[before]);
        } else if (nxt > -1) {
            auto nn = ind.upper_bound(nxt);
            if (nn == ind.end() || a[*nn] < a[nxt]) s.insert(a[nxt]);
        }
    }
    return ret;
}




