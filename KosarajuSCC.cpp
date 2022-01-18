#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <bool> v;
vector <vector <int>> g, rev;
stack <int> sk;

int n,e;

void DFS1(int x) {
    v[x]=true;
    for(auto i: g[x])
        if(v[i]==false)
            DFS1(i);
    sk.push(x);
}

void reverse() {
    int i;
    for(i=0; i<n; i++) {
        for(auto j: g[i]) {
            rev[j].pb(i);
        }
    }
}

void DFS2(int x) {
    cout<<x<<" ";
    v[x]=true;
    for(auto i: rev[x])
        if(v[i]==false)
            DFS2(i);
}

void printSCC() {
    int i,x;
    
    //first dfs call
    for(i=0; i<n;i++)
        if(v[i]==false)
            DFS1(i);
    
    //reverse directions of all edges
    reverse();
    
    //clear visited array
    for(int i=0;i<n;++i)
		v[i] = false;
    
    cout<<"The SCCs are : "<<endl;
    
    //second dfs call
    while(sk.empty()==false) {
        x=sk.top();
        sk.pop();
        if(v[x]==false) {
            DFS2(x);
            cout<<endl;
        }
    }
}

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n>>e;
        
        //assign memory for new data
        v.assign(n, false);
        g.assign(n, vector <int> ());
        rev.assign(n, vector <int> ());
        
        //take edges as input
        for(i=0; i<e; i++) {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
        }
        
        printSCC();
        
        //clear previous values
        v.clear();
        for(i=0; i<n; i++) {
            g[i].clear();
        }
    }
    return 0;
}

/* 

input :
1
8 10
0 1
1 2
2 0
2 3
3 4
4 5
4 7
5 6
6 4
6 7

o/p :
The SCCs are : 
0 2 1 
3 
4 6 5 
7               

*/
