133. Clone Graph
Medium

https://leetcode.com/problems/clone-graph/


Share
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
      if (!node) return nullptr;
      
      // map original nodes to copied nodes
      unordered_map<Node*, Node*> copy; 
      
      // BFS initialization
      queue<Node*> q({node});
      copy[node] = new Node(node->val);
      
      // BFS
      while (!q.empty()) {
        Node* cur = q.front(); q.pop();
		
		// create neighbors for current node
        for (Node* nb : cur->neighbors) {
          if (copy.count(nb))
            copy[cur]->neighbors.push_back(copy[nb]);
          else {
            copy[nb] = new Node(nb->val);
            copy[cur]->neighbors.push_back(copy[nb]);
            q.push(nb);
          }
        }
      }
      
      return copy[node];
    }
};
