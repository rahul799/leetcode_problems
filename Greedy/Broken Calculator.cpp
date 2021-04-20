
991. Broken Calculator


On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.

 

Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
Example 2:

Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.


We can solve it with both greedy and BFS


/* Initially, I am thinking about using BFS.. but the solution will easily get TLE...
 * Later, after analyze the problem in detail, 
 * I found:
 * (1) when X > Y... multiple by 2 will only bring us far away from target...
 *     so each step, we can only subtract 1 from X to get the target value...
 *     thus we just need to return X - Y;
 * (2) when Y > X... we can think reversely...
 *     we can achieve Y from the previous number by either of two cases 
 *     (a) pre - 1 = Y;
 *     (b) pre * 2 = Y...
 *     which step to take is dependent on if Y is even or odd...
 *     if (Y is even), pre = Y / 2;
 *     if (Y is odd), pre = Y + 1...
 *     then we reset Y as pre...
 *     do the same thing, until Y <= X... which is the first case...
 *         
 */

class Solution {
    public int brokenCalc(int X, int Y) {
        int cnt = 0;
        while (Y > X) {
            if ((Y & 1) == 1) {
                Y += 1;
                cnt++;
            } 
            Y >>= 1;
            cnt++;
        }  // this is to deal with the case when x > y
        return cnt + (X - Y);
    }
}





BFS approach:


// C++ program to find minimum number of steps needed 
// to convert a number x into y with two operations 
// allowed : (1) multiplication with 2 (2) subtraction 
// with 1. 
#include<bits/stdc++.h> 
using namespace std; 

// A node of BFS traversal 
struct node 
{ 
	int val; 
	int level; 
}; 

// Returns minimum number of operations 
// needed to convert x into y using BFS 
int minOperations(int x, int y) 
{ 
	// To keep track of visited numbers 
	// in BFS. 
	set<int> visit; 

	// Create a queue and enqueue x into it. 
	queue<node> q; 
	node n = {x, 0}; 
	q.push(n); 


	// Do BFS starting from x 
	while (!q.empty()) 
	{ 
		// Remove an item from queue 
		node t = q.front(); 
		q.pop(); 

		// If the removed item is target 
		// number y, return its level 
		if (t.val == y) 
			return t.level; 

		// Mark dequeued number as visited 
		visit.insert(t.val); 

		// If we can reach y in one more step 
		if (t.val*2 == y || t.val-1 == y) 
			return t.level+1; 

		// Insert children of t if not visited 
		// already 
		if (visit.find(t.val*2) == visit.end()) 
		{ 
			n.val = t.val*2; 
			n.level = t.level+1; 
			q.push(n); 
		} 
		if (t.val-1>=0 && visit.find(t.val-1) == visit.end()) 
		{ 
			n.val = t.val-1; 
			n.level = t.level+1; 
			q.push(n); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int x = 4, y = 7; 
	cout << minOperations(x, y); 
	return 0; 
} 

