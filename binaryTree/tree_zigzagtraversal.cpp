#include<iostream>
#include<queue>
#include<stack>
#include<vector>
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

//zig zag traversal bruteForce
vector<int> zigzagLevelOrder(node* root) {
        vector<int> ans;
        if(root == nullptr){
            return {};
        }
        
        queue<node*> q;
        stack<node*> s;
        q.push(root);

        bool toReverse = false;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                node* temp = q.front();
                q.pop();

                if(toReverse){
                    s.push(temp);
                }
                else{
                    ans.push_back(temp->data);
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            toReverse = !toReverse;
            while(!s.empty()){
                ans.push_back(s.top()->data);
                s.pop();
            }
        }
        return ans;
    }

//zig zag traversal optimized
vector<int> zigzagLevelOrderFast(node* root) {
    vector<int> ans;
    if(root == nullptr){
        return {};
    }

    queue<node*> q;
    q.push(root);
    bool toReverse = false;


    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            node* temp = q.front();
            q.pop();

            int index = toReverse ? i : size-1-i;

            ans[index] = temp -> data;

            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
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

    vector<int> vec = zigzagLevelOrder(root);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}