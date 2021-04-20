

https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

https://www.youtube.com/watch?v=eWkWapKb3c4&list=PLEvw47Ps6OBCwgmsyZ2AZsFEIYCHqlD4W&ab_channel=CodeWithSunny


#include<bits/stdc++.h>
using namespace std;


// vector to store prime number found
vector<int> primes;

// classical sieve
// Time Complexity:- O(nloglog(n))

void sieve(int n)
{
	// vector to mark initially all indexes as true
	vector<bool> isPrime(n+1,true);
	
	isPrime[0] = isPrime[1] = false;
	
	for(int i=2;i*i<=n;i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i;j<=n;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
	
	for(int i=0;i<=n;i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}
}


int main()
{
	// find prime numbers upto n;
	
	int n = 100;
	
	sieve(n);
	
	cout<<"Prime number in the range 1 to "<<n<<"are:- \n";
	
	for(auto it:primes)
	{
		cout<<it<<" ";
	}
}





int n;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
    //  here we start from i sqaure and take a jump of i
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
