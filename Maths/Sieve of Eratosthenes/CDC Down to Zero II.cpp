


You are given  queries. Each query consists of a single number . You can perform any of the  operations on  in each move:

1: If we take 2 integers  and  where , , then we can change 

2: Decrease the value of  by .

Determine the minimum number of moves required to reduce the value of  to .

Input Format

The first line contains the integer .
The next  lines each contain an integer, .

Constraints



Output Format

Output  lines. Each line containing the minimum number of moves required to reduce the value of  to .

Sample Input

2
3
4
Sample Output

3
3
Explanation

For test case 1, We only have one option that gives the minimum number of moves.
Follow  ->  ->  -> . Hence,  moves.

For the case 2, we can either go  ->  ->  ->  ->  or  ->  ->  -> . The 2nd option is more optimal. Hence,  moves.
  
  
  
  
  
  
  
  memset(dp, -1, sizeof dp);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 1; i < N; i++){
        if (dp[i] == -1 || dp[i-1] + 1 < dp[i])
            dp[i] = 1 + dp[i-1];
        for (int j = 2; j <= i && i*j < N; j++){
            if (dp[i*j] == -1 || dp[i] + 1 < dp[i*j])
                dp[i*j] = 1 + dp[i];    
        }
    }
