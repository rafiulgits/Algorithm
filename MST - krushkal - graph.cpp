#include<bits/stdc++.h>
using namespace std;

/* using STL pair for combine the graph data for store edge info
   edge = weight, (node1, node2) */
pair < int, pair<int,int> > edgesList[100];

/* edge number and total nodes = 100*/
int edges; int parent[100];

void initialParent();
void makeJoin(int node1, int node2);
int getRoot(int nood);
int Krushkal();

int main()
{
    /* initially parent of any node is node itself */
    initialParent();

    /* input number of edges */
    cin >> edges;

    /* input edges information */
    for(int i=0; i<edges; i++)
    {
        /* input two connected nodes */
        int node1; cin >> node1;
        int node2; cin >> node2;
        /* input the weight of this edge */
        int weight; cin >> weight;

        /* store this edge information with an individual index in
           edgesList by pairing */
        edgesList[i] = make_pair(weight, make_pair(node1,node2));
    }

    /* sort all edges by their weight */
    sort(edgesList, edgesList+edges);

    /* call MST function  */
    cout << Krushkal();
}

int Krushkal()
{
    /* initially total cost zero */
    int totalCost = 0;

    /* access all edges and their weight and connected nodes */
    for(int i=0; i<edges; i++)
    {
        /* access this edge weight */
        int weight = edgesList[i].first;
        /* access this edge's connected nodes*/
        int node1 = edgesList[i].second.first;
        int node2 = edgesList[i].second.second;

        /* check whether they connected or not */
        if(getRoot(node1) != getRoot(node2))
        {
            /* add this edge's weight with MST */
            totalCost += weight;

            /* joint this two nodes by union */
            makeJoin(node1, node2);
        }
    }
    /* return the minimal cost */
    return totalCost;
}

void initialParent()
{
    /* make all nodes parent node itself */
    for(int i=0; i<100; i++)
        parent[i] = i;
}

int getRoot(int node)
{
    /* till access the last connected parent */
    while(parent[node] != node)
    {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}
void makeJoin(int node1, int node2)
{
    /* access this two nodes parent */
    int root1 = getRoot(node1);
    int root2 = getRoot(node2);

    /* joint them with one parent
       parent flow must be from node1 --> node2 */
    parent[root1] = parent[root2];
}
