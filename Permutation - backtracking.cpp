#include<bits/stdc++.h>
using namespace std;

void permutation(int start, int stop, string source);

int main()
{
    string data;

    /* input the string that you want to permute */
    cin >> data;

    /* calling permutation function for permute the string
       initially we will start from the index 0 and will stop
       at last index. last index  = string size - 1 */
    permutation(0, data.size()-1, data);

}
void permutation(int start, int stop, string source)
{
    /* check any element is exist or not for permute */
    if(start == stop)
        cout << source << " ";

    else
    {
        /* check all element from start to stop index */
        for(int i=start; i<=stop; i++)
        {
            /* exchange the current element with another one */
            swap(source.at(i), source.at(start));
            permutation(start+1, stop, source);
            /* ------------> backtracked <--------------
               restore the element in its previous index */
            swap(source.at(i), source.at(start));
        }
    }
}
