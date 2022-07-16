#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

node* buildTree(int data){

    if(data == -1) return nullptr;

    node* root = new node(data);

    cout<<"Enter the left of "<<data<<": ";
    int ldata;
    cin>>ldata;

    cout<<"Enter the right of "<<data<<": ";
    int rdata;
    cin>>rdata;

    root -> left = buildTree(ldata);
    root -> right = buildTree(rdata);

    return root;
}

bool pathSumFast(node* temp, int targetSum, vector<int> &ans){
    if(!temp)   return false;

    ans.push_back(temp -> data);

    pathSumFast(temp -> left, targetSum, ans);
    pathSumFast(temp -> right, targetSum, ans);

    int sum = 0;
    for(int i=0; i<ans.size(); i++){
        sum += ans[i];
        if(sum == targetSum)
            return true;
    }

    ans.pop_back();
}

bool pathSum(node* root, int targetSum){
    vector<int> ans;

    bool result = pathSumFast(root, targetSum, ans);

    return result;
}

int main()
{
    cout<<"Enter data for the root: ";
    int rdata;
    cin>>rdata;
    node* root = buildTree(rdata);

    cout<<pathSum(root, 1);
    return 0;
}