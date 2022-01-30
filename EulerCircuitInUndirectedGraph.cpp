// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    vector <bool> visited;
	
    //normal dfs
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
		
		
	    //find first non zero degree node
	    for(i=0; i<n; i++) {
	        if(g[i].size()>0)
	            break;
	    }
	    
	    int node=i;
	    
	    dfs(node, g);
	    
	    //if a non zero degree is unvisited after single dfs call, return false
	    for(i=0; i<n; i++) {
	        if(g[i].size()>0 && visited[i]==false)
	            return 0;
	    }
	    
	    for(i=0; i<n; i++) {
	        if(g[i].size()%2!=0)	//count of odd degree vertices
	            odd++;
	        if(odd>2)	//if no of odd degree vertices are > 2, return false
	            return 0;
	    }
	    if(odd==0) 		//if odd==0, eulerian circuit
	        return 2;
	    else
	        return 1;	//else, eulerian path
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
