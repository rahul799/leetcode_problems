




https://www.evernote.com/shard/s654/client/snv?noteGuid=ed29e6fd-226a-4808-9fc1-9a7827e5e26a&noteKey=5da51370c90e9d8709ce41ed71318e87&sn=https%3A%2F%2Fwww.evernote.com%2Fshard%2Fs654%2Fsh%2Fed29e6fd-226a-4808-9fc1-9a7827e5e26a%2F5da51370c90e9d8709ce41ed71318e87&title=Lots%2Bof%2BDriving%2B%257C%2BCodeChef

https://www.ideone.com/Hl5pYf

Lots of Driving Problem Code: DRIVINGC 




You will get two points for solving this problem.
You are given a grid with R rows and C columns. You are also given a robot which is very small and can be placed on the grid - to walk around 
in the grid. You will place the robot at some starting cell of your choosing. You will give the robot an initial direction. Then, when you start 
the robot, it will walk in the given direction till it gets out of the grid or encounters a "turn" cell in the grid.
Each cell in the grid is either empty (depicted by '.') or a turn cell (depicted by 'r' or 'l'). When the robot encounters a turn cell with 'r', 
it will turn right on that cell. Note that this turn will be relative to the direction in which the robot is moving. Similarly, when the robot 
encounters a turn cell with 'l', it will turn left on that cell. The examples and explanations clarify this.
The robot will eventually leave the grid or enter a loop. You wish to choose a start point and direction for the robot such that it visits the 
maximum number of unique cells. Note that the start point you select must be an empty cell.
Print the maximum number of unique cells the robot will visit when you choose such a starting point.
Input
The first line of input contains a number T, the number of test cases. Then follows the description of T test cases. The first line of each 
test case contains two intgers R and C. On the next R lines are exactly C characters each. Each character is either '.', 'r' or 'l'.
Output
For each test case, output a single number on a line by itself. This number should be the maximum number of unique cells the robot can visit 
if you place it optimally.
Constraints
1 ≤ T ≤ 20
1 ≤ R ≤ 20
1 ≤ C ≤ 20

Sample Input
3
3 5
.....
...r.
...r.
2 2
..
..
1 5
.r...

Sample Output
8
2
4

Explanation
We will assume that the rows are labeled from 1 to R from top to bottom and columns are labeled from 1 to C from left to right.
In the first test case the optimal choice is to keep the robot at 2,1 facing east. The robot will move as 2,1 - 2,2 - 2,3 - 2,4 and then turn right, facing south. The robot will then move as 2,4 - 3,4 and then turn right, facing west. The robot will then move as 3,4 - 3,3 - 3,2 - 3,1 and then leave the grid. The robot touched 8 unique cells.
In the second test case you cannot optimise robot placement. No matter what you do, you can only touch 2 different cells.
In the third test case the optimal choice is to place the robot on 1,5 facing west.








#include<bits/stdc++.h>
 
using namespace std;
 
set<pair<int, int> > visited;
 
void travel(vector<string> g, int i, int j, int x, int y) {
	if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) return;	
 
	if(visited.find(make_pair(i, j)) == visited.end()) {
		visited.insert(make_pair(i, j));
		if(g[i][j] == '.') {			
			travel(g, i + x, j + y, x, y);
		}
		if(g[i][j] == 'l') {
			if(x == -1 && y == 0) { //Up
				x = 0; y = -1;
				travel(g, i + x, j + y, x, y);
			}
			if(x == 1 && y == 0) { //Down
				x = 0; y = -1;
				travel(g, i + x, j + y, x, y);
			}
			if(x == 0 && y == -1) { //Left
				x = 1; y = 0;
				travel(g, i + x, j + y, x, y);
			}
			if(x == 0 && y == 1) { //Right
				x = -1; y = 0;
				travel(g, i + x, j + y, x, y);
			}
		}
		if(g[i][j] == 'r') {
			if(x == -1 && y == 0) { //Up
				x = 0; y = 1;
				travel(g, i + x, j + y, x, y);
			}
			if(x == 1 && y == 0) { //Down
				x = 0; y = -1;
				travel(g, i + x, j + y, x, y);
			}
			if(x == 0 && y == -1) { //Left
				x = -1; y = 0;
				travel(g, i + x, j + y, x, y);
			}
			if(x == 0 && y == 1) { //Right
				x = 1; y = 0;
				travel(g, i + x, j + y, x, y);
			}
		}
	}
	return;
}
 
int solve(vector<string> g, int i, int j) {
	visited.clear();
	travel(g, i, j, -1, 0);
	int up = visited.size();
 
	visited.clear();
	travel(g, i, j, 0, -1);		
	int left = visited.size();
 
	visited.clear();
	travel(g, i, j, 0, 1);
	int right = visited.size();
 
	visited.clear();	
	travel(g, i, j, 1, 0);
	int down = visited.size();	
 
	return max(up, max(down, max(left, right)));
}
 
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int r, c; cin >> r >> c;
		vector<string> grid;
		string s;
		for(int i = 0;i < r;i++) {
			cin >> s;
			grid.push_back(s);
		}
		int mx = 0;
		for(int i = 0;i < r;i++) {
			for(int j = 0;j < c;j++) {
				if(grid[i][j] == '.')
					mx = max(mx, solve(grid, i, j));
			}
		}
 
		cout << mx << endl;
	}
	return 0;
}
