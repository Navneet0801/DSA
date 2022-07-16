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

node* buildTree(int data){

    if(data == -1) return nullptr;

    node* root = new node(data);

    cout<<"Enter the left of "<<data<<": ";
    int ldata;
    cin>>ldata;

    cout<<"Enter the right of "<<data<<": ";
    int rdata;
    cin>>rdata;

    root -> left = buildTree(ldata);
    root -> right = buildTree(rdata);

    return root;
}

node* lowestCommonAncestor(node* root, int p, int q){
    if(!root)  return nullptr;

    if(root -> data == p || root->data == q){
        return root;
    }

    node* leftAns = lowestCommonAncestor(root -> left, p, q);
    node* rightAns = lowestCommonAncestor(root -> right, p, q);

    if(leftAns != nullptr  &&  rightAns  != nullptr)
        return root;

    else if(leftAns == nullptr  &&  rightAns != nullptr)
        return rightAns;

    else if(leftAns != nullptr  &&  rightAns == nullptr)
        return leftAns;

    else
        return nullptr;
}

int main()
{
    cout<<"Enter data for the root: ";
    int rdata;
    cin>>rdata;
    node* root = buildTree(rdata);


    node* result = lowestCommonAncestor(root, 4, 5);

    cout<<result -> data;

    return 0;
}