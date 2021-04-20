https://leetcode.com/problems/count-of-smaller-numbers-after-self/


https://www.youtube.com/watch?v=JIBfKrGVF6I&t=282s


315. Count of Smaller Numbers After Self
Hard

2908

94

Add to List

Share
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
 

Constraints:

0 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4



















class Solution {
public:;
    
    struct Node{
        int val;
        int count;
        Node* left;
        Node*right;
        Node(int val, int count){
            this->val = val;
            this->count = count;
            this->left = NULL;
            this->right = NULL;
        }
    };
    
    int add(Node*& root, int val, int total){
        if(root == NULL){
        root = new Node(val, 0);
        return total;
        
    }
    
    if(root->val < val){
        return root->count+(add(root->right,val,total+1));
        
        
    }
    
        else {
        root->count++;
        return add(root->left, val, total);
        
    }
}
    
    
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        Node* root = NULL;
        for(int i = n-1; i >=0; i--){
            ans[i] = add(root, nums[i], 0);
            
        }
        return ans;
        
    }
};







 

