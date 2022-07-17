#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

int findposition(vector<int> a, int ele, int n){
    for(int i=0; i<n; i++){
        if(a[i] == ele){
            return i;
        }
    }
    return -1;
}

node* solve(vector<int> preorder, vector<int> inorder, int index, int inorderstart, int inorderend, int n){
    //base case
    if(index >= n || inorderstart >= inorderend){
        return nullptr;
    }

    int element = preorder[index++];
    node* root = new node(element);
    int position = findposition(inorder, element, n);

    //recursion
    root -> left = solve(preorder, inorder, index, inorderstart, position-1, inorder.size());
    root -> left = solve(preorder, inorder, index, position+1, inorderend, inorder.size());

    return root;
}

node* makeTree(vector<int> preorder, vector<int> inorder){
    int index = 0;
    int inorderstart = 0;
    int inorderend = inorder.size()-1;
    node* root = solve(preorder, inorder, index, inorderstart, inorderend, inorder.size());
}

void postorder(node* root){
    if(!root)   return;

    postorder(root -> left);
    postorder(root -> right);

    cout<<root->data<<" ";
}

int main()
{
    vector<int> preorder = {1,6,7,8};
    vector<int> inorder = {1,6,8,7};

    node* root = makeTree(preorder, inorder);

    postorder(root);

    return 0;
}