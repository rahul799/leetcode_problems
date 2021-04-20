118. Pascal's Triangle
Easy

2336

130

Add to List

Share
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30







class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //creates a vector triangle with numRows number of inner vectors of size 1 and value 1
        vector<vector<int>> triangle(numRows, vector<int> (1,1));
        
        if(numRows == 0) return triangle; 
        
        vector<int> prevRow;
		
		//We start the for loop from 1st index because the vector at 0th index of triangle is already intialized with 1
		//if the numRows is 1, then we do not enter the for loop and simply skip to return triangle
        for(int currRow = 1; currRow<numRows ; currRow++)
        {
            prevRow = triangle[currRow-1]; 
            for(int i=1;i<currRow;i++)
            {
			   //this loop fills up the elements apart from the 1st and last element of the vector
                triangle[currRow].push_back(prevRow[i] + prevRow[i-1]);
            }
            triangle[currRow].push_back(1);      //setting the last element of the vector as 1      
        }        
        return triangle;
    }
};
