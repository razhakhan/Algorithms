#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <int> disc, low; 
vector <bool> presentInStack;
stack <int> sk;
int timer=0;
/* 
1.  vectors to store discovery time of node,
    node with the lowest disc time 
    reachable from present node
2.  presentInStack to differentiate cross edge or back edge 
*/

vector <vector <int>> g;
int n, e;

int dfs(int u) {
    
    disc[u]=timer;
    low[u]=timer;
    timer++;
    sk.push(u);
    presentInStack[u]=true;
    
    //main dfs call
    
    for(auto v: g[u]) {
        //if v is not already visited, visit it
        if(disc[v]==-1) {
            dfs(v);
            low[u]=min(low[u], low[v]);  //tree edge formula
        }
        //if v is present in stack, then uv is a back edge
        else if(presentInStack[v]) {
            low[u]=min(low[u], disc[v]); //back edge formula
        }
        else {
            //else uv is a cross edge, so do nothing
        }
    }
    
    /* printing SCCs, 
    if low[u]=disc[u], then the node is the
    head node of SCC */
    
    if(low[u]==disc[u]) {
        
        //pop and print until u see head node
        
        while(sk.top()!=u) {
            cout<<sk.top()<<" ";
            presentInStack[sk.top()]=false;
            sk.pop();
        }
        
        //pop the head node too
        
        cout<<sk.top()<<endl;
        presentInStack[sk.top()]=false;
        sk.pop();
    }
    
}

void Tarjan() {
    int i;
    cout<<"The SCCs are: "<<endl;
    for(i=0; i<n; i++) {
        if(disc[i]==-1)
            dfs(i);
    }
}

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //assign default value as -1
        disc.assign(n, -1);
        low.assign(n, -1);
        presentInStack.assign(n, false);
        
        g.assign(n, vector <int> ());
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
        }
        
        Tarjan();
        
        //clear previous values
        disc.clear();
        low.clear();
        presentInStack.clear();
        for(i=0; i<n; i++) {
            g[i].clear();
        }
    }
    return 0;
}

/* 
input:

1
7 9
0 1
1 2
1 3
3 4
4 0
4 5
4 6
5 6
6 5
output:

The SCCs are: 
2
6 5
4 3 1 0

*/
