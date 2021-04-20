 /* Dijkstra’s Algorithm allows you to calculate the shortest path between 
    one node of your choosing and every other node in a graph. 
    
    Given a graph and a source vertex in the graph, find shortest paths from source
    to all vertices in the given graph.
    
    We generate a SPT (shortest path tree) with given source as root. We maintain
    two sets, one set contains vertices included in shortest path tree, other set
    includes vertices not yet included in shortest path tree. At every step of the
    algorithm, we find a vertex which is in the other set (set of not yet included)
    and has a minimum distance from the source.
    
    Time Complexity:  If we take a closer look, we can observe that the statements
    in inner loop are executed O(V+E) times (similar to BFS).
    So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)
    */
    
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // create adjacency list
        unordered_map<int,vector<pair<int, int>>> adjList;
        for( auto f : flights )
            adjList[f[0]].push_back( { f[1], f[2] } );
        
        // minHeap based on cost of distance from source
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        minHeap.push( { 0, src, K+1 } ); // cost, vertex, hops
        
        while( !minHeap.empty() ) {
            auto t = minHeap.top(); minHeap.pop();
            int cost = t[0];
            int curr = t[1];
            int stop = t[2];
            if( curr == dst )
                return cost;

            if( stop > 0 )
                for( auto next : adjList[curr] )
                    minHeap.push( { cost+next.second, next.first, stop-1 } );
        }
        return -1;
    }
