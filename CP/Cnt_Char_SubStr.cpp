// https://www.codechef.com/viewsolution/1049505575

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabbacbc";
    int n = s.length();
    unordered_map<char, int> umpp;
    for (char c : s)
        umpp[c]++;
    int dp[n][26] = {0};
    dp[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if ((s[i] - 'a') == j)
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = INT_MAX;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (umpp[c] == 0)
            continue;
        int wnd_size = umpp[c];
        int i = 0, j = wnd_size - 1;
        while (j < n)
        {
            int freq = dp[j][c - 'a'];
            if (i > 0)
                freq -= dp[i - 1][c - 'a'];
            ans = min(ans, wnd_size - freq);
            i++, j++;
        }
    }
    cout << ans << "\n";
}