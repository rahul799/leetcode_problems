

1202. Smallest String With Swaps
Medium

757

27

Add to List

Share
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.



class Solution {
private:
    /*
     * Find the subset a vertex belongs to.
     */
    int find(vector<int> &ss, int x) {
        if (ss[x] == -1) return x;
        return ss[x] = find(ss, ss[x]);
    }
    
    /*
     * Unionize two subsets. 
     */
    void _union(vector<int> &ss, int x, int y) {
        int xp = find(ss, x);
        int yp = find(ss, y);
        if (xp != yp) ss[yp] = xp;
    }

public:
    
    /* We use disjoint set (or Union-Find) to form subsets */
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        /* 
         * Treat index of string s as vertex. Create parent subsets 
         * and initialize them to -1 - this means the subsets don't
         * have parent info yet.
         */
        vector<int> ss;
        for (int i = 0; i < s.size(); i++) ss.push_back(-1);
        
        /*
         * Go through each pair one by one. Find the subsets
         * that the vertices of the pair belong to. If they 
         * are different, unionize them.
         */
        for (int i = 0; i < pairs.size(); ++i) {
            int x = find(ss, pairs[i][0]), y = find(ss, pairs[i][1]);            
            if (x != y) _union(ss, x, y);
        }
        
        /* Create separate vectors from the subsets */
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < s.size(); i++) m[find(ss, i)].push_back(i);
        
        /* Sort the vertices in each vector and change the original 
         * array based on the sorted results 
         */
        for (auto x : m) {
            string str = ""; int j = 0;
            for (auto i : x.second) { str += s[i]; }
            sort(str.begin(), str.end());
            for (auto i : x.second) { s[i] = str[j++]; }
        }
        
        return s;
    }
};
