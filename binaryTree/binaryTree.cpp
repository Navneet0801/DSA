#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node * buildTree(node * root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main(){
    node * root = NULL;

    //create a tree
    buildTree(root);
}