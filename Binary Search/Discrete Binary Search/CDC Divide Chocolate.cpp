


1231. Divide Chocolate
Hard

451

32

Add to List

Share
You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using K cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

 

Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
Example 3:

Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
 

Constraints:

0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5



class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int sum = accumulate(sweetness.begin(), sweetness.end(), 0);
        if(K==0) return sum;
        int target = sum/K;
        int l = 0, r = target; //minimum sweetness
        while(l<=r) {
            int m = l+((r-l)/2);
            if(CanCut(sweetness, m, K)) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return r;        
    }
    bool CanCut(vector<int>& sweetness, int s, int K) {
        int cur_sum = 0;
        for(int i=0; i<sweetness.size()&&K>=0; i++) {
            cur_sum += sweetness[i];
            if(cur_sum>=s) {cur_sum = 0; K--;}
        }
        return K==-1;
    }
};



