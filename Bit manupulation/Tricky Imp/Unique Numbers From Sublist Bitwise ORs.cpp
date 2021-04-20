Unique Numbers From Sublist Bitwise ORs
Given a list of non-negative integers nums, return the number of unique integers we can form by taking any sublist of nums and performing a bitwise OR of every number in the sublist.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 2, 4]
Output
6
Explanation
We can form the numbers [1, 2, 3, 4, 6, 7]

1 == 1
2 == 2
4 == 4
1 | 2 == 3
2 | 4 == 6
1 | 2 | 4 == 7


Intuition
Observations:

If we start taking AND of elements of any sequence, the AND value will either remain same or decrease
let arr[1], arr[2], arr[3] be the sequence

  -> a1 = arr[1], 
  -> a2 = arr[1]&arr[2], 
  -> a3 = arr[1]&arr[2]&arr[3]
We can say : a1 >= a2 >= a3
because while taking AND we cannot set a bit so either the AND value will remain same or decrease
AND value can decrease by atmost number of set bits in A times i.e at max max(log (A)) times.

The number of unique AND of a subarrays starting at any position will change by atmost LOG( A[i] ) times ( A[i] is first element of subarray)

The AND's of subarrays starting at ith index can be calculated from AND's of subarrays starting at (i+1)th index

st[i] : contains AND values of subarrays starting from ith index

for eg : arr[] = [2,6,7,2,4]; (0 based indexing)

 Subarrays starting at 4th index
 	: [4]			            --> st[5] = { 4 }
 Subarrays starting at 3rd index
 	: [2], [2,4]			    --> st[4] = { 2, 0 }
 Subarrays starting at 2nd index
 	: [7], [7,2], [7,2,4],		--> st[3] = { 7, 2, 0 }
AND_VAL[i, len] : AND of elements of subarray starting from 'ith' index of length 'len'
Observe that

AND_VAL[i,1] = arr[i];
AND_VAL[i,2] = arr[i] & AND_VAL[i+1,1];
AND_VAL[i,3] = arr[i] & AND_VAL[i+1,2];
AND_VAL[i,4] = arr[i] & AND_VAL[i+1,3];
.
.
AND_VAL[i,j] = arr[i] & AND_VAL[i+1,j-1];
also AND_VAL[i+1, j] are present in st[i+1]. ( check definition of st[i] )
Therefore st[i] can be calculated from st[i+1] as AND values of st[i] are nothing but AND of arr[i] with values in st[i+1]

From Observation (3) we can conclude :
st[i].size() <= log( max( A ) ) <= 20 as ( A <= 10^6 )

Time Complexity : O( n * log( max( arr[i] ) ) )
Code :

int closestToTarget(vector<int>& arr, int target) {
int ans = INT_MAX, n = arr.size();


int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<unordered_set<int>> v(n);
    int ans = 0;
    v[0].insert(nums[0]);
    unordered_set<int> s;
    s.insert(nums[0]);
    for (int i = 1; i < n; i++) {
        if (s.count(nums[i]) == 0) {
            s.insert(nums[i]);
        }
        v[i].insert(nums[i]);
        for (auto j : v[i - 1]) {
            j |= nums[i];
            if (s.count(j) == 0) {
                s.insert(j);
            }
            v[i].insert(j);
        }
    }
    return s.size();
}
