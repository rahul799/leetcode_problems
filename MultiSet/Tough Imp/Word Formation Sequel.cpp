






https://binarysearch.com/problems/Word-Formation-Sequel/editorials/2960904



Word Formation Sequel
Given a list of strings words and a string letters, find the length of the longest word that can be made by rearranging the given letters, and if you have the letter "*", it can match any character. It is not necessary to use all the letters.

Example 1
Input
words = ["alice", "sunstroke", "mercantilely", "lakism", "phosphine"]
letters = "*s*ki*"
Output
6
Explanation
The longest word we can make is "lakism" where we can replace the * with l, a, and m.


Intuition
Let's check all the strings, if they can be formed using the letters given :)

check() function:
I used a multiset (you can use a unordered_map<char,int> of frequencies too)

Any time i didn't have the needed character for making the word,
I tried to use the '*' character,
if i didn't have that as well I returned false :D





bool check(const string& w, const string& ll) {
    multiset<char> l(ll.begin(), ll.end());
    for (const char& c : w)
        if (l.count(c))
            l.erase(l.find(c));
        else if (l.count('*'))
            l.erase(l.find('*'));
        else
            return false;
    return true;
}

int solve(vector<string>& words, string letters) {
    size_t res = 0;
    for (const string& w : words)
        if (check(w, letters)) res = max(res, w.size());
    return res;
}
