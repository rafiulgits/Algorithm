#include<bits/stdc++.h>
using namespace std;

int KMP(string source, string pattern);

int main()
{
    /* define the source string and input with space */
    string source; getline(cin, source);

    /* program will continue till user search for pattern index in source string */
    string pattern;
    while(getline(cin, pattern))
    {
        /* call KMP for get the pattern index */
        cout << KMP(source, pattern) << endl;
    }
}
int KMP(string source, string pattern)
{
    ///:::::::::::::::::  Prefix Table define area ::::::::::::::::::::::///

    /* define an array of pattern pattern length and initially they will carry zero*/
    int p_len = pattern.size();
    int table[p_len] = {0};

    /* starting index*/
    int index = 0;

    /* traverse from the second index of pattern*/
    for(int i=1; i<p_len; i++)
    {
        /* if this two index value matched-then both go for next */
        if(pattern[i] == pattern[index])
        {
            table[i] = index + 1;
            index++; i++;
        }
        else
        {
            /* for non-zero index-> go the previous matched index */
            if(index != 0)
                index = table[index-1];
            else
                i++;
        }
    }

    ///::::::::::::::::: String compare area ::::::::::::::::::::::::::///
    int i=0, j=0;
    while(i<source.size() && j<pattern.size())
    {
        /* if pattern match in source for particular index then go for next*/
        if(source[i] == pattern[j])
        {
            i++; j++;
        }
        else
        {
            /* for non-zero index - go previous matched index */
            if(j != 0)
                j = table[j-1];
            else
                i++;
        }
    }

    /* this condition means - pattern must exist in source text :: return the starting index */
    if(j == pattern.size())
      return i-j;

    /* identify :: there is not match */
    return -1;
}
