CCCXXVV
Question 237 of 927



https://binarysearch.com/problems/CCCXXVV


Given a string numeral representing a Roman numeral, convert it to an integer.

A Roman numeral is represented by writing its symbols from left to right from greatest to least, with the only exception being when when representing one less than a symbol.

For example, the Roman numerals from 1 to 12 are: I, II, III, IV, V, VI, VII, VIII, IX, X, XI, XII

The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
Example 1
Input
numeral = "XIV"






// A simple approach to solve this Problem:-
// Just add the number according to given character. Corner cases are like IV,IX.... In these cases you have to subtract the number, therefore to check these cases you have to compare the character with the next one.

int solve(string s) {
    unordered_map<char, int> hash = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
                                     {'X', 10},   {'V', 5},   {'I', 1}};

    int n = s.length(), ans = hash[s[n - 1]];
    for (int i = n - 2; i >= 0; --i) {
        char ch = s[i];
        if (hash[ch] >= hash[s[i + 1]])
            ans += hash[ch];
        else
            ans -= hash[ch];
    }
    return ans;
}



