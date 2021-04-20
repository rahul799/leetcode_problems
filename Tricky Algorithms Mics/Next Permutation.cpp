31. Next Permutation


Share
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1




// find position of number to be changed (first from the end, where n[i] < n[i+1])
  // find the smallest num past nums[indx] that is bigger than it
// (numbers past indx1 sorderd desending - just iterate while they are still larger)
 // sort past indx1 accending (if we didn't find the position - indx1 will be -1; so - will sort from 0)
// - since we know that part is already in decending order - just reverse it.




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            // first step is to find a point lesser than it's previous index
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
// second step is to swap that element with a number just greater than it from the end
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
            // third step is to swap them and reverse the remaining numbers
//     	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 

