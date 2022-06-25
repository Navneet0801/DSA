#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

//Constructor function which initialize a node
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//function for creation of a tree
node * buildTree(node * root){
    cout<<"Enter a data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return root;
    }

    cout<<"Enter the left data for your node: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right data for your node: "<<data<<endl;
    root->right = buildTree(root->right);

}

//function for level order traversal
void levelOrderTraversal(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;  // last level completed and if not
            if(!q.empty()) // if queue still has some child nodes
                q.push(NULL);  
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node * root = NULL;

    //creating a tree
    buildTree(root);



    //level order traversal
    levelOrderTraversal(root);

    return 0;
}