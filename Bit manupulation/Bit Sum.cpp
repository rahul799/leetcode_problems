Bit Sum
You are given a list of integers nums and an integer k. You must perform this operation k times:

Choose any number on the list. In the binary representation of the number, choose a bit that is 0 and make it 1.

Return the minimum possible sum of all the numbers (mod 10 ** 9 + 7) after performing k operations.

Constraints

k < n where n is the length of nums.
nums[i] ≤ 10 ** 9.
Example 1
Input
nums = [3, 7, 3]
k = 2
Output
21
Explanation
In binary representation 3 is 11, and 7 is 111. Since we need to set 2 bits, we can set the lowest 0s of the two 3s such that they become 111. The total sum is then 7 + 7 + 7 = 21.

Example 2
Input
nums = [5, 3]
k = 1
Output
10
Explanation
In binary representation 5 is 101 and 3 is 11. So we can set the second bit of 5 to make it 111.


Intuition
We start from the rightmost bit. Then for every value in the array, we check if rightmost bit of the value is 1. If yes, we increase the result by the bit value.

When we have finish iterating the array, we consider the next smallest bit. Then we check if the second-rightmost bit is 1. If yes, we increase the result by the bit value (which is 2). Then we consider the next smallest bit and so on.

We repeat until when we have increased the required number of bits.

Implementation
The implementation is fast (27ms beats 100%) because the number of times we increase res is exactly k.

Time Complexity
\mathcal{O}(n \log A)O(nlogA) where AA is the size of the largest integer in the array.








 int solve(vector<int>& nums, int k) {
           vector<int> bits(32,0);
           int n=nums.size();
           int mod=1e9+7;
           int sum=0;
           for(auto i:nums){
               sum+=i;
               sum%=mod;
               for(int j=0;j<32;j++){
                  bits[j]+= i&1;
                  i>>=1;
               }
           }
           int curr=1;
           int t=0;
           int s=0;
#           while(k>0){
#               if(n-bits[s]>k){
#                   sum+=curr*k;
#                   sum%=mod;
#                   break;
#               }
#               else{
#                   int q=n-bits[s];
#                   k-=q;
#                   sum+=curr*q;
#                   sum%=mod;
#                   curr*=2;
#               }
#               s++;
#           }
#           return sum;
#     }
