
1136. Parallel Courses
Hard

246

9

Add to List

Share
There are N courses, labelled from 1 to N.

We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.

 

Example 1:



Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: 
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.
Example 2:



Input: N = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: 
No course can be studied because they depend on each other.
 

Note:

1 <= N <= 5000
1 <= relations.length <= 5000
relations[i][0] != relations[i][1]
There are no repeated relations in the input.








class Solution {
public:
	int minimumSemesters(int N, vector<vector<int>>& relations) {
		vector<int> indegree(N+1,0);
		unordered_map<int,vector<int>> adjList;
		queue<int> q;

		//create adjaceny list and dependency
		for(vector<int> relation:relations) {
			adjList[relation[0]].push_back(relation[1]);
			indegree[relation[1]]++;
		}

		//push courses with 0 dependency in queue
		for(int i=1;i<=N;i++) if(indegree[i]==0)  q.push(i);

		int ans=0;
		while(!q.empty()) {
			int n=q.size();
			ans++;
			for(int i=0;i<n;i++) {
				int cur=q.front();
				q.pop();
				for(int v:adjList[cur]) {
					if(--indegree[v]==0) {
						q.push(v);
					}
				}
			}
		}

		//cycle present, not possible
		for(int in:indegree) if(in>0)  return -1;

		return ans;

	}
};






Approach 2: 


Our task is to find the length of longest path in the graph. If it is DAG, the length exists. If it contains a loop, return -1.

We use a dist array to remember the longest path, dist[v] means the maximum length of path starting with v. This is sort of like a DP array.
dist[u] = Max over all neighbor v, dist[v]+1.

dfs ensures we update this dp array in correct order.

We also use a visit array to check if there is a cycle. When visiting a node, mark it with flag 1. When done visiting that node, mark it with flag 2. Therefore anytime we see a flag 1 in our neighbor, we are in a cycle, dfs returns false.

class Solution {
    int[] visit;
    int[] dist;
    int max;
    ArrayList<Integer>[] graph;
    public int minimumSemesters(int N, int[][] relations) {
        max = 0;
        visit = new int[N+1];
        dist = new int[N+1];
        graph = new ArrayList[N+1];
        for(int i = 0; i<=N ;i++){
            graph[i] = new ArrayList<Integer>();
        }
        for(int[] e: relations){
            graph[e[0]].add(e[1]);
        }
        for(int u = 1; u<=N; u++){
            if(visit[u]==0){
                if(!dfs(u)) return -1;
            }
        }
        return max+1;
    }
    
    public boolean dfs(int u){
        if(visit[u] == 1) return false;
        if(visit[u] == 2) return true;
        visit[u] = 1;
        for(int v: graph[u]){
            if(dfs(v)){
                dist[u] = Math.max(dist[u], dist[v]+1);
            }else{
                return false;
            }
        }
        max = Math.max(max, dist[u]);
        visit[u] = 2;
        return true;
    }
}
