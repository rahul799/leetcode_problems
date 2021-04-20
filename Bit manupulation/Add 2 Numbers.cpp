

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

class Solution {
     public int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        while (b != 0)  {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry; 
        }
        return a;
    }
}
