#include<bits/stdc++.h>
using namespace std;

int main()
{
    string data;

    /* input the string that you want to permute */
    cin >> data;

    /* using next_permutation for access all next possible permutation */
    do
    {
        cout << data << " ";
    }
    while(next_permutation(data.begin(), data.end()));

    /* reverse the source string and print current form*/
    reverse(data.begin(), data.end());
    cout << endl << data << endl;

    /* using previous_permutation for access all previous possible permutation */
    do
    {
        cout << data << " ";
    }
    while(prev_permutation(data.begin(),data.end()));
}
