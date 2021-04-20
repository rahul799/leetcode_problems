

Last Value Map


Implement a data structure LastValueMap which has the following methods:

void set(int key, int value) which associates key with value.
void remove(int key) which removes key and its associated value.
int getLast() which returns the value of the last added key. If a key is updated with a value, it should become last. You can assume that there is always a last value.
Constraints

0 ≤ n ≤ 200,000 where n is the number of method calls
Example 1
Input
methods = ["constructor", "set", "set", "getLast", "set", "getLast", "remove", "getLast"]
arguments = [[], [1, 2], [2, 3], [], [1, 9], [], [1], []]`
Output
[null, null, null, 3, null, 9, null, 3]
Explanation
x = LastValueMap()
x.set(1, 2)
x.set(2, 3)
x.getLast() == 3
x.set(1, 9)
x.getLast() == 9
x.remove(1)
x.getLast() == 3



class LastValueMap {
    public:
    stack<int> q;

    unordered_map<int, int> mp;
    LastValueMap() {
    }

    void set(int key, int value) {
        q.push(key);
        mp[key] = value;
    }

    void remove(int key) {
        mp.erase(key);
    }

    int getLast() {
    // there may be chances I have removed that key from my stack
        while (mp.find(q.top()) == mp.end()) {
            q.pop();
        }
        return mp[q.top()];
    }
};
