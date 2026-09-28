=====================================
       ADJACENCY MATRIX
=====================================

    A B C D E F
A   0 1 1 0 0 0
B   1 0 0 1 1 0
C   1 0 0 0 0 1
D   0 1 0 0 0 0
E   0 1 0 0 0 1
F   0 0 1 0 1 0

=====================================
       MATRIX TRAVERSALS
=====================================
BFS (Matrix): A B C D E F
DFS (Matrix): A B D E F C

=====================================
       ADJACENCY LIST
=====================================
A -> C B
B -> E D A
C -> F A
D -> B
E -> F B
F -> E C

=====================================
       LIST TRAVERSALS
=====================================
BFS (List): A C B F E D
DFS (List): A C F E B D

=====================================
       VERTEX SEARCH
=====================================

Searching for vertex E:

Using Adjacency Matrix representation:
Vertex E found.
Operations required: 5

Using Adjacency List representation:
Vertex E found.
Operations required: 5

=====================================
       EDGE CHECKING
=====================================

Checking edge B-E using Matrix:
Edge B-E exists.
Operations required: 1

Checking edge B-E using List:
Edge B-E exists.
Operations required: 1

=====================================
       COMPLEXITY ANALYSIS
=====================================

Adjacency Matrix:
Space       : O(V^2)
BFS         : O(V^2)
DFS         : O(V^2)
Edge check  : O(1)

Adjacency List:
Space       : O(V + E)
BFS         : O(V + E)
DFS         : O(V + E)
Edge check  : O(degree(V))

=====================================
       CONCLUSION
=====================================




