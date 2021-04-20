4. Distant Barcodes
Medium

516

23

Add to List

Share
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
 

Constraints:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000




My idea:
First fill the even index and then odd index.
We just need to prevent most frequent barcode occupy both even and odd index.
Therefore, we can start to fill with the most frequent barcode to prevent this situation.

Use a unordered_map to calculate the frequency. O(N), N is the len of barcode.
Find the most frequent barcode. O(N)
erase it in the map avg. O(1)

then start to fill!
total time complexity: O(N)

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans(barcodes.size());
        unordered_map<int,int> m;
        for(auto i : barcodes)
        {
            m[i]++;
        }
        
        int maxVal = -1;
        int maxCnt = -1;
        for(auto p : m)
        {
            if(p.second > maxCnt)
            {
                maxCnt = p.second;
                maxVal = p.first;
            }
        }
        
        m.erase(maxVal);
        
        int pos = 0;
        for(int i = 0 ; i < maxCnt ; i++)
        {
            ans[pos] = maxVal;
            pos += 2;
        }
        
        for(auto p : m)
        {
            for(int i = 0 ; i < p.second ; i++)
            {
                if(pos >= ans.size())
                {
                    pos = 1;
                }
                ans[pos] = p.first;
                pos+=2;
            }
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int m[10001]={0};
        vector<pair<int, int>> s;
        for (auto n : b) ++m[n];
        for (int i=0;i<10001;i++){
            if(m[i]>0){
                s.push_back({m[i],i});
            }
        } 
        sort(s.begin(),s.end());
        int pos=0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            for(int i=0;i<it->first;i++,pos+=2){
                if(pos>=b.size()) pos=1;
                b[pos]=it->second;
            }
        }
        return b;   
    }
};
