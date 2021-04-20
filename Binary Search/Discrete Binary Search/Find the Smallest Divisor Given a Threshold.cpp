
class Solution { // binary search template based solution. 'left close, right open' philosophy, i.e.,  [)
public:// Time/Space: O(logN); Space: O(1)
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
		int right = *max_element(begin(nums),end(nums))+1; // Note, this is to ensure left close, right open [ )
        while(left < right){
            int mid = left + (right - left ) / 2;
            if(getSum(nums, mid) <= threshold) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
private:
    int getSum(vector<int>& nums, const int divisor){
        int ans = 0;
        for(auto num: nums) ans += num/divisor + (num%divisor > 0 ? 1: 0);
        return ans;
    }
};





Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.


Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 



Input: nums = [19], threshold = 5
Output: 4
