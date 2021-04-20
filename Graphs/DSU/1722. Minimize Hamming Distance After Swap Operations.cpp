
1722. Minimize Hamming Distance After Swap Operations
Medium

142

4

Add to List

Share
You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

 

Example 1:

Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
Example 2:

Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
Output: 2
Explanation: There are no allowed swaps.
The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
Example 3:

Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
Output: 0
 

Constraints:

n == source.length == target.length
1 <= n <= 105
1 <= source[i], target[i] <= 105
0 <= allowedSwaps.length <= 105
allowedSwaps[i].length == 2
0 <= ai, bi <= n - 1
ai != bi






#define MAXN 100001
class Solution {
public:
    int parent[MAXN];
    int ranking[MAXN];
    
    int find(int a) {
        if(a == parent[a])
            return a;
        
        return parent[a] = find(parent[a]);
    }
    
    void set_union(int a, int b) {
        a = find(a);
        b = find(b);
        
        if(ranking[a] < ranking[b])
            swap(a, b);
        
        ranking[a]++;
        
        parent[b] = a;
    }
    
    int minimumHammingDistance(vector<int>& S, vector<int>& T, vector<vector<int>>& Swaps) {
        
        for(int i = 0; i < MAXN; i++) {
            parent[i] = i;
            ranking[i] = 0;
        }
        
        for(auto a: Swaps) 
            set_union(a[0], a[1]);
        
        map<int, map<int, int>> freq_diff;
        
        for(int i = 0; i < S.size(); i++)
            freq_diff[find(i)][S[i]]++;
        
        for(int i = 0; i < T.size(); i++)
            freq_diff[find(i)][T[i]]--;
        
        int answer = 0;
        
        for(auto a : freq_diff) {
            auto b = a.second;
            
            for(auto c : b) 
                answer += abs(c.second);
        }
        
        return answer/2;
    }
};
