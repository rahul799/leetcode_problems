1169. Invalid Transactions
Medium

114

741

Add to List

Share
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.

Given a list of transactions, return a list of transactions that are possibly invalid.  You may return the answer in any order.

 

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
 

Constraints:

transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.


class Solution {
    struct Node{
        int time;
        int account;
        string name;
        string city;
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        vector<string> rst;
        vector<Node> vec(n);
        for(int i=0;i<n;i++)
        {
            string tmp=transactions[i];
            for(char&c:tmp)
            {
                if(c==',') c=' ';
            }
            stringstream str(tmp);
            str>>vec[i].name>>vec[i].time>>vec[i].account>>vec[i].city;
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i].account>1000)
            {
                rst.push_back(transactions[i]);
                continue;
            }
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(abs(vec[i].time-vec[j].time)<=60&&vec[i].name==vec[j].name&&vec[i].city!=vec[j].city)
                {
                    rst.push_back(transactions[i]);
                    break;
                }
            }
        }
        return rst;
    }
};
