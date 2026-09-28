# Social-Network-Graph-New
GRAPH REPRESENTATION AND TRAVERSAL OF A SOCIAL NETWORK
a) Implementation of the Network Using Adjacency Matrix and Adjacency List
Introduction

A graph is a non-linear data structure consisting of vertices and edges. In a social network, the users can be represented as vertices and the relationships or connections between users can be represented as edges. In this problem, the social network consists of six vertices: A, B, C, D, E, and F.

The given connections are:

A–B, A–C, B–D, B–E, C–F, and E–F.

The graph is undirected because each connection works in both directions. For example, A–B means that A is connected to B and B is also connected to A.

The graph contains six vertices and six edges.

Adjacency Matrix

An adjacency matrix represents a graph using a two-dimensional array. Each row and column represents a vertex. If two vertices are connected, the corresponding position contains 1. If there is no connection, the position contains 0.

The vertices are arranged in the order A, B, C, D, E, and F.

The adjacency matrix is:

      A  B  C  D  E  F
A     0  1  1  0  0  0
B     1  0  0  1  1  0
C     1  0  0  0  0  1
D     0  1  0  0  0  0
E     0  1  0  0  0  1
F     0  0  1  0  1  0


For example, the value at A-B is 1 because A and B are connected. The value at A-D is 0 because A and D are not directly connected.

Since the graph is undirected, the matrix is symmetrical. Therefore, if A is connected to B, both A-B and B-A contain the value 1.

Adjacency List

An adjacency list stores the neighbouring vertices of every vertex. It stores only the connections that actually exist.

The adjacency list for the given graph is:

A → B, C
B → A, D, E
C → A, F
D → B
E → B, F
F → C, E


This representation is more memory-efficient for sparse graphs because it does not store unnecessary information about connections that do not exist.

Breadth First Search

Breadth First Search, or BFS, is a graph traversal algorithm that visits vertices level by level. BFS uses a queue data structure.

Starting from vertex A, the first vertex visited is A. The neighbours of A are B and C, so B and C are visited next. After that, the neighbours of B are checked, and D and E are visited. Finally, F is visited through C.

Therefore, the BFS traversal starting from A is:

A → B → C → D → E → F


The BFS algorithm can be represented as follows:

BFS(A)

1. Mark A as visited.
2. Insert A into the queue.
3. Remove a vertex from the queue.
4. Visit all its unvisited neighbours.
5. Mark those neighbours as visited and insert them into the queue.
6. Continue until the queue becomes empty.


For an adjacency list, the time complexity of BFS is O(V + E), where V is the number of vertices and E is the number of edges.

For an adjacency matrix, BFS takes O(V²) time because the algorithm may have to examine every position in a row to find neighbouring vertices.

Depth First Search

Depth First Search, or DFS, is another graph traversal algorithm. DFS explores one path as deeply as possible before backtracking. It can be implemented using recursion or a stack.

Starting from A, DFS first visits B. From B, it visits D. Since D has no unvisited neighbours, the algorithm returns to B and visits E. From E, it visits F, and from F it visits C.

Therefore, assuming the neighbours are processed in alphabetical order, the DFS traversal is:

A → B → D → E → F → C


The DFS algorithm can be represented as follows:

DFS(v)

1. Mark vertex v as visited.
2. Visit vertex v.
3. For each unvisited neighbour of v:
       Call DFS on that neighbour.
4. Continue until all reachable vertices are visited.


For an adjacency list, DFS takes O(V + E) time. For an adjacency matrix, DFS takes O(V²) time.

b) Search Operation

A search operation is used to locate a particular vertex in the graph. Suppose the required vertex is E.

The vertices are stored in the order:

A, B, C, D, E, F


Using a simple linear search, the program checks each vertex one by one.

The search process is:

Check A → Not found
Check B → Not found
Check C → Not found
Check D → Not found
Check E → Found


Therefore, vertex E is found after 5 comparisons.

The worst-case time complexity of a linear vertex search is O(V), because all vertices may have to be checked before finding the required vertex.

Edge Searching

We can also check whether two particular vertices are directly connected.

For example, consider checking whether E and F are connected.

