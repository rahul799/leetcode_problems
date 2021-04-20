


You are given a list of integers stairs and an integer k. You are currently at stair 0 and want to climb to the last index of stairs. The cost of using stair 
i is stairs[i] and in each round you can either jump 1, 2, ... k, stairs at once.

Return the minimum cost to climb to the last stair.



I'm posting all my three Solutions that I have done. I have mentioned the time complexities of all the solutions.
First, I tried to solve it using DP. But it gave TLE. In DP we will be checking all possible K moves in each index from 0 to n.
Second approach is by using Min Heap. If you Dry run the examples you will get to know that all we need is Minimum value in the K window and add the current stairs cost. And we can find the minimum value in the K window by using Min Heap.

Now, the Third one is just the extension of the second one.
We can also find Minimum element in a K window by using deque. If you have solve the problem, finding Maximum/Minimum element of all Subarray of size K, then you can easily understand the Solution. If not then I recommend you to understand ( https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/ ) how we can find minimum/maximum value of all subarray of size K.
Using this approach we can find our solution in O(n) time





#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& stairs, int k) {
        // Using Deque (O(n))[Accepted]
        deque<pair<int, int>> dq;
        int n = stairs.size();
        dq.push_back({stairs[0], 0});
        for (int i = 1; i < n; ++i) {
            while (i - dq.front().second > k) dq.pop_front();
            int curr = dq.front().first;
            curr += stairs[i];
            while (!dq.empty() && curr <= dq.back().first) dq.pop_back();
            dq.push_back({curr, i});
        }
        return dq.back().first;
    }
};

// Using Priority Queue(Accepted)
// Time Complexity:- O(n*logk)
// int solve(vector<int>& stairs, int k) {
// priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// int n=stairs.size();
// pq.push({stairs[0],0});
// for(int i=1; i<n; ++i)
// {
//     while(i-pq.top().second>k)
//         pq.pop();
//     int curr=pq.top().first;
//     curr+=stairs[i];
//     pq.push({curr,i});
// }
// return pq.top().first+stairs[n-1];
// }

// Using Dynamic Programming:- (Not Accepted)(TLE)
// Time Complexity:- O(n*k)

// vector<int> DP;
// int solve(vector<int>& stairs, int k) {
//     int n=stairs.size();
//     DP.resize(n+1,-1);
//     return F(stairs,n,0,k);
// }
// int F(vector<int> &stairs, int n, int i, int k)
// {
//     if(i>=n-1) return stairs[n-1];
//     if(DP[i]!=-1) return DP[i];
//     int y=INT_MAX;
//     vector<int> arr(k+1,0);
//     for(int x=1; x<=k; ++x)
//     {
//         arr[x]=F(stairs,n,i+x,k)+stairs[i];
//         y=min(arr[x],y);
//     }
//     return DP[i]=y;
// }

int solve(vector<int>& stairs, int k) {
    return (new Solution())->solve(stairs, k);
}
