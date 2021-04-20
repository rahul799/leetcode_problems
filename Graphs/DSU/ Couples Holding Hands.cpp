

https://leetcode.com/problems/couples-holding-hands/submissions/



765. Couples Holding Hands


Add to List

Share
N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
Note:

len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1
    
    
    
  We can number each pair of socks with 0,1,\dots,N-10,1,…,N−1. Then sock 00 and 11 belongs to pair 00, 22 and 33 belongs to pair 11, and generally 
   sock ii belongs to pair i/2i/2.

In the end, index 00 and 11 will be the first pair, and 22 and 33 the second, etc.

Obviously, those positions which are already a pair will stay untouched. Then for other positions, their current 
    socks must come from two different pairs. 
    Say they come from pair uu and pair vv. We can then add an undirected edge between uu and vv. After the processing, the unpaired pairs will be grouped 
    into several connected components, and each connected component will exactly be a cycle. 
    It takes sz-1sz−1 swaps for a cycle with szsz nodes, so we can calculated the total swaps we need accordingly.


        
        
        
        
        
        
        
 vector<int> p, sz;
int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}
void connect(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    if (sz[pu] >= sz[pv]) {
        p[pv] = pu;
        sz[pu] += sz[pv];
    } else {
        p[pu] = pv;
        sz[pv] += sz[pu];
    }
}

int solve(vector<int>& row) {
    int n = row.size() / 2;
    p = vector<int>(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    sz = vector<int>(n, 1);
    for (int i = 0; i < n; ++i) {
        int u = row[i << 1] / 2;
        int v = row[i << 1 | 1] / 2;
        connect(u, v);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (find(i) == i) ans += sz[i] - 1;
    return ans;
}
    
        
        
        
        
        
        
        
class Solution {

public:
    void make_set(int v, vector<int> &parent, vector<int> &siz){
        parent[v]=v;
        siz[v]=1;
    }
   int find_set(int v, vector<int> &parent){ 
       if(v==parent[v])return v;   //find parent of a node & path compression optimaization
       return parent[v]= find_set(parent[v], parent);
   } 
bool union_sets(int a, int b, vector<int> &parent, vector<int> &siz){  //union by size
    a= find_set(a,parent);
    b= find_set(b,parent);
    
    if(a!=b){
        if(siz[a]<siz[b])swap(a,b);
        parent[b]=a;
        siz[a]+=siz[b];
        return true;    // return true if parent are different else false
    }
    return false;
}
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> parent(n);
        vector<int> siz(n);
        int connected_component=n/2;
        for(int i=0;i<n;i++){
            make_set(i,parent, siz);
        }
        for(int i=1;i<n;i+=2){
            bool x = union_sets(i-1,i,parent,siz);
                            
        }
       
        for(int i=1;i<n;i+=2){
           int x=  union_sets(row[i-1], row[i],parent, siz);
            if(x)connected_component--;        //no. of times union is performed in the given array
        }
        return n/2-connected_component;
    }
};
