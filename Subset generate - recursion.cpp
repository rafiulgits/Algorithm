#include<bits/stdc++.h>
using namespace std;

void subSet(string collection, string source);

int main()
{
    /* one for resource and another for to carry subset*/
    string data;
    string collector;

    /* input the string, for finding subsets */
    cin >> data;

    /* call the subset function */
    subSet(collector, data);
}
void subSet(string collection, string source)
{
    if(source.empty())
    {
        /* print "Null" text for empty set*/
        if(collection.empty())
            cout << "Null ";
        else
            cout << collection <<" ";
    }
    else
    {
        /* recursion function */
        subSet(collection+source.at(0), source.substr(1));
        subSet(collection, source.substr(1));
    }
}