Using an adjacency matrix, the program directly accesses the position corresponding to E and F. The value is 1, so E and F are connected.

The operation requires only one direct matrix access and therefore has a time complexity of O(1).

Using an adjacency list, the program first accesses the list of E:

E → B, F


The program then checks the neighbours until F is found. Since F is the second neighbour in this list, two neighbour comparisons are required.

Therefore, edge checking using an adjacency list takes O(degree of the vertex) time.

c) Analysis of the Two Graph Representations
Space Requirements

The adjacency matrix requires O(V²) space because it stores a position for every possible pair of vertices.

There are six vertices in the given graph. Therefore, the adjacency matrix requires:

6 × 6 = 36 positions.

Many of these positions contain 0 because there is no direct connection between the corresponding vertices.

The adjacency list requires O(V + E) space. It stores the vertices and only the edges that actually exist.

There are six vertices and six edges in the given graph. Since this is an undirected graph, each edge is stored in the neighbour list of both vertices. Therefore, there are twelve edge references in addition to the six vertex/list structures.

Thus, the adjacency list uses considerably less storage than the adjacency matrix for this sparse graph.

Traversal Behaviour

Both representations can be used to perform BFS and DFS.

Using the adjacency matrix, the algorithm must examine the entire row of the matrix to determine which vertices are connected to the current vertex. This means that even if a vertex has only a few neighbours, many positions containing 0 may still be checked.

Using the adjacency list, the algorithm directly accesses the actual neighbours of the current vertex. Therefore, it does not need to examine nonexistent connections.

For this reason, adjacency lists are generally more efficient for traversing sparse graphs.

The BFS traversal from A is:

A → B → C → D → E → F


The DFS traversal from A is:

A → B → D → E → F → C

Search and Edge-Checking Operations

An adjacency matrix provides very fast edge checking. If we want to know whether two vertices are connected, the corresponding matrix position can be accessed directly. Therefore, edge checking takes O(1) time.

An adjacency list requires the list of one vertex to be searched for the other vertex. Therefore, the time depends on the number of neighbours of that vertex.

For vertex searching, a simple linear search requires O(V) time in both representations if the vertex labels are stored sequentially.

Time Complexity

For an adjacency matrix, BFS and DFS have a time complexity of:

O(V²)

This is because every vertex may require checking all V possible neighbouring positions.

For an adjacency list, BFS and DFS have a time complexity of:

O(V + E)

This is because every vertex and every actual edge is processed only as required.

For a sparse graph, E is much smaller than V². Therefore, O(V + E) is generally more efficient than O(V²).

Suitability for a Sparse Social Network

The given social network is a sparse graph because there are only six actual connections between the six vertices. A complete undirected graph with six vertices could have a maximum of:

V(V − 1) / 2

6(6 − 1) / 2 = 15

possible edges.

However, the given network contains only six edges. Therefore, many possible connections do not exist.

An adjacency matrix still reserves space for all possible pairs of vertices, including those that are not connected. An adjacency list stores only the connections that actually exist.

Therefore, the adjacency list requires less memory and allows BFS and DFS to operate more efficiently on this sparse network.

Conclusion

The given social network was successfully represented using both an adjacency matrix and an adjacency list. BFS and DFS were performed starting from vertex A.

The BFS traversal obtained was:

A → B → C → D → E → F


The DFS traversal obtained was:

A → B → D → E → F → C


A search operation for vertex E required five comparisons using a simple linear search.

The adjacency matrix provides the advantage of constant-time edge checking, with a time complexity of O(1). However, it requires O(V²) memory and may store a large number of unnecessary zero values.

The adjacency list requires O(V + E) space and allows BFS and DFS to be performed in O(V + E) time. It stores only the actual connections between vertices and is therefore more memory-efficient for sparse graphs.

Based on the execution results and complexity analysis, the adjacency list is more suitable for the given sparse social network. It uses less memory and provides efficient traversal because it processes only the actual connections in the network. The adjacency matrix would be preferable when fast and frequent edge-checking operations are more important than memory efficiency.

Hence, for a sparse social network, the adjacency list is generally the more suitable graph representation.
