#include<bits/stdc++.h>
using namespace std;

/* unsigned long long - for store the maximum range*/
unsigned long long fibonacci(int n);

unsigned long long store[500] = {0};

int main()
{
    int n;

    /* this program will take input till user turn off input :: EOF */
    while(cin >> n)
    {
        cout << fibonacci(n) << endl;
    }
}

unsigned long long fibonacci(int n)
{
    if(n < 2)
        return n;

    if(store[n] == 0)
    {
        /* using dynamic programming and remember the previous one */
        store[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return store[n];
}
