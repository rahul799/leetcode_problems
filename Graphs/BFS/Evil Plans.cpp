Susmita has come up with an evil plan to destroy the world. She decides to plant some bombs at certain locations. This world consists of cities on an  grid. 
When a bomb with range  is planted at city , it destroys all the cities  with .
She has prepared a list of cities where the  bombs are to be planted and she wants to know how good this plan is. She asks you to prepare an 
boolean grid whose values are 1 for cities that will be destroyed and 0 for the cities that won't be destroyed.


https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/evil-plans/copy-from/1325661403




#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;
void solve(int n, int m, int q, vector<pair<int, int>> ar, int r, vector<vector<bool>> &out)
{
    queue<pair<pair<int,int>, int>> qu;
    for(auto it:ar)
    {
        qu.push({it,0});
        out[it.first][it.second]=1;
    }
    int cnt=0;
    while(!qu.empty())
    {
        cnt++;
        pair<pair<int,int>, int> fr = qu.front();
        qu.pop();
        int x = fr.first.first;
        int y = fr.first.second;
        int dep = fr.second;

        if(dep==r)
        {
            break;
        }
        if(x>0 && !out[x-1][y])
        {
            out[x-1][y]=1;
            qu.push({{x-1,y},dep+1});
        }
        if(x<n-1 && !out[x+1][y])
        {
            out[x+1][y]=1;
            qu.push({{x+1,y},dep+1});
        }
        if(y>0 && !out[x][y-1])
        {
            out[x][y-1]=1;
            qu.push({{x,y-1},dep+1});
        }
        if(y<m-1 && !out[x][y+1])
        {
            out[x][y+1]=1;
            qu.push({{x,y+1},dep+1});
        }
    }
}

int n,m,q,r;
vector<pair<int, int>> ar;
int main()
{
    int x,y;
    cin>>n>>m>>q>>r;
    vector<vector<bool>> out(n,vector<bool>(m,0));

    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        ar.push_back({x-1,y-1});
    }

    solve(n,m,q,ar,r,out);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
}




