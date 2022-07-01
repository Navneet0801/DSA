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

node* buildTree(int data){
    if(data == -1){
        return nullptr;
    }

    node* root = new node(data);

    cout<<"data for left of "<<data<<": ";
    int ldata;
    cin>>ldata;
    cout<<"data for right of "<<data<<": ";
    int rdata;
    cin>>rdata;

    root->left = buildTree(ldata);
    root->right = buildTree(rdata);
    return root;
}

int maxDepth(node* root) {
        if(root == nullptr){
            return 0;
        }
        
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        
        int ans = max(left , right) + 1;
        return ans;
    }

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    cout<<"Height of tree is: "<<maxDepth(root)<<endl;
    


    return 0;
}