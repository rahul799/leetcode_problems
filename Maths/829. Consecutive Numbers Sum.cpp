829. Consecutive Numbers Sum

Share
Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

Example 1:

Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3
Example 2:

Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
    
    
    
    
All ways can be represented in the following form:
a + a + 1 + a + 2 ... + a + k = N
Where a is the first number in the seqeunce and a + k is the last number in the sequence.

General Idea: Iterate through all the possible values of k and if there exist an integer value of a that satisfy the equation, we have found a valid way.

We can use arithematic progression to condense this representation:
a + a + 1 + a + 2 ... + a + k = (k+1)a + (1+2+...+k)= (k+1)a + (k*(k+1)/2) = N

As the a is easily fractorized out we can repsent a in terms of k and N by:
a = N/(k+1) - k/2

As we know the that a must be positive, we can find the upper bound for k:
N/(k+1) - k/2 > 0
N/(k+1) > k/2
N > k(k+1)/2

This will allow us to terminate early instead of iterating through every possible k from 0 to N

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        long long int count = 0; 
        for (long long int k = 0; k*(k+1)/2 < N ;k++) {
            double a = ((double) N)/((double) k + 1) - (double) k/2;
            if (a - (int) a == 0) {
                count += 1;
            }
        }
        return count; 
    }
};

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for(int k = 0; k < sqrt(0.25 + 2*N) - 0.5; k++)
            if((N-((k+1)*k)/2) % (k+1) == 0)
                ans++;
        return ans;
    }
};
