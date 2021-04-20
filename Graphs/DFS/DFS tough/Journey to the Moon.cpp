
Journey to the Moon




https://www.hackerrank.com/challenges/journey-to-the-moon/problem


The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut 
ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example



There are  astronauts numbered  through . Astronauts grouped by country are  and . There are  pairs to choose from:  and .

Function Description

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

int n: the number of astronauts
int astronaut[p][2]: each element  is a  element array that represents the ID's of two astronauts from the same country
Returns
- int: the number of valid pairs

Input Format

The first line contains two integers  and , the number of astronauts and the number of pairs.
Each of the next  lines contains  space-separated integers denoting astronaut ID's of two who share the same nationality.

Constraints

Sample Input 0

5 3
0 1
2 3
0 4
Sample Output 0

6
Explanation 0

Persons numbered  belong to one country, and those numbered  belong to another. The UN has  ways of choosing a pair:


Sample Input 1

4 1
0 2
Sample Output 1

5
Explanation 1

Persons numbered  belong to the same country, but persons  and  don't share countries with anyone else. The UN has  ways of choosing a pair:










#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;

void dfile(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
void dfs(int src,vector<int> &vis,vector<int> g[],int &counter){
    vis[src] = 1;
    counter++;
    for(auto x:g[src]){
        if(!vis[x]){
            dfs(x,vis,g,counter);
        }
    }
}

int32_t main()
{   
   
    int v,e;
    cin>>v>>e;
    vector<int> g[v];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> solution;
    vector<int> vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            int counter = 0;
            dfs(i,vis,g,counter);
            solution.push_back(counter);
        }
    }
    int val = (v*(v-1)) / 2;
    for(int i=0;i<solution.size();i++){
        int x = (solution[i]*(solution[i]-1)) / 2;
        val = val - x;
    }
    cout<<val;
    
   

    
    return 0;   
}
