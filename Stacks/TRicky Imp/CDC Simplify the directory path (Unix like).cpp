
Update: search simpllify Path


Simplify the directory path (Unix like)

https://www.geeksforgeeks.org/simplify-directory-path-unix-like/

Simplify the directory path (Unix like)
Difficulty Level : Medium
Last Updated : 08 Feb, 2021
Given an absolute path for a file (Unix-style), simplify it. Note that absolute path always begin with ‘/’ ( root directory ), a dot in path represent current directory and double dot represents parent directory.
Examples: 

"/a/./"   --> means stay at the current directory 'a'
"/a/b/.." --> means jump to the parent directory
              from 'b' to 'a'
"////"    --> consecutive multiple '/' are a  valid  
              path, they are equivalent to single "/".

Input : /home/
Output : /home

Input : /a/./b/../../c/
Output : /c

Input : /a/..
Output:/

Input : /a/../
Output : /

Input : /../../../../../a
Output : /a

Input : /a/./b/./c/./d/
Output : /a/b/c/d

Input : /a/../.././../../.
Output:/

Input : /a//b//c//////d
Output : /a/b/c/d
Note: The given input will always have a valid absolute path.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach 1:
By looking at examples we can see that the above simplification process just behaves like a stack. Whenever we encounter any file’s name, we simply push it into the stack. when we come across ” . ” we do nothing. When we find “..” in our path, we simply pop the topmost element as we have to jump back to parent’s directory. 
When we see multiple “////” we just ignore them as they are equivalent to one single “/”. After iterating through the whole string the elements remaining in the stack is our simplified absolute path. We have to create another stack to reverse the elements stored inside the original stack and then store the result inside a string.
 


/* C++ program to simplify a Unix
   styled absolute path of a file */
#include <bits/stdc++.h>
using namespace std;
 
// function to simplify a Unix - styled
// absolute path
string simplify(string A)
{
    // stack to store the file's names.
    stack<string> st;
 
    // temporary string which stores the extracted
    // directory name or commands("." / "..")
    // Eg. "/a/b/../."
    // dir will contain "a", "b", "..", ".";
    string dir;
 
    // contains resultant simplifies string.
    string res;
 
    // every string starts from root directory.
    res.append("/");
 
    // stores length of input string.
    int len_A = A.length();
 
    for (int i = 0; i < len_A; i++) {
 
        // we will clear the temporary string
        // every time to accomodate new directory
        // name or command.
        dir.clear();
 
        // skip all the multiple '/' Eg. "/////""
        while (A[i] == '/')
            i++;
 
        // stores directory's name("a", "b" etc.)
        // or commands("."/"..") into dir
        while (i < len_A && A[i] != '/') {
            dir.push_back(A[i]);
            i++;
        }
 
        // if dir has ".." just pop the topmost
        // element if the stack is not empty
        // otherwise ignore.
        if (dir.compare("..") == 0) {
            if (!st.empty())
                st.pop();           
        }
 
        // if dir has "." then simply continue
        // with the process.
        else if (dir.compare(".") == 0)
            continue;
         
        // pushes if it encounters directory's
        // name("a", "b").
        else if (dir.length() != 0)
            st.push(dir);       
    }
 
    // a temporary stack  (st1) which will contain
    // the reverse of original stack(st).
    stack<string> st1;
    while (!st.empty()) {
        st1.push(st.top());
        st.pop();
    }
 
    // the st1 will contain the actual res.
    while (!st1.empty()) {
        string temp = st1.top();
         
        // if it's the last element no need
        // to append "/"
        if (st1.size() != 1)
            res.append(temp + "/");
        else
            res.append(temp);
 
        st1.pop();
    }
 
    return res;
}
 
// Driver code.
int main()
{
    // absolute path which we have to simplify.
    string str("/a/./b/../../c/");
    string res = simplify(str);
    cout << res;
    return 0;
}
