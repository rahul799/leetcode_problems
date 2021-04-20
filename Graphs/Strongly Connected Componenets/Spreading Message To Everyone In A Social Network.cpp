Spreading Message To Everyone In A Social Network



thealgorists.com/Algo/AdvancedGraphProblems/SpreadMessageToEntireNetwork



Problem Statement: In a certain social network, when someone gets a message he/she sends that message to all of his/her followers.
Now, I am considering to spread a promotion message across all people in that social network.


Your task is to find the minimum number of people to reach out (for example, who doesn't follow anyone etc) so that my promotion message spreads out across 
entire social 
network.

We need to consider loops like, if A follows B, B follows C, C follows D, D follows A (A -> B -> C -> D -> A) then reaching only one of them is sufficient to spread your message.

Input: List of followers for every user in the social network:

1:  3, 4
2:
3:  1
4:  3

Here, user 1 has user 3 and 4 as followers. User 2 has no followers. User 3 has user 1 s follower. User has user 3 as follower.

Output: Minimal list of people to be reached to spread out message across everyone in the network.




Approach : Solution:
It's quite evident from the problem statement that we would need to construct a directed graph to represent the entire social network where the edges represent 
the followee - follower relationship. Edge A -> B represents B
follows A.




Topological Sort of all the users in the given social network, you need to let only those users know who have indegree = 0 and appears all the way to the left 
in the topological sort (i.e, towards the beginning of the topologically sorted list). These users have indegree = 0 because they do not follow any other users. 
All other users are reachable from one or more of these users (with zero indegree). Recall the concept of Topological Sort. For those users who have no inbound 
edges, there is no way they would come to know about the message if we do not let them know 
implicitly.




What's missing from the directed graphs in the above diagram is Strongly Connected Components. Please read the chapter Strongly Connected Components (SCC) to
know more
about it.

A very important observation here is that all the users belonging to a Strongly Connected Component has non-zero indegree since all of them have at least one 
inbound edge






These Strongly Connected Components (SCC) can be of two types:
Isolated SCC, i.e, SCC with no incoming cross-edge or a forward edge from a vertex that is not part of the same SCC:

This kind of SCCs are totally disconnected from the rest of the graph (i.e, social network), and cannot be reached from a node outside of the SCC or from other 
SCC. In this case we just need to make the indegree for the root of the Strongly Connected Component zero and include that in our final list of minimum number 
of users need to be informed. The SCC below is an 
isolated SCC.






SCC reachable from some other vertex which is not part of the same SCC:

This kind of Strongly Connected Component is connected to the rest of the social network by one or more vertices outside of the SCC (through forward edge) or from any other SCC (through cross-edge).
In this case there is at least one cross-edge or forward edge from a node that is not part of this SCC. In this case we do not need to let any of the users in 
the SCC explicitly know (by that I meant, none of the users in the SCC need to be part of the minimum number of people to reach out), since they will come to 
know from the rest of the social network since the root of the SCC is already connected (in addition to the root, even a non-root vertex can be connected to the
rest of the directed graph through an incoming cross-edge). In the below diagram SCC 5-6-7 is connected to the SCC 2-3-4 through the cross-edge 4->6. Also both
SCC 2-3-4 and 5-6-7 are connected to the rest of the graph by vertex A. Both of these two SCCs have incoming forward edges from vertex A. So if user A gets the
message all the users in SCC 2-3-4 and 5-6-7 will get the 
message too.










import java.util.*;

/**
 * Created by Abhishek on 9/21/20.
 */
public class SpreadMessageInANetwork {

    int discoveryTime = 0; // discovery time

    // Nodes in adjacency lists are numbered from 0 to N - 1
    public void findSccAndDecrementIndegreeOfRoot(List< Set< Integer >> adjacencyLists, int[] indegree) {
        discoveryTime = 0; // reset index to 0
        int len = adjacencyLists.size();
        int[] discoveryTime = new int[len];
        int[] earliestDiscoveredNodeReachable = new int[len];
        Deque< Integer > sccStack = new ArrayDeque<>();
        boolean[] onStack = new boolean[len];

        for (int i = 0; i < adjacencyLists.size(); i++) {
            if (discoveryTime[i] == 0) { // indices[i] == 0 when vertex i is not already visited
                dfs(adjacencyLists, discoveryTime, earliestDiscoveredNodeReachable, sccStack, onStack, i, indegree);
            }
        }
    }

    private void dfs(
            List< Set< Integer >> adjacencyLists,
            int[] discoveryTimes,
            int[] earliestDiscoveredNodeReachable,
            Deque< Integer > strongComponentStack,
            boolean[] onStack,
            int currentNode,
            int[] indegree)
    {
        discoveryTime++;
        discoveryTimes[currentNode] = discoveryTime; // array is zero based index, nodes are numbered from 0 to N - 1
        earliestDiscoveredNodeReachable[currentNode] = discoveryTime;
        strongComponentStack.push(currentNode);
        onStack[currentNode] = true;
        for (int adjVertex : adjacencyLists.get(currentNode)) { //adjacencyList of vertex i is stored ar index i in arraylist
            if (discoveryTimes[adjVertex] == 0) { // discoveryTime[v] == 0 when vertex v is not already visited
                dfs(adjacencyLists, discoveryTimes, earliestDiscoveredNodeReachable, strongComponentStack, onStack, adjVertex, indegree);
                earliestDiscoveredNodeReachable[currentNode] =
                        Math.min(earliestDiscoveredNodeReachable[currentNode], earliestDiscoveredNodeReachable[adjVertex]);
            } else { // adjacentVertex is already visited
                if (!onStack[adjVertex]) {
                    // the adjacent vertex is already visited BUT it is not in the stack
                    // this means the current edge is just a cross edge to an SCC
                    // which has already been found and processed
                    continue;
                } else {
                    // adjacent vertex is in stack, so must be in the same SCC
                    earliestDiscoveredNodeReachable[currentNode] =
                            Math.min(earliestDiscoveredNodeReachable[currentNode], discoveryTimes[adjVertex]);
                    // NOTE: Because adjacentVertex is on the stack already, the edge (currentNode, adjacentVertex)
                    // is a back-edge in the DFS tree and
                    // therefore adjacentVertex is not in the subtree of currentNode.
                    // Because earliestDiscoveredNodeReachable[i]
                    // takes into account nodes reachable only through the nodes in the subtree of currentNode and we
                    // must stop at adjacentVertex and use discoveryTime[adjacentVertex]
                    // instead of earliestDiscoveredNodeReachable[adjacentVertex]. One back-edge is okay, but not more than one.
                }
            }
        }
        // now that DFS on currentNode is done lets see
        // if we got any SCC before backtracking
        if (earliestDiscoveredNodeReachable[currentNode] == discoveryTimes[currentNode]) {
            Set< Integer > sccNodes = new HashSet<>();
            int top = 0;
            // construct a set of all the nodes in this SCC
            do {
                top = strongComponentStack.pop();
                sccNodes.add(top);
                onStack[top] = false;
            } while (top != currentNode); // root can have self loop as well. it takes care of that too.

            // Determine if there is any incoming edge from
            // a node that is not part of this SCC.
            // Presence of a cross-edge or a forward edge from outside of the SCC
            // would mean that this SCC is reachable from a vertex outside of this SCC
            // and need not be included in the minimum list of users to send message.
            for (int current : sccNodes) {
                for (int otherNode : sccNodes) {
                    if (adjacencyLists.get(otherNode).contains(current)) {
                        indegree[current]--;
                    }
                }
            }
            boolean isolatedSCC = true;
            for (int sccNode : sccNodes) {
                if (indegree[sccNode] != 0) {
                    isolatedSCC = false;
                }
            }
            for (int sccNode : sccNodes) {
                    indegree[sccNode] = Integer.MAX_VALUE;
            }
            if (isolatedSCC) {
               indegree[currentNode] = 0;
            }

            }

        }


    public List< Integer > getMinimumUsersToMessage(List< Set< Integer >> adjacencyLists) {
        int totalNumberOfUsers = adjacencyLists.size();
        int[] indegree = new int[totalNumberOfUsers];

        // construct indegree array
        for (Set< Integer > adjacencyList : adjacencyLists) {
            for (int user : adjacencyList) {
                indegree[user]++;
            }
        }

        // find SCCs and decrement indegrees as appropriate, as discussed in our algorithm
        findSccAndDecrementIndegreeOfRoot(adjacencyLists, indegree);

        List< Integer > res = new ArrayList<>();

        for (int i = 0; i < totalNumberOfUsers; i++) {
            if (indegree[i] == 0) {
                res.add(i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        /*
          0<-------1
                  _
            \     /|
            _\|  /
               2
              / \
               |
               3
               |
              \ /
               6
                _
            /  |\
          |/_    \
          4------>5

            Expected Result => 3
         */
        List< Set< Integer >> adjLists = new ArrayList<>();
        adjLists.add(new HashSet< Integer >() {{ add(2); }}); // for node 0
        adjLists.add(new HashSet< Integer >() {{ add(0); }}); // for node 1
        adjLists.add(new HashSet< Integer >() {{ add(1); }}); // for node 2
        adjLists.add(new HashSet< Integer >() {{ add(2); add(6); }}); // for node 3
        adjLists.add(new HashSet< Integer >() {{ add(5); }}); // for node 4
        adjLists.add(new HashSet< Integer >() {{ add(6); }}); // for node 5
        adjLists.add(new HashSet< Integer >() {{ add(4); }}); // for node 6

        SpreadMessageInANetwork ob = new SpreadMessageInANetwork();
        List< Integer > res = ob.getMinimumUsersToMessage(adjLists);
        for (int i : res) {
            System.out.print(i + "  ");
        }
        System.out.println();
        System.out.println();

        /*
          0<-------1
                  _
            \     /|
            _\|  /
               2
               |
              \ /
               3
                _
             / |\
           |/_   \
           4----->5

           Expected result => 0 or 1 or 2
         */
        adjLists = new ArrayList<>();
        adjLists.add(new HashSet< Integer >() {{ add(2); }}); // for node 0
        adjLists.add(new HashSet< Integer >() {{ add(0); }}); // for node 1
        adjLists.add(new HashSet< Integer >() {{ add(1); add(3); }}); // for node 2
        adjLists.add(new HashSet< Integer >() {{ add(4); }}); // for node 3
        adjLists.add(new HashSet< Integer >() {{ add(5); }}); // for node 4
        adjLists.add(new HashSet< Integer >() {{ add(3); }}); // for node 5

        ob = new SpreadMessageInANetwork();
        res = ob.getMinimumUsersToMessage(adjLists);
        for (int i : res) {
            System.out.print(i + "  ");
        }
        System.out.println();
        System.out.println();

        /*
            0

            Expected Result: 0
         */
        adjLists = new ArrayList<>();
        adjLists.add(new HashSet< Integer >()); // for node 0
        ob = new SpreadMessageInANetwork();
        res = ob.getMinimumUsersToMessage(adjLists);
        for (int i : res) {
            System.out.print(i + "  ");
        }
        System.out.println();
        System.out.println();

        /*
            0------>1
            ^       |
            |_______|

            ExpectedResult: 0 or 1
         */
        adjLists = new ArrayList<>();
        adjLists.add(new HashSet< Integer >(){{add(1);}}); // for node 0
        adjLists.add(new HashSet< Integer >(){{add(0);}}); // for node 1
        ob = new SpreadMessageInANetwork();
        res = ob.getMinimumUsersToMessage(adjLists);
        for (int i : res) {
            System.out.print(i + "  ");
        }
        System.out.println();
        System.out.println();


        /*
            1------>0

            ExpectedResult: 1
         */
        adjLists = new ArrayList<>();
        adjLists.add(new HashSet< Integer >()); // for node 0
        adjLists.add(new HashSet< Integer >(){{add(0);}}); // for node 1
        ob = new SpreadMessageInANetwork();
        res = ob.getMinimumUsersToMessage(adjLists);
        for (int i : res) {
            System.out.print(i + "  ");
        }
        System.out.println();


    }

}
