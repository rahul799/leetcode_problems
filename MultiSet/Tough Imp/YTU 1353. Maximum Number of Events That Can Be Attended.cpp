1353. Maximum Number of Events That Can Be Attended
Medium

592

81

Add to List

Share
Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.





Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
Example 3:

Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4
Example 4:

Input: events = [[1,100000]]
Output: 1
Example 5:

Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105





Intuition:

Let's say you are on day i right now. What is the best option you have? See what all events are on, and choose the one that ends the earliest so that you can attend the
	later ending event afterwards. Think of it like, why would you leave an event of short duration. It'll anyways get over soon. You can attend the later ending event
	after this if possible. Right?
How to see which event is on? Maintain a multiset and store the end days of the events as you iterate. So sort the events by the start days.
Do not forget to remove the events which have got over on ith day.


		
1. Sort the events by the start time and in case of tie by the end time in ascending order.

2. Loop over the sorted events. Attend as much as you can and keep the last day occupied. When you try to attend new event keep in 
mind the first day you can attend a new event in 






bool arrange(vector<int> & v1, vector<int> &v2){
    return v1[1] < v2[1];
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if(events.size() == 0 ){
            return 0;
        }
        int i, j, noOfEvents = 0;
        set<int> s;
        sort(events.begin(),events.end(),arrange);
        int n = events.size();
        int lastDay = events[n-1][1];
        for(i = 0; i <= lastDay; i++){
            s.insert(i);
        }
	
	
	 # We will check the start in unique day set. if it is not present, we simply add this.
        # else, we will check next start, and will add all start date until we reach to finish date
	
	
        for(i = 0; i < events.size(); i++){
            auto day = s.lower_bound(events[i][0]);
            if(day == s.end() || *day > events[i][1]){
                continue;
            }else{
                noOfEvents++;
                s.erase(day);
            }
        }
        return noOfEvents;
    }
};




class Solution {
public:
	static const bool mySort(vector<int> &a, vector<int> &b) {
		if (a[0] != b[0]) {
			return a[0] < b[0];
		}
		return a[1] < b[1];
	}

	int maxEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end(), mySort);

		int n = events.size();
		int ans = 0;
		int i = 0;

		multiset<int> s;
		for (int d = 1; d < 100001; ++d) {
			while (!s.empty() && *(s.begin()) < d) {
				s.erase(s.begin());
			}

			while (i < n && events[i][0] == d) {
				s.insert(events[i][1]);
				i++;
			}

			if (s.size() > 0) {
				ans++;
				s.erase(s.begin());
			}
		}

		return ans;

	}
};






