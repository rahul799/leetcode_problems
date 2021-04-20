
https://leetcode.com/problems/arithmetic-slices/


Approach 1: Brute Force
The most naive solution is to consider every pair of elements(with atleast 1 element between them), so that the range of elements lying between these two elements acts as
a slice. Then, we can iterate over every such slice(range) to check if all the consecutive elements within this range have the same difference. For every such range found,
we can increment the countcount that is used to keep a track of the
required result.



Complexity Analysis

Time complexity : O(n^3)O(n 
3
 ). We iterate over the range formed by every pair of elements. Here, nn refers to the number of elements in the given array AA.

Space complexity : O(1)O(1). Constant extra space is used.




413. Arithmetic Slices
Medium

1632

202

Add to List

Share
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7
 
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

 
Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.












Approach 3: Using Recursion
Algorithm

By making use of the observation discussed in the last approach, we know, that if a range of elements between the indices (i,j)(i,j) constitute an Arithmetic Slice, and
another element A[j+1]A[j+1] is included such that A[j+1]A[j+1] and A[j]A[j] have the same difference as that of the previous common difference, the ranges between
(i,j+1)(i,j+1) will constitutes an arithmetic slice. Further, if the original range (i,j)(i,j) doesn't form an arithmetic slice, adding new elements to this range 
won't do us any good. Thus, no more arithmetic slices can be obtained by adding new elements to it.

By making use of this observation, we can develop a recursive solution for the given problem as well. Assume that a sumsum variable is used to store the total number of
arithmetic slices in the given array AA. We make use of a recursive function slices(A,i) which returns the number of Arithmetic Slices in the range (k,i)(k,i), but which are not a part of any range (k,j)(k,j) such that j<ij<i. It also updates sumsum with the number of arithmetic slices(total) in the current range. Thus, kk refers to the minimum index such that the range (k,i)(k,i) constitutes a valid arithmetic slice.

Now, suppose we know the number of arithmetic slices in the range (0,i-1)(0,i−1) constituted by the elements [a_0,a_1,a_2,...a_(i-1)][a 

 i−1)], to be say xx. If this range itself is an arithmetic slice, all the consecutive elements have the same difference(equal to say, a_(i-1)-a_(i-2)a 
(
​	
 i−1)−a 
(
​	
 i−2)). Now, adding a new element a_ia 
i
​	
  to it to extend the range to (0,i)(0,i) will constitute an arithmetic slice only if this new element satisfies a_i-a_(i-1)=a_(i-1)-a_(i-2)a 

 i−2). Thus, now, the addition of this new element, will lead to an addition of apap number of arithmetic slices to the ones obtained in the range 
 (0,i-1)(0,i−1). The new arithmetic slices will be the ones constituting the ranges (0,i), (1,i), ... (i-2,i)(0,i),(1,i),...(i−2,i), which are a total of x+1x+1
 additional arithmetic slices. This is because, apart from the range (0,i)(0,i) the rest of the ranges (1,i), (2,i),...(i-2,i)(1,i),(2,i),...(i−2,i) can be mapped 
 to (0,i-1), (1,i-1),...(i-3,i-1)(0,i−1),(1,i−1),...(i−3,i−1), with count equal to xx.

Thus, in every call to slices, if the i^{th}i 
th
  element has the same common difference with the last element as the previous common difference, we can find the number of new arithmetic slices added by the use of
  this element, apap and also update the sumsum to include this apap into it, apart from the count obtained by the smaller ranges. But, if the new element doesn't have 
  the same common difference, extra arithmetic slices can't be contributed by it and hence, no addition is done to sumsum for the current element. But, of course sumsum 
  will be updated as per the count obtained from the smaller ranges.
  
  
  
  public class Solution {
    int sum = 0;
    public int numberOfArithmeticSlices(int[] A) {
        slices(A, A.length - 1);
        return sum;
    }
    public int slices(int[] A, int i) {
        if (i < 2)
            return 0;
        int ap = 0;
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            ap = 1 + slices(A, i - 1);
            sum += ap;
        } else
            slices(A, i - 1);
        return ap;
    }
}


[1,2,3] --> [1,2,3] --> 1 combination
[1,2,3,4] --> add new combination [2,3,4], [1,2,3,4] --> 2 new combs than dp[i-1]
[1,2,3,4,5] --> add new combination [3,4,5],[2,3,4,5],[1,2,3,4,5] --> 3 new combs than dp[i-1]

sum += dp[i] simply accumulating the dp[i]



Beware recursive formulaa can also be linear


Complexity Analysis

Time complexity : O(n)O(n). The recursive function is called at most n-2n−2 times.

Space complexity : O(n)O(n). The depth of the recursion tree goes upto n-2n−2.


  Approach 4: Dynamic Programming
Algorithm

In the last approach, we start with the full range (0,n-1)(0,n−1), where nn is the number of elements in the given AA array. We can observe that the result for the range 
(0,i)(0,i) only depends on the elements in the range (0,i)(0,i) and not on any element beyond this range. Thus, we can make use of Dynamic Programming to solve the given 
problem.

We can make use of a 1-D dpdp with number of elements equal to nn. dp[i]dp[i] is used to store the number of arithmetic slices possible in the range (k,i)(k,i) and not 
in any range (k,j)(k,j) such that j<ij<i. Again, kk refers to the minimum index possible such that (k,j)(k,j) constitutes a valid Arithmetic Slice.

Instead of going in the reverse order as in the recursive approach, we can start filling the dpdp in a forward manner. The intuition remains the same as in the last
approach. For the i^{th}i 
th
  element being considered, we check if this element satsfies the common difference criteria with the previous element. If so, we know the number of new arithmetic slices added will be 1+dp[i-1]1+dp[i−1] as discussed in the last approach. The sumsum is also updated by the same count to reflect the new arithmetic slices added.

The following animation illustrates the dpdp filling process







Complexity Analysis

Time complexity : O(n)O(n). We traverse over the given AA array with nn elements once only.

Space complexity : O(n)O(n). 1-D dpdp of size nn is used.







Approach 5: Constant Space Dynamic Programming
Algorithm

In the last approach, we can observe that we only require the element dp[i-1]dp[i−1] to determine the value to be entered at dp[i]dp[i]. Thus, instead of making use 
of a 1-D array to store the required data, we can simply keep a track of just
the last element.






public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int dp = 0;
        int sum = 0;
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp = 1 + dp;
                sum += dp;
            } else
                dp = 0;
        }
        return sum;
    }
}





Complexity Analysis

Time complexity : O(n)O(n). We traverse over the given AA array with nn elements once only.

Space complexity : O(1)O(1). Constant extra space is used.
  
  
