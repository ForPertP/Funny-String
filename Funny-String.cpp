#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s)
{
    std::string result {"Funny"};
    std::string r = s;
    std::reverse(r.begin(), r.end());

    bool isFunny = true;
    int len = s.length();
    
    for (int i = 1; i < len; i++)
    {
        if (abs(s[i] - s[i-1]) != abs(r[i] - r[i-1]))
        {
            isFunny = false;
            break;
        }     
    }
    
    if (isFunny == false)
    {
        result.insert(0, "Not ");
    }    
    
    return result;    
}

