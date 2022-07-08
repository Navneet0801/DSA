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

vector<int> levelOrderTraversalBottom(node* root) {
    vector<int> ans;
    if(root == nullptr){
        return {};
    }

    queue<node*> q;
    stack<int> s;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            node* temp = q.front();
            q.pop();

            s.push(temp -> data);
            if(temp -> right) q.push(temp -> right);
            if(temp -> left) q.push(temp -> left);
        }
    }
    while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
    }
    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    vector<int> vec = levelOrderTraversalBottom(root);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}