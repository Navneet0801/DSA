#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

void display(node * n){
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
}

struct node * reversebyiterative(node * head){
    node * prev = NULL;
    node * curr = head;
    node * next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node * reversebyrecursion(node * head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node * newhead = reversebyrecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
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
    cout<<endl;

    // Reverse by iteration..
    // head = reversebyiterative(head);

    // Reverse by recursion..
    head = reversebyrecursion(head);

    display(head);

    return 0;
}