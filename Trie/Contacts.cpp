https://www.hackerrank.com/challenges/contacts/problem


We're going to make our own Contacts application! The application must perform two types of operations:

add name, where  is a string denoting a contact name. This must store  as a new contact in the application.
find partial, where  is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
Given  sequential add and find operations, perform each operation in order.

Input Format

The first line contains a single integer, , denoting the number of operations to perform.
Each line  of the  subsequent lines contains an operation in one of the two forms defined above.

Constraints

It is guaranteed that  and  contain lowercase English letters only.
The input doesn't have any duplicate  for the  operation.
Output Format

For each find partial operation, print the number of contact names starting with  on a new line.


Sample Input

4
add hack
add hackerrank
find hac
find hak
Sample Output

2
0
Explanation

We perform the following sequence of operations:

Add a contact named hack.
Add a contact named hackerrank.
Find and print the number of contact names beginning with hac. There are currently two contact names in the application and both of them start with hac, so we print  on a new line.
Find and print the number of contact names beginning with hak. There are currently two contact names in the application but neither of them start with hak, so we print  on a new line.





#include<bits/stdc++.h>
using namespace std;
struct node{
    int count;
    node *next[26];
    node()
    {
        count = 0;
        for(int i = 0; i<26; i++)
            next[i] = NULL;
    }
}*root;

void add(string name)
{
    node *current = root;
    current->count++;
    for(int i = 0; i<name.size(); i++)
    {
        char nw = name[i];
        if(current->next[(int)nw - 'a'] == NULL)
            current->next[(int) nw - 'a'] = new node();
        current = current->next[(int) nw - 'a'];
        current->count++;
    }
}

int solve(string partial)
{
    node *current = root;
    for(int i = 0; i<partial.size(); i++)
    {
        char nw = partial[i];
        if(current->next[(int) nw - 'a'] == NULL)
            return 0;
        current = current->next[(int) nw - 'a'];
    }
    return current->count;
}

string command, str;
int main()
{
    int i, j, cs, n;
    root = new node();
    cin >> n;
    while(n--)
    {
        cin >> command >> str;
        if(command == "add")
            add(str);
        else
            printf("%d\n",solve(str));
    }
}










// #include <bits/stdc++.h>

// using namespace std;

// /*
//  * Complete the contacts function below.
//  */
// vector<int> contacts(vector<vector<string>> queries) {
//     /*
//      * Write your code here.
//      */

// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     int queries_rows;
//     cin >> queries_rows;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     vector<vector<string>> queries(queries_rows);
//     for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
//         queries[queries_row_itr].resize(2);

//         for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
//             cin >> queries[queries_row_itr][queries_column_itr];
//         }

//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }

//     vector<int> result = contacts(queries);

//     for (int result_itr = 0; result_itr < result.size(); result_itr++) {
//         fout << result[result_itr];

//         if (result_itr != result.size() - 1) {
//             fout << "\n";
//         }
//     }

//     fout << "\n";

//     fout.close();

//     return 0;
// }

