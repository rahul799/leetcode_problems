1029. Two City Scheduling
Medium

1664

188

Add to List

Share
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

 

Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
Example 3:

Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086
 

Constraints:

2 * n == costs.length
2 <= costs.length <= 100
costs.length is even.
1 <= aCosti, bCosti <= 1000

How much money can we save if we fly a person to A vs. B? To minimize the total cost, we should fly the person with the maximum saving to A, and with the minimum - to B.

Example: [30, 100], [40, 90], [50, 50], [70, 50].
Savings: 70, 50, 0, -20.

Obviously, first person should fly to A, and the last - to B.

Solution
We sort the array by the difference between costs for A and B. Then, we fly first N people to A, and the rest - to B.



class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cs, int res = 0) {
  sort(begin(cs), end(cs), [](vector<int> &v1, vector<int> &v2) {
    return (v1[0] - v1[1] < v2[0] - v2[1]);
  });
  for (auto i = 0; i < cs.size() / 2; ++i) {
    res += cs[i][0] + cs[i + cs.size() / 2][1];
  }
  return res;
}
   
};


