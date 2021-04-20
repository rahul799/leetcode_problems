
https://www.geeksforgeeks.org/number-ways-insert-character-increase-lcs-one/?fbclid=IwAR1euGjovUEqiruK33b8S2SOO1N6zhY5S72FPEJL_NFxnZ8Fjp0nVzXMYCk#:~:text=So%2C%20we%20have%203%20%2B%201,longest%20common%20subsequence%20by%20one


Given two strings A and B. The task is to count the number of ways to insert a character in string A to increase the length of the Longest Common Subsequence between string A and string B by 1.

Examples:

Input : A = “aa”, B = “baaa”
Output : 4
The longest common subsequence shared by string A and string B is “aa”, which has a length of 2.
There are two ways that the length of the longest common subsequence can be increased to 3 by adding a single character to string A:

There are 3 different positions in string A where we could insert an additional ‘a’ to create longest common subsequence “aaa” (i.e at the beginning, middle, and end of the string).
We can insert a ‘b’ at the beginning of the string for a new longest common subsequence of “baaa”. So, we have 3 + 1 = 4 ways to insert an alphanumeric character into string A and increase the length of the longest common subsequence by one.



Let say for a given string A and string B, the length of their LCS is k. Let’s insert a single character ‘c’ after the ith character in string A and denote the string formed after the insertion as string Anew, which looks like:
Anew = A1, i . c . Ai + 1, n
where Ai, j denotes a substring of string A from the ith to the jth characters and ‘.’ denotes a concatenation of two strings.
Let’s define knew to be the length of the LCS of Anew and B. Now we want to know if knew = k + 1.
The crucial observation is that the newly inserted character ‘c’ must be a part of any common subsequence of Anew and B having length > k. We know this because if there is any common subsequence of Anew and B, this is a contradiction because it would mean the length of the LCS of A and B is > k.
Using the above observation, we can try the following approach. For each possible character ‘c'(there are 52 upper and lower case English letters and 10 Arabic digits, so there are 62 possible characters to insert) and for every possible insertion i in String A (there are |a| + 1 insertion positions), let’s try to insert ‘c’ after the ith character in string A and match it with every occurrence of ‘c’ in string B, we can try to match these ‘c’ characters such that:
A1, i . c . Ai+1, n
B1, j-1 . c . Bj+1, m



Now, in order to check if such an insertion produces an LCS of length k + 1, it’s sufficienet to check if the length of the LCS of A1, i and B1, j-1 plus the length of the LCS Ai+1, n and Bj+1, m is equal to k. In this case, the lCS of Anew and B is k + 1 because there is both a match between the fixed occurances of character ‘c’ and there is no longer common subsequence between them.

If we can quickly get the length of the LCS between every two prefixes of A and B as well as between every two of their suffixes, we can compute the result. The 
length of the LCS between their prefixes can be read from a Dynamic Programming table used in computing the LCS of string A and string B. In this method, dp[i][j] 
stores the length of longest common subsequence of A, i and Bi, j. Similarly, the length of the LCS between their suffixes can be read from an analogous dp table which can be computed during computation of the LCS of Areversed and Breversed where Sreversed denotes the reversed 
string S.



// CPP Program to Number of ways to insert a 
// character to increase LCS by one 
#include <bits/stdc++.h> 
#define MAX 256 
using namespace std; 

// Return the Number of ways to insert a 
// character to increase the Longest 
// Common Subsequence by one 
int numberofways(string A, string B, int N, int M) 
{ 
	vector<int> pos[MAX]; 

	// Insert all positions of all characters 
	// in string B. 
	for (int i = 0; i < M; i++) 
		pos[B[i]].push_back(i + 1); 

	// Longest Common Subsequence 
	int dpl[N + 2][M + 2]; 
	memset(dpl, 0, sizeof(dpl)); 
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= M; j++) { 
			if (A[i - 1] == B[j - 1]) 
				dpl[i][j] = dpl[i - 1][j - 1] + 1; 
			else
				dpl[i][j] = max(dpl[i - 1][j], 
								dpl[i][j - 1]); 
		} 
	} 
	int LCS = dpl[N][M]; 

	// Longest Common Subsequence from reverse 
	int dpr[N + 2][M + 2]; 
	memset(dpr, 0, sizeof(dpr)); 
	for (int i = N; i >= 1; i--) { 
		for (int j = M; j >= 1; j--) { 
			if (A[i - 1] == B[j - 1]) 
				dpr[i][j] = dpr[i + 1][j + 1] + 1; 
			else
				dpr[i][j] = max(dpr[i + 1][j], 
								dpr[i][j + 1]); 
		} 
	} 

	// inserting character between position 
	// i and i+1 
	int ans = 0; 
	for (int i = 0; i <= N; i++) { 
		for (int j = 0; j < MAX; j++) { 
			for (auto x : pos[j]) { 
				if (dpl[i][x - 1] + dpr[i + 1][x + 1] == LCS) { 
					ans++; 
					break; 
				} 
			} 
		} 
	} 

	return ans; 
} 

// Driver Program 
int main() 
{ 
	string A = "aa", B = "baaa"; 
	int N = A.length(), M = B.length(); 
	cout << numberofways(A, B, N, M) << endl; 
	return 0; 
} 
