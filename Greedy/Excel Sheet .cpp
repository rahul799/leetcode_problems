
Given a positive integer N, print its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.



using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long int n;
	    int i=1;
	    cin>>n;
	    string s={'\0'};
	    while(n)
	    {
	        n--;
	        {s = char(((n)%26)+'A')+s;}
	        n=n/26;
	    }
	    cout<<s<<endl;
	}
	return 0;
}
