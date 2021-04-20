


Factorial Sum
Question 418 of 987
Given a positive integer n, return whether n can be written as the sum of distinct positive factorial numbers.

Example 1
Input
n = 31
Output
true
Explanation
Since 31 = 4! + 3! + 1!

Example 2
Input
n = 4
Output
false
Explanation
Since 4 = 2! + 2! but not distinct.

Example 3
Input
n = 6
Output
true
Example 4
Input
n = 29
Output
false





bool solve(int n) {
    if (n == 1) return true;
    vector<long long int> fact;
    long long int prod = 1;
    int i = 1;
    while (prod < n) {
        prod *= i;
        i++;
        fact.push_back(prod);
    }
    int size = fact.size() - 1;
    while (size >= 0 and n) {
        if (n >= fact[size]) n -= fact[size];
        size--;
        // cout<<n<<" ";
    }
    return n == 0;
}
