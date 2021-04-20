
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/connected-horses-10/editorial/



Given three integers  and Q where  is the size of the board and Q is the number of horses on it.
Q lines follow each containing the 2 integers X and Y which are the coordinates of the Horses.

output the number of photographs taken by photographer (The multiplication of factorials of number of each connected group of horses).

Pre-requisites: Dynamic Programming Concept, DFS, Math.

Difficulty Level: Easy - Medium.

Hints: Use (DFS) to traverse the board and counting the number of horses
int each connected group, then find the factorial of this number.
Apply the same concept in each connected group of horses.


Approach:

This Question depends on your Graph Skills (DFS), Math Skills.

Firstly:

Check this condition "Now these horses are not the usual horses which could jump
to any of the 8 positions they usually jump in. They can move only if there is another
horse on one of the 8-positions that it can go to usually and then both the horses
will swap their positions. This swapping can happen infinitely times."

So you should count how many horses in a connected group.

Note: Connected group means that you can swap any 2 horses in the
group in some number of movements.

So You should use a DFS to traverse each group and check how many
horses in each group, as you can swap them with each other.





If you have for instance 5 horses in a group, how many number of ways
you can swap them ?

Note: This Question has the same meaning of "how to arrange n horses in r places ?"

So you can use this law in counting:


Thirdly:

So now how to calculate the factorial ?

Note: you can't calculate the factorial each time you want because this
will result in Time Limit Exceeded, as each factorial take .






#include <bits/stdc++.h>

using namespace std;

long long n , m , q , x , y, tem1, tem2 , t, sum, mod = 1e9 + 7, ans;

bool vis [1000 + 1][1000 + 1];
bool arr [1000 + 1][1000 + 1];
long long factorial [1000000 + 1];

int dirc [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

void pre_calculate(){       // calculating factorial

    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

void dfs(int x, int y){

    vis[x][y] = true;
    sum++;

    for(int i = 0; i < 8; i++){                     // check for the 8 movements

        int dx = x + dirc[i][0];
        int dy = y + dirc[i][1];

        if(dx <= 0 || dx > n || dy <= 0 || dy > m) continue;        // out of board
        if(vis[dx][dy] || !arr[dx][dy]) continue;                   // check if the cell is visited or doesn't contain a horse
        dfs(dx, dy);

    }

}


int main()
{

    pre_calculate();

    cin >> t;

    while(t--){

        cin >> n >> m >> q;

        ans = 1;

        for(int i = 0; i <= n; i++){                // reset arrays in each test case

            for(int j = 0; j <= m; j++){

                vis[i][j] = false;
                arr[i][j] = false;
            }
        }

        for(int i = 0; i < q; i++){

            cin >> tem1 >> tem2;
            arr[tem1][tem2] = true;
        }

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(!vis[i][j] && arr[i][j]){

                    sum = 0;
                    dfs(i , j);                             // begin dfs from that unvisited horse (New group of connected horses)
                    ans = (ans * factorial[sum]) % mod;     // number of arrangements
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
