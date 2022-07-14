#include<iostream>
#include<map>
#include<set>
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

map<int , map<int , multiset<int>>> mp;

void traversal(int hd, int lvl, node* temp){
    if(temp == nullptr)     return;
    traversal(hd-1 , lvl+1, temp->left);
    traversal(hd+1 , lvl+1, temp->right);
    mp[hd][lvl].insert(temp->data);
}

vector<int> verticalOrderTraversal(node* root){
    vector<int> ans;
    traversal(0,0,root);

    for(auto i:mp){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    vector<int> vec = verticalOrderTraversal(root);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}