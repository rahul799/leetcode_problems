




https://codeforces.com/contest/25/problem/D



Berland Government decided to improve relations with neighboring countries. First of all, it was decided to build new
roads so that from each city of Berland and neighboring countries it became possible to reach all the others. There are 
n cities in Berland and neighboring countries in total and exactly n - 1 two-way roads. Because of the recent financial crisis,
the Berland Government is strongly pressed for money, so to build a new road it has to close some of the existing ones. Every 
day it is possible to close one existing road and immediately build a new one. Your task is to determine how many days would be needed to rebuild roads so that from each city it became possible to reach all the others, and to draw a plan of closure of old roads and building of new ones.

Input
The first line contains integer n (2 ≤ n ≤ 1000) — amount of cities in Berland and neighboring countries. Next n - 1 lines contain 
the description of roads. Each road is described by two space-separated integers ai, bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — pair of cities,
which the road connects. It can't be more than one road between a pair of cities. No road connects the city with itself.

Output
Output the answer, number t — what is the least amount of days needed to rebuild roads so that from each city it became 
possible to reach all the others. Then output t lines — the plan of closure of old roads and building of new ones. Each line 
should describe one day in the format i j u v — it means that road between cities i and j became closed and a new road 
between cities u and v is built. Cities are numbered from 1. If the answer is not unique, output any.

Examples
inputCopy
2
1 2
outputCopy
0
inputCopy
7
1 2
2 3
3 1
4 5
5 6
6 7
outputCopy
1
3 1 3 7






Problem D - Roads not only in Berland
Before we start this problem, it is helpful to know about the union find data structure. The main idea is this: given some elements x1, x2, x3, ..., xn that are partitioned in some way, we want to be able to do the following:
merge any two sets together quickly
find the parent set of any xi
This is a general data structure that sometimes appears in programming competitions. There are a lot of ways to implement it; one good example is written by Bruce Merry (aka BMerry) here.

Back to the problem: Every day we are allowed to build exactly 1 road, and close exactly 1 road. Thus, we can break the problem into two parts:
How do we connect the parts of the graph that are disconnected?
How do we remove roads in a way that does not disconnect parts of the graph?
Let build be the list all roads that need to be built, and let close be the list of nodes that need to be closed. We can show that in fact, these lists are of the same size. This is because the connected graph with n nodes is a tree if and only if it has n - 1 edges. Thus, if we remove more roads than than we build, then the graph is disconnected. Also, if we build more roads than we remove, then we have some unnecessary roads (the graph is no longer a tree).

Now consider the format of the input data:
a1, b1
a2, b2
...
an - 1, bn - 1
We can show that edge (ai, bi) is unnecessary if and only if the nodes ai, bi have already been connected by edges (a1, b1), (a2, b2), ..., (ai - 1, bi - 1). In other words, if the vertices ai, bi are in the same connected component before we, add (ai, bi) then we do not need to add (ai, bi). We can use union-find to help us solve this problem:

<code>
for( i from 1 to n-1 )
{
    if( find(ai)=find(bi) ) close.add(ai, bi);
    else merge(ai, bi);
}
</code>

In other words, we treat each connected component as a set. Union find allows us to find the connected component for each node. If the two connected components are the same, then our new edge is unnecessary. If they are different, then we can merge them together (with union find). This allows us to find the edges that we can remove.

In order to find the edges that we need to add to the graph, we can also use union-find: whenever we find a component that is disconnected from component 1, then we just add an edge between them.

<code>
for( i from 2 to n )
    if( find(vi)!=find(v1) )
    {
        then merge(v1, vi);
        build.add(v1, vi);
    }
</code>

We just need to store the lists of roads that are unnecessary, and the roads that need to be built.
