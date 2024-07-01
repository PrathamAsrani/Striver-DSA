#include <bits/stdc++.h>
using namespace std;

void printLCS(string &s, string &t){
    int n = s.size(), m = t.size();
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else 
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << "Length of LCS: " << dp[n][m] << "\n";
    int idx = dp[n][m];
    char lcs[idx+1];
    lcs[idx] = '\0';

    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            lcs[idx-1] = s[i-1];
            i--;
            j--;
            idx--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << "Longest common subsequence is " << lcs << "\n";
}

int main(int argc, char const *argv[])
{
    string s = "ABCDGH", t = "AEDFHR";
    printLCS(s, t);
    return 0;
}
