#include<iostream>
#include<queue>
#include<stack>
#include<vector>
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

void traverseLeft(node* temp, vector<int> &ans){
    if(temp == nullptr){
        return;
    }

    stack<int> s;

    s.push(temp -> data);
    if(temp -> left) traverseLeft(temp -> left, ans);

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}

void traverseRight(node* temp, vector<int> &ans){
    if(temp == nullptr){
        return;
    }

    ans.push_back(temp -> data);
    if(temp -> right) traverseLeft(temp -> right, ans);
}

vector<int> topViewTraversal(node* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }


    traverseLeft(root->left, ans); //traverse the left of tree except left leaf node
    ans.push_back(root -> data);
    traverseRight(root->right, ans); //traverse the right of tree except right leaf node

    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    vector<int> vec = topViewTraversal(root);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}