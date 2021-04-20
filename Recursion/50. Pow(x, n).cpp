

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).



50. Pow(x, n)
Medium

2290

3745

Add to List

Share
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104''''



class Solution {
    public:
        double myPow(double x, int n) {
        	double ans = 1;
        	unsigned long long p;
        	if (n < 0) {
        		p = -n;
        		x = 1 / x;
        	} else {
        		p = n;
        	}
    		while (p) {
    			if (p & 1)
    				ans *= x;
    			x *= x;
    			p >>= 1;
    		}
    		return ans;
        }
    };
