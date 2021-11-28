#include <bits/stdc++.h>
using namespace std;
#define N 100000

vector < vector <pair<int, int> > > g;
vector <int> dist;
set < pair<int, int> > s;

int main() {
	int n,e,i,u,disu,disuv,v;
	cin>>n>>e;
	
	dist.assign(n+1, 100000);
	g.assign(n+1, vector<pair<int, int>>());
	
	for(i=0;i<e;i++) {
	    int a,b,w;
	    cin>>a>>b>>w;
	    g[a].push_back({w,b});
	}
	
	s.insert({0, 1});
	dist[1]=0;
	while(s.empty()==false) {
	    pair <int, int> temp=*(s.begin());
	    disu=temp.first;
	    u=temp.second;
	    s.erase(s.begin());
	    //cout<<u<<" "<<disu<<endl;
	    for(auto i:g[u]) {
	        v=i.second;
	        disuv=i.first;
	        if(dist[v]>disu+disuv) {
	            //if dist[v] is not inf, its already been visited 
	            // and we should update in set (delete old and insert new)
	            if(dist[v]!=100000)
	                s.erase({dist[v], v});
	            dist[v]=disu+disuv;
	            s.insert({dist[v], v});
	        }
	    }
	}
	
	cout<<"distance from source 1"<<endl;
	for(int r=1; r<n+1;r++) {
	    cout<<"vertex "<<r<<" distance: "<<dist[r]<<endl;
	}
	
	/*for(auto i:g) {
	    for(auto j:i) {
	        cout<<j.first<<" "<<j.second<<endl;
	    }
	}*/
	
	return 0;
}

/* input :
4 5
1 2 4
1 3 8
2 3 2
2 4 6
3 4 1
o/p:
distance from source 1
vertex 1 distance: 0
vertex 2 distance: 4
vertex 3 distance: 6
vertex 4 distance: 7
*/
