Maximum XOR Queries


https://binarysearch.com/problems/Maximum-XOR-Queries/editorials/2544258




You are given a list of non-negative integers nums and a two-dimensional list of integers queries where each element 
contains [x, limit].

Return a list such that for each query [x, limit], we find an e in nums such that e ≤ limit and XOR(e, x) is maximized. 
If there's no such e, use -1.

Constraints

n ≤ 100,000 where n is the length of nums
m ≤ 100,000 where m is the length of queries
Example 1
Input
nums = [2, 4, 8]
queries = [
    [3, 5],
    [2, 0]
]
Output
[4, -1]
Explanation
For the first query, we can use 2 or 4 in nums. 2 ^ 3 = 1 while 4 ^ 3 = 7 so we pick 4 which yields the bigger XOR. In 
the second query, there's no number that's less than or equal to 0, so 
we set it to -1.




Intuition
We can use a 0-1 Trie and do online queries. To handle the limits, we add an additional lolo field in the TrieNode structure to store the minimum value of the subtree.

For each query, we go down from the Trie's root to find the optimal answer. If a bit is set in xx, we try to use the 00 path if it exists. If a bit is not set in xx, we try to use the 11 path if it exists and its lo\leq limitlo≤limit. If at any stage we have no way to go, we add -1−1 to the final answer.

Time complexity: O((N+Q)\log\text{MAX})O((N+Q)logMAX)
Space complexity: O((N+Q)\log\text{MAX})O((N+Q)logMAX)

struct TrieNode {
    int lo = INT_MAX;
    TrieNode* children[2]{};
};

class Solution {
    public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            TrieNode* p = root;
            for (int i = 30; i >= 0; --i) {
                int nxt = (num & (1 << i)) ? 1 : 0;
                if (!p->children[nxt]) p->children[nxt] = new TrieNode();
                p = p->children[nxt];
                p->lo = min(p->lo, num);
            }
        }
        vector<int> ret;
        for (auto q : queries) {
            int x = q[0], limit = q[1];
            int ans = 0;
            TrieNode* p = root;
            for (int i = 30; i >= 0; --i) {
                if (x & (1 << i)) {
                    if (p->children[0]) {
                        p = p->children[0];
                    } else if (!p->children[1] || (p->children[1]->lo > limit)) {
                        ret.emplace_back(-1);
                        break;
                    } else {
                        p = p->children[1];
                        ans ^= (1 << i);
                    }
                } else {
                    if (p->children[1] && (p->children[1]->lo <= limit)) {
                        p = p->children[1];
                        ans ^= (1 << i);
                    } else if (!p->children[0]) {
                        ret.emplace_back(-1);
                        break;
                    } else {
                        p = p->children[0];
                    }
                }
                if (i == 0) ret.emplace_back(ans);
            }
        }
        return ret;
    }
};

vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
    return (new Solution())->solve(nums, queries);
}



