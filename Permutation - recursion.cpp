#include<bits/stdc++.h>
using namespace std;

void permutation(string collection, string source);

int main()
{
    /* data is for source string and for to combination */
    string data;
    string collector;

    /* input the string that you want for permute */
    cin >> data;

    /* calling the permutation function */
    permutation(collector, data);
}
void permutation(string collection, string source)
{
    /* check any element does exist in source string for use to permute*/
    if(source.empty())
        cout << collection <<" ";
    else
    {
        /* use all element in the source string for permute
           in recursion : loop start from 0 */

        for(int i=0; i<source.size(); i++)
        {
            string part = source.substr(0,i) + source.substr(i+1);

            /* calling recursion function */
            permutation(collection+source.at(i), part);
        }
    }
}
