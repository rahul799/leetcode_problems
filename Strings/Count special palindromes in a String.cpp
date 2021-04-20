

Count special palindromes in a String
Last Updated: 05-02-2019
Given a String s, count all special palindromic substrings of size greater than 1. A Substring is called special palindromic substring if all the characters 
in the substring are same or only the middle character is different for odd length. Example “aabaa” and “aaa” are special palindromic substrings and 
“abcba” is not special palindromic substring.



Efficient Solution
There are 2 Cases :
Case 1: All Palindromic substrings have same character :
We can handle this case by simply counting the same continuous character and using formula K*(K+1)/2 (total number of substring possible : Here K is count of Continuous same char).



 Lets Str = "aaabba"
 Traverse string from left to right and Count of same char
  "aaabba"  =  3, 2, 1
   for "aaa" : total substring possible are
   'aa' 'aa', 'aaa', 'a', 'a', 'a'  : 3(3+1)/2 = 6 
   "bb" : 'b', 'b', 'bb' : 2(2+1)/2 = 3
   'a'  : 'a' : 1(1+1)/2 = 1 
Case 2:
We can handle this case by storing count of same character in another temporary array called “sameChar[n]” of size n. and pick each character one-by-one and check its previous and forward character are equal or not if equal then there are min_between( sameChar[previous], sameChar[forward] ) substring possible.

Let's Str = "aabaaab"
 Count of smiler char from left to right :
 that we will store in Temporary array "sameChar"
  Str         =    " a a b a a a b "
sameChar[]  =      2 2 1 3 3 3 1
According to the problem statement middle character is different:
so we have only left with char "b" at index :2 ( index from 0 to n-1)
substring : "aabaaa"
so only two substring are possible : "aabaa", "aba"
that is min (smilerChar[index-1], smilerChar[index+1] ) that is 2.



https://www.hackerrank.com/challenges/special-palindrome-again/editorial?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings



// C++ program to count special Palindromic substring 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count special Palindromic susbstring 
int CountSpecialPalindrome(string str) 
{ 
	int n = str.length(); 

	// store count of special Palindromic substring 
	int result = 0; 

	// it will store the count of continues same char 
	int sameChar[n] = { 0 }; 

	int i = 0; 

	// traverse string character from left to right 
	while (i < n) { 

		// store same character count 
		int sameCharCount = 1; 

		int j = i + 1; 

		// count smiler character 
		while (str[i] == str[j] && j < n) 
			sameCharCount++, j++; 

		// Case : 1 
		// so total number of substring that we can 
		// generate are : K *( K + 1 ) / 2 
		// here K is sameCharCount 
		result += (sameCharCount * (sameCharCount + 1) / 2); 

		// store current same char count in sameChar[] 
		// array 
		sameChar[i] = sameCharCount; 

		// increment i 
		i = j; 
	} 

	// Case 2: Count all odd length Special Palindromic 
	// substring 
	for (int j = 1; j < n; j++) 
	{ 
		// if current character is equal to previous 
		// one then we assign Previous same character 
		// count to current one 
		if (str[j] == str[j - 1]) 
			sameChar[j] = sameChar[j - 1]; 

		// case 2: odd length 
		if (j > 0 && j < (n - 1) && 
			(str[j - 1] == str[j + 1] && 
			str[j] != str[j - 1])) 
			result += min(sameChar[j - 1], 
						sameChar[j + 1]); 
	} 

	// subtract all single length substring 
	return result - n; 
} 

// driver program to test above fun 
int main() 
{ 
	string str = "abccba"; 
	cout << CountSpecialPalindrome(str) << endl; 
	return 0; 
} 



Same question:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,i=0,j,ans=0;
    cin>>n;

    string s;
    cin>>s;

    int same_char_count[n]={0};

    while(i<n) {
        j=i+1,c=1;
        while(j<n && s[i]==s[j]) {
            ++j,++c;
        }

        //total substrings which have all same char(s)
        ans+=(c*(c+1))>>1;
        same_char_count[i]=c;
        i=j;
    }

    for(j=1;j<n-1;++j) {
        if(s[j]==s[j-1]) {
            same_char_count[j] = same_char_count[j-1];
        }

        //odd length substr(s) which has middle element diiferent
        if(s[j-1]==s[j+1] && s[j]!=s[j-1]) {
            ans += min(same_char_count[j-1], same_char_count[j+1]);
        }
    }
    cout<<ans<<endl;

    return 0;
}





