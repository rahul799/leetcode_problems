1337. The K Weakest Rows in a Matrix
Easy

725

49

Add to List

Share
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.




typedef pair<int,int> pi;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        if(mat.empty()) return {};
        if(k > row) return {};
        if(row < 1) return {};
        vector<int> result;
        priority_queue<pi, vector<pi>, greater<pi>> minheap;
        for(int r=0; r<row; r++) {
            int count = 0;
            for(int c=0; c<col; c++) {
                if(mat[r][c]==1) {
                    count++;
                }
            }
            minheap.push({count, r});
        }
        while(k-- != 0) {
            pair<int,int> current = minheap.top(); minheap.pop();
            result.push_back(current.second);
        }
        return result;
    }
}; 





    bool comp(const pair<int,int> &a, const pair<int,int> &b){
     if(a.second==b.second){
            return a.first<b.first;
        }
       return a.second<b.second;
}
class Solution {

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>a;
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    ans++;
                }
            }
            a.push_back({i,ans});
            ans=0;
        }
        vector<int>val;
        sort(a.begin(), a.end(), comp);
        auto it=a.begin();
        for(int i=0;i<k;i++){
            val.push_back(it->first);
            it++;
        }
        return val;
    }
};
