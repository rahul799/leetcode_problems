
435. Non-overlapping Intervals
Medium


Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.





class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int size = intervals.size(), amountRemoved = 0;
        if(size <=1) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b){
            return a[1] < b[1];
        });
        
        int previousEnd = intervals[0][1];
        
        for(int i = 1; i < size; i++){
            // if the current interval's start is less than the previous interval's end
			// (there is an overlap)
            if(intervals[i][0] < previousEnd){
                amountRemoved++;
            }
            // if there is no overlap, update previousEnd
            else previousEnd = intervals[i][1];
        }
        
        return amountRemoved;
        
    }
        
};






