
Online Meeting Rooms
Implement a data structure which implements the following method:

schedule(int start, int end) which means to book an event from [start, end], inclusive. It returns the minimum number of meeting rooms you need to host all the events that's been scheduled so far.
Constraints

0 ≤ n ≤ 100,000 where n is the number of calls to schedule
Example 1
Input
methods = ["constructor", "schedule", "schedule", "schedule", "schedule"]
arguments = [[], [0, 5], [2, 6], [0, 7], [8, 9]]`
Output
[null, 1, 2, 3, 3]
Explanation
c = OnlineMeetingRooms()
c.schedule(0, 5) == 1
c.schedule(2, 6) == 2
c.schedule(0, 7) == 3
c.schedule(8, 9) == 3




Intuition
This question can be solved using a ordered map mp. As events come, you increment mp[start] by 1 and decrement mp[end] by 1. That is, when the meeting starts, you add one room and when the meeting ends, you vacate the room. Then you iterate over the map counting the values, and return the max value.

To account for the cases with start_time == end_time, you can increment all the event end times by 1. This does not change the final solution, and solves the problem elegantly.

Implementation
mp[start]++ adds one room when the event starts
mp[end]-- vacates the room when the event ends
The following for loop just iterates over this map, and adds the values to a variable booked. The final answer is the maximum value of booked.

Example #1
Let's say our input was [[1, 5], [2, 3]]. After the first meeting, mp = {1 : 1, 5 : -1}. After the second meeting, mp = {1 : 1, 2 : 1, 3 : -1, 5 : -1}. So the booked variable takes the value 1, 2, 1, 0 in the iteration. We return 2 which is max(booked)

Time Complexity
\mathcal{O}(n\log n )O(nlogn) since we use a ordered map to insert the meetings.

Space Complexity
\mathcal{O}(n)O(n) to store all the meetings and the counts.

class OnlineMeetingRooms {
    public:
    map<int, int> mp;

    OnlineMeetingRooms() {
    }

    int schedule(int start, int end) {
        end += 1;  // extend the end time by 1, this will not affect the answer but account cases
                   // like start_time == end_time correctly.
        mp[start]++;
        mp[end]--;
        int booked = 0;

        int result = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            booked += it->second;
            result = max(result, booked);
        }

        return result;
    }
};
