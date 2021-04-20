



https://leetcode.com/problems/range-sum-query-mutable/


307. Range Sum Query - Mutable
Medium

1584

94

Add to List

Share
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
 

Constraints:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
0 <= i <= j <= nums.length - 1



 
 We don't use segment tree  in case we have frequent update operations

Parent is i - 
 
 
 
 
 
 class NumArray {
public:
    int n;
    vector<int>seg;
    void build(int index,int low,int high,vector<int>nums)
    {
        if(low==high)
        {
            seg[index]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid,nums);
        build(2*index+2,mid+1,high,nums);
        seg[index]=seg[2*index+1]+seg[2*index+2];
        
    }
    
    int query(int index,int low,int high,int l,int r)
    {

        if(low>=l && high<=r)  
        {
            return seg[index];
        }
        if(high<l || low >r) return 0;   

        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return left+right;
    }

    
    
     void updatehelper(int ind,int low,int high,int pos,int val)
     {
        if(low==high)
        {
            seg[ind]=val;
        }
        else
        {
            int mid=(low+high)/2;
            if(pos<=mid)
            {
                updatehelper(2*ind+1,low,mid,pos,val);
            }
            else
            {
                updatehelper(2*ind+2,mid+1,high,pos,val);
            }
            seg[ind]=seg[2*ind+1]+seg[2*ind+2];
         }
     }
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        if(n==0)
            return ;
        seg.resize(4*n);
        
        build(0,0,n-1,nums);
        
    }
    
    
    void update(int i, int val) {
        updatehelper(0,0,n-1,i,val);
    }
    
    int sumRange(int i, int j) {
        return query(0,0,n-1,i,j);
        
    }
};



















class NumArray {
private:
    int arr_size;
    int tree_size;
    vector<int> tree;
    int merge(int l, int r){return (l+r);}
    
   void buildTree(vector<int>& arr,int treeIndex, int lo, int hi){
       if(lo==hi) {
           tree[treeIndex] = arr[lo]; //leaf node -> store value
           return;
       }
       //recurse deeper for children
       int mid = lo+(hi-lo)/2;
       int leftIndex = 2*treeIndex+1;
       int rightIndex = 2*treeIndex+2;
       buildTree(arr,leftIndex, lo, mid);
       buildTree(arr, rightIndex, mid+1, hi);
       //merge, e.g. sum
       tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
   }
    
     void updateTree(int treeIndex, int lo, int hi,int arrIndex, int val){
          if(lo==hi) {// leaf node. update element.
              tree[treeIndex] = val; 
              return;
          }
         // recurse deeper for appropriate child
         int mid = lo+(hi-lo)/2;
         int leftIndex = 2*treeIndex+1;
         int rightIndex = 2*treeIndex+2;
         if (arrIndex > mid)  updateTree(rightIndex, mid+1, hi, arrIndex, val);
         else updateTree(leftIndex, lo, mid, arrIndex, val);
         //merge updates
         tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
         
     }
    
     int queryTree(int treeIndex, int lo, int hi, int i, int j){
        //segment completely outside range
         if(lo > j || hi < i) return 0;
         // segment completely inside range
         if(i <= lo &&  j >=hi) return tree[treeIndex];
         // partial overlap of current segment and queried range. Recurse deeper.
         int mid = lo+(hi-lo)/2;
         int leftIndex = 2*treeIndex+1;
         int rightIndex = 2*treeIndex+2;
         if (i > mid)  //if the range is completely to the right of mid
             return queryTree(rightIndex, mid+1, hi, i, j);
         else if (j <= mid)  //if the range is completely to the left of mid
             return queryTree(leftIndex, lo, mid, i, j);
         //if the range falls on left and right of mid
         int leftQuery = queryTree(leftIndex, lo, mid, i, mid);
         int rightQuery = queryTree(rightIndex, mid+1, hi, mid+1, j);
          // merge query results
         return merge(leftQuery, rightQuery);
     }

public:
    NumArray(vector<int>& nums) {
        arr_size = nums.size();
        if (arr_size==0) return;
        int height = (int)(ceil(log2(arr_size)));   
        tree_size = 2*(int)pow(2, height) - 1;  
        tree.resize(tree_size,0);
        
        buildTree(nums, 0, 0, arr_size-1);
    }
    
    void update(int i, int val) {
         updateTree(0, 0, arr_size-1, i, val);
    }
    
    int sumRange(int i, int j) {
        int sum = queryTree(0, 0, arr_size-1, i, j);
        return sum;
    }
};
