#include<iostream>
#include<math.h>
using namespace std;

// struct node{
//     int data;
//     node* left;
//     node* right;

//     node(int d){
//         this->data = d;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };

// node* buildTree(int data){
//     //base condition
//     if(data == -1){
//         return nullptr;
//     }

//     node* root = new node(data);

//     cout<<"Enter number for left of "<<data<<": ";
//     int ldata;
//     cin>>ldata;
//     cout<<"Enter number for right of "<<data<<": ";
//     int rdata;
//     cin>>rdata;

//     root->left = buildTree(ldata);
//     root->right = buildTree(rdata);
// }

// int main(){
//     int rdata;
//     cout<<"Enter root: ";
//     cin>>rdata;

//     buildTree(rdata);

//     return 0;
// }

int main(){
    int input;
    cin>>input;
    int a[32];
    int i=0;

    while(input>0){
        a[i] = input%2;
        input = input/2;
        i++;
    }

    int n = i/2;
    for(int j=0; j<n; j++){
        int temp = a[i-j-1];
        a[i-j-1] = a[j];
        a[j] = temp;
    }

    int num = 0;

    for(int j=0; j<i; j++){
        int bit;
        bit = a[j] == 0 ? 1 : 0;
        num += pow(2 , (i-j-1))*bit;
    }

    cout<<num;

    return 0;
}