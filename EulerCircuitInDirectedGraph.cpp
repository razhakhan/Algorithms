/* 
A directed graph has an eulerian cycle if following conditions are true :
1) All vertices with nonzero degree belong to a single strongly connected component. 
2) In degree is equal to the out degree for every vertex.
*/

#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <bool> visited;
vector <int> in;
vector <vector <int>> g;
vector <vector <int>> rev;

int n,e;

void dfs(int x, vector <vector <int>> adj) {
    visited[x]=true;
    for(auto y : adj[x]) {
        if(visited[y]==false )
            dfs(y, adj);
    }
}

bool isEulerian() {
    //find the first vertex having edges (connected)
    int i;
    for(i=0; i<n; i++) {
        if(g[i].size()>0)
            break;
    }
    
    //kosaraju starts
    int node=i;
    
    dfs(node, g); //1st dfs
    
    //if dfs traversal doesnt visit all vertices, return false
    for(i=0; i<n; i++) {
        if(g[i].size()>0 && visited[i]==false)
            return false;
    }
    
    rev.assign(n, vector <int> ());     //rev graph
    
    for(i=0; i<n; i++) {
        for(auto j: g[i]) {
            rev[j].pb(i);
        }
    }
    
    visited.assign(n, false);   //re initialize visited array to 0
    
    dfs(node, rev);     //2nd dfs (starting node should be same as 1st dfs)
    
    //if dfs traversal doesnt visit all vertices, return false
    for(i=0; i<n; i++) {
        if(g[i].size()>0 && visited[i]==false)
            return false;
    }
    
    //if out degree not equal to in degree, return false
    for (int i = 0; i < n; i++)
        if (g[i].size() != in[i])
            return false;
 
    return true;
}

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //assign memory for new data
        visited.assign(n, false);
        in.assign(n, 0);
        g.assign(n, vector <int> ());
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            in[b]++;
        }
        
        if ( isEulerian() ) {
            cout<<"Graph is Eulerian"<<endl;
        }
        else {
            cout<<"Graph is not Eulerian"<<endl;
        }
        
        //clear previous values
        visited.clear();
        for(i=0; i<n; i++) {
            g[i].clear();
        }
        
    }
}

/*

ip:
1
5 6
1 0
0 2
2 1
0 3
3 4
4 0
op:
Graph is Eulerian


ip:
1
1
6 6
0 1
0 2
1 2
3 4
4 5
3 5
op:
Graph is not Eulerian

*/
