

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val==p->val || root->val==q->val)
            return root;
        TreeNode *l=lowestCommonAncestor(root->left, p, q);
        TreeNode *r=lowestCommonAncestor(root->right, p, q);
        if(l && r)
            return root;
        if(l)
            return l;
        return r;
    }
};

/*

ip:

[3,5,1,6,2,0,8,null,null,7,4]
5
1
[3,5,1,6,2,0,8,null,null,7,4]
5
4
[1,2]
1
2

op:
3
5
1

*/

