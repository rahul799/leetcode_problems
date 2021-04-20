https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/



Check whether a given point lies inside a triangle or not


Given three corner points of a triangle, and one more point P. Write a function to check whether P lies within the triangle or not.
For example, consider the following program, the function should return true for P(10, 15) and false for P'(30, 15)


Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And coordinates of the given point P be (x, y)

1) Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram. Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
2) Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1.
3) Calculate area of the triangle PBC. Let this area be A2.
4) Calculate area of the triangle PAC. Let this area be A3.
5) If P lies inside the triangle, then A1 + A2 + A3 must be equal to A



#include <bits/stdc++.h> 
using namespace std; 

/* A utility function to calculate area of triangle formed by (x1, y1), 
(x2, y2) and (x3, y3) */
float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

/* A function to check whether point P(x, y) lies inside the triangle formed 
by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) 
{ 
/* Calculate area of triangle ABC */
float A = area (x1, y1, x2, y2, x3, y3); 

/* Calculate area of triangle PBC */
float A1 = area (x, y, x2, y2, x3, y3); 

/* Calculate area of triangle PAC */
float A2 = area (x1, y1, x, y, x3, y3); 

/* Calculate area of triangle PAB */	
float A3 = area (x1, y1, x2, y2, x, y); 
	
/* Check if sum of A1, A2 and A3 is same as A */
return (A == A1 + A2 + A3); 
} 

/* Driver program to test above function */
int main() 
{ 
/* Let us check whether the point P(10, 15) lies inside the triangle 
	formed by A(0, 0), B(20, 0) and C(10, 30) */
if (isInside(0, 0, 20, 0, 10, 30, 10, 15)) 
	printf ("Inside"); 
else
	printf ("Not Inside"); 

return 0; 
} 
