

https://binarysearch.com/problems/Create-Largest-Lexicographic-Number-From-a-List

Create Largest Lexicographic Number From a List
Question 52 of 866
Given a list of integers nums, rearrange its order to form the largest possible integer and return it as a string.

For example, given [10, 7, 76, 415], return the string "77641510".

Constraints

n ≤ 1,000 where n is the length of nums
nums[i] ≤ 1,000
Example 1
Input
nums = [10, 7, 76, 415]
Output
"77641510"
Example 2
Input
nums = [961, 745, 331, 794, 923]
Output
"961923794745331"
Example 3
Input
nums = [45, 14, 70, 67, 95]
Output
"9570674514"
Example 4
Input
nums = [70, 5, 94, 18, 78]
Output
"947870518"




string solve(vector<int>& _nums) {
    // if i have two numbers
    // i can try both the ways to combine them
    // and select the larger way!
    vector<string> nums;
    for (const int& num : _nums) {
        nums.push_back(to_string(num));
    }

    // now i just sort these to give the biggest value
    sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
        string ab = a + b, ba = b + a;
        return ab > ba;
    });

    string res = "";
    for (const string& num : nums) {
        res += num;
    }

    return res;
}
