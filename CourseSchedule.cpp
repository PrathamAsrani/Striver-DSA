//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	void bfs(int V, vector<int> adj[], vector<int> &inDegree, vector<int> &ans){
	    queue<int> q;
	    for(int i = 0; i < V; i++)
	        if(inDegree[i] == 0) q.push(i);
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(int nei:adj[node]){
	            inDegree[nei]--;
	            if(inDegree[nei] == 0)
	                q.push(nei);
	        }
	    }
	}
	
	bool dfs(int node, vector<int> adj[], vector<int> &order, vector<bool> &vis, vector<bool> &pathVis){
        vis[node] = pathVis[node] = true;
        for(int nei : adj[node]){
            if(!vis[nei] && dfs(nei, adj, order, vis, pathVis) == true) return true;
            else if(pathVis[nei]) return true;
        }
        pathVis[node] = false;
        order.insert(order.begin(), node);
        return false;
    }
	
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    /*
	    vector<int> adj[N];
	    for(auto i:prerequisites)
	        adj[i.first].push_back(i.second);
	    vector<int> inDegree(N, 0), ans;
	    for(int i = 0; i < N; i++){
	        for(int des:adj[i]) 
	            inDegree[des]++;
	    }
	    bfs(N, adj, inDegree, ans);
	    return ans.size() == N;
	    */
	    
	    
	    vector<int> adj[N];
	    for(auto i:prerequisites)
	        adj[i.second].push_back(i.first);
	    vector<int> order;
	    vector<bool> vis(N, false), pathVis(N, false);
	    for(int i = 0; i < N; i++){
            if(!vis[i] && dfs(i, adj, order, vis, pathVis)) return 0;
        }
	    return order.size() == N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends