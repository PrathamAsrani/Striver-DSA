#include <bits/stdc++.h>
using namespace std;

/*
Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts. You must make at least one cut. Assume that the length of rope is more than 2 meters. 
*/

vector<int> dp;

int cut(int idx, int n){
    if(idx == n) return 1;
    if(dp[idx] != -1) return dp[idx];
    int ans = 0;
    for(int i = idx+1; i <= n; i++){
        ans = max(ans, cut(i, n) * (i-idx));
    }
    return dp[idx] = ans;
}

int fun(int n){
    if(n < 2) return 0;
    dp.resize(n, -1);
    return cut(0, n);
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    // TC: O(N^2), SC: O(N)
    cout << fun(n) << "\n";

    return 0;
}
