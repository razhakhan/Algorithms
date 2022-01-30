#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int n;
/*
void inOrder(TreeNode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val <<" ";
        inOrder(root->right);
    }
}
*/
TreeNode* ConstructTree(int arr[], TreeNode *root, int i, int n) {
    if(i<n) {
        if(arr[i]==-1) {    //if arr element is -1, it is NULL
            struct TreeNode *temp=NULL;
            root=temp;
        }
        else {
            struct TreeNode *temp=new TreeNode(arr[i]); //create node for the arr element
            root=temp;
            root->left=ConstructTree(arr, root->left, 2*i+1, n);    //recursively build its left
            root->right=ConstructTree(arr, root->right, 2*i+2, n);  //and right nodes and their subtrees
        }
    }
    return root;    //return the root of the whole tree
}

class Solution {
public:
    TreeNode * lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root==NULL)  //if root is null, you've reached the end and didnt find p or q, return null
            return NULL;
        if(root->val==p || root->val==q)    //if present root is p or q, return it
            return root;
        TreeNode *l=lowestCommonAncestor(root->left, p, q); //search for p or q in left subtree
        TreeNode *r=lowestCommonAncestor(root->right, p, q); //search for p or q in right subtree
        if(l && r)  //if both l and r are not null, we've found p and q
            return root;
        if(l)   //if r is null and l is not null, l is the lca
            return l;
        return r;   //else r is the lca
    }
};

int main() {
    int t,i;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        int p,q;
        //take nodes as input
        for(i=0; i<n; i++) {
            cin>>arr[i];    //if arr[i]==-1, then it is null
        }
        cin>>p; //1st element
        cin>>q; //2nd element
        //construct tree
        TreeNode * root=ConstructTree(arr, root, 0,n);
        //inOrder(root);
        //cout<<endl;
        Solution obj;
		TreeNode* ans = obj.lowestCommonAncestor(root, p, q);
		cout<<ans->val<<endl;
    }
}

/* 
ip:
3
11
3 5 1 6 2 0 8 -1 -1 7 4
5
1
11
3 5 1 6 2 0 8 -1 -1 7 4
5
4
2
1 2
1
2
op:
3
5
1
*/
