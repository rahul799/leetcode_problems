Josephus problem


Birthday Party
Question 159 of 978
There are n children standing in a circle, waiting to get a balloon. The distribution is carried out starting with the kth (0-indexed) child, and giving them a balloon they run off and play. Every kth child gets a balloon going clockwise until there is one child left that gets a balloon.

Given n and k , return the starting index of the child that receives the last balloon.

Constraints

1 ≤ n, k ≤ 2,000
0 ≤ k ≤ 2,000
Example 1
Input
n = 3
k = 2
Output
1
Explanation
In first round, child 2 gets a ballon, leaving us [0, 1].
In second round, child 0 gets a balloon, leaving us [1].




int solve(int n, int k) {
          if (n == 1)
            return 0;
        return (solve(n - 1, k) + (k + 1)) % n;
    }
    
