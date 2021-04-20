

Lone Integer
You are given a list of integers nums where each integer occurs exactly three times except for one which occurs once. Return the lone integer.



Consider every integer as just a 32 bit integer. For each 32 bit place, we just need to count how many 1's there are for all the numbers. 
If the num_ones in that bit place mod 3 is not 0, that means the lone integer had a 1 there. So, we set that bit place to 1 in our final answer.

Do that for every 31 bits in Java.

Implementation
For each bit, were going to count how many 1 there was for every number. Then, we are going to mod 3. The lone integer should have a 1 
there after mod 3. Use all of that to construct our final answer.

Time Complexity
\mathcal{O}(n)O(n) We go through each n numbers 32 times

Space Complexity
\mathcal{O}(1)O(1) We do not use any auxiliary space to get our answer






Bonus: solve it in \mathcal{O}(1)O(1) space.

Constraints

n ≤ 100,000 where n is length of nums
Example 1
Input
nums = [2, 2, 2, 9, 5, 5, 5]
Output
9
Example 2
Input
nums = [7, 1, 1, 1]
Output
7
Solved




int solve(vector<int>& nums) {
    int num = 0;
    int n = 0;
    while (n < 32) {
        // count set bits at position nth
        int cnt_set_bits = 0;
        for (auto x : nums) {
            if ((x >> n) & 1) cnt_set_bits++;
        }
        if (cnt_set_bits % 3 != 0) {
            num += (1 << n);
        }
        n++;
    }
    return num;
}
