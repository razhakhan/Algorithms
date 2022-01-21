#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back
#define INF 1000000

vector <int> dist;  //to note distance of each vertex from source
vector <vector < pair<int, int> > > g;  //{(v,w) , (v,w),...}
int n,e;

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //assign memory for new data
        dist.assign(n, INF);  //assign all distances as INF
        g.assign(n, vector <pair<int,int>> ());
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b,w;
            cin>>a>>b>>w;
            g[a].pb({b,w});
            g[b].pb({a,w});
        }
        
        int s=0;    //source
        dist[s]=0;  //dist of source=0
        deque <int> q;  //insertion and deletion at both ends
        q.push_front(s);
        int u,v,w;
        
        while(q.empty()==false) {
            u=q.front();    //front vertex
            q.pop_front(); 
            for(auto i: g[u]) {
                v=i.first;  //v - adjacent vertex of u
                w=i.second; //weight of uv
                if(dist[u]+w<dist[v]) { //enqueue only when shorter/optimal distance is achieved
                    dist[v]=dist[u]+w;
                    if(w==1)
                        q.push_back(v);
                    else
                        q.push_front(v);
                }    
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<i<<" is at a dist of "<<dist[i]<<" from "<<s<<endl;
        
        //clear previous values
        dist.clear();
        for(i=0; i<n; i++) {
            g[i].clear();
        }
    }
}

/*

input :

1
9 13
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1

o/p:
0 is at a dist of 0
1 is at a dist of 0
2 is at a dist of 1
3 is at a dist of 1
4 is at a dist of 2
5 is at a dist of 1
6 is at a dist of 2
7 is at a dist of 1
8 is at a dist of 2

*/
