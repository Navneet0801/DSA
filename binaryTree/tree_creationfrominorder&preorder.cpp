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

int findPosition(vector<int> inorder, int element, int start, int end){
    for(int i=start; i<=end; i++){
        if(inorder[i] == element)
            return i;
    }
    return -1;
}
    
node* solve(vector<int> preorder, vector<int> inorder, int index, int start, int end){
        
    if(start > end)     return nullptr;
        
    int curr = preorder[index];
    index++;
    node* root = new node(curr);
        
    if(start == end){
        return root;
    }
        
    int position = findPosition(inorder, curr, start, end);
        
    root -> left = solve(preorder, inorder, index, start, position-1);
    root -> right = solve(preorder, inorder, index, position+1, end);
        
    return root;
}
    
node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    static int index = 0;
        
    int start = 0;
    int end = inorder.size() - 1;
        
    node* ans = solve(preorder, inorder, index, start, end);
        
    return ans;
}

void postOrderTraversal(node* root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    cout<<root->data<<" ";
}

int main()
{
    vector<int> preorder = {1,6,7,8};
    vector<int> inorder = {1,6,8,7};

    node* root = buildTree(preorder, inorder);

    postOrderTraversal(root);

    return 0;
}