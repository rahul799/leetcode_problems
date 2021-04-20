
https://leetcode.com/problems/advantage-shuffle/discuss/1125177/Simple-and-Intuitive-Solution-using-Multiset-or-C%2B%2B

870. Advantage Shuffle


Add to List

Share
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

 

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]
 

Note:

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9








class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        multiset<int> set(A.begin(), A.end());
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++ ){ 
            auto find = set.upper_bound(B[i]);
            if(find != set.end()){
            ans[i] = *find;
                set.erase(find);
             }
        }
        if(set.size()){
            
            auto it = set.begin();
            for(int i = 0; i < n; i++)
                if(!ans[i]){
                    ans[i] = *it;
                     it++;
                }
        }
        return ans;
    }
};
