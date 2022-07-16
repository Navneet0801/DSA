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

node* solve(node* root, int &k, int Node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == Node) 
    {
        return root;
    }
    
    node* leftAns = solve(root->left, k, Node);
    node* rightAns = solve(root->right, k, Node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(node *root, int k, int Node)
{
    node* ans = solve(root, k, Node);
    if(ans == NULL || ans->data == Node)
        return -1;
    else
        return ans->data;
}

int main()
{
    cout<<"Enter data for the root: ";
    int rdata;
    cin>>rdata;
    node* root = buildTree(rdata);

    int result = kthAncestor(root, 2, 5);
    cout<<result;

    return 0;
}