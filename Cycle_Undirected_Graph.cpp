// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int src, vector<int> adj[], vector<bool> &vis){
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int nei : adj[node]){
                if(!vis[nei]){
                    q.push({nei, node});
                    vis[nei] = true;
                }
                else if(nei != parent)
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVis){
        visited[node] = true;
        pathVis[node] = true;
        for(auto nei: adj[node]){
            if(nei != parent && !visited[nei] && dfs(nei, node, adj, visited, pathVis) == true) return true;
            else if(nei != parent && pathVis[nei]) return true;
        }
        pathVis[node] = false;
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        /*
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i] && bfs(i, adj, visited)) return true;
        }
	    return 0;
	    */
	    
	    vector<bool> visited(V, false);
        vector<bool> pathVis(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i] && dfs(i, -1, adj, visited, pathVis)) return true;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends