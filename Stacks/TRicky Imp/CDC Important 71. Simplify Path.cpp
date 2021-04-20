


https://www.youtube.com/watch?v=8fM6D3sMIDs&ab_channel=AlgorithmsMadeEasy

71. Simplify Path
Medium

331

96

Add to List

Share
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: path = "/a/./b/../../c/"
Output: "/c"
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.






class Solution {
public:
    string simplifyPath(string path) {
        string res, s;
        stack<string>stk;
        stringstream ss(path);  //it is uses to break string into words
        //this is similar to split function
        while(getline(ss, s, '/')) {
            
            // If the current component is a . or an empty string, we will do
            // nothing and simply continue. Well if you think about it, the split 
            //     string array for the string /a//b would be [a,,b]. yes, that's 
            //         an empty string in between a and b. Again, from the perspective 
            //         of the overall path, it doesn't mean anything.
                
                
                
            if (s == "" || s == ".") continue;
            // in case if our result string just contains a '.' or is 
            // that string empty one,  we will continue 
            
            if (s == ".." && !stk.empty()) 
                stk.pop();
            
            //we will remove the previous element before two .. 
            else if (s != "..") stk.push(s);
        }
        while(!stk.empty()){
            res = "/"+ stk.top() + res;
            stk.pop(); 
        }
        return res.empty() ? "/" : res;
        
        //this is use to handle the edge case if the res is empty 
        // we will pop it out
    }
};


