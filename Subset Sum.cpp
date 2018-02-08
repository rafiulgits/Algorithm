#include<bits/stdc++.h>
using namespace std;

void subsetSum(int arr[], int index, int len, int currSum, int sum, int solution[]);

int main()
{
    /* input the array of set size*/
    int len; cin >> len;

    /* define data array for contain the set
       solution array for to carry subset index visit checking*/
    int data[len]; int solution[len] = {0};

    /* input the set as array from user */
    for(int i=0; i<len; i++)
        cin >> data[i];

    /* input the sum number */
    int sum; cin >> sum;

    /* we start from array's index 0, so make this visit first */
    solution[0] = 1;

    /* pass all parameters to the function */
    subsetSum(data, 0, len, 0, sum, solution);
}

void subsetSum(int arr[], int index, int len, int currSum, int sum, int solution[])
{
    /* check whether the current sum equal to the sum or not */
    if(currSum == sum)
    {
        for(int i=0; i<len; i++)
        {
            /* check which index of array involve to this subset */
            if(solution[i] == 1)
                cout << arr[i] << " ";
        }
        cout << endl;
    }

    /* this is base case :: check for return */
    else if(index == len || currSum > sum)
        return;

    else
    {
        /* make this current index as visit and add this index value with
           current sum. Call function with next index */
        currSum += arr[index];
        solution[index] = 1;
        subsetSum(arr, index+1, len, currSum, sum, solution);

        /*------------> Backtracking <-------------*/
        currSum -= arr[index];
        solution[index] = 0;
        subsetSum(arr, index+1, len, currSum, sum, solution);
    }
}
