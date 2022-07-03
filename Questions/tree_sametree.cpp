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

int isSameTree(node* root1 , node* root2){
    if(root1 == nullptr && root2 == nullptr){
        return 1;
    }

    if(root1 == nullptr && root2 != nullptr){
        return 0;
    }

    if(root1 != nullptr && root2 == nullptr){
        return 0;
    }

    int leftCheck = isSameTree(root1->left , root2->left);
    int rightCheck = isSameTree(root1->right , root2->right);
    int currVal = root1->data == root2->data;

    if(leftCheck && rightCheck && currVal){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    node * root1 = nullptr;
    node * root2 = nullptr;
    
    cout<<"Enter Data for root1: ";
    int r1data;
    cin>>r1data;

    root1 = buildTree(r1data);

    cout<<"Enter Data for root2: ";
    int r2data;
    cin>>r2data;

    root2 = buildTree(r2data);

    if(isSameTree(root1 , root2)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    


    return 0;
}