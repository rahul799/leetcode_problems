


1734. Decode XORed Permutation
Medium

268

9

Add to List

Share
There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

 

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]



class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        int x=n+1;
        int tot=0;
        for(int i=1;i<=x;i++) // a1^a2^a3^..
            tot^=i;
        int p=0;
        for(int i=0;i<n;i++){ 
            p^=encoded[i]; // (a1^a2), (a1^a3), (a1^a4)..
            tot^=p; 
        }
        //Now tot contains the first number;
        vector<int> ans(n+1);
        ans[0]=tot;
        for(int i=0;i<n;i++){
            ans[i+1]=(tot^encoded[i]);
            tot=ans[i+1];
        }
        return ans;
    }
};


