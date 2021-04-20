Highest Volume Stocks
Implement a data structure StockMarket which has the following methods:


For each stock, we'll keep track of the volume currently traded for that stock. We'll also maintain a balanced binary search 
tree-backed mapping from volume to all stocks that trade at that volume.

When we increase the volume of a stock, we have to update both of these maps, which involves clearing out the stale entry for 
the latter map and putting it at the proper volume, and also updating the volume for the stock directly.

When we query for the top K stocks, we traverse the latter mapping in decreasing volume order and add stocks one at a time.

Implementation
As stated above, we maintain a mapping from stock to its volume, as well as from a stock volume to all stocks with that volume. Since the inner set is backed by a balanced binary search tree, we can loop over it in order to ensure the lexicographic order.

Time Complexity
Assuming there are NN stocks, the add operation runs in \mathcal{O}(\log N)O(logN) time due to the map operation. 
The query operation runs in \mathcal{O}(K \log N)O(KlogN) time also due to map operations taking \mathcal{O}(\log N)O(logN) 
time.







StockMarket(String[] stocks, int[] amounts) which creates a new instance. stocks and amounts has the same length and each 
stock stocks[i] initially has amounts[i] volume in the market
add(String stock, int amount) which accumulatively adds stock with volume amount
top(int k) which returns the top k highest volume stocks, sorted in descending order by volume. If there are ties in 
volume, return the lexicographically smallest stocks first.
Constraints

n ≤ 100,000 where n is the number of calls to add and top.
Example 1
Input
methods = ["constructor", "add", "add", "add", "top"]
arguments = [[["NFLX"], [300]], ["AMZN", 100], ["GOOG", 300], ["AMZN", 300], [2]]`
Output
[null, null, null, null, ["AMZN", "GOOG"]]
Explanation
s = StockMarket(["NFLX"], [300])
s.add("AMZN", 100)
s.add("GOOG", 300)
s.add("AMZN", 300)
s.top(2) == ["AMZN", "GOOG"]
At the end "AMZN"'s volume is 400, "GOOG"'s volume is 300, and "NFLX"'s volume is 300. Since "AMZN" has the most
volume we return it first. Then, since "GOOG" and "NFLX" are tied in terms of volume, we return the lexicographically 
smaller stock which is "GOOG".




class StockMarket {
    set<pair<int, string>> SET;
    unordered_map<string, int> UMP;

    public:
    StockMarket(vector<string>& stocks, vector<int>& amounts) {
        for (int i = 0; i < stocks.size(); i++) {
            SET.insert({-1 * amounts[i], stocks[i]});
            UMP[stocks[i]] = amounts[i];
        }
    }

    void add(string s, int amount) {
        int currAmount = UMP[s];
        SET.erase({-1 * currAmount, s});
        currAmount += amount;
        SET.insert({-1 * currAmount, s});
        UMP[s] = currAmount;
    }

    vector<string> top(int k) {
        vector<string> highVol;
        for (auto& it : SET) {
            highVol.push_back(it.second);
            if (highVol.size() == k) break;
        }
        return highVol;
    }
};





class StockMarket {
    public:
    map<int, set<string>> amountToStocks;
    map<string, int> stockToAmount;
    StockMarket(vector<string>& s, vector<int>& amounts) {
        for (int i = 0; i < s.size(); i++) {
            add(s[i], amounts[i]);
        }
    }

    void add(string s, int amount) {
        if (stockToAmount.count(s)) {
            amountToStocks[stockToAmount[s]].erase(s);
        }
        stockToAmount[s] += amount;
        amountToStocks[stockToAmount[s]].insert(s);
    }

    vector<string> top(int k) {
        vector<string> ret;
        for (auto it = amountToStocks.rbegin(); ret.size() < k && it != amountToStocks.rend();
             it++) {
            for (auto stock : it->second) {
                ret.push_back(stock);
                if (ret.size() == k) break;
            }
        }
        return ret;
    }
};
