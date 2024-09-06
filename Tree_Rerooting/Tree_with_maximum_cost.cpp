// https://codeforces.com/problemset/problem/1092/F

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> a, sum, cost;
vector<vector<int>> adj;

void preCalculate(int u = 1, int par = 0){
    sum[u] = a[u];
    for(auto v: adj[u]){
        if(v == par) continue;
        preCalculate(v, u);
        sum[u] += sum[v];
        cost[u] += sum[v] + cost[v];
    }
}

void dfs(ll &ans, int u = 1, int par = 0){
    ans = max(ans, cost[u]);
    for(auto &v: adj[u]){
        if(v == par) continue;
        // reduce the cost of v because v will be the next root
        int u_remaining_cost = cost[u] - sum[v] - cost[v];
        // add cost[u] in v node because v will ve the next root
        cost[v] += u_remaining_cost + sum[u] - sum[v];
        sum[v] = sum[u];
        dfs(ans, v, u);
    }
}

void solve(){
    // taking input
    // cout << "Enter n: ";
    ll n;
    cin >> n;
    sum.resize(n+1, 0);
    cost.resize(n+1, 0);
    a.resize(n+1, 0);
    
    // cout << "Enter array 'a': ";
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> edges;
    // cout << "Enter edges: ";
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }


    // creating adjList
    adj.resize(n+1);
    for(auto &e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    preCalculate(1, -1);

    ll ans = 0;
    dfs(ans, 1, 0);
    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}