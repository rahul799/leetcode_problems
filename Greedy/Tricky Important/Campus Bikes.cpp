1057. Campus Bikes
Medium



Add to List

Share
On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.

Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.

 

Example 1:



Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: [1,0]
Explanation: 
Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
Example 2:



Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: [0,2,1]
Explanation: 
Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].




As the question states, there are n workers and m bikes, and m > n.
We are able to solve this question using a greedy approach.

initiate a priority queue of bike and worker pairs. The heap order should be Distance ASC, WorkerIndex ASC, Bike ASC
Loop through all workers and bikes, calculate their distance, and then throw it to the queue.
Initiate a set to keep track of the bikes that have been assigned.
initiate a result array and fill it with -1. (unassigned)
poll every possible pair from the priority queue and check if the person already got his bike or the bike has been assigned.
early exist on every people got their bike.




class Solution {
public:
    struct node{
        int dist, worker, bike;   
    };
    
    static bool myfunc(node& a, node& b){
        if(a.dist != b.dist)
            return a.dist < b.dist;
        else{
            if(a.worker != b.worker)
                return a.worker < b.worker;
            else
                return a.bike < b.bike;
        }
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<node> nodes;
        int m=workers.size(), n=bikes.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int dist = abs(workers[i][1] - bikes[j][1]) + abs(workers[i][0] - bikes[j][0]);
                node cur = {dist, i, j};
                nodes.push_back(cur);
            }
        }
        
        sort(nodes.begin(), nodes.end(), myfunc);
        
        vector<int> result(m, -1);
        unordered_set<int> marked;
        
        for(int i=0; i<nodes.size(); i++){
            if(result[nodes[i].worker] == -1 && marked.find(nodes[i].bike) == marked.end()){
                result[nodes[i].worker] = nodes[i].bike;
                marked.insert(nodes[i].bike);
            }
        }
        
        return result;
    }
};








bool cmp(pair<int,int> &p1,pair<int,int> &p2)
    {
        if(p1.first!=p2.first) 
            return p1.first<p2.first;
        else 
            return p1.second<p2.second;
    }
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        //simulate the process according to thr description
        vector<int> result(workers.size(),-1);
        map<int,vector<pair<int,int>>> record;
        vector<int> visited(bikes.size(),0);
        for(int i(0);i<=workers.size()-1;i++)
        {
            for(int j(0);j<=bikes.size()-1;j++)
            {
                int temp=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                //cout<<temp<<endl;
                auto iter=record.find(temp);
                if(iter!=record.end())
                    iter->second.push_back({i,j});
                else
                {
                    vector<pair<int,int>> temp_v;
                    record.insert({temp,temp_v});
                    iter=record.find(temp);
                    iter->second.push_back({i,j});
                }
            }
        }
        int count=0;
        for(auto iter=record.begin();iter!=record.end();iter++)
        {
            sort(iter->second.begin(),iter->second.end(),cmp);
            for(int i(0);i<=(iter->second).size()-1;i++)
            {
                //if(count==workers.size())
                    //return result;
                int fir=iter->second[i].first;
                int sec=iter->second[i].second;
                //cout<<fir<<" "<<sec<<endl;
                if(result[fir]==-1&&visited[sec]==0)
                {
                    result[fir]=sec;
                    visited[sec]=1;
                    count++;
                }
            }
        }
        return result;
    }
};

