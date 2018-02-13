/*
Bellman Ford shortest distance algorithm allowed negative edges and path in graph
Iterate all edges with edges number -1 time.
Every times access all edges starting and ending node with weight and update toNode or ending node
*/

#include<bits/stdc++.h>

/* define a max value :: taking as infinite value*/
#define INFINITE 99999999

using namespace std;

/*
vector array that will carry all edges:: taking max length array for 1000 nodes
vector[index] -> will carry three value :: fromNode, toNode and weight between them
*/
vector<int>edgesList[999000];

/* 1000 index array for carrying distance of nodes */
int dis[1000];

/* number of nodes and edges for particular graph */
int nodes, edges;

void BellmanFord(int start);

int main()
{
    /* input the number of nodes and edges from user :: testing graph data*/
    cin >> nodes >> edges;

    /* input all edges data :: edges will addressing as numeric value. i.e: 1,2,3 4*/
    for(int i=1; i<= edges; i++)
    {
        /* input node information for this edge:: from, to, weight*/
        int fromNode; cin >> fromNode;
        int toNode; cin >> toNode;
        int weight; cin >> weight;

        /* added those information in index number edge*/
        edgesList[i].push_back(fromNode);
        edgesList[i].push_back(toNode);
        edgesList[i].push_back(weight);
    }

    /* call function for finding shortest path from any particular node */
    BellmanFord(1);

    /* printing shortest path of all nodes from the starting node */
    for(int i=2; i<=nodes; i++)
        cout << dis[i] << " ";
}

void BellmanFord(int start)
{
    /* initially load all nodes distance as infinite value that defined at top */
    fill(dis, dis+1000, INFINITE);

    /* make starting node distance zero:: considering there is no self loop */
    dis[start] = 0;

    /* iterate all edges with edges-1 times*/
    for(int checker=1; checker<edges; checker++)
    {
        /* iterate for any update*/
        for(int e=1; e<=edges; e++)
        {
            /* accessing particular node information */
            int fromNode = edgesList[e][0];
            int toNode = edgesList[e][1];
            int weight = edgesList[e][2];

            /* checking for update:: if any update required then update the toNode cost */
            if(dis[toNode] > dis[fromNode] + weight)
            {
                dis[toNode] = dis[fromNode] + weight;
            }
        }
    }
}
