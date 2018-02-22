/*
UVA - 929
Number Maze
*/

#include<bits/stdc++.h>
#define INFINITE 999999999

using namespace std;
typedef pair<int,int>Pair;
typedef pair<int,Pair> Cell;

int row; int col;

bool canGo(Pair thisCell);

int main()
{

    cin>>row>>col;
    int matrix[row][col]; int minCost[row][col];
    for(int r=0; r<row; r++)
    {
        for(int c=0; c<col; c++)
        {
            cin>>matrix[r][c];
            minCost[r][c] = INFINITE;
        }
    }

    bool visit[row][col];
    fill(&visit[0][0], &visit[0][0]+sizeof(visit),0);

    /* Cell:: value of one cell and its address -> row , col*/
    Cell start = make_pair(matrix[0][0], make_pair(0,0));

    multiset<Cell>next; next.insert(start); minCost[0][0] = matrix[0][0];

    /* BFS traversal for Dijkstra */
    while(! next.empty())
    {
        Cell now = *next.begin(); next.erase(next.begin());
        int pCost = now.first;
        int pRow = now.second.first;
        int pCol = now.second.second;

        /* check out whether this is the end point or not */
        if(pRow==row-1 && pCol==col-1)
        {
            cout << pCost << endl;
            break;
        }

        if(visit[pRow][pCol]) continue;

        visit[pRow][pCol] = true;


        /* try to go: left, right, top, down -> for find out next min cost cell*/
        Pair leftCell = make_pair(pRow, pCol-1);
        Pair rightCell = make_pair(pRow, pCol+1);
        Pair upCell = make_pair(pRow-1, pCol);
        Pair downCell = make_pair(pRow+1, pCol);

        if(canGo(leftCell))
        {
            int r = leftCell.first; int c = leftCell.second;
            if(minCost[r][c] > minCost[pRow][pCol]+matrix[r][c])
            {
                minCost[r][c] = minCost[pRow][pCol]+matrix[r][c];
                Cell thisCell = make_pair(minCost[r][c], make_pair(r,c));
                next.insert(thisCell);
            }
        }
        if(canGo(rightCell))
        {
            int r = rightCell.first; int c = rightCell.second;
            if(minCost[r][c] > minCost[pRow][pCol]+matrix[r][c])
            {
                minCost[r][c] = minCost[pRow][pCol]+matrix[r][c];
                Cell thisCell = make_pair(minCost[r][c], make_pair(r,c));
                next.insert(thisCell);
            }
        }
        if(canGo(upCell))
        {
            int r = upCell.first; int c = upCell.second;
            if(minCost[r][c] > minCost[pRow][pCol]+matrix[r][c])
            {
                minCost[r][c] = minCost[pRow][pCol]+matrix[r][c];
                Cell thisCell = make_pair(minCost[r][c], make_pair(r,c));
                next.insert(thisCell);
            }
        }
        if(canGo(downCell))
        {
            int r = downCell.first; int c = downCell.second;
            if(minCost[r][c] > minCost[pRow][pCol]+matrix[r][c])
            {
                minCost[r][c] = minCost[pRow][pCol]+matrix[r][c];
                Cell thisCell = make_pair(minCost[r][c], make_pair(r,c));
                next.insert(thisCell);
            }
        }
    }
}
bool canGo(Pair thisCell)
{
    return (thisCell.first>=0 && thisCell.second>=0 && thisCell.first<row && thisCell.second<col);
}
