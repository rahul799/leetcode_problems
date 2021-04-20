



365. Water and Jug Problem
Medium

399

854

Add to List

Share
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
 

Constraints:

0 <= x <= 10^6
0 <= y <= 10^6
0 <= z <= 10^6




This is a brain teaser question. I think many people should have heard this question before. There is a water tank with a capacity of 3 liters and a water tank with a 
capacity of 5 liters, asking us how to accurately weigh out 4 liters of water. I think many people know how to do it. First fill a 5 liter pitcher with water and pour it 
into a 3 liter pitcher. At this time, there are still 2 liters of water in the 5 liter pitcher, and then pour out all the water in the 3 liter pitcher. Pour the 2 liters
of water from the liter pitcher into the 3 liter pitcher. At this time, fill the 5 liter pitcher, and then pour the water into the 3 liter pitcher with 2 liters of water at 
this time, so that after 1 liter of the 5 liter pitcher is poured out, 4 liters remain That is what you want. Many people know this, but this question gives us three 
parameters
at will. It is more difficult to ask if there is a solution. Here I will copy the explanation of the online god :

This question can actually be converted into a very large container. We have two cups with capacities x and y respectively. We ask whether we can make the container by
pouring water in and scooping out with two cups. The water in it is exactly z liters. Then we can use a formula to express:

z = m * x + n * y

Among them, m and n are the times of scooping and pouring water. A positive number means to pour water in, and a negative number means to pour water out. Then the example
in the question can be written as: 4 = (-2) * 3 + 2 * 5, which is 3 The liter pitcher poured water twice out, and the 5-liter pitcher poured water into it twice. Then the 
question becomes for any given x, y, z, whether there are m and n that make the above equation hold. According to the Pei Shu theorem , the solution of ax + by = d is d = gcd(x, y), then as long as z% d == 0, the above equation will be solved, so the problem is solved, we just need to look Whether z is a multiple of the greatest common divisor of x and y, don’t forget that there is another restriction condition x + y >= z, because x and y cannot weigh more than their sum, see the code below ；







class Solution {
 public :
     bool canMeasureWater( int x, int y, int z) {
         return z == 0 || (x + y >= z && z% gcd(x, y) == 0 );
    }
    int gcd( int x, int y) {
         return y == 0 ? x: gcd(y, x% y);
    }
};
