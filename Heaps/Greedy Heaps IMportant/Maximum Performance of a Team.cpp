1383. Maximum Performance of a Team
Hard

308

23

Add to List

Share
There are n engineers numbered from 1 to n and two arrays: speed and efficiency, where speed[i] and efficiency[i] represent the speed and efficiency for the i-th engineer respectively. Return the maximum performance of a team composed of at most k engineers, since the answer can be a huge number, return this modulo 10^9 + 7.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers. 

 

Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
Example 2:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
Example 3:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
 

Constraints:

1 <= n <= 10^5
speed.length == n
efficiency.length == n
1 <= speed[i] <= 10^5
1 <= efficiency[i] <= 10^8
1 <= k <= n






class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        priority_queue<int, vector<int> , greater<int>> pq;
        vector<pair<int, int>> pairArray;
        for(int i = 0; i < n; i++){
            pairArray.emplace_back(efficiency[i], speed[i]);
        }
        
        sort(pairArray.begin(), pairArray.end(), greater<>());
        
        long sum = 0, result = 0;
        for(int i = 0; i < n; i++){
            
            sum += pairArray[i].second;
            if(i >= k) {
                int min = pq.top();
                pq.pop();
                sum -= min;
            }
            pq.push(pairArray[i].second);
            result = max(result, sum*pairArray[i].first);
        }
        return result%1000000007;
        
        
    }
};











