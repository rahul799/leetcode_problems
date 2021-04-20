
Make Target List with Increment and Double Operations


You are given a list of non-negative integers target. Consider a list A of the same length as target containing all zeros initially. 
In one operation, you can increment one number in A, or double every number in A. Return the minimum number of operations required to 
turn A into target.

Constraints

0 ≤ n ≤ 100,000 where n is the length of target
Example 1
Input
target = [3, 2, 2]
Output
5
Explanation
First, we start with A = [0, 0, 0]

We increment A[0] and get [1, 0, 0]
We increment A[1] and get [1, 1, 0]
We increment A[2] and get [1, 1, 1]
We double every element and get [2, 2, 2]
We increment A[0] and get [3, 2, 2]
Example 2
Input
target = [0, 0, 0, 0, 0]
Output
0
Explanation
A is already equal to target.

As with a lot of similar questions, it's worth considering doing the operations backwards (subtracting and dividing instead of adding and multiplying).
Of course, you first need to convince yourself that it's symmetric to solve both ways.
Why is solving backwards any better?
If we multiply, we can't be sure when it's best to multiply and when to use addition.
On the other hand, when dividing, anytime the number is odd, we just can't divide, and when it's even, it's always better to divide than to subtract (since we get to zero faster that way).

Now, we can solve for each number independently.
If it's currently odd, we must decrease it by one, and that operation will be independent from any other operation anyway, so add one to the total count.
If it's even, we should divide, but this time it's better to divide as many numbers as possible together, so we only need to keep track of the number that needs to be divided the most, that way, every other number will be divided together with maximal one.

Implementation
We iterate over all the numbers in target.
We count the number of operations needed to decrease that number to zero.
If it's currently odd, we subtract one, adding one to our total cost.
If it's currently even, we divide by two, and add one to the current division count.
Furthermore, we keep track of the number that needed the most divisions.
Finally, the solution is the total number of subtraction done throughout the numbers, and the maximum division needed.

Time Complexity
\mathcal{O}(n * \log n )O(n∗logn) since we iterate over every number and for each one, we divide by two every other round so at most \mathcal{O}( \log n)\approx32O(logn)≈32 additional operations

Space Complexity
\mathcal{O}(1)O(1) since we only use constant variables to keep track of needed operations


int solve(vector<int>& target) {
    int subs = 0;
    int maxDivs = 0;

    for (int num : target) {
        int curDivs = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                num--;
                subs++;
            } else {
                num /= 2;
                curDivs++;
            }
        }
        maxDivs = max(maxDivs, curDivs);
    }

    return subs + maxDivs;
}
