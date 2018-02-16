#include<bits/stdc++.h>

/* define the infinite value*/
#define INFINITE 9999999
using namespace std;

/* construct a graph in matrix form*/
int graph[100][100];

void showGraph(int nodes);
bool isPathExist(int start, int stop, int parent[],int nodes);
int FordFulkerson(int start, int stop, int nodes);

int main()
{
    /* initial graph value with zero :: cost of connected nodes */
    memset(&graph[0][0], 0, sizeof(graph));

    /* input number of nodes and edges for particular graph */
    int nodes; int edges;
    cin >>nodes >> edges;

    /* input nodes and cost data */
    for(int i=0; i<edges; i++)
    {
        int node1; cin >> node1;
        int node2; cin >> node2;
        int cost;  cin >> cost;

        /* set the cost by position */
        graph[node1][node2] = cost;
    }

    /* input start and stop position for flow */
    int start; int stop;
    cin >> start >> stop;

    /* show the graph in matrix formation */
    showGraph(nodes);

    /* call the function for find out maximum flow */
    cout<<FordFulkerson(start,stop,nodes)<<endl;
}

void showGraph(int nodes)
{
    /* 2D array view :: matrix formation view */
    for(int row=0; row<nodes; row++)
    {
        for(int col=0; col<nodes; col++)
            cout << graph[row][col] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isPathExist(int start, int stop, int parent[],int nodes)
{
    /* this function will say whether any path exist or not for flow */

    /* node visit checker for every path */
    bool visit[nodes] = {false};
    queue<int>next; next.push(start);
    visit[start] = true; parent[start] = -1;

    /* simple BFS for finding whether any path is available or not */
    while(! next.empty())
    {
        int row = next.front(); next.pop();

        for(int col=0; col<nodes; col++)
        {
            /* for next node:: it must be not visited and flow-value greater than zero */
            if(! visit[col] && graph[row][col] > 0)
            {
                visit[col] = true;
                next.push(col);
                parent[col] = row;
            }
        }
    }
    /* return the status of visiting stop node :: if visited->return true, else false */
    return visit[stop];
}
int FordFulkerson(int start, int stop, int nodes)
{
    /* initial parent of particular node */
    int parent[nodes];

    /* initially max flow is zero */
    int maxFlow = 0;

    /* continue flow till new flow-path exist there */
    while(isPathExist(start,stop,parent,nodes))
    {

        /* path flow */
        int pathFlow = INFINITE;
        int node;

        for(node=stop; node!=start; node=parent[node])
        {
            /* find out maximum capability of flow of this path */
            pathFlow = min(pathFlow, graph[parent[node]][node]);
        }
        for(node=stop; node!=start; node=parent[node])
        {
            /* change the forward and backward flow value*/
            graph[parent[node]][node] -= pathFlow;
            graph[node][parent[node]] += pathFlow;
        }

        /* added this path flow with total flow*/
        maxFlow += pathFlow;
    }

    /* return the flow */
    return maxFlow;
}
