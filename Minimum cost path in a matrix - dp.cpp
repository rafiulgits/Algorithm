#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*input matrix row and column from user*/
    int row; int col;
    cin >> row >> col;

    /* define matrix */
    int matrix[row][col];

    /* input every cell cost from user */
    for(int r=0; r<row; r++)
    {
        for(int c=0; c<col; c++)
        {
            cin >> matrix[r][c];
        }
    }


    /* define the minimum cost matrix and initial
       the first cell with matrix first cell */
    int minCost[row][col]; minCost[0][0] = matrix[0][0];

    /* fill up all the cell of first row with the addition of
       previous cell (in column) and value of this cell

       X -> * -> * -> *
       ? -- ? -- ? -- ?
    */
    for(int c=1; c<col; c++)
    {
        minCost[0][c] = minCost[0][c-1] + matrix[0][c];
    }

    /* fill up all the cell of first column with the addition of
       previous cell (in row) and value of this cell

       X -> * -> * -> *
       * -- ? -- ? -- ?
       * -- ? -- ? -- ?
       * -- ? -- ? -- ?

    */
    for(int r=1; r<row; r++)
    {
        minCost[r][0] = minCost[r-1][0] + matrix[r][0];
    }


    /* fill up all other cell by comparing the minimum of left and
       top cell of the corresponding cell and add with its value */
    for(int r=1; r<row; r++)
    {
        for(int c=1; c<col; c++)
        {
            minCost[r][c] = min(minCost[r][c-1], minCost[r-1][c]);
            minCost[r][c] += matrix[r][c];
        }
    }

    /* consider the last cell (right-bottom) of the matrix is the end point */
    cout << minCost[row-1][col-1] << endl;
}
