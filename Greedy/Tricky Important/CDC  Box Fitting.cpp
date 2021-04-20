B. Box Fitting


https://www.youtube.com/watch?v=AkotUlDjgcw&ab_channel=codeExplainer



https://codeforces.com/contest/1498/problem/B


https://www.youtube.com/watch?v=AkotUlDjgcw&ab_channel=codeExplainer


memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n rectangles, each of height 1. Each rectangle's width is a power of 2 (i. e. it can be represented as 2x for some non-negative integer x).

You are also given a two-dimensional box of width W. Note that W may or may not be a power of 2. Moreover, W is at least as large as the width of the largest rectangle.

You have to find the smallest height of this box, such that it is able to fit all the given rectangles. It is allowed to have some empty space left in this box after
fitting all the rectangles.

You cannot rotate the given rectangles to make them fit into the box. Moreover, any two distinct rectangles must not overlap, i. e., any two distinct rectangles must
have zero intersection area.

See notes for visual explanation of sample input.

Input
The first line of input contains one integer t (1≤t≤5⋅103) — the number of test cases. Each test case consists of two lines.

For each test case:

the first line contains two integers n (1≤n≤105) and W (1≤W≤109);
the second line contains n integers w1,w2,…,wn (1≤wi≤106), where wi is the width of the i-th rectangle. Each wi is a power of 2;
additionally, maxi=1nwi≤W.
The sum of n over all test cases does not exceed 105.

Output
Output t integers. The i-th integer should be equal to the answer to the i-th test case — the smallest height of the box.

Example
inputCopy
2
5 16
1 2 8 4 8
6 10
2 8 8 2 2 8
outputCopy
2
3
Note
For the first test case in the sample input, the following figure shows one way to fit the given five rectangles into the 2D box with minimum height:


In the figure above, the number inside each rectangle is its width. The width of the 2D box is 16 (indicated with arrow below). The minimum height required for
the 2D box in this case is 2 (indicated on the left).

In the second test case, you can have a minimum height of three by keeping two blocks (one each of widths eight and two) on each of the three levels.




#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
void solve(){
    ll n,w;
    cin>>n>>w;
    multiset<ll>ms;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ms.insert(x);
    }
    int h=1,left=w;
    while(!ms.empty()){
        auto itr = ms.upper_bound(left);
        if(itr==ms.begin()){
            left=w;
            h++;
        }
        else{
            itr--;
            int val = *itr;
            left-=val;
            ms.erase(itr);
        }
    }
    cout<<h<<"\n";
}  
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}






