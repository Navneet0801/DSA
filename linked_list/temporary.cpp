#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

void display(node* n){
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
}

int main()
{
    node* head;
    node* second;
    node* last;

    head = new node();
    second = new node();
    last = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = last;

    last->data = 3;
    last->next = NULL;

    display(head);

    return 0;    
}