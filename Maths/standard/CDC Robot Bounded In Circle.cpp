
1041. Robot Bounded In Circle
Medium

983

291

Add to List

Share
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.
Example 3:

Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'






First of all, this isn't an easy question. I thought hard about this one. there are two things I found important. One, if you end up where you started, it is a circle.
  Two, if you end up in a different place with facing north (again), hence you are drifting away. All other scenarios are going to be in a circle (or come back)
    in infinity no matter. You can think that the starting and the end point form a vector. Unless the end direction is north, concataned vectors will always
    end up on the starting point eventually (infinity).

  
  
  
  
  
  
    public boolean isRobotBounded(String instructions) {
        int[] cur = new int[] {0, 0};
        int[][] dirs = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int dir = 0; // 0:north(up), 1: right, 2: down, 3: left
        
        for (char in : instructions.toCharArray()) {
            if (in == 'G') {
                cur[0] += dirs[dir][0];
                cur[1] += dirs[dir][1];
            } else if (in == 'L') {
                dir = (dir + 3) % 4;
            } else {
                dir = (dir + 1) % 4;
            }
        }
        if (cur[0] == 0 && cur[1] == 0) { // ended up at the same place
            return true;
        }
        if (dir == 0 && !(cur[0] == 0 && cur[1] == 0)) { // if the direction is north and location has changed
            return false;
        }
        return true; // it is always true
    }








 bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
