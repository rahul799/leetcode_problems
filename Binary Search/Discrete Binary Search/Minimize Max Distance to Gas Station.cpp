
774. Minimize Max Distance to Gas Station
Hard

https://leetcode.com/problems/minimize-max-distance-to-gas-station/

Share
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.




class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) 
    {



/*
    K = 2
    
	A---B-----------C-------D
    |---|-----------|-------|
    0   2           8       12

step 1: when every station must be 12 apart, find the number of new stations.

	newSpan = 12 - 0 = 12
    #newStation:
                    (2-0) / 12 = 0
                    (8-2) / 12 = 0
                    (12-8) / 12 = 0
    
    
step 2: halve newSpan and find the number of new stations.
    newSpan = (12 - 0) / 2 = 6.0
    #newStations = 
                    (2-0) / 6 = 0
                    (8-2) / 6 = 0
                    (12-8) / 6 = 0
                    
                    
step 3: halve newSpan and find the number of new stations.
    newSpan = (6.0) / 2 = 3.0
    #newStations = 
                    (2-0) / 3 = 0
                    (8-2) / 3 = 2.0     => at least 1 new station
                    (12-8) / 3 = 1.33   => at least 1 new station
*/


        double lb = 0;
        double ub = stations.back() - stations[0];
        

        while (ub - lb > 1e-6)
        {
            
            
            double mid = lb + (ub-lb)/2.0;
            if (numNewStations(mid, stations) <= K)
            {
                // shrink span
                // earlier chossen mid value is too large that it wasnot able to accumulate the larger size span
                ub = mid;
            }
            else
            {
                // expand span
                lb = mid;
            }
        }

        return lb;
    }
	
	
	int numNewStations(double newSpan, vector<int>& stations)
	{
		int cnt = 0;
		
		for (int i=1; i < stations.size(); i++)
		{
			double dist = stations[i] - stations[i-1];
			cnt += floor(dist / newSpan) ;
		}
		
		return cnt;
	}
};
