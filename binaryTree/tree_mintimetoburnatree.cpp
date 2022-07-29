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

node* createParentmapping(node* root, int target, map<node*,node*> &nodetoparent){
      node* result = nullptr;
      
      queue<node*>q;
      q.push(root);
      nodetoparent[root] = nullptr;
      
      while(!q.empty()){
          node* front = q.front();
          q.pop();
          
          if(front->data == target){
              result = front;
          }
          
          if(front->left){
              nodetoparent[front->left]=front;
              q.push(front->left);
          }
          
           if(front->right){
              nodetoparent[front->right]=front;
              q.push(front->right);
          }
      }
      return result;
  }
  
  int burntree(node* root, map<node*,node*> &nodetoparent){
      
      map<node* ,bool> visited;
      queue<node*> q;
      
      q.push(root);
    
      visited[root]=true;
      int ans=0;
      
      while(!q.empty()){
          int size=q.size();
          bool flag=0;
          
          for(int i=0;i<size;i++){
              node *front=q.front();
              q.pop();
              
            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }
            
           if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }
            
            if(nodetoparent[front] && !visited[nodetoparent[front]]){
                flag=1;
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]]=1;
            }
          }
          
          if(flag==1){
              ans++;
          }
      }
      return ans;
  }
  
  
  
    int minTime(node* root, int target) 
    {
        map<node*, node*> nodetoparent;
       
       node* targetNode = createParentmapping(root,target,nodetoparent);
       
       int m = burntree(targetNode,nodetoparent);
       
       return m;
    }

int main(){
    node * root = nullptr;
    
    cout<<"Enter Data for root: ";
    int rdata;
    cin>>rdata;

    root = buildTree(rdata);

    cout<<minTime(root, 4);


    return 0;
}