



1016. Binary String With Substrings Representing 1 To N
Medium

159

384

Add to List

Share
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

 

Example 1:

Input: S = "0110", N = 3
Output: true
Example 2:

Input: S = "0110", N = 4
Output: false
 

Note:

1 <= S.length <= 1000
1 <= N <= 10^9








class Solution {
public:
    bool queryString(string S, int N) {
        // bits : [0, 30]
        // substrings start with 1
        const int L = S.length();
        // vector<int> visited(N + 1, 0);
        unordered_set<int> s;
        for (int i = 0; i < L; ++i) {
            if (S[i] == '0') continue;
            
            for (int j = 0, v = 0; j < 31 && i + j < L; ++j) {
                v = S[i + j] - '0' + (v << 1);
                // cout << S[i + j] << ':' << v << ' ';
                if (v > N) break;
                // visited[v] = 1;
                s.insert(v);
            }
            // cout << endl;
        }
        // for (int i = 1; i <= N; ++i) cout << i << ':' << visited[i] << ' '; cout << endl;
        // return accumulate(begin(visited), end(visited), 0) == N;
        return s.size() == N;
    }
};




// class Solution {
// public:
//     bool queryString(string S, int N) {
//         int reqWind = ceil(log2(N)*1.0);
//         if(N == 1){
//             reqWind=1;
//         }
//         if(S.size()<reqWind){
//             return false;
//         }
//         unordered_set<int> s;
//         for(int slide=1; slide<=reqWind; slide++){
//             int i=0;
//             int val = 0;
//             while(i<S.size() && i<slide){
//                 val = val + (S[i]-'0')*pow(2,slide-(i+1));
//                 i++;
//             }
//             if(val>=1 && val<=N) {
//                 s.insert(val);
//             }
//             for(int i=slide;i<S.size();i++){
//                 int lId = i-slide;
//                 val =val-(S[lId]-'0')*pow(2,slide-1);
//                 val = 2*val + (S[i]-'0');
//                 if(val>=1 && val<=N){
//                     s.insert(val);
//                 }
//             }
//         }
//         return s.size()==N;
//     }
// };
