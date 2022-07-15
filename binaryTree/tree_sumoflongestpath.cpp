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

void solve(node* temp, int len, int &maxLen, int sum, int &maxSum){
        if(temp == nullptr){
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                maxSum = max(maxSum, sum);
            }
        return;
        }
        
        sum += temp -> data;
        
        solve(temp -> left, len+1, maxLen, sum, maxSum); 
        solve(temp -> right, len+1, maxLen, sum, maxSum); 
    }

int sumOfLongRootToLeafPath(node *root){
    int len = 0;
    int maxLen = 0;
        
    int sum = 0;
    int maxSum = INT_MIN;
        
    solve(root, len, maxLen, sum, maxSum);
        
    return maxSum;
}

int main()
{
    cout<<"Enter data for the root: ";
    int rdata;
    cin>>rdata;
    node* root = buildTree(rdata);

    cout<<sumOfLongRootToLeafPath(root);

    return 0;
}