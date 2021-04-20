



 bubbleSort(nums);


    1. Bubble sort:
    Worstcase time: O(n^2), Bestcase Time: O(n) -  list already sorted, Space: O(1)
    
    void bubbleSort(vector<int>& nums){
         for(int i=0;i<nums.size()-1;i++){
            for (int j=0;j<nums.size()-i-1;j++){
                if (nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return nums;
    }
};
    
 
 
 2. Insertion sort: (Inserting ith element in the proper position)
    Worstcase time: O(n^2), Bestcase Time: O(n) - list already sorted, Space: O(1)
    */
    vector<int> insertionSort(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int j = i;
            while (j>0 && nums[j-1]>nums[j]){
                swap(nums[j],nums[j-1]);
                j--;
            }
        }
        return nums;   
    }
    
    
  /*
    3. Selection sort: (Select the  min/max value based on current element and swap it)
    Worstcase time: O(n^2), Bestcase Time: O(n^2), Space: O(1)
    */
    vector<int> selectionSort(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int minIndex = i;
            for (int j=i+1;j<nums.size();j++){
                if (nums[minIndex]>nums[j])
                    minIndex = j;
            }
            swap(nums[i], nums[minIndex]);
        }
        return nums;
    }
    
    
    
     6. Quick sort:
    Worstcase time: O(n^2), Bestcase Time: O(nlogn), Ave: O(nlogn), Space: O(1)-- not including recursive function stack space.
    Quicksort uses divide-and-conquer approach.
    1. Base operation: find pivot element
    2. Divide and concure art: divide the array into two halves and recursselvy quicksort the array
    3. Combine part do nothing
    best case and avg case when partition element is around middle and in that case
    T(n) = O(n) + 2T((n-1)/2) + Nothing -- best case 
    T(n) = O(n) + T(9n/10)+ T(n/10) -- > O(n logn) -- averge case
    Worstcase when partition element is around start and end every time -- revered sorted input list provided here:
    T(n) = O(n) + T(n-1) + Nothing -- > O(n + n-1 + n-2 + .. ) --> O(n^2)
    We can use randomized quicksort which gives worst case complexity as O(n logn) by picking pivot element randomly.  But it can not gurantee, complexity can go to O(n^2) here also.
    */
    
    int partitionIndex(vector<int>& nums, int low, int high){
        int index = low-1;
        for (int j=low;j<=high;j++){
            if (nums[j]<= nums[high]){
                index++;
                swap(nums[index], nums[j]);
            }
        }
        return index;
    }
    void quickSortHelper(vector<int>& nums, int low, int high){
        if (low<high){
            int p = partitionIndex(nums, low, high);
            quickSortHelper(nums, low, p-1);
            quickSortHelper(nums, p+1, high);
        }
    }
    vector<int> quickSort(vector<int>& nums) {
        quickSortHelper(nums, 0, nums.size()-1);
        return nums;
    }
    /*
    Note considering high index for finding partition element gives O(n^2) time complexity in case list is sorted in reverse order. So to increase the probability of getting O(nlogn) complexity, randomized quick sort can be used. 
    int partitionIndex(vector<int>& nums, int low, int high){
        int randIndex = low + rand()%(high-low+1);
        swap(nums[randIndex], nums[high]);
        int index = low-1;
        for (int j=low;j<=high;j++){
            if (nums[j]<= nums[high]){
                index++;
                swap(nums[index], nums[j]);
            }
        }
        return index;
    }
    */
   
