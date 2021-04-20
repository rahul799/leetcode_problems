Construct lexicographically smallest palindrome - GeeksforGeeks
Given a string of lowercase alphabets. Some of characters of given string got corrupted and are now represented by *. We can replace * with any of lowercase alphabets. You have to
construct lexicographically smallest palindrome string. If it is not possible to construct a palindrome print “Not Possible”.


      Input : str[] = "bc*b"
      Output : bccb
      Input : str[] = "bc*a*cb"
      Output : bcaaacb
      Input : str[] = "bac*cb"
      Output : Not Possible
      
      
      
      
      Start traversing the string from both end. Say with i=0, j=strlen-1, keep increasing i and
      decreasing j after every single iteration till i exceeds j. Now at any intermediate position we
      have five possible case :
    1. str[i] and str[j] both are same and also not equal to ‘*’. In this case simply continue.
     2. str[i] and str[j] both are same and are equal to ‘*’. Here you must fill str[i] = str[j] =
      ‘a’ for smallest possible palindrome.
      3. str[i] equals to ‘*’ and str[j] is some alphabet. Here fill str[i] = str[j] to make our string
      a palindrome.

      4. str[j] equals to ‘*’ and str[i] is some alphabet. Here fill str[j] = str[i] to make our string
      a palindrome.
      5. str[i] is not equals to str[j] and also both are some alphabet. In this case palindrome
      construction is not possible. So, print “Not Possible” and break from loop.
      After i exceeds j means we have got our required palindrome. Else we got “Not possible” as
      result.
      
      
      // CPP for constructing smallest palindrome
      #include <bits/stdc++.h>
      using namespace std;
      // function for printing palindrome
      string constructPalin(string str, int len)
      {
      int i = 0, j = len - 1;
      // iterate till i<j
      for (; i < j; i++, j--) {
      // continue if str[i]==str[j]
      if (str[i] == str[j] && str[i] != '*')
      continue;
      // update str[i]=str[j]='a' if both are '*'
      else if (str[i] == str[j] && str[i] == '*') {
      str[i] = 'a';
      str[j] = 'a';
      continue;
      }
      // update str[i]=str[j] if only str[i]='*'
      else if (str[i] == '*') {
      str[i] = str[j];
      continue;
      }
      // update str[j]=str[i] if only str[j]='*'
      else if (str[j] == '*') {
      str[j] = str[i];
      continue;
      }
      // else print not possible and return
      cout << "Not Possible";
      return "";
      }
     return str;
      }
      // driver program
      int main()
      {
      string str = "bca*xc**b";
      int len = str.size();
      cout << constructPalin(str, len);
      return 0;
      }
