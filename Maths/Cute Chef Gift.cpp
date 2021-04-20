

Chef wants to give a gift to Chefina to celebrate their anniversary. Of course, he has a sequence a1,a2,…,aN ready for this occasion. Since the half-heart necklace is kind of cliche, he decided to cut his sequence into two pieces and give her a piece instead. Formally,
he wants to choose an integer l (1≤l<N) and split the sequence into its prefix with length l and its suffix with length N−l.

Chef wants his gift to be cute; he thinks that it will be cute if the product of the elements in Chefina's piece is coprime with the product of the elements in 
his piece. Can you tell him where to cut the sequence? Find the smallest valid l such that Chef's gift would be cute.



The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains the integer N.
The second line contains N space-separated integers a1,a2,…,aN.
Output
For each test case, print a single line containing one integer l where Chef should cut the sequence.

It is guaranteed that a solution exists for the given test data.



#include <stdio.h>
#include <iostream> 
#include <algorithm>  
  
using namespace std; 

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    unsigned long long int product = 1;
	    for(int i=0;i<n;i++)
	    {
	        product = product*arr[i];
	    }
	    unsigned long long int ans = 1;
	    for(int i=n-1;i>=0;i--)
	    {
	        product = product / arr[i];
	        ans = ans * arr[i];
	        if(__gcd(product,ans) == 1)
	        {
	            printf("%d\n",i+1);
	            break;
	        }
	    }
	}
	return 0;
}

