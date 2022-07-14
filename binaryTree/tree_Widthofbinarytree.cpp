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

int maxDepth(node* root) {
        if(root == nullptr){
            return 0;
        }
        
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        
        int ans = max(left , right) + 1;
        return ans;
    }

//Approach 1 time complexity O(n^2)
int diameterOfBinaryTree(node* root) {
    if(root == nullptr){
        return 0;
    }
    int opt1 = diameterOfBinaryTree(root -> left);
    int opt2 = diameterOfBinaryTree(root -> right);
    int opt3 = maxDepth(root->left) + 1 + maxDepth(root->right);

    int ans = max(opt1 , max(opt2 , opt3));
    
    return ans;
}

//Approach 2 time complexity O(n)
pair<int,int> diameterFast(node* root){
    if(root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(opt1 , max(opt2 , opt3));
    ans.second = max(left.second , right.second) + 1;
    return ans;
}

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    cout<<"Height of tree is: "<<maxDepth(root)<<endl;

    cout<<"Width of the tree is(O(n^2)): "<<diameterOfBinaryTree(root)<<endl;

    cout<<"Width of the tree is(O(n)): "<<diameterFast(root).first<<endl;
    


    return 0;
}