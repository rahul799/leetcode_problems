229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]





// what we do is we assign 0 zero index candidates as majority eleemnt

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1(0), candidate2(0), count1(0), count2(0);
        for(auto x: nums){
            if(count1 == 0 && x != candidate2) candidate1 = x;
            if(count2 == 0 && x != candidate1) candidate2 = x;
            if(x == candidate1) count1++;
            if(x == candidate2) count2++;
            if(x != candidate1 && x != candidate2) count1--, count2--;
        }
        int check1(0), check2(0);
        for(auto x: nums){
            if(x == candidate1) check1++;
            else if(x == candidate2) check2++;
        }
        if(check1 > nums.size()/3 && check2 > nums.size()/3) return {candidate1, candidate2};
        if(check1 > nums.size()/3) return {candidate1};
        if(check2 > nums.size()/3) return {candidate2};
        return vector<int>();
    }
};
