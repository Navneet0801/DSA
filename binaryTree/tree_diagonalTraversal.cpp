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

void diagonalPrintUtil(node* root, int d, map<int, vector<int>> &diagonalPrint){
    // Base case
    if (!root)
        return;
        
    diagonalPrint[d].push_back(root->data);
    
    diagonalPrintUtil(root->left,  d + 1, diagonalPrint);
    
    diagonalPrintUtil(root->right, d, diagonalPrint);
}
 

vector<int> diagonal(node *root)
{
    map<int, vector<int> > diagonalPrint;
    vector<int> ans;
    diagonalPrintUtil(root, 0, diagonalPrint);
   
   for(auto i:diagonalPrint){
       for(auto j:i.second){
           ans.push_back(j);
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

    vector<int> vec = diagonal(root);

    for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
    }

    return 0;
}