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

pair<bool, int> isSumTree(node* root){
    if(root == nullptr){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == nullptr && root->right == nullptr){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);
    int cond = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if(leftAns.first && rightAns.first && cond){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }
    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    bool check = isSumTree(root).first;

    if(check){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }


    return 0;
}