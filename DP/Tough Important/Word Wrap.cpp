




https://www.codingninjas.com/codestudio/problems/word-wrap_982931


You are given N words of various lengths, now you have to arrange these words in such a way that each line contains at most M characters and each word is separated by a space character. Cost of each line is equal to the cube of extra space characters required to complete M characters in that particular line. Total cost is equal to the sum of costs of each line.
Your task is to form this arrangement with the minimum cost possible and return the minimum total cost.
Note:
1. Length of each word should be less than or equal to M.
2. You can’t break a word, i.e. the entire word should come in the same line and it must not be the case that a part of it comes in the first line and another part on the next line.
Input Format:
The first line of the input contains an integer T denoting the number of Test cases.

The first line of each Test case should contain two positive integers N and M, where N is the number of words and M is the number of characters we require in each line. 

Following N lines, contains one word each.
Output Format:
The only line of output of each test case should contain an integer denoting the minimum cost required to form the arrangement. 
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints:
1 <= T <= 100
1 <= N <= 300
1 <= |words[i]| <= 100
1 <= M <= 100
Time Limit: 1sec
Sample Input 1:
1
3 6
ab
a
b
Sample Output 1:
0
Explanation For Sample Input 1:
All the 3 words can be inserted in a single line.
ab a b Total Characters = 6
Hence extra spaces used are (6-6)^3=0
Sample Input 2:
1
4 5
a
bc
def
ghij
Sample Output 2:
10
Explanation For Sample Input 2:
The optimal output will be:
a bc
def
ghij 
Hence extra spaces will be -> (1)^3 + (2)^3 + (1)^3 = 10







/*
    Time Complexity: O(N^2)
    Space Complexity: O(N^2),

    where N is the number of words.
*/
  
  
  
  
  You are given N words of various lengths, now you have to arrange these words in such a way that each line contains at most M characters and each word is separated by a space character. Cost of each line is equal to the cube of extra space characters required to complete M characters in that particular line. Total cost is equal to the sum of costs of each line.
Your task is to form this arrangement with the minimum cost possible and return the minimum total cost.
Note:
1. Length of each word should be less than or equal to M.
2. You can’t break a word, i.e. the entire word should come in the same line and it must not be the case that a part of it comes in the first line and another part on the next line.
Input Format:
The first line of the input contains an integer T denoting the number of Test cases.

The first line of each Test case should contain two positive integers N and M, where N is the number of words and M is the number of characters we require in each line. 

Following N lines, contains one word each.
Output Format:
The only line of output of each test case should contain an integer denoting the minimum cost required to form the arrangement. 
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints:
1 <= T <= 100
1 <= N <= 300
1 <= |words[i]| <= 100
1 <= M <= 100
Time Limit: 1sec
Sample Input 1:
1
3 6
ab
a
b
Sample Output 1:
0
Explanation For Sample Input 1:
All the 3 words can be inserted in a single line.
ab a b Total Characters = 6
Hence extra spaces used are (6-6)^3=0
Sample Input 2:
1
4 5
a
bc
def
ghij
Sample Output 2:
10
Explanation For Sample Input 2:
The optimal output will be:
a bc
def
ghij 
Hence extra spaces will be -> (1)^3 + (2)^3 + (1)^3 = 10
  
  
  
  
  

// This is helper function used to calculate the cost
int calculateCost(int word, int line, vector<int> &wordsLength, vector<vector<int>> &dp, int &m)
{
    // Here, vector<int> wordsLength is storing the length of words.
    int n = wordsLength.size();
    if (word == wordsLength.size())
    {
        return 0;
    }

    // This 2 Dimensional DP array dp[word][line] indicates the
    // cost to put words from index word to line in a single line.
    int &res = dp[word][line];
    if (res != -1)
    {
        return res;
    }

    int ans = 10000000;
    int current = 0;
    for (int w = word; w <= n - 1; w++)
    {
        // Here we are making sure that we don't cross the maximum limit m.
        if (current + wordsLength[w] <= m)
        {
            // After pushing this word(wordsLength[w]) in the line, we will be updating the line’s capacity.
            current += wordsLength[w] + 1;
            // The variable cost is the cost calculated till now till now .
            int cost = m - current + 1;
            // The variable ans2 is the cost if we move to the next line on this word only.
            int ans2 = cost * cost * cost + calculateCost(w + 1, line + 1, wordsLength, dp, m);
            if (ans > ans2)
            {
                ans = ans2;
            }

        }

    }

    return res = ans;
}

int wordWrap(vector<string> words, int m, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<int>wordsLength;
    for (int i = 0; i < n; i++)
    {
        wordsLength.push_back(words[i].size());
    }

    int ans = calculateCost(0, 0, wordsLength, dp, m);
    return ans;
}
