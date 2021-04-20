
DDoS Protection
Question 435 of 987



https://binarysearch.com/problems/DDoS-Protection



You are given a two-dimensional integer list requests where each list contains elements [user_id, timestamp_sec]. Each list represents a user's request to a website at a timestamp in seconds.

You are also given integers u and g where

u is the maximum number of requests that are allowed in any < 60 second window for a given user_id.
g is the maximum number of requests that are allowed in any < 60 second window globally.
We'd like to process each request one by one and rate limit them. If there are requests at the same time by multiple users, requests with lower user_id are processed first. If any request violates the above rules, it gets dropped.

Return the total number of requests that will be successfully processed.

Constraints

n ≤ 100,000 where n is the length of requests
Example 1
Input
requests = [
    [0, 1],
    [0, 2]
]
u = 1
g = 5
Output
1
Explanation
In this example, a user can send at most 1 request in any 60 second window. Since user 0 makes 2 requests in succession, the second request gets dropped.

Input
requests = [
    [0, 1],
    [0, 61]
]
u = 1
g = 5
Output
2
Explanation
User 0 makes 2 requests but since it's been 60 seconds since the first request, the second request is allowed.

Example 3
Input
requests = [
    [0, 1],
    [1, 2],
    [2, 3]
]
u = 1
g = 2
Output
2
Explanation
The third request is dropped since it violates global rule of at most 2 requests per 60 seconds.

Example 4
Input
requests = [
    [0, 1],
    [0, 2],
    [1, 3],
    [1, 4]
]
u = 2
g = 4
Output
4
Explanation
Both user 0 and 1 are allowed 2 requests each per 60 seconds.





The idea is to use queues to find the number of requests in 60 sec window.
Let the time stamps be 1,23,67,90,180 consider there is only a single user.
The value of u be 1.
1)first we have to check if the queue has any timestamps stored in it that don't belong to our latest 60 second window. If they exist, we pop them off.
2)check the size of the queue, which gives the no of requests that are present in the latest 60 sec window.
3)Based on the size push the timestamp into queue, and increment a counter ,that stores no of processed requests.

queue<int>q;
count=0;
u=1;
time :1 window:[0,0] size of window=0 q.size()=0 =>q.push(1) count=1
time:23 window:[1,23] size of window=22 q.size()=1=>ignore the request count=1
time:67 window:[67,67] size of window=44 q.size()=0=>q.push(67) count=2
time:90 window:[90,90] size of window=90 q.size()=1=>ignore the request count=2
time:180 window:[180,180] size of window=0 q.size()=0=>q.push(1) count=3

Here timestamps have been popped off to get the no of requests in latest 60 second time window. The time window comes from timestamp-60, the timestamps whose
value is not within timestamp-60 and timestamp are
popped off.





bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
int solve(vector<vector<int>>& req, int u, int g) {
    // queue to store timestamps of all accepted requests
    queue<int> q;
    // every user has a queue which has timestamps of all accepted requests
    unordered_map<int, queue<int>> map;
    // sort based timestamp and user id as given in question
    sort(req.begin(), req.end(), comp);
    // count:stores no of requests inserted into queues when they are eligible and overcome u
    // and g constraints
    int count = 0;
    int n = req.size();
    for (int i = 0; i < n; i++) {
        int user = req[i][0];
        int time = req[i][1];
        // if there are any requests in queue with time diff of 60s, we pop them off so that
        // size of queue q helps us to check no of global requests in that 60 seconds window
        while (q.size() && time - q.front() >= 60) {
            q.pop();
        }
        // same goes with queue of a user, pop of the timestamps that are not going to be in the
        // lastest 60 second window
        while (map[user].size() && time - map[user].front() >= 60) {
            map[user].pop();
        }
        // compare the sizes of queues with u and g,push them into queues and increment the
        // counter
        if (q.size() < g && map[user].size() < u) {
            map[user].push(time);
            q.push(time);
            count++;
        }
        // if above conditions are not satisfied we ignore that request,we wont push timestamp
        // into user queue and global queue
    }
    return count;
}
