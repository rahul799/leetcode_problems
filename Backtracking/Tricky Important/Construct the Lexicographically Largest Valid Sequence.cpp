



class Solution {
public:
    
    
    bool constructArray(int n, int idx, vector<int>&arr, vector<bool>&vis){
        if(idx >= 2*n -1)
            return true;
        
        // we are going from n to 1 to ensure that we get lexographically valid sequence at th end
        for(int x = n; x > 0; --x){
            
            // if the digit x doesn't fit well at index idx
            if(vis[x]) continue;
            if(x == 1 && arr[idx] != 0) continue;
            if(x > 1 && !(arr[idx] == 0 && idx+x < 2*n-1 && arr[idx+x] == 0))continue;
            
            // if the digit x fits well at index idx
            if(x == 1)arr[idx] = x;
            else arr[idx] = x, arr[idx+x] = x;
            vis[x] = true;
            
            // find next idx
            int nextIdx = idx+1;
            while(nextIdx < 2*n-1 && arr[nextIdx] != 0){
                nextIdx += 1;
            }
            
            
            // construct rest of the array
            if(constructArray(n, nextIdx, arr, vis)) return true;
            
            // backtrack or undo the changes
            if(x == 1) arr[idx] = 0;
            else arr[idx] = 0, arr[idx+x] = 0;
            vis[x] = false;
            
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        
        if(n == 1)return {1};
        vector<int> arr(2*(n-1) + 1, 0);
        vector<bool> vis(n+1, false);
        constructArray(n, 0, arr, vis);
        return arr;
        
    }
};
