// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    vector <bool> visited;
    
    void dfs(int x, vector<int> adj[] ) {
        visited[x]=true;
        for(auto y : adj[x]) {
            if(visited[y]==false)
                dfs(y, adj);
        }
    }
    
	int isEularCircuit(int n, vector<int>g[]) {
	    visited.assign(n, false);
	    int i, odd;
	    odd=0;
	    
	    for(i=0; i<n; i++) {
	        if(g[i].size()>0)
	            break;
	    }
	    
	    int node=i;
	    
	    dfs(node, g);
	    
	    for(i=0; i<n; i++) {
	        if(g[i].size()>0 && visited[i]==false)
	            return 0;
	    }
	    
	    for(i=0; i<n; i++) {
	        if(g[i].size()%2!=0)
	            odd++;
	        if(odd>2)
	            return 0;
	    }
	    if(odd==0) 
	        return 2;
	    else
	        return 1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends
