Implement a historical hash table following methods:



https://binarysearch.com/problems/Historical-Map/editorials/3076321



HistoricalMap() constructs a new instance of a historical map.
set(int key, int val, in timestamp) updates the key key with value val at time timestamp.
get(int key, int timestamp) retrieves the value that was associated with the key key at timestamp. If there is no key that was set at this time, then return -1.
Constraints

n ≤ 100,000 where n is the number of calls to get and set.
Example 1
Input
methods = ["constructor", "set", "set", "get", "get", "get"]
arguments = [[], [1, 10, 100], [1, 20, 200], [1, 0], [1, 110], [1, 200]]`
Output
[null, null, null, -1, 10, 20]
Explanation
h = HistoricalMap()
h.set(1, 10, 100) # key = 1, value = 10, time = 100
h.set(1, 20, 200) # key = 1, value = 20, time = 200
h.get(1, 0) == -1 # Key was not set at timestamp 0
h.get(1, 110) == 10 # At time 110, the key was set to value 10
h.get(1, 200) == 20 # At time 200, the key was overwritten to value 20




Intuition
we need store the values corresponding to the keys at a time stamp , if there is a key with the same timestamp we need to update the value for that timestamp.
so from this statement it is clear that we have to store the value of keys with time timestamp and and value on that timestamp so we will use a unordered_map for this part so we can have \mathcal{O}(1 )O(1) lookup for the key now we have to insert the value so we used a map here so that the values are stored in sorted order so that we can lookup for the value related to the time stamp in \mathcal{O}(\log n )O(logn)
as in a map the complexity of insertion and query is both \mathcal{O}(\log n )O(logn)
my English is very weak so sorry in case if you have any trouble understanding the solution

Implementation
a map store the element in the form of key value pair
m represents a unordered_map with key as the key in the question and it's value as a map<int,int> in which the map key represent's the timestamp and it's value represents the value corresponding to that timestamp

Time Complexity
\mathcal{O}(\log n )O(logn) for updation in map
\mathcal{O}(\log n )O(logn) for query as lower_bound is \mathcal{O}(\log n )O(logn) in map

Space Complexity
\mathcal{O}(n )O(n) as we are using linear space to store every querry

class HistoricalMap {
    public:
    unordered_map<int, map<int, int>> m;
    HistoricalMap() {
    }

    int get(int key, int timestamp) {
        map<int, int>& times = m[key];
        auto find = times.upper_bound(timestamp);
        if (find == times.begin()) return -1;
        return prev(find)->second;
    }

    void set(int key, int val, int timestamp) {
        m[key][timestamp] = val;
    }
};
