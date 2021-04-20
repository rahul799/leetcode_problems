Microsoft  OLA


https://github.com/jolly-fellow/microsoft



https://medium.com/@molchevsky/best-solutions-for-microsoft-interview-tasks-cae6b0f3ff86

Min Deletions to Make Frequency of Each Letter Unique



Description:
Given a string s consisting of n lowercase letters, you have to delete the minimum number of characters from s so that every letter in s appears a unique number of times. 
We only care about the occurrences of letters that appear at least once in result.


Input: "eeeeffff"
Output: 1
Explanation:
We can delete one occurence of 'e' or one occurence of 'f'. Then one letter will occur four times and the other three times.


Input: "aabbffddeaee"
Output: 6
Explanation:
For example, we can delete all occurences of 'e' and 'f' and one occurence of 'd' to obtain the word "aabbda".
Note that both 'e' and 'f' will occur zero times in the new word, but that's fine, since we only care about the letter that appear at least once.

Approach:


Let us have a string: abbbcccdddddeeeeee
Let’s rearrange it this way:
1: a
3: bbb
3: ccc
4: ddddd
4: eeeeee
As you can see the strings are sorted by number of their occurrence in the string. Each previous line may be only lesser or equal to the next one. In order to make number of each character unique we have to make from these strings a comfortable stairs where each stair step has height only one line. In other words if we meet two strings with the same length we need to decrease one of them.
We have to get this:
1: a
2: bb
3: ccc
4: dddd
5: eeeeee
We can go from the longest string and compare it with the previous one:
If the previous string is lesser then do nothing.
If the previous string is equal then remove one letter from it and increase counter of letters to remove.
But this algorithm will not work if we have three or more strings with the same length. To make it works we will need to start from the beginning after removing of each character. It doesn’t look effective.
So lets use a priority queue instead of sorting. The strings will be always sorted into the queue with the longest string on the top. Lets put the strings to a priority queue and take out the longest one, compare it with the next string and if they are equal remove one letter from the current string, increase a counter or characters to remove and put it back into the queue. Repeat this while the queue is not empty. By this algorithm we can count how many characters we need to remove in order to make number of each character unique.
Actually we don’t need to keep letters in the strings. It is enough to keep only numbers of their occurrences in given string. Index of the array will be number of letter in the alphabet.
Complexity of counting of the characters is O(N)
Complexity of counting of the characters to remove is O(Log(D)) but not bigger than size of the alphabet, in our case not bigger than O(Log(26))
Where N is length of given string and D is number of characters to remove
Thus general complexity is O(N)
C++ code:
int solution(const string & s) {
    // counter of characters to delete
    int count = 0;
    // array of counters of occurrences for all possible characters
    vector<int> occurrences('z' - 'a', 0);
    // count the occurrences
    for (char c: s) { ++occurrences[c - 'a']; }
    priority_queue<int> pq;
    // put non zero occurrences into the queue
    for (int c: occurrences) {
        if (c != 0) { pq.push(c); }
    }
    while (!pq.empty()) {
        // take the biggest frequency of a character
        int most_frequent = pq.top(); pq.pop();
        if (pq.empty()) { return count; }
        // if this frequency is equal to the next one
        // and bigger than 1 decrease it to 1 and put
        // back to the queue
        if (most_frequent == pq.top()) {
            if (most_frequent > 1) {
                pq.push(most_frequent - 1);
            }
            count++;
        }
        // all frequencies which are bigger than
        // the next one are removed from the queue 
        // because they are unique
    }
    return count;
}
