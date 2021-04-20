No Prefix Set

Given  strings. Each string contains only lowercase letters from (both inclusive). The set of  strings is said to be GOOD SET if no string is prefix of another string else, it is BAD SET. (If two strings are identical, they are considered prefixes of each other.)

For example, aab, abcde, aabcd is BAD SET because aab is prefix of aabcd.

Print GOOD SET if it satisfies the problem requirement.
Else, print BAD SET and the first string for which the condition fails.

Input Format
First line contains , the number of strings in the set.
Then next  lines follow, where  line contains  string.

Constraints

 Length of the string 

Output Format
Output GOOD SET if the set is valid.
Else, output BAD SET followed by the first string for which the condition fails.

Sample Input00

7
aab
defgab
abcde
aabcde
cedaaa
bbbbbbbbbb
jabjjjad
Sample Output00

BAD SET
aabcde
Sample Input01

4
aab
aac
aacghgh
aabghgh
Sample Output01

BAD SET
aacghgh
Explanation
aab is prefix of aabcde. So set is BAD SET and it fails at string aabcde.








#include<bits/stdc++.h>
using namespace std;
string str, bad_string;
struct node{
    bool end_mark;
    node *next[10];
    node()
    {
        end_mark = false;
        for(int i = 0; i<10; i++)
            next[i] = NULL;
    }
}*root;
bool add(string s)
{
    node *current = root;
    for(int i = 0; i<s.size(); i++)
    {
        int nw = s[i] - 'a';
        if(i == (s.size()-1) && current->next[nw] != NULL)
            return false;
        if(current->next[nw] == NULL)
            current->next[nw] = new node();
        current = current->next[nw];
        if(current->end_mark)
            return false;
    }
    current->end_mark = true;
    return true;
}

int main()
{
    int i, N;
    bool ok = true;
    cin >> N;
    root = new node();
    for(i = 1; i<=N; i++)
    {
        cin >> str;
        if(!ok)
            continue;
        ok = add(str);
        if(!ok)
            bad_string = str;
    }
    if(ok)
        printf("GOOD SET\n");
    else
    {
        printf("BAD SET\n");
        cout << bad_string << endl;
    }
}
