Given strings a, b, and c, return the length of their longest common subsequence.

A subsequence of a string is defined as deleting some or no characters of the original string without changing the order of the remaining characters.

Constraints

Length of a, b, and c ≤ 100
Example 1
Input

a = "epidemiologist"
b = "refrigeration"
c = "supercalifragilisticexpialodocious"
Output

5




#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(string a, string b, string c) {
        int m = a.size(), n = b.size(), o = c.size();
        	int L[m+1][n+1][o+1];
        	//cout << L[m+1][n+1][o+1];
        for(int i = 0; i <=m; i++){
		    for (int j=0; j<=n; j++) 
		{ 
			for (int k=0; k<=o; k++) 
			{ 
				if (i == 0 || j == 0||k==0) 
					L[i][j][k] = 0; 

				else if ((a[i-1] == b[j-1]) && (a[i-1]==c[k-1])) 
					L[i][j][k] = L[i-1][j-1][k-1] + 1; 

				else
					L[i][j][k] = max(max(L[i-1][j][k], 
										L[i][j-1][k]), 
									L[i][j][k-1]); 
			} 
		} 
	}
	return L[m][n][o];

    }
};

