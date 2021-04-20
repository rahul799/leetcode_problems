1552. Magnetic Force Between Two Balls
Medium


Add to List

Share
In universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.


class Solution {
public:
    bool isAnswer(vector<int>&A , int mid ,int m ){
        int initial= 1;  // greedily place the first ball 
        int prev = A[0];  // update prev pointer as the ball is being placed here
        for(int i = 1 ; i < A.size() ; i++){
            if(A[i]-prev >= mid){  // if gap is sufficient enough place the ball
                prev = A[i];//update prev pointer 
                initial+=1;  // increment the no of placable balls
                if(initial == m ) return true;  // all balls placed return true
            }
        }
        if(initial < m) return false; // some balls are left to be placed return false
        return true;
    }
    int maxDistance(vector<int>& A, int m) {
        sort(A.begin()  , A.end());
        int s = 0 ,n = A.size(),  e = A[n-1];
        int ans ;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(isAnswer(A, mid ,m)){
                ans = mid , s = mid+1; // if this gap is sufficient enough try widening the gap
                
            }else{
                e = mid-1; // reduce the gap size 
            }
        }
        return ans;
    }
};
