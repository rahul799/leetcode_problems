B. Just Eat It!

Today, Yasser and Adel are at the shop buying cupcakes. There are n cupcake types, arranged from 1 to n on the shelf,
and there are infinitely many of each type. The tastiness of a cupcake of type i is an integer ai. There are both tasty 
and nasty cupcakes, so the tastiness can be positive, zero or negative.

Yasser, of course, wants to try them all, so he will buy exactly one cupcake of each type.

On the other hand, Adel will choose some segment [l,r] (1≤l≤r≤n) that does not include all of cupcakes (he can't choose 
[l,r]=[1,n]) and buy exactly one cupcake of each of types l,l+1,…,r.

After that they will compare the total tastiness of the cupcakes each of them have bought. Yasser will be happy if the
total tastiness of cupcakes he buys is strictly greater than the total tastiness of cupcakes Adel buys regardless of Adel's 
choice.

For example, let the tastinesses of the cupcakes be [7,4,−1]. Yasser will buy all of them, the total tastiness will be 
7+4−1=10. Adel can choose segments [7],[4],[−1],[7,4] or [4,−1], their total tastinesses are 7,4,−1,11 and 3, respectively.
Adel can choose segment with tastiness 11, and as 10 is not strictly greater than 11, Yasser won't be happy :(

Find out if Yasser will be happy after visiting the shop.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains n (2≤n≤105).

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109), where ai represents the tastiness of the 
i-th type of cupcake.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
For each test case, print "YES", if the total tastiness of cupcakes Yasser buys will always be strictly greater than the 
total tastiness of cupcakes Adel buys regardless of Adel's choice. Otherwise, print "NO".

Example
inputCopy
3
4
1 2 3 4
3
7 4 -1
3
5 -5 5
outputCopy
YES
NO
NO
Note
In the first example, the total tastiness of any segment Adel can choose is less than the total tastiness of all cupcakes.

In the second example, Adel will choose the segment [1,2] with total tastiness 11, which is not less than the total tastiness 
of all cupcakes, which is 10.

In the third example, Adel can choose the segment [3,3] with total tastiness of 5. Note that Yasser's cupcakes' total 
tastiness is also 5, so in that case, the total tastiness of Yasser's cupcakes isn't strictly greater than the total 
tastiness of
Adel's cupcakes.




If there is at least a prefix or a suffix with non-positive sum, we can delete that prefix/suffix and end up with an 
array with sum ≥ the sum of the whole array. So, if that's the case, the answer is "NO".

Otherwise, all the segments that Adel can choose will have sum < than the sum of the whole array because the elements
that are not in the segment will always have a strictly positive sum. So, in that case, the answer is "YES".







#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

bool solve(){
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    sum = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}


