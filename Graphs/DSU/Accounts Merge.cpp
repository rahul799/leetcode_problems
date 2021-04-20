721. Accounts Merge
Medium

2103

395

Add to List

Share
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30]




Intuition

Draw an edge between two emails if they occur in the same account. The problem comes down to finding connected components of this graph.

Algorithm

For each account, draw the edge from the first email to all other emails. Additionally, we'll remember a map from emails to names on the side. After finding
each connected component using a depth-first search, we'll add that to our answer.





Approach 2:


As in Approach #1, our problem comes down to finding the connected components of a graph. This is a natural fit for a Disjoint Set Union (DSU) structure.

Algorithm

As in Approach #1, draw edges between emails if they occur in the same account. For easier interoperability between our DSU template, we will map each email to some integer index by using emailToID. Then, dsu.find(email) will tell us a unique id representing what component that email is in.

For more information on DSU, please look at Approach #2 in the article here. For brevity, the solutions showcased below do not use union-by-rank.






We first create n (size of accounts) groups, one for each account.
In the beginning each group points to itself.
Create a email to groups mapping 'emailToGroup' as described below:
For each emails in account[i] ( group => i ):
2.1 If email is not present in emailToGroup then add ( email, i ) to emailToGroup.
2.2 If email is present then merge group 'i' and group 'emailToGroup[email]'.
                   // Union
                    int root1 = find( parent, i );
                    int root2 = find( parent, emailToGroup[email] );
                    parent[ root1 ] = root2;
Create a reverse map of group to email.
class Solution {
    int find( vector<int>& parent, int i ) {
        while( parent[i] != i )
            i = parent[i];
        return i;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n); // groups 0 ... n-1
        unordered_map< string, int > emailToGroup; // email -> group
    
        for (int i = 0; i < n; i++) {
            parent[i] = i; // init parent
            for( int j=1; j < accounts[i].size(); j++ ) {
                string email = accounts[i][j];
                if( emailToGroup.find( email ) != emailToGroup.end() ) {
                    // Union
                    int root1 = find( parent, i );
                    int root2 = find( parent, emailToGroup[email] );
                    parent[ root1 ] = root2;
                } else {
                    emailToGroup[ email ] = i;
                }
            }
        }
    
        unordered_map<int, vector<string>> groupToEmail;
        for( auto it : emailToGroup ) {
            int root = find( parent, it.second );
            groupToEmail[root].push_back( it.first );
        }
        
        // create result
        vector<vector<std::string>> res;
        for( auto it : groupToEmail ) {
            sort( it.second.begin(), it.second.end() );
            vector<string> tmp = { accounts[it.first][0] };
            tmp.insert( tmp.end(), it.second.begin(), it.second.end() );
            res.push_back( tmp );
        }
        return res;
    }
};



Time Complexity: O(A \log A)O(AlogA), where A = \sum a_iA=∑a 
i
​	
 , and a_ia 
i
​	
  is the length of accounts[i]. If we used union-by-rank, this complexity improves to O(A \alpha(A)) \approx O(A)O(Aα(A))≈O(A), where \alphaα is the 
  Inverse-Ackermann function.

Space Complexity: O(A)O(A), the space used by our DSU structure.


