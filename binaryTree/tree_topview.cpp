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

vector<int> topView(node* root){
    vector<int> ans;

    if(root == nullptr){
        return ans;
    }

    map<int, int> mp;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        if(mp.find(hd) == mp.end())
            mp[hd] = frontNode -> data;

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, hd-1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, hd+1));
    }

    for(auto i:mp){
        ans.push_back(i.second);
    }

    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    vector<int> vec = topView(root);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}