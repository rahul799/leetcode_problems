
Recursive Voting



You are given a list of integers votes representing election votes for candidates a and b. Each element in votes represents a vote to one of the two candidates:

If votes[i] < 0, then it's a vote for a.
If votes[i] ≥ n, then it's a vote for b.
Otherwise, the vote at index i made the same vote as votes[votes[i]].
Return the number of votes that candidate a received. You can assume all votes are eventually made to either a or b.

Constraints

0 ≤ n ≤ 100,000 where n is the length of votes
Example 1
Input
votes = [2, -1, 5, 1, 3]
Output
3
Explanation
We can see that votes[1], votes[3], and votes[4] were made to candidate a.






class UnionDisjoint{
private:
    vector<int> rank;
    vector<int> parent;
public:
    UnionDisjoint(int n){
        rank.resize(n, 1);
        parent.resize(n);
        for (int i=0;i<n;i++) parent[i]=i;
    }
    
    int find(int x){
        if (parent[x]==x) return x;
        return find(parent[x]);
    }
    
    bool Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if (px==py) return false;
        if (rank[px]<rank[py]){
            parent[px] = py;
        } else {
            parent[py] = px;
            if (rank[px]==rank[py]) rank[px]++;
        }
        return true;
    }
};

int solve(vector<int>& votes) {
    int n = votes.size();
    UnionDisjoint ud(n+2);

    // n -> b, n+1 -> a
    for (int i=0;i<n;i++){
        if (votes[i]<0){
            ud.Union(n+1, i);
        } else if (votes[i]>=n) {
            ud.Union(n, i);
        } else {
            ud.Union(i, votes[i]);
        }
    }

    int ans = 0;
    for (int i=0;i<n;i++){
        if (ud.find(i)==ud.find(n+1)) ans++;
    }

    return ans;
}








int helper(vector<int>& nums, vector<int>& visited, int i) {
    int n = nums.size();
    if (nums[i] < 0) return visited[i] = 0;
    if (nums[i] >= n) return visited[i] = 1;
    if (visited[i] != -1) return visited[i];
    return visited[i] = helper(nums, visited, nums[i]);
}
int solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> visited(n, -1);
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == 0) {
            a += 1;
        } else if (visited[i] == 1) {
            b += 1;
        } else if (nums[i] < 0) {
            visited[i] = 0;
            a += 1;
        } else if (nums[i] >= n) {
            visited[i] = b;
            b += 1;
        } else {
            int x = helper(nums, visited, i);
            a += x == 0;
            b += x == 1;
        }
    }
    return a;
}
