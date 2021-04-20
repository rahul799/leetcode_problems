

Diverse Words
You are given a list of strings words and an integer k. Return the number of sublists in words that have exactly k different words.

Constraints

n ≤ 100,000 where n is the length of words
k ≤ 10,000
Example 1
Input
words = ["hi", "hello", "hello", "hi"]
k = 2
Output
5
Explanation
These sublists have 2 unique words

["hi", "hello"]
["hello", "hi"]
["hi","hello","hello"]
["hello","hello","hi"]
["hi","hello","hello","hi"]
This doesn't count since it has only 1 unique word

["hello", "hello"]



Intuition
There is a way to solve this problem in \mathcal{O}(K)O(K) space and count exactly the number of sublists with exactly KK distinct words without using inclusion-exclusion.
We'll presume an understanding of two pointers.

Imagine sweeping over the list from left to right and keeping track, for every word currently in our window, of the rightmost occurrence of each word. There are three 
cases to consider:

Case 1: We've seen fewer than KK distinct words overall. Obviously, there can be no sublist ending at our current index with exactly KK words.

Case 2: We've seen exactly KK distinct words overall. The word with the earliest rightmost occurrence is the rightmost "leftmost index" that constitutes a valid sublist 
with exactly KK distinct words ending at the current index, and the leftmost "leftmost index" is the start of the window.

Case 3: We've seen more than KK distinct words. Since we've seen more than KK distinct words altogether, the leftmost index needs to be advanced until we've removed all
occurrences of a given word. The word with the earliest rightmost occurrence is the word for which we'll remove all occurrences first, and then we apply the logic in case 2, except that we permanently advance the leftmost "leftmost index" to be one higher than the last occurrence of the word we just removed.

Implementation
We keep track of the last time a word appeared in the lastappear map. We also reverse this mapping in revlastappear - since this map is backed by a balanced binary search
tree, it lets us query for the smallest key in \mathcal{O}(\log K)O(logK) time. We then run two pointers as described above.

Time Complexity
This solution runs in \mathcal{O}(N \log K)O(NlogK) due to the need for performing arbitrary removal, insertion, and fetching of the smallest integer on the rightmost
occurrence map, as well as keeping the data structure sparse in the event KK is small and there are many duplicate occurrences of a word.

Space Complexity
We need \mathcal{O}(N)O(N) space to track the last appearance of every word.

int solve(vector<string>& words, int k) {
    map<string, int> lastappear;
    map<int, string> revlastappear;
    int ret = 0;
    int lhs = 0;
    for (int i = 0; i < words.size(); i++) {
        if (lastappear.count(words[i])) {
            revlastappear.erase(lastappear[words[i]]);
        }
        lastappear[words[i]] = i;
        revlastappear[i] = words[i];
        if (lastappear.size() > k) {
            int first = revlastappear.begin()->first;
            string firstword = revlastappear[first];
            revlastappear.erase(first);
            lastappear.erase(firstword);
            lhs = first + 1;
        }
        if (lastappear.size() == k) {
            ret += revlastappear.begin()->first - lhs + 1;
        }
    }
    return ret;
}
