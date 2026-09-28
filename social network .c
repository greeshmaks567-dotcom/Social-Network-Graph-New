#include <stdio.h>
#include <stdlib.h>

#define MAX 6

char vertices[MAX] = {'A', 'B', 'C', 'D', 'E', 'F'};

/* =========================================================
   ADJACENCY MATRIX
   ========================================================= */

int matrix[MAX][MAX] = {
    {0, 1, 1, 0, 0, 0},  // A
    {1, 0, 0, 1, 1, 0},  // B
    {1, 0, 0, 0, 0, 1},  // C
    {0, 1, 0, 0, 0, 0},  // D
    {0, 1, 0, 0, 0, 1},  // E
    {0, 0, 1, 0, 1, 0}   // F
};

/* Find index of a vertex */
int getIndex(char vertex)
{
    for (int i = 0; i < MAX; i++)
    {
        if (vertices[i] == vertex)
            return i;
    }

    return -1;
}

/* =========================================================
   BFS USING ADJACENCY MATRIX
   ========================================================= */

void BFS_Matrix(char start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    int startIndex = getIndex(start);

    visited[startIndex] = 1;
    queue[rear++] = startIndex;

    printf("BFS (Matrix): ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%c ", vertices[current]);

        for (int i = 0; i < MAX; i++)
        {
            if (matrix[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

/* =========================================================
   DFS USING ADJACENCY MATRIX
   ========================================================= */

void DFS_Matrix_Helper(int vertex, int visited[])
{
    visited[vertex] = 1;

    printf("%c ", vertices[vertex]);

    for (int i = 0; i < MAX; i++)
    {
        if (matrix[vertex][i] == 1 && visited[i] == 0)
        {
            DFS_Matrix_Helper(i, visited);
        }
    }
}

void DFS_Matrix(char start)
{
    int visited[MAX] = {0};
    int startIndex = getIndex(start);

    printf("DFS (Matrix): ");

    DFS_Matrix_Helper(startIndex, visited);

    printf("\n");
}


/* =========================================================
   ADJACENCY LIST
   ========================================================= */

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

/* Create a new node */
struct Node* createNode(int vertex)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

/* Add edge to adjacency list */
void addEdge(int u, int v)
{
    struct Node *newNode;

    /* u -> v */
    newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    /* v -> u (undirected graph) */
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

/* Display adjacency list */
void displayList()
{
    printf("\nADJACENCY LIST:\n");

    for (int i = 0; i < MAX; i++)
    {
        printf("%c -> ", vertices[i]);

        struct Node *temp = adjList[i];

        while (temp != NULL)
        {
            printf("%c ", vertices[temp->vertex]);
            temp = temp->next;
        }

        printf("\n");
    }
}


/* =========================================================
   BFS USING ADJACENCY LIST
   ========================================================= */

void BFS_List(char start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    int startIndex = getIndex(start);

    visited[startIndex] = 1;
    queue[rear++] = startIndex;

    printf("BFS (List): ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%c ", vertices[current]);

        struct Node *temp = adjList[current];

        while (temp != NULL)
        {
            int neighbour = temp->vertex;

            if (visited[neighbour] == 0)
            {
                visited[neighbour] = 1;
                queue[rear++] = neighbour;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}


/* =========================================================
   DFS USING ADJACENCY LIST
   ========================================================= */

void DFS_List_Helper(int vertex, int visited[])
{
    visited[vertex] = 1;

    printf("%c ", vertices[vertex]);

    struct Node *temp = adjList[vertex];

    while (temp != NULL)
    {
        int neighbour = temp->vertex;

        if (visited[neighbour] == 0)
        {
            DFS_List_Helper(neighbour, visited);
        }

        temp = temp->next;
    }
}

void DFS_List(char start)
{
    int visited[MAX] = {0};
    int startIndex = getIndex(start);

    printf("DFS (List): ");

    DFS_List_Helper(startIndex, visited);

    printf("\n");
}


/* =========================================================
   SEARCH VERTEX
   ========================================================= */

int searchVertex(char target)
{
    int operations = 0;

    for (int i = 0; i < MAX; i++)
    {
        operations++;

        if (vertices[i] == target)
        {
            printf("Vertex %c found.\n", target);
            printf("Operations required: %d\n", operations);

            return operations;
        }
    }

    printf("Vertex %c not found.\n", target);
    printf("Operations required: %d\n", operations);

    return operations;
}


/* =========================================================
   EDGE CHECKING - MATRIX
   ========================================================= */

void checkEdgeMatrix(char u, char v)
{
    int i = getIndex(u);
    int j = getIndex(v);

    if (matrix[i][j] == 1)
        printf("Edge %c-%c exists.\n", u, v);
    else
        printf("Edge %c-%c does not exist.\n", u, v);

    printf("Operations required: 1\n");
}


/* =========================================================
   EDGE CHECKING - LIST
   ========================================================= */

void checkEdgeList(char u, char v)
{
    int i = getIndex(u);
    int j = getIndex(v);

    int operations = 0;

    struct Node *temp = adjList[i];

    while (temp != NULL)
    {
        operations++;

        if (temp->vertex == j)
        {
            printf("Edge %c-%c exists.\n", u, v);
            printf("Operations required: %d\n", operations);
            return;
        }

        temp = temp->next;
    }

    printf("Edge %c-%c does not exist.\n", u, v);
    printf("Operations required: %d\n", operations);
}


/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main()
{
    /* Create adjacency list */

    for (int i = 0; i < MAX; i++)
        adjList[i] = NULL;

    /*
        Edges:
        A-B
        A-C
        B-D
        B-E
        C-F
        E-F
    */

    addEdge(0, 1);  // A-B
    addEdge(0, 2);  // A-C
    addEdge(1, 3);  // B-D
    addEdge(1, 4);  // B-E
    addEdge(2, 5);  // C-F
    addEdge(4, 5);  // E-F


    /* =====================================================
       MATRIX
       ===================================================== */

    printf("=====================================\n");
    printf("       ADJACENCY MATRIX\n");
    printf("=====================================\n\n");

    printf("    A B C D E F\n");

    for (int i = 0; i < MAX; i++)
    {
        printf("%c   ", vertices[i]);

        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }


    /* =====================================================
       BFS AND DFS - MATRIX
       ===================================================== */

    printf("\n=====================================\n");
    printf("       MATRIX TRAVERSALS\n");
    printf("=====================================\n");

    BFS_Matrix('A');
    DFS_Matrix('A');


    /* =====================================================
       ADJACENCY LIST
       ===================================================== */

    printf("\n=====================================\n");
    printf("       ADJACENCY LIST\n");
    printf("=====================================\n");

    displayList();


    /* =====================================================
       BFS AND DFS - LIST
       ===================================================== */

    printf("\n=====================================\n");
    printf("       LIST TRAVERSALS\n");
    printf("=====================================\n");

    BFS_List('A');
    DFS_List('A');


    /* =====================================================
       VERTEX SEARCH
       ===================================================== */

    printf("\n=====================================\n");
    printf("       VERTEX SEARCH\n");
    printf("=====================================\n");

    printf("\nSearching for vertex E:\n");

    printf("\nUsing Adjacency Matrix representation:\n");
    searchVertex('E');

    printf("\nUsing Adjacency List representation:\n");
    searchVertex('E');


    /* =====================================================
       EDGE CHECKING
       ===================================================== */

    printf("\n=====================================\n");
    printf("       EDGE CHECKING\n");
    printf("=====================================\n");

    printf("\nChecking edge B-E using Matrix:\n");
    checkEdgeMatrix('B', 'E');

    printf("\nChecking edge B-E using List:\n");
    checkEdgeList('B', 'E');


    /* =====================================================
       COMPLEXITY ANALYSIS
       ===================================================== */

    printf("\n=====================================\n");
    printf("       COMPLEXITY ANALYSIS\n");
    printf("=====================================\n");

    printf("\nAdjacency Matrix:\n");
    printf("Space       : O(V^2)\n");
    printf("BFS         : O(V^2)\n");
    printf("DFS         : O(V^2)\n");
    printf("Edge check  : O(1)\n");

    printf("\nAdjacency List:\n");
    printf("Space       : O(V + E)\n");
    printf("BFS         : O(V + E)\n");
    printf("DFS         : O(V + E)\n");
    printf("Edge check  : O(degree(V))\n");


    /* =====================================================
       CONCLUSION
       ===================================================== */

    printf("\n=====================================\n");
    printf("       CONCLUSION\n");
    printf("=====================================\n");

    printf("\nThe given social network is sparse.\n");
    printf("Therefore, the adjacency list is more suitable.\n");
    printf("It requires O(V + E) space and provides efficient\n");
    printf("BFS and DFS traversal for a sparse graph.\n");

    return 0;
}
