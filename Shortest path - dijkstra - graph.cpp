/*
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
this code is for find shortest distance of any node from a particular node
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

#include<bits/stdc++.h>

/* define total max node of this graph and infinite distance*/
#define NODE  10000
#define INFINITE 99999999

using namespace std;

/* pair for carry connected node and cost , dis array will carry individual distance o*/
typedef pair<int,int> Pair;
bool visit[NODE] = {false};
int dis[NODE];
vector<Pair>adjacent[NODE];

void Dijkstra(int from);

int main()
{
    /* input the number of nodes and edges of testing graph*/
    int nodes,edges;
    cin >> nodes >> edges;

    /* input adjacent adjacent nodes and cost between them*/
    for(int i=0, node1, node2, weight; i<edges; i++)
    {
        cin>>node1 >> node2 >> weight;

        /* make pair for adjacent node and cost*/
        adjacent[node1].push_back(make_pair(weight, node2));
        adjacent[node2].push_back(make_pair(weight, node1));
    }

    /* calling Dijkstra's function with a starting node */
    Dijkstra(1);

    /* output all nodes shortest distance from this particular starting node*/
    for(int i=1; i<= edges; i++)
        cout << "Shortest distance of node "<<i<<" is : "<<dis[i] <<endl;
}

void Dijkstra(int from)
{
    /* fill up all node distance with infinite value*/
    fill(dis, dis+NODE, INFINITE);

    /* for making min heap :: upcoming shortest cost node*/
    priority_queue<Pair, vector<Pair>, greater<Pair> > next;

    /* insert this pair into priority queue and make this node distance initially zero
       :: considering there is self loop */
    Pair now = make_pair(0,from); next.push(now); dis[from] = 0;

    /* traverse all nodes */
    while(! next.empty())
    {
        /* upcoming low cost node */
        now = next.top(); next.pop();

        /* access this low cost node */
        int nowNode = now.second;

        /* check whether this node is visit or not*/
        if(visit[nowNode]) continue;

        /* if not visited --> then visit this node */
        visit[nowNode] = true;

        /* traverse all adjacent node */
        for(int i=0; i<adjacent[nowNode].size(); i++)
        {
            /* access connected node and cost */
            int thisNode = adjacent[nowNode][i].second;
            int thisWeight = adjacent[nowNode][i].first;

            /* check whether this distance is minimum than previous or not */
            if(dis[nowNode]+thisWeight < dis[thisNode])
            {
                /* update this node distance and pushed into queue for next checking */
                dis[thisNode] = dis[nowNode] + thisWeight;
                next.push(make_pair(dis[thisNode], thisNode));
            }
        }
    }


}
