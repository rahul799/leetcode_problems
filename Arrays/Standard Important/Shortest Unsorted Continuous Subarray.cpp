581. Shortest Unsorted Continuous Subarray


Share
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=










// Approach is to find the start and the end index where there is some violation
int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int start = 0;
        int end = n - 1;
        
        while(start < n-1 && nums[start] <= nums[start+1])
            start++;
        if(start == n-1)
            return 0;
    
        while(end > 0 && nums[end] >= nums[end-1])
            end--;
        
     //[2, 6, 4, 8, 40 10, 9,  32, 45]
    
    
        // this may be a possible answer but we have to further check

        int minVal = nums[start];
        int maxVal = nums[start];
        
    
    // calculating the max and min value in a given ange
        for(int i=start; i<=end; i++)
        {
            if(nums[i] < minVal)
                minVal = nums[i];
            if(nums[i] > maxVal)
                maxVal = nums[i];
        }
        
    // check if there is any element greater than minimum --> make it the start index
        for(int i=0; i<start; i++)
        {
            if(nums[i] > minVal)
                start = i;
        }
        
        for(int i=end; i<n; i++)
        {
            if(nums[i] < maxVal)
                end = i;
        }
        
        return (end - start + 1);
    }



