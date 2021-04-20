
https://www.codingninjas.com/codestudio/problems/covid-spread_980228




You are given a city which contains N x M houses, where each house can have one of the following three conditions :
1. The value ‘0’ represents an empty house,
2. The value ‘1’ represents a non-infected person,
3. The value ‘2’ represents an infected person.
It takes one day to propagate the infection from an infected house to its adjacent (Front, Back, Left, Right) non-empty and non-infected house. An empty house can only break the line of propagation of infection.
You need to return the minimum number of days Covid will take to infect each and every house in the city. And for the God’s sake if this is impossible, return -1 instead.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case will contain two integers ‘N’ and ‘M’ denoting the number of rows and columns, respectively.

Next ‘N’ lines contain ‘M’ space-separated integers each denoting the conditions of the house in the city as above explained.
Output Format :
For each test case, print the minimum number of days Covid will take to infect each and every person in the city. If this is impossible, print -1 instead.

The output of every test case will be printed in a separate line.
Note :
You do not need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 50
1 <= N, M <= 100
0 <= houses[i][j] <= 2

Where ‘T’ is the number of test cases.
Where 'N' is the number of rows in the given matrix, and 'M' is the number of columns in the given city.
And, houses[i][j] denotes the condition of (i,j) house in the city.

Time limit: 1 sec
Sample Input 1 :
2
2 2
2 2
0 1
2 3
1 0 1
2 1 0
Sample Output 1 :
1
-1
Explanation To Sample Input 1 :
In the first test case, the minimum number of days Covid will take to infect each and every person in the city is 1, so the output is 1.

In the second test case, Covid cannot be spread to each and every person, so the output is -1.
Sample Input 2 :
2
2 3
1 0 1
2 1 1
3 3
2 1 1
1 1 0
0 1 1
Sample Output 2 :
3
4
Explanation To Sample Input 2 :
In the first test case, the minimum number of days Covid will take to infect each and every person in the city is 3, so the output is 3.

In the second test case, the minimum number of days Covid will take to infect each and every person in the city is 4, so the output is 4.


/*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M)

    Where 'N' and 'M' are the dimensions of the given city.
*/

#include <queue>

bool isValid(vector<vector<int>> &houses, int i, int j, int n, int m)
{

    //    Check if i, j is under the array limits of row and column.
    if (i >= 0 && i < n && j >= 0 && j < m && houses[i][j] == 1)
    {
        return true;
    }

    return false;
}

int covidSpread(vector<vector<int>> &houses)
{
    int n = houses.size();

    if (n == 0)
    {
        return 0;
    }

    int m = houses[0].size();

    //    Create a queue of house coordinates.
    queue<pair<int, int>> infected;

    int nDays = 0;

    int countNonInf = 0;

    //    Store all the cells which are infected houses in first time frame
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (houses[i][j] == 2)
            {
                //    If the house is infected.
                infected.push({i, j});
            }
            else if (houses[i][j] == 1)
            {
                //    If the house is non-infected.
                countNonInf++;
            }
        }
    }

    //      All the four directions in x and y direction.
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (infected.empty() == false)
    {
        //    Increment the days.
        nDays++;

        int nHouse = infected.size();

        for (int i = 0; i < nHouse; i++)
        {
            //    Pop a position of infected house from the infected queue.
            pair<int, int> pos = infected.front();
            infected.pop();

            //    Check for all the four directions.
            for (int j = 0; j < 4; j++)
            {
                int newX = (pos.first + dx[j]);
                int newY = (pos.second + dy[j]);

                if (isValid(houses, newX, newY, n, m))
                {
                    //    This time there is one more house that has become infected.
                    countNonInf--;

                    //    We will make this new house infected.
                    houses[newX][newY] = 2;

                    //    Push the newly infected house in the infected queue.
                    infected.push({newX, newY});
                }
            }
        }
    }

    if (countNonInf == 0)
    {
        return nDays - 1;
    }
    else
    {
        return -1;
    }
}
