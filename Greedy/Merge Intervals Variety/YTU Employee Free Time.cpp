


759. Employee Free Time
Hard

732

51

Add to List

Share
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

 

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
 

Constraints:

1 <= schedule.length , schedule[i].length <= 50
0 <= schedule[i].start < schedule[i].end <= 10^8







Approach #1: Events (Line Sweep) [Accepted]
Intuition



Use a sorted associative array m to store all employee's intervals. Then perform a linear scan of m tracking each previous interval's end with each current interval's begin to see if a gap of free time exists.
If some interval overlaps any interval (for any employee), then it won't be included in the answer. So we could reduce our problem to the following: given a set of intervals, find all places where there are no intervals.

To do this, we can use an "events" approach present in other interval problems. For each interval [s, e], we can think of this as two events: 
balance++ when time = s, and balance-- when time = e. We want to know the regions where balance == 0.

Algorithm

For each interval, create two events as described above, and sort the events. Now for each event occuring at time t, if the balance is 0, then the 
preceding segment [prev, t] did not have any
intervals present, where prev is the previous value of t.


Complexity Analysis

Time Complexity: O(C\log C)O(ClogC), where CC is the number of intervals across all employees.

Space Complexity: O(C)O(C).

Approach #2: Priority Queue [Accepted]
Intuition

Say we are at some time where no employee is working. That work-free period will last until the next time some employee has to work.

So let's maintain a heap of the next time an employee has to work, and it's associated job. When we process the next time from the heap, 
we can add the next job for that employee.

Algorithm

Keep track of the latest time anchor that we don't know of a job overlapping that time.

When we process the earliest occurring job not yet processed, it occurs at time t, by employee e_id, and it was that employee's e_jx'th job. 
If anchor < t, then there was a free interval Interval(anchor, t)








vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
       
        priority_queue<pair<int,int> >q;
        
        int lastBusyTimeSoFar = -1;
        
        for (int i = 0 ; i < schedule.size(); ++i)
        {
            vector<Interval> busyTimes = schedule[i];
            
            for (int j = 0 ; j < busyTimes.size(); ++j)
                q.push(make_pair(-busyTimes[j].start, - busyTimes[j].end));
        }
        
        vector<Interval> result;
        
        while ( !q.empty() )
        {
            int s = -q.top().first;
            int e = -q.top().second;
            
            q.pop();
            
            if (lastBusyTimeSoFar == -1)
                lastBusyTimeSoFar = e;
            else
            {
                if ( s > lastBusyTimeSoFar) // found a gap
                {
                    result.push_back(Interval(lastBusyTimeSoFar, s));
                }
                
                if (e > lastBusyTimeSoFar)
                    lastBusyTimeSoFar = e;
            }
        }
        
        return result;
    }
    
    
    
    
    
    Use a sorted associative array m to store all employee's intervals. Then perform a linear scan of m tracking each previous interval's 
    end with each current interval's begin to see if a gap of free time exists.
    
    
    class Solution {
public:
    using VI = vector<Interval>;
    using VVI = vector<VI>;
    using Map = map<int, int>;
    VI employeeFreeTime(VVI A, Map m = {}, VI ans = {}) {
        for (auto& employee: A)
            for (auto& i: employee)
                m[i.start] = max(m[i.start], i.end);
        auto pre = m.size() ? m.begin()->first : 0; // init previous end to current begin
        for (auto [cur, end]: m) {
            if (pre < cur)
                ans.emplace_back(Interval(pre, cur)); // gap [previous end 👉 current begin] 🎯
            pre = max(pre, end); // previous end is maximum end seen so far
        }
        return ans;
    }
};
    
    
