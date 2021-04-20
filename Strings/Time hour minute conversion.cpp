
Ayush went to sleep at time  and woke up at time . How much time did he sleep? Time is given in format  and Ayush due to his normal human body limitations cannot sleep for more than 23 hours 59 minutes.

Input Format

First line contains an integer  denoting number of test cases

For each test cases there are two lines containing time  and 

https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-15-august/challenges/easy-7-cc/problem

#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin>> t;
    while(t--){
        string s, e ;
        cin >> s >> e;
        int sh = stoi(s.substr(0,2)) , sm = stoi(s.substr(3));
        
        int eh = stoi(e.substr(0,2)),  em =stoi(e.substr(3));
        
        int hrs = 0 , mins = 0 ;
        if(sh == eh and sm <= em ){
            mins = em - sm; hrs = 0 ;
        }else{
            mins += ( 60- sm);
            sh+=1;
            if(sh <= eh){
                hrs = eh - sh;
            }else{
                hrs = (24- sh)+ eh;
            }
            mins+= ( em);
        }
        if(mins >= 60 ){
            hrs += (mins/60);
            mins %= 60;
        }
        cout << hrs <<" hours "<<mins<<" minutes\n";
    }   
    return 0;
}
