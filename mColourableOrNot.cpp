#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <bool> visited;
vector <int> color;
vector <vector <int>> g;
int n,e,m;
int ans;

void bfs(int src) {
    
    queue <int> q;
    q.push(src);
    visited[src]=true;
    
    while(q.empty()==false) {
        int x=q.front();
        q.pop();
        for(auto y: g[x]) {
            
            if(visited[y]==false) {
                q.push(y);
                visited[y]=true;
            }
            
            if(color[x]==color[y]) 
                color[y]++;
                
            if(color[y]>m) {
                ans=0;
                return;
            }
        }
    }
}

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //assign memory for new data
        visited.assign(n, false);
        g.assign(n, vector <int> ());
        color.assign(n, 1);
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        cin>>m; //number of colours
        
        ans=1;
        
        for(i=0; i<n; i++) {
            if(visited[i]==false)
                bfs(i);
            if(ans==0) break;
        }
        
        if(ans==1) 
            cout<<"colorable"<<endl;
        else
            cout<<"not colorable"<<endl;
        
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
4 5
0 1
1 2
2 3
3 0
0 2
3

op:
colorable

ip:
1
3 3
0 1
1 2
0 2
2

op:
not colorable

*/
