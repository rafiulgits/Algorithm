#include<bits/stdc++.h>
using namespace std;

/* 1D vector for store adjacent node with weight */
vector< pair<int,int> > adjacent[1000];
/* boolean array of visiting checking */
bool visit[1000] = {false};

int Prim(int start);

int main()
{
    /* input number of edges */
    int edges; cin >> edges;

    /* input two adjacent nodes and cost between them */
    for(int i=0; i<edges; i++)
    {
        int node1; cin >> node1;
        int node2; cin >> node2;
        int weight; cin >> weight;

        /* set adjacent node with weight */
        adjacent[node1].push_back(make_pair(weight,node2));
        adjacent[node2].push_back(make_pair(weight,node1));
    }

    /* call MST function*/
    cout << Prim(1) << endl;


}
int Prim(int start)
{
    /* for making mean heap in priority_queue use vector with data type
       and grater with data type, as because -to provide inbuilt template */
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > next;
    int totalCost = 0;

    /* starting node with 0 cost */
    next.push(make_pair(0, start));

    /* for carry parameter value */
    int node, weight;
    pair<int, int> now;

    while(! next.empty())
    {
        /* next min weight from priority_queue. take it and remove it from there */
        now = next.top(); next.pop();

        /* access the node from this adjacent */
        node = now.second;

        /* check whether this node is already visited or not */
        if(! visit[node])
        {
            /* access the weight of this node, add this weight with cost make this node visited*/
            weight = now.first;
            totalCost += weight;
            visit[node] = true;

            /* access all adjacent connect with this node and push them into priority_queue
               if they are not already visited */
            for(int i=0; i<adjacent[node].size(); i++)
            {
                int connectNode = adjacent[node][i].second;

                if(! visit[connectNode])
                    next.push(adjacent[node][i]);
            }
        }
    }

    return totalCost;

}
