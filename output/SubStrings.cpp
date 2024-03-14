#include <bits/stdc++.h>
using namespace std;

/*
Input :  abcd
Output :  a 
          b
          c
          d
          ab
          bc
          cd
          abc
          bcd
          abcd
*/

void longestSubstring(string s, int n)
{
    for(int len = 1; len <= s.size(); len++){
        for(int start = 0; start <= s.size() - len; start++){
            string sub = s.substr(start, len);
            cout << sub << "\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    string s = "abcd";
    longestSubstring(s, 3);
    return 0;
}
