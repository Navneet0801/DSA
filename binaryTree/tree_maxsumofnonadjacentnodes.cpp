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

pair<int, int> solve(node* temp){
    if(!temp){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(temp -> left);
    pair<int, int> right = solve(temp -> right);

    pair<int, int> res;

    res.first = temp->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res; 
}

int maxSum(node* root){
    pair<int, int> ans;  //first is for including and second if for excluding the current node
    ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    cout<<"Enter data for the root: ";
    int rdata;
    cin>>rdata;
    node* root = buildTree(rdata);

    int result = maxSum(root);
    cout<<result;

    return 0;
}