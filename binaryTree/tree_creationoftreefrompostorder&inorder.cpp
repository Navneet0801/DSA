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
    
node* solve(vector<int> postorder, vector<int> inorder, int index, int start, int end){
        
    if(start > end)     return nullptr;
        
    int curr = postorder[index];
    index--;
    node* root = new node(curr);
        
    if(start == end){
        return root;
    }
        
    int position = findPosition(inorder, curr, start, end);
    
    root -> right = solve(postorder, inorder, index, position+1, end);
    root -> left = solve(postorder, inorder, index, start, position-1);
        
    return root;
}
    
node* buildTree(vector<int>& postorder, vector<int>& inorder) {
    static int index = inorder.size() - 1;
        
    int start = 0;
    int end = inorder.size() - 1;
        
    node* ans = solve(postorder, inorder, index, start, end);
        
    return ans;
}

void preOrderTraversal(node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

int main()
{
    vector<int> postorder = {8,7,6,1};
    vector<int> inorder = {1,6,8,7};

    node* root = buildTree(postorder, inorder);

    preOrderTraversal(root);

    return 0;
}