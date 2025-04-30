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


nt main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch){ return !issapce(ch)})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch) }).base(),
        s.end()
    );

    return s;
}

