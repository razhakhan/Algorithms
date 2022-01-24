#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <bool> v;
vector <vector <int>> g;
stack <int> sk;
int n,e;

//normal dfs function
int dfs(int x) {
	v[x]=true;
	for(auto i: g[x]) {
		if(v[i]==false) {
			dfs(i);
		}
	}
	sk.push(x);
	//push the deepest node in the tree to stack
}

int main() {
	int t,i;
    	cin>>n>>e;
        
    	//assign memory for new data
    	v.assign(n, false);
    	g.assign(n, vector <int> ());
        
    	//take edges as input
    	for(i=0; i<e; i++) {
        	int a,b;
        	cin>>a>>b;
        	g[a].pb(b);
    	}
 
	//call dfs on all unvisited nodes
    	for(i=0; i<n; i++) {
		if(v[i]==false) {
			dfs(i);
		}
    	}
	
	//pop each element from stack and print
    	while(sk.empty()==false) {
		int x;
		x=sk.top();
		sk.pop();
		cout<<x<<" ";
	}
	
    	//clear previous values
    	v.clear();
    	for(i=0; i<n; i++) {
        	g[i].clear();
    	}
}

/* 

ip : 

6 6
5 2
5 0
4 0
4 1
2 3
3 1

op:

5 4 2 3 1 0

*/
