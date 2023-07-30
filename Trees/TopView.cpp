#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};



class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
        
        void topView(Node * root) {

        if(root==NULL)
        return;
        map<int,int> m;
        // vector<pair<int,int>> p;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        // int flag=0;int sm=0;
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* nd=temp.first;
            int hd=temp.second;
            if(m.find(hd)==m.end()){
                // p.push_back(make_pair(nd->data,hd));
                m[hd]=nd->data;
            }
            if(nd->left!=NULL){
                q.push(make_pair(nd->left,hd-1));
            }
            if(nd->right!=NULL){
                q.push(make_pair(nd->right,hd+1));
            }
        }
        // sort(p.begin(),p.end(), sortbysec );
        for(auto i:m)
        cout<<i.second<<" ";
        cout<<endl;
        return;
    }

}; //End of Solution
int main(){
    Node* nd = new Node(10);
    Solution sol;
    vector<int> a={116,37,23,108,59,86,64,94,14,105,17,111,65,55,31,79,97,78,25,50,22,66,46,104,98,81,90,68,40,103,77,74,18,69,82,41,4,48,83,67,6,2,95,54,100,99,84,34,88,27,72,32,62,9,56,109,115,33,15,91,29,85,114,112,20,26,30,93,96,87,42,38,60,7,73,35,12,10,57,80,13,52,44,16,70,8,39,107,106,63,24,92,45,75,116,5,61,49,101,71,11,53,43,102,110,1,58,36,28,76,47,113,21,89,51,19,3};  
    for(int i=0;i<a.size();i++){
        sol.insert(nd,a[i]);
    }
    // sol.insert(nd,20);
    // sol.insert(nd,30);
    // sol.insert(nd,40);
    // sol.insert(nd,50);
    // sol.insert(nd,2);
    // sol.insert(nd,3);
    // sol.insert(nd,1);
    // sol.insert(nd,0);
    sol.topView(nd);
    
}