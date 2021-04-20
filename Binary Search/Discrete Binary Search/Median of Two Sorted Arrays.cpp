
LeetCode 4. Median of Two Sorted Arrays
Binary Search
​

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
Constraints:

nums1.length == m

nums2.length == n

0 <= m <= 1000

0 <= n <= 1000

1 <= m + n <= 2000

-10^6 <= nums1[i], nums2[i] <= 10^6



class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        total = len(nums1) + len(nums2)
        half = total // 2
        
        if len(B) < len(A):
            A, B = B, A
        
        l, r = 0, len(A) - 1
        while True:
            i = (l + r) // 2 # A
            j = half - i - 2 # B
        
            Aleft = A[i] if i >= 0 else float("-infinity")
            Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")
            Bleft = B[j] if j >= 0 else float("-infinity")
            Bright = B[j + 1] if (j + 1) < len(B) else float("infinity")
        
            # partition is correct
            if Aleft <= Bright and Bleft <= Aright:
                # odd
                if total % 2:
                    return min(Aright, Bright)
                # even
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            elif Aleft > Bright:
                r = i - 1
            else:
                l = i + 1
                
                
    
    
    
   The idea is to find the smaller half of the numbers with a binary search on the the short string. Assume we have two sorted sequences: a[0], a[1], ... a[L1] and b[0], b[1]...b[L2] where L1 >= L2. We are using binary search to find an i so that a[0], a[1], ... a[m-i-2] and b[0], b[1]...b[i], where m = (L1+L2+1)/2, are the first m smallest numbers of the combined sequence. This is equivlent to a[m-i-2] <= b[i+1] and b[i] <= a[m-i-1].

class Solution {
    double search(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), m = (n1+n2)/2; 
        // second one is empty
        if (n2 == 0) {
            if (n1%2 == 1) return nums1[n1/2]*1.0;
            else return (nums1[n1/2-1] + nums1[n1/2])/2.0;
        }
        
        // second one could be put in front of the fist one to make a sorted string
        if (nums2[n2-1] < nums1[0]) {
            if ((n2+n1)%2 == 1) return 1.0*nums1[m-n2];
            else {
                if (n1 == n2) return (nums1[0] + nums2[n2-1])/2.0;
                else return (nums1[m-n2-1] + nums1[m-n2])/2.0;
            }
        }
        
        // second one has no impact on the result
        if (nums2[0] >= nums1[n1-1] || (n1 > m && nums2[0] >= nums1[m])) {
            if ((n2+n1)%2 == 1) return 1.0*nums1[m];
            else {
                if (n1 == n2) return (nums1[n1-1] + nums2[0])/2.0;
                else return (nums1[m-1] + nums1[m])/2.0;
            }
        }
        
        // binary search on the second one to find an i such that nums1[0]...nums1[m-i-2],  
        // sums2[0]...nums2[i] are the (n1+n2+1)2 smallest numbers. 
        // Namely nums2[i+1] >= nums1[m-i-2] and nums1[m-i-1] >= nums2[i].
        int i = binarySearch(nums1, nums2, 0, n2-1);
        m = (n1 + n2 + 1)/2;
        if (i == n2-1) {
            if ((n1+n2)%2 == 0) return (max(nums2[i], nums1[m-i-2]) + nums1[m-i-1])/2.0;
            return 1.0*max(nums1[m-i-2], nums2[i]);
        }
        if ((n1+n2)%2==0) return (max(nums2[i], nums1[m-i-2]) + min(nums2[i+1], nums1[m-i-1]))/2.0;
        return max(nums2[i], nums1[m-i-2])*1.0;
    }
    
    int binarySearch(vector<int>& nums1, vector<int>& nums2, int l, int r) {
        int n1 = nums1.size(), n2 = nums2.size(), m = (n1+n2+1)/2;
        if (l == r) return l;
        int i = l + (r-l)/2;
        if (nums1[m-i-2] > nums2[i+1]) {
            if (r == i+1) return r;
            return binarySearch(nums1, nums2, i+1, r);
        }
        if (nums1[m-i-1] < nums2[i]) {
            if (i == l) return l;
            return binarySearch(nums1, nums2, l, i-1);
        }
        return i;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() >= nums2.size()) return search(nums1, nums2);
        else return search(nums2, nums1);
    }
};
