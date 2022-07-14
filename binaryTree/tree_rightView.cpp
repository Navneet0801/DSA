#include<bits/stdc++.h>

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

void goFind(node* temp, vector<int> &ans, int lvl){
    if(temp == nullptr)  return;

    if(lvl == ans.size()){
        ans.push_back(temp -> data);
    }

    goFind(temp -> right, ans, lvl+1);
    goFind(temp -> left, ans, lvl+1);
}

vector<int> leftView(node* root){
    vector<int> ans;
    goFind(root, ans, 0);
    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    vector<int> vec = leftView(root);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}