Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10



// read notes link 1 to understand this question


class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            
            // whenever we find a smaller element
            while (!indexes.empty() && height[indexes.top()] > height[i]) { 
                // else if current eleemnt is lesser than the last element
                
                int h = height[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top(); // last element
                area = max(area, h * (i - l - 1));
            }
            indexes.push(i); // in case current height is larger than the last height, directly add it
        }
        return area; 
    }
};





// Firstly, it looks like a range query problem. We maintain an monotonic increasing stack called mono_stack . When we meet a new height:

// If this height is higher than or equal to the last height in mono_stack, we just add it to the mono_stack.
// If this height is lower than the last height in mono_stack, we must pop the last height of mono_stack to keep the monotone.

// The hardest operation happens at the second situation. As our rule 3: When a element is popped from the monotonic stack, it will never be used again. If we pop the last height, it should be totally thrown away and never added to stack again. If not, we cannot ensure that every item is added to the monotonic stack once and so the time complexity of the monotonic stack is not equal to O(N).


// Therefore, when pop an item, we should calculate the largest possible rectangle it can generate and update the ret value. When we generate its largest possible rectangle, we meet rule 2 (The minima/maxima element or the monotonic order of elements in a range is useful to get answer of every range query.). Because of the monotone of the stack, we can get the leftmost and rightmost indexes which the popping item can “use” to generate rectangle easily. So we just use height*length to get the area of the rectangle.
// Finally, we need to deal with the end boundary. We can just add a height 0 to the end of heights which can make sure that all previous heights were checked when we end the for loop.


