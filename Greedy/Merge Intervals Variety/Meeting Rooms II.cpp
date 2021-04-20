


253. Meeting Rooms II
Medium

3228

53

Add to List

Share
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.







Intuition
Track the change of room numbers in time order.

Explanation:

Save all time points and the change on current meeting rooms.
Sort all the changes on the key of time points.
Track the current number of using rooms cur and update result res








class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) {
            return 0;
        }
        map<int, int> map;
        for(auto interval : intervals) {
            map[interval.start]++;
            map[interval.end]--;
        }
        int count = 0;
        int result = 0;
        for(auto it = map.begin() ; it != map.end() ; ++it) {
            count = count + it -> second;
            result = max(result, count);
        }
        return result;
    }
};




 int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &t : intervals)
            m[t[0]]++, m[t[1]]--;
        int cur = 0, res = 0;
        for (auto &it : m)
            res = max(res, cur += it.second);
        return res;
    }
    
    


// greedy : always change the smallest end time;
// heap : min_heap
// sort : sort the intervals by start time O(nlogn)
int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval &i, Interval &j){return i.start < j.start;});
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto interval : intervals){
        if(!min_heap.empty() && min_heap.top() <= interval.start) min_heap.pop();
        min_heap.push(interval.end);
    }
    return min_heap.size();
}
