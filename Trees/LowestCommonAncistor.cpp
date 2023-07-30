#include<iostream>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // ?base condition 
        if(root==NULL)
        return NULL;
        if(root->val==p->val)
        return p;
        if(root->val==q->val)
        return q;
        
        //recur
        TreeNode* leftN=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN=lowestCommonAncestor(root->right,p,q);
        if(leftN==NULL && rightN==NULL)
        return NULL;
        else if(leftN!=NULL && rightN==NULL)
        return leftN;
        else if(leftN==NULL && rightN!=NULL)
        return rightN;
        else
        return root;
    }
};