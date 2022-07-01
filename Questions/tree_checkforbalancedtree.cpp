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

int height(node* root) {
        if(root == nullptr){
            return 0;
        }
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        int ans = max(left , right) + 1;
    return ans;    
}

bool isBalanced(node* root){
    if(root == nullptr){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right))<=1;

    if(left && right && diff){
        return true;
    }
    return false;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    if(isBalanced(root))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    


    return 0;
}