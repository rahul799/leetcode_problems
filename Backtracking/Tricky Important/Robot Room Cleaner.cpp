
489. Robot Room Cleaner



Add to List

Share
Given a robot cleaner in a room modeled as a grid.

Each cell in the grid can be empty or blocked.

The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

Design an algorithm to clean the entire room using only the 4 given APIs shown below.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
Example:

Input:
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3

Explanation:
All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.
Notes:

The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
The robot's initial position will always be in an accessible cell.
The initial direction of the robot will be facing up.
All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
Assume all four edges of the grid are all surrounded by wall.
Accepted







class Solution {
private:
	int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    //up,right,down,left

	set<pair<int,int>> visited;

public:
	void goBack(Robot& robot)
	{
		//turn back
		robot.turnRight();
        robot.turnRight();

        robot.move(); //move one cell back

        //go back to the direction it was in before
        robot.turnRight();
        robot.turnRight();
	}

	void backtrack(Robot& robot, int row, int col, int dir)
	{
        visited.insert(make_pair(row,col));
		robot.clean();
		
		//explore all directions from current pos
		for(int i=0; i<4; i++)
		{
            int newD = (dir + i) % 4;
                
			int nextRow = row + directions[newD][0];
			int nextCol = col + directions[newD][1];
            //order is imp because if visited, don't move robot
			if(visited.count(make_pair(nextRow,nextCol)) == 0 && robot.move())
			{
				backtrack(robot,nextRow,nextCol,newD);

				//robot.move moved robot in i direction 
                //so get back to original cell to explore other directions from it
				goBack(robot);
			}
			robot.turnRight();
		}
	}

    void cleanRoom(Robot& robot) {
        //defining origin at starting position
        int row = 0, col = 0, dir = 0;
        backtrack(robot,0,0,0);
    }
};
