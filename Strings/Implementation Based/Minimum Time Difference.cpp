539. Minimum Time Difference


https://leetcode.com/problems/minimum-time-difference/


Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints <= 2 * 104
timePoints[i] is in the format "HH:MM".




class Solution {
public:
    int findMinDifference(vector<string>& t) {
        sort(t.begin(),t.end());
        int ans=INT_MAX,n=t.size();
        // cout<<stoi("00")<<endl;
        for(int i=1;i<t.size();i++)
        {
            // cout<<t[i-1].substr(0,2)<<endl;
            int hd=stoi(t[i].substr(0,2))-stoi(t[i-1].substr(0,2));
            int md=stoi(t[i].substr(3,2))-stoi(t[i-1].substr(3,2));
            int tdim=hd*60+md;
            ans=min(ans,tdim);
        }
        int hd=stoi(t[0].substr(0,2))-stoi(t[n-1].substr(0,2))+24;
        int md=stoi(t[0].substr(3,2))-stoi(t[n-1].substr(3,2));
        int tdim=hd*60+md;
        ans=min(ans,tdim);
        return ans;
    }
};

