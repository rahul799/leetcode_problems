


Unlock Rooms

https://binarysearch.com/problems/Unlock-Rooms

You are given a two-dimensional list of integers rooms. Each index i in rooms represents a room and rooms[i] represents different keys to unlock other rooms.

You are currently in an unlocked room 0 and every other room is locked. Given you can move freely between unlocked rooms, return whether you can unlock every room.




    void dfs(int start, vector<vector<int>>& rooms, bool* visited) {
        visited[start] = true;
        for (int i : rooms[start]) {
            if (!visited[i]) {
                dfs(i, rooms, visited);
            }
        }
    }

    bool solve(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) {
            return true;
        }
        bool* visited = new bool[rooms.size()]();
        dfs(0, rooms, visited);
        for (int i = 0; i < rooms.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }


