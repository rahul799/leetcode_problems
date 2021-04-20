

https://codeforces.com/problemset/problem/698/A


Vasya has n days of vacations! So he decided to improve his IT skills and do sport. Vasya knows the following information about each of this n days: whether that gym opened and whether a contest was carried out in the Internet on that day. For the i-th day there are four options:

on this day the gym is closed and the contest is not carried out;
on this day the gym is closed and the contest is carried out;
on this day the gym is open and the contest is not carried out;
on this day the gym is open and the contest is carried out.
On each of days Vasya can either have a rest or write the contest (if it is carried out on this day), or do sport (if the gym is open on this day).

Find the minimum number of days on which Vasya will have a rest (it means, he will not do sport and write the contest at the same time). The only limitation that Vasya has — he does not want to do the same activity on two consecutive days: it means, he will not do sport on two consecutive days, and write the contest on two consecutive days.

Input
The first line contains a positive integer n (1 ≤ n ≤ 100) — the number of days of Vasya's vacations.

The second line contains the sequence of integers a1, a2, ..., an (0 ≤ ai ≤ 3) separated by space, where:

ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.
Output
Print the minimum possible number of days on which Vasya will have a rest. Remember that Vasya refuses:

to do sport on any two consecutive days,
to write the contest on any two consecutive days.


4
1 3 2 0
outputCopy
2
inputCopy
7
1 3 3 2 1 2 3
outputCopy
0
inputCopy
2
2 2
outputCopy
1


https://ideone.com/WPbqt4




int dp[105][3];
 
int minimumRest(vector<int>& v, int length, int last, int i) {
	if (i >= length) {
		return 0;
	}
 
	if (dp[i][last] != -1) {
		return dp[i][last];
	}
 
	if (v[i] == 0) { //rest
		dp[i][last] = minimumRest(v, length, 0, i+1) + 1;
	}
	else if (v[i] == 1) {//contest
		if (last == v[i]) {
			dp[i][last] = minimumRest(v, length, 0, i+1) + 1;
		}
		else {
			dp[i][last] = minimumRest(v, length, 1, i+1);
		}
	}
	else if (v[i] == 2) { //gym
 
		if (last == v[i]) {
			dp[i][last] = minimumRest(v, length, 0, i+1) + 1;	
		}
		else {
			dp[i][last] = minimumRest(v, length, 2, i+1);
		}
	}
	else if (v[i] == 3) { //gym or contest
		int a = last == 1 ? INT_MAX : dp[i][last] = minimumRest(v, length, 1, i+1);
		int b = last == 2 ? INT_MAX : dp[i][last] = minimumRest(v, length, 2, i+1);
		dp[i][last] = min(a, b);
	}
 
	return dp[i][last];
}
 
int main(int argc, char const *argv[])
{ 
	memset(dp, -1, sizeof(dp));
 
	int n;
	cin >> n;
 
	vector<int> v(n);
 
	for (auto &it: v) {
		cin >> it;
	}
 
	int ans = minimumRest(v, n, 0, 0);
 
	output(ans);
 
	return 0;
}



