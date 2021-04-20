
https://codeforces.com/blog/entry/20935


The first problem we solve is as follows: Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose a subset of nodes such 
that no two adjacent nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is 
maximum.cpp







This problem is quite similar to 1-D array problem where we are given an array A1, A2, ..., AN; we can't choose adjacent elements and we have to maximise sum of chosen elements. Remember, how we define our state as  denoting answer for A1, A2, ..., Ai. Now, we define our recurrence as (two cases: choose Ai or not, respectively).

Now, unlike array problem where in our state we are solving for first i elements, in case of trees one of our states usually denotes which subtree we are solving for. For defining subtrees we need to root the tree first. Say, if we root the tree at node 1 and define our DP  as the answer for subtree of node V, then our final answer is .

Now, similar to array problem, we have to make a decision about including node V in our subset or not. If we include node V, we can't include any of
its children(say v1, v2, ..., vn), but we can include any grand child of V. If we don't include V, we can include any child of V.

So, we can write a recursion by defining maximum of two cases.
.

As we see in most DP problems, multiple formulations can give us optimal answer. Here, from an implementation point of view, we can define an easier 
solution using DP. We define two DPs,  and , denoting maximum coins possible by choosing nodes from subtree of node V and if we include node V in our answer or not, respectively. Our final answer is maximum of two case i.e. .

And defining recursion is even easier in this case. (since we cannot include any of the children) and (since we can include children now, but we can also 
choose not include them in subset, hence max of both cases).

About implementation now. You must notice that answer for a node is dependent on answer of its children. We write a recursive definition of DFS, where we first 
call recursive function for all children and then calculate answer for current node.



//adjacency list
//adj[i] contains all neighbors of i
vector<int> adj[N];

//functions as defined above
int dp1[N],dp2[N];

//pV is parent of node V
void dfs(int V, int pV){

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    int sum1=0, sum2=0;

    //traverse over all children
    for(auto v: adj[V]){
    if(v == pV) continue;
    dfs(v, V);
    sum1 += dp2[v];
    sum2 += max(dp1[v], dp2[v]);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}

int main(){
    int n;
    cin >> n;

    for(int i=1; i<n; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    dfs(1, 0);
    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
}
