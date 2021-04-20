


List Splitting




Given a list of integers nums, and an integer k, return whether it's possible to split the list into lists such that each list has a length ≥ k and is strictly increasing. The list does not need to be split contiguously, that is, you can take integers from nums and place them in any list in any order.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input

nums = [5, 6, 4, 9, 12]
k = 2
Output

true
Explanation

One possible split is [4, 5] and [6, 9, 12].

Example 2
Input

nums = [5, 7, 7, 7]
k = 2
Output

false
Explanation

It's not possible to split this list so that each list is strictly increasing.






We know that the list have to be strictly increasing.
The number of lists we need is thus bounded by the most frequently appeared number.

We know that each list has to have at least K elements.
Thus, the total of numbers required is most_frequent_count*k.

We check whether nums.size() >= most_frequent_count*k, it is fine if we have more numbers than needed as we can simply append it to any of the list.

Time Complexity: O(N) for counting the most frequently appeared number
Space Complexity: O(N) in the worst case when all numbers are distinct.




#include "solution.hpp"
using namespace std;

class Solution {
    public:
    bool solve(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int most_frequent = 0;  // we need at least this amount of list
        for (int x : nums) {
            most_frequent = max(most_frequent, ++cnt[x]);
        }
        // since each list need at least k items =>
        // minimum number of items required = most_frequent*k
        // check if we have enough items
        return most_frequent * k <= nums.size();
    }
};


bool solve(vector<int>& nums, int k) {
    return (new Solution())->solve(nums, k);
}
