#include <bits/stdc++.h>
using namespace std;

void longestSubstring(string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            string sub = s.substr(j, i - j + 1);
            cout << sub << "\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    longestSubstring(s, 3);
    return 0;
}
