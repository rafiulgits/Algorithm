#include<bits/stdc++.h>

/* define the maximum node this program can use */
#define NODE 1000

using namespace std;
typedef pair<int,int> Pair;

/* :::::::::::::: function variables :::::::::::::::::
   adjacent vector will carry the graph
   bridges vector will carry the articulation bridge
   points set will carry the articulation points
   parent array will carry the initial parent of a node
   discTime array will carry the time of discover of a node
   low array will carry the lowest possible time to reach a node
   counter will count the time for every passed node
   visit array will carry the visiting status of a node
 */
vector<int>adjacent[NODE];
vector<Pair>bridges;
set<int>points;
int parent[NODE] = {-1};
int discTime[NODE] = {0};
int low[NODE] = {0};
int counter = 0;
bool visit[NODE] = {false};

void Tarzan(int node);
void showNodes();
void showBridges();

int main()
{
    /* input the number of nodes and edges for particular graph */
    int nodes; int edges;
    cin >> nodes >> edges;

    /* input the adjacent nodes */
    for(int i=0; i<edges; i++)
    {
        int node1; int node2;
        cin >> node1 >> node2;

        adjacent[node1].push_back(node2);
        adjacent[node2].push_back(node1);
    }

    /* call the function for find out articulation nodes and paths */
    Tarzan(0);

    /* display articulation nodes and paths */
    showNodes();
    showBridges();
}
void Tarzan(int node)
{
    /* update the visiting status for the node*/
    visit[node] = true;

    /* increase the timer and update the discover and lower time for this node*/
    counter ++;
    discTime[node] = counter;
    low[node] = counter;

    /* this will count the child number of the node */
    int child = 0;

    for(int i=0; i<adjacent[node].size(); i++)
    {
        /* access all the adjacent of the node */
        int thisNode = adjacent[node][i];

        /* checking whether this node is already visited or not */
        if(! visit[thisNode])
        {
            /* increase the child number of the node */
            child++;

            /* update this child parent and pass this child for next checking */
            parent[thisNode] = node;
            Tarzan(thisNode);


            /* condition for articulation path */
            if(low[thisNode] > discTime[node])
            {
                bridges.push_back(make_pair(node,thisNode));
            }

            /* condition for articulation node */
            if(parent[node] == -1 && child > 1)
            {
                points.insert(node);
            }
            else if(parent[node] != -1 && low[thisNode] >= discTime[node])
            {
                points.insert(node);
            }

            /* update the lowest time to reach the node */
            low[node] = min(low[node],low[thisNode]);
        }

        /* update the lowest time with this condition :: for visited adjacent*/
        else if(thisNode != parent[node])
            low[node] = min(low[node],discTime[thisNode]);
    }
}
void showNodes()
{
    /* iterate all nodes in the set STL */
    set<int>::iterator i = points.begin();
    for(; i!= points.end(); i++)
        cout << *i << " ";
    cout << endl;
}
void showBridges()
{
    /* iterate all pairs in the vector STL*/
    for(int i=0; i<bridges.size(); i++)
        cout << bridges[i].first << " --- " << bridges[i].second << endl;
}
