
https://docs.google.com/document/d/1TLxfxM254E_Od_rdWqkhPZbv-rWzqjRLW_OVhW3RXS0/edit

	https://www.youtube.com/watch?v=4y-4UycCEzg&ab_channel=ClubofProgrammers%2CIITBHUVaranasi





BELLMAN-FORD AND FLOYD-WARSHALL

Bellman Ford -

Suppose that we are given a weighted directed graph G with n vertices and m edges, and some specified vertex v. You want to find the length of shortest paths from vertex v to every other vertex.

Unlike the Dijkstra algorithm, this algorithm can also be applied to graphs containing negative weight edges. However, if the graph contains a negative cycle, then, clearly, the shortest path to some vertices may not exist (due to the fact that the weight of the shortest path must be equal to minus infinity); however, this algorithm can be modified to signal the presence of a cycle of negative weight, or even deduce this cycle.

Implementation -

We start the implementation with a structure edge for representing the edges. The input to the algorithm are numbers n, m, list e of edges and the starting vertex v. All the vertices are numbered 0 to n−1.

struct edge
{
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1000000000;

void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
    // display d, for example, on the screen
}

Time Complexity - O(N * M)

The constant INF denotes the number "infinity" — it should be selected in such a way that it is greater than all possible path lengths.

Better Implementation will be when we break the loop if no further modifications are made.




Path Retrieval -

For that, let's create another array p[0…n−1], where for each vertex we store its "predecessor", i.e. the penultimate vertex in the shortest path leading to it. In fact, the shortest path to any vertex a is a shortest path to some vertex p[a], to which we added a at the end of the path.


void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;
    vector<int> p (n, -1);

    for (;;)
    {
        bool any = false;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if (!any)  break;
    }

    if (d[t] == INF)
        cout << "No path from " << v << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());

        cout << "Path from " << v << " to " << t << ": ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
}






Negative cycle - 

Hence we obtain the criterion for presence of a cycle of negative weights reachable for source vertex v: after (n−1)th phase, if we run algorithm for one more phase, and it performs at least one more relaxation, then the graph contains a negative weight cycle that is reachable from v; otherwise, such a cycle does not exist.

Moreover, if such a cycle is found, the Bellman-Ford algorithm can be modified so that it retrieves this cycle as a sequence of vertices contained in it. For this, it is sufficient to remember the last vertex x for which there was a relaxation in the nth phase. This vertex will either lie in a negative weight cycle, or is reachable from it. To get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex x, pass through to the predecessors n times. Hence we will get the vertex y, namely the vertex in the cycle earliest reachable from source. We have to go from this vertex, through the predecessors, until we get back to the same vertex y (and it will happen because relaxation in a negative weight cycle occurs in a circular manner).


References - 

https://cp-algorithms.com/graph/bellman_ford.html

https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

Questions -

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=364

https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=475

https://cses.fi/problemset/task/1673

https://cses.fi/problemset/task/1197











Floyd - Warshall - 

Given a directed or an undirected weighted graph G with n vertices. The task is to find the length of the shortest path dij between each pair of vertices i and j.

The graph may have negative weight edges, but no negative weight cycles.

If there is such a negative cycle, you can just traverse this cycle over and over, in each iteration making the cost of the path smaller.
This algorithm can also be used to detect the presence of negative cycles. The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.


Algorithm -

The key idea of the algorithm is to partition the process of finding the shortest path between any two vertices to several incremental phases.

Let us number the vertices starting from 1 to n. The matrix of distances is d[][].

Before k-th phase (k=1…n), d[i][j] for any vertices i and j stores the length of the shortest path between the vertex i and vertex j, which contains only the vertices {1,2,...,k−1} as internal vertices in the path.

In other words, before k-th phase the value of d[i][j] is equal to the length of the shortest path from vertex i to the vertex j, if this path is allowed to enter only the vertex with numbers smaller than k (the beginning and end of the path are not restricted by this property).

It is easy to make sure that this property holds for the first phase. For k=0, we can fill the matrix with d[i][j]=wij if there exists an edge between i and j with weight wij and d[i][j]=∞ if there doesn't exist an edge. In practice ∞ will be some high value. As we shall see later, this is a requirement for the algorithm.

Suppose now that we are in the k-th phase, and we want to compute the matrix d[][] so that it meets the requirements for the (k+1)-th phase. We have to fix the distances for some vertex pairs (i,j). There are two fundamentally different cases:

The shortest way from the vertex i to the vertex j with internal vertices from the set {1,2,…,k} coincides with the shortest path with internal vertices from the set {1,2,…,k−1}.

In this case, d[i][j] will not change during the transition.

The shortest path with internal vertices from {1,2,…,k} is shorter.

This means that the new, shorter path passes through the vertex k. This means that we can split the shortest path between i and j into two paths: the path between i and k, and the path between k and j. It is clear that both these paths only use internal vertices of {1,2,…,k−1} and are the shortest such paths in that respect. Therefore we already have computed the lengths of those paths before, and we can compute the length of the shortest path between i and j as d[i][k]+d[k][j].

Combining these two cases we find that we can recalculate the length of all pairs (i,j) in the k-th phase in the following way:

dnew[i][j]=min(d[i][j],d[i][k]+d[k][j])

Thus, all the work that is required in the k-th phase is to iterate over all pairs of vertices and recalculate the length of the shortest path between them. As a result, after the n-th phase, the value d[i][j] in the distance matrix is the length of the shortest path between i and j, or is ∞ if the path between the vertices i and j does not exist.

Implementation -

Let d[][] is a 2D array of size n×n, which is filled according to the 0-th phase as explained earlier. Also we will set d[i][i]=0 for any i at the 0-th phase.


for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}

Time Complexity - O(N ^ 3)

References -

https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html

https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

Questions -

https://www.spoj.com/problems/SOCIALNE/

https://codeforces.com/problemset/problem/295/B

https://codeforces.com/contest/25/problem/C

https://cses.fi/problemset/task/1672

https://www.spoj.com/problems/ROHAAN/

https://codeforces.com/problemset/problem/21/D



