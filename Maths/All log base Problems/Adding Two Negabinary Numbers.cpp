1073. Adding Two Negabinary Numbers
Medium

137

63

Add to List

Share
Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

 

Example 1:

Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
Example 2:

Input: arr1 = [0], arr2 = [0]
Output: [0]
Example 3:

Input: arr1 = [0], arr2 = [1]
Output: [1]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
arr1[i] and arr2[i] are 0 or 1
arr1 and arr2 have no leading zeros












class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    deque<int> ans;
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    while (carry || i >= 0 || j >= 0) {
      if (i >= 0)
        carry += arr1[i--];
      if (j >= 0)
        carry += arr2[j--];
      ans.push_front(carry & 1);
      carry = -(carry >> 1);
    }

    while (ans.size() > 1 && ans.front() == 0)
      ans.pop_front();

    return {begin(ans), end(ans)};
  }
};



