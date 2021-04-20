





https://binarysearch.com/problems/Gene-Mutation-Groups



Gene Mutation Groups
Question 690 of 906
You are given a list of unique strings genes where each element has the same length and contains characters "A", "C", "G" and/or "T".

If strings a and b are the same string except for one character, then a and b are in the same mutation group.
If strings a and b are in a group and b and c are in a group, then a and c are in the same group.
Return the total number of mutation groups.

Constraints

n ≤ 10,000
k ≤ 20 where k is the length of a string in genes
Example 1
Input
genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
Output
2
Explanation
There are two mutation groups:

["ACGT", "ACCT", "AGGT"]
["TTTT", "TTTG"]







Create a graph, where number of nodes n is the number of given genes, and edges exits between nodes that differ by only one character.
Use Union Find (aka. Disjoint Sets) data structure to count the number of components in the graph.
In the beginning, there are n groups. Each time we do a union, we decrement the number of groups.

Implementation
Create a map gene_map to map each gene to it's index in the array, so we can use UnionFind with n integer elements.
Loop through the genes, and for each gene, loop through it's characters, replacing each with other 3 possible types of characters. With each changed character, we try to find a match in the gene_map for the changed gene (1 character difference).
If it exists, we do union on those to indices gene_map[gene]. If union happens, we decrement the number of groups.
The problem is very similar to Number of Islands problem, and other problems that ask you to count the number of separate components in a graph.

Time Complexity
\mathcal{O}(N * K)O(N∗K) - Where N is the size of the genes array, and K is the length of each gene.

Space Complexity
\mathcal{O}(N)O(N) - For creating the gene_map and union_find






    private:
    vector<int> parents, rank;

    public:
    UnionFind(int n) {
        parents.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node) {
        int root = node;

        while (root != parents[root]) {
            root = parents[root];
        }

        // Path compression
        while (node != root) {
            int temp = parents[node];
            parents[node] = root;
            node = temp;
        }

        return root;
    }

    // Returns true if union happens
    bool unify(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return false;

        // Union by rank
        if (rank[rootA] > rank[rootB]) {
            parents[rootB] = rootA;
        } else if (rank[rootB] > rank[rootA]) {
            parents[rootA] = rootB;
        } else {
            parents[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
};

int solve(vector<string>& genes) {  // Time: O(N * K), Space: O(N)
    int n = genes.size();
    unordered_map<string, int> gene_map;
    char type[4] = {'A', 'C', 'G', 'T'};

    for (int i = 0; i < n; i++) gene_map[genes[i]] = i;

    UnionFind union_find(n);
    int groups = n;

    for (string& gene : genes) {
        int curr = gene_map[gene];

        for (char& c : gene) {
            char orig = c;
            for (char t : type) {
                if (t != orig) {
                    c = t;
                    if (gene_map.count(gene)) {
                        if (union_find.unify(curr, gene_map[gene])) groups--;
                    }
                }
            }

            c = orig;
        }
    }

    return groups;
}
