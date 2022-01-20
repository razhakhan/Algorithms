#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

//white=0 - Vertex is not processed yet
//grey=1    Vertex is being processed
//black=2   Vertex and all its descendants are processed

int n, e;
vector <int> colour;
vector <vector <int>> g;

bool dfs(int u) {
    colour[u] = 1; // GREY
    for(int v : g[u]){
        if(colour[v] == 2){
            return true;    //back edge, so cycle
        }
        if(colour[v] == 0)  //check for descendants
            if(dfs(v))
                return true;
    }
    colour[u] = 2; // BLACK
    return false;           //no cycle descendant sub trees
}

bool isCyclic() {
    for(int i = 0; i < n; i++)
        if(colour[i] == 0) 
            if(dfs(i)==true)
                return true;
    return false;
}

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //make all node colours as white
        colour.assign(n, 0);
        g.assign(n, vector <int> ());
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        if(isCyclic())
            cout<<"Graph contains cycle";
        else
            cout<<"Graph doesn't contain cycle";
        
        //clear previous values
        colour.clear();
        for(i=0; i<n; i++) {
            g[i].clear();
        }
    }
}

/*
ip : 
1
4 2
1 2
2 3

op:
Graph doesn't contain cycle
*/
