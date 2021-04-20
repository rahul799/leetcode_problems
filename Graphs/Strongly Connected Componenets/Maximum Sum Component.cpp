

Maximum Sum ComponentSubmissions: 1680   Accuracy: 15.21%   Max. Score: 100

Given an undirected graph with V vertices and E edges. Every node has been assigned a value. The task is to find the connected chain with the maximum 
sum of values among all the connected components in the graph.




https://practice.geeksforgeeks.org/contest-problem/maximum-sum-component/1/



Example 1:

Input: 
V = 7, E = 4 
Values = {10, 25, 5, 15, 5, 20, 0} 
Edges={ {1,2} ,{3,4}, {4,5} ,{6,7} }
Output: 35
Explanation: The graph looks like
1     3      5       6
|       \   /        |  
2         4          7
Component {1, 2} has Value {10, 25}: 
sumValue = 10 + 25 = 35 

Component {3, 4, 5}  has Value {5, 15, 5}: 
sumValue = 5 + 15 + 5 = 25 

Component {6, 7} has Value {20, 0}: 
sumValue = 20 + 0 = 20 

Max Sum value chain is {1, 2} with values 
{10, 25}, hence 35 is the answer. 
 

Your Task: 
You don't need to read input or print anything. Your task is to complete the function solve() that takes
V (number of vertices in the graph),
E(number of edges in the graph),
Values( Values[i] represent the value of i+1th node),
Edges (Edges[i][0] is connected with Edges[i][1] ) 
as input parameters and returns the maximum sum of values of the node which are present in the same component.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

 

Constraints:
1<=V<=1e5 
0<=E<=min( V*(V-1)/2 , 1e5 )
1<=Values[i]<=1e5 
1<=Edges[i][0],Edges[i][1] <=V
Graph doesn't contain multiple edges and self loops.






class Solution{   
public:
    vector<vector<int>> adj;
    vector<int> vis;
    long long dfs(int node,vector<int> &Values)
    {
      long long sum=Values[node-1];
      vis[node]=1;
      for(auto i:adj[node])
      {
        if(!vis[i])
          sum+=dfs(i,Values);
      }
      return sum;
    }
    long long solve(int V,int E,vector<int> Values,vector<vector<int>> Edges){
      long long answer=0;
      adj=vector<vector<int>>(V+1);
      vis=vector<int>(V+1);
      for(auto i:Edges)
      {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
      }
      for(int i=1;i<=V;i++)
      {
        if(!vis[i]){
           long long x=dfs(i,Values);
           if(answer<x)
              answer=x;
        }
      }
      return answer;
    }
};
