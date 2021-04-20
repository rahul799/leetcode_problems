Leetcode 153: Find Minimum in Rotated Sorted Array
Detailed video explanation: https://youtu.be/OXkLNPalfRs
===================================================

C++:
---
int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) l = mid+1;
            else if(nums[mid] < nums[r]) r = mid;
            else return nums[r];
        }
        return nums[l];
    }
