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
}

//function for level order traverse
void levelOrderTraversal(node* root){
    queue<node*> q;
    if (root) {
        q.push(root);
    }
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node* front = q.front(); 
            q.pop();
            cout << front->data << ' ';
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        cout << endl; // change line after every level
    }
}

//function for pre order traverse
void preOrderTraversal(node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//function for post order traverse
void postOrderTraversal(node* root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    cout<<root->data<<" ";
}

//function for inorder traverse
void inOrderTraversal(node* root){
    if(root == nullptr){
        return;
    }

    inOrderTraversal(root->left);

    cout<<root->data<<" ";

    inOrderTraversal(root->right);
}

int main(){
    node * root;
    cout<<"Enter data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);


    //levelOrderTraversing
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    //pre Order Traversal
    cout << "Printing the pre order traversal output " << endl;
    preOrderTraversal(root);
    cout<<endl;

    //post Order Traversal
    cout << "Printing the post order traversal output " << endl;
    postOrderTraversal(root);
    cout<<endl;

    //inorder Traversal
    cout << "Printing the inorder traversal output " << endl;
    inOrderTraversal(root);
    cout<<endl;

    return 0;
}