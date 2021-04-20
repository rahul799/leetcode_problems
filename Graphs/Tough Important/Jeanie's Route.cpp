

https://www.hackerrank.com/challenges/jeanies-route/problem

Byteland has  cities (numbered from  to ) and  bidirectional roads. It is guaranteed that there is a route from any city to any other city.

Jeanie is a postal worker who must deliver  letters to various cities in Byteland. She can start and end her delivery route in any city. Given the destination cities for  letters and the definition of each road in Byteland, find and print the minimum distance Jeanie must travel to deliver all  letters.

Note: The letters can be delivered in any order.

Input Format

The first line contains two space-separated integers,  (the number of cities) and  (the number of letters), respectively.
The second line contains  space-separated integers describing the delivery city for each letter.
Each line  of the  subsequent lines contains  space-separated integers describing a road as , where  is the distance (length) of the bidirectional road between cities  and .

Constraints

Output Format

Print the minimum distance Jeanie must travel to deliver all  letters.

Sample Input 0

5 3
1 3 4
1 2 1
2 3 2
2 4 2
3 5 3
Sample Output 0

6
Explanation 0

Jeanie has  letters she must deliver to cities , , and  in the following map of Byteland:








Approach :  2 times sum of All Edges - ( diameter of tree)

Let's solve another problem where Jeanie has to return to the city she started from. If Jeanie passes any edge, then she will have to pass the same edge in backward direction.
Thus, the answer is: 


Jeanie also has to pass an edge if and only if there is at least one delivery destination in both directions.


In this way, Jeanie has to travel a further distance than she had to travel in the real problem. It's easy to understand the difference in distance between her starting and ending points.


Thus, the real answer is: 


Calculating maximum distance is an easy dfs problem. For any node , find any furthest node , and from node  find any furthest node . The answer is the distance between  and  (it's also possible with easy dp on a tree).


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MA(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=500002;
const int inf=1000000000;
int n,K,s[N],SUM,M;
bool f[N];
vector <int> v[N],d[N];

int input(){
    scanf("%d%d",&n,&K);
    for (int i=0,x;i<K;i++){
        scanf("%d",&x);
        s[x]=1;
        f[x]=1;
    }
    for (int i=1,x,y,z;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        v[x].pb(y);
        v[y].pb(x);
        d[x].pb(z);
        d[y].pb(z);
    }
    return 0;
}

int go(int x,int from){
    int D1=-inf;
    int D2=-inf;

    for (int i=0;i<v[x].size();i++)
    if (v[x][i]!=from){
        D1=max(D1,go(v[x][i],x)+d[x][i]);
        if (D1>D2) swap(D1,D2);
        s[x]+=s[v[x][i]];
        if (0<s[v[x][i]] && s[v[x][i]]<K) SUM+=d[x][i];
    }

    if (D1>0) M=max(M,D1+D2);

    if (D2>0 && f[x]) M=max(M,D2);

    if (f[x]) D2=max(D2,0);

    return D2;
}

int sol(){
    go(1,1);
    printf("%d\n",SUM*2-M);
    return 0;
}

int main() {
    input();
    sol();
    return 0;
    }


