
666. Path Sum IV
Medium

197

269

Add to List

Share
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:

The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary tree with the depth smaller than 5, you need to return the sum of all paths from the root towards the leaves.

It's guaranteed that the given list represents a valid connected binary tree.

Example 1:

Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
 

Example 2:

Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.




class Solution {
public:
    int ans = 0;
    /*
		This function calculate the number of leafs present in the subtree of that node,
		because the node contributes number of leaves*node->val to the sum.
		Example:
		           3
				  / \
                5     1
			   / \
			 4    7
			 
			So sum is 3*3(3 leaves) + 5*2(2 leaves) + 4(leaf) + 7(leaf) + 1(leaf)
	*/
    int recurLeaves(int i, vector<int>& lvl)
    {
        if(lvl[i] == -1)
            return 0;
        else
        {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int left = recurLeaves(l, lvl);
            int right = recurLeaves(r, lvl);
            
            //NODE IS LEAF, INC
            if(left == right && left == 0)
                left++;
            
            ans += (left + right)*lvl[i];
            return right + left;
        }
    }
    
    int pathSum(vector<int>& nums) {
	/*
	Build a array representing tree, that is if
	                i -> root, then 
	 (2*i + 1)---> is left child and (2*i + 2)--->i is right child 
	*/
        vector<int> lvl(31, -1);
        
        for(auto i: nums)
        {
            string s = to_string(i);
            int l = s[0] - '0';
            int p = s[1] - '0';
            int v = s[2] - '0';
            
            lvl[pow(2, l  - 1) - 1 + p - 1] = v;
        }
        
        recurLeaves(0, lvl);
        return ans;
    }
};









class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> sumMap; // node id -> cumulative sum until the node
        unordered_set<int> leafSet;  // collect leaf nodes
        // we can traverse from the vector as it is sorted in ascending order
		for (auto i=0; i<nums.size(); i++) {			
            int level = nums[i]/100; // compute level of current node
            int pos = (nums[i]-level*100) / 10; // compute position in the level of current node
            int curID = level*10 + pos; // level+pos is an ID of each node
            int curVal = nums[i] % 10;  // current value
            int parentID = (level-1)*10 + (pos+1)/2;  // compute the id of parent node (imagine tree structure)
            if (sumMap.count(parentID)) {
				// if there is a parent sum, we add the parent's sum to the cumulative sum of the current node
                sumMap[curID] = curVal + sumMap[parentID];
            } else {
				// if there is no parent, cumaltive sum is just current value (e.g., root)
                sumMap[curID] = curVal;
            }
            // update leaf node information (we should remove parent since the current node is the leaf we have seen so far
            if (leafSet.count(parentID)) leafSet.erase(parentID);
            leafSet.insert(curID);
        }
        int total = 0;
		// we only add all leaf nodes' cumulative sum
        for (int id: leafSet) total += sumMap[id];
        return total;
    }
};
