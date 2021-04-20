

1024. Video Stitching
Medium

634

30

Add to List

Share
You are given a series of video clips from a sporting event that lasted T seconds.  These video clips can be overlapping with each other and have varied lengths.

Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.

 

Example 1:

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Explanation: 
We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
Example 2:

Input: clips = [[0,1],[1,2]], T = 5
Output: -1
Explanation: 
We can't cover [0,5] with only [0,1] and [1,2].
Example 3:

Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
Output: 3
Explanation: 
We can take clips [0,4], [4,7], and [6,9].
Example 4:

Input: clips = [[0,4],[2,8]], T = 5
Output: 2
Explanation: 
Notice you can have extra video after the event ends.
 

Constraints:

1 <= clips.length <= 100
0 <= clips[i][0] <= clips[i][1] <= 100
0 <= T <= 100



class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
         int min = 0;
        int max = 0;
        int total =0;
        
        while(max<T){ 
            
            for(int i=0;i<clips.size();i++){
              int l = clips[i][0];
              int r = clips[i][1];
              if(l<=min && r>max){
                  max = r; 
              }
            }
            
            // edge case when the task to be done is not possible
            if(min==max) return -1;
            min = max;
            total++;
        }
        
        return total;
        
    }
};





class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        int i, j;
        /*
            dp[i] refers to the furthest valid duration that could be
            gained with i clips
            dp[i] = max(dp[i-1], clips[j][1] which clips[j][0] <= dp[i])
        */
        
        vector<int> dp = vector<int>(n + 1, -1);
        dp[0] = 0;
        for (i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            for (j = 0; j < n; j++) {
                if (clips[j][0] <= dp[i-1]) {
                    dp[i] = max(dp[i], clips[j][1]);
                }
            }
        }
        /*
			we get the smallest i such that dp[i] >= T
		*/
        for (i = 1; i <= n; i++) {
            if (dp[i] >= T) {
                return i;
            }
        }
        return -1;
    }
    
};







int videoStitching(vector<vector<int>>& clips, int T, int res = 0) {
  sort(begin(clips), end(clips));
  for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
    while (i < clips.size() && clips[i][0] <= st) end = max(end, clips[i++][1]);
    if (st == end) return -1;
  }
  return res;
}
