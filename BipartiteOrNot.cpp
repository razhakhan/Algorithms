#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <int> v;
vector <vector <int>> g;
int n,e;
int res;

//colours used : 1,2 

void dfs(int x, int color) {
    v[x]=color; //assign vertex with a color
    for(auto y: g[x]) {
        if(v[y]==-1)    //if v is unvisited
            dfs(y, 3-color);  // 3-1=2, 3-2=1 so color gets switched for adj nodes
        //if colour of y equals colour of x, not Bipartite
        else if(color==v[y]) {    
            res=1;  //this indicates that odd cycle is found, hence not Bipartite
            break;
        }
    }
}

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //assign memory for new data
        v.assign(n, -1);
        g.assign(n, vector <int> ());
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        res=0;  //initially res=0
        //run dfs on all unvisited nodes
        for(i=0; i<n; i++) {
            if(v[i]==-1)
                dfs(i, 1);
        }
        
        if(res==0)
            cout<<"Bipartite"<<endl;
        else
            cout<<"Not Bipartite"<<endl;
        
        //clear previous values
        v.clear();
        for(i=0; i<n; i++) {
            g[i].clear();
        }
    }
}

/*
ip: 
1
4 4
0 1
0 3
1 2
2 3
op:
Bipartite

ip :
1
5 5
0 1
0 4
1 2
2 3
3 4

op:
Not Bipartite
*/
