
//  Definition for a binary tree node.
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<iostream>
using namespace std;
class Solution1 {
public:
    int height(TreeNode* root){
        //base case
        if(root==NULL)
        return 0;
        int leftH=height(root->left);
        int rightH=height(root->right);
        return (1+ max(leftH,rightH));
    }
    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL)
        return true;
        int leftH=height(root->left);
        int rightH=height(root->right);
        int diff=abs(leftH-rightH);
        bool center=diff<=1;
        //recur
        bool Left=isBalanced(root->left);
        bool Right=isBalanced(root->right);
        if(center && Left && Right)
        return true;
        else
        return false;
    }
};

class Solution2 {
    bool isvalid=true;
public:
    int height(TreeNode* &root){
        if(!root) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        if(isvalid&& abs(lh-rh)>1)
            isvalid=false;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isvalid;
    }
};