739. Daily Temperatures
Medium


Add to List

Share
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


https://www.youtube.com/watch?v=t5iAzq0yG1I&t=328s&ab_channel=CppHack



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
           int n=T.size();
        vector<int> answer(n,0);
        if(n<=1)return answer;
        stack<int> warmer; 
        for(int i=n-1;i>=0;i--){
            // if we encounter a number larger than the top of stack, pop it out
            while(!warmer.empty()&&T[i]>=T[warmer.top()]){
                     warmer.pop();
            }
        // eif the number is  smalller simply insert the difference in indexes 
        if(!warmer.empty())
        answer[i]=warmer.top()-i; 
           
        warmer.push(i);
     }   
     return answer;
  }
};
