Dice Throw | DP-30

Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.



// C++ program to find number of ways to get sum 'x' with 'n' 
// dice where every dice has 'm' faces 
#include <iostream> 
#include <string.h> 
using namespace std; 

// The main function that returns number of ways to get sum 'x' 
// with 'n' dice and 'm' with m faces. 
int findWays(int m, int n, int x) 
{ 
	int table[n + 1][x + 1]; 
	memset(table, 0, sizeof(table)); // Initialize all entries as 0 

	// Table entries for only one dice 
	for (int j = 1; j <= m && j <= x; j++) 
		table[1][j] = 1; 

	// i: number of dice, j: sum 
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= x; j++) 
			for (int k = 1; k <= m && k < j; k++) 
				table[i][j] += table[i-1][j-k]; 

	/* Uncomment these lines to see content of table 
	for (int i = 0; i <= n; i++) 
	{ 
	for (int j = 0; j <= x; j++) 
		cout << table[i][j] << " "; 
	cout << endl; 
	} */
	return table[n][x]; 
} 

