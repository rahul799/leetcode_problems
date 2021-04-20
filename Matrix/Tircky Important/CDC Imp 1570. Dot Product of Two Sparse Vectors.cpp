

https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

1570. Dot Product of Two Sparse Vectors
Medium

250

39

Add to List

Share
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

 

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
Example 2:

Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
Example 3:

Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100


Approach 1: YTU  Using index pair Approach


class SparseVector {
    
public:
    vector<pair<int,int>>v;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) v.push_back(make_pair(i,nums[i]));
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int rs=0; 
        for(int i1=0,i2=0; i1<v.size()&&i2<vec.v.size();){
            if(v[i1].first<vec.v[i2].first){
                i1++;
            }else if(v[i1].first>vec.v[i2].first){
                i2++;
            }else{
                rs+=v[i1].second*vec.v[i2].second;
                i1++;
                i2++;
            }
        }
         
        return rs;
    }
};



Approach 2: 

We can also represent elements of a sparse vector as a list of <index, value> pairs. We use two pointers to
iterate through the two vectors to calculate the dot product.
  
  
  
Complexity Analysis

Let nn be the length of the input array and LL and L_{2}L 
2​	be the number of non-zero elements for the two vectors.

Time complexity: O(n)O(n) for creating the <index, value> pair for non-zero values; O(L+L_{2})O(L+L 
2​) for calculating the dot product.

Space complexity: O(L)O(L) for creating the <index, value> pairs for non-zero values. O(1)O(1) for calculating the dot product.
  
  
  
  
  

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                pair<int, int> pair = {i, nums[i]};
                values.insert(pair);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dotProduct = 0;
        
        for (auto& it : values) {
            auto got = vec.values.find(it.first);
            if (got != vec.values.end()) {
                dotProduct += it.second * got->second;
            }
        }
        
        return dotProduct;
    }
    
private:
    unordered_map<int, int> values;
};
