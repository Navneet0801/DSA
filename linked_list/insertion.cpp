#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void display(node * n){
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
}

struct node* insertatFirst(node* head, int data){
    node* ptr;
    ptr = new node();

    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node* insertatIndex(node* head, int data, int index){
    node* ptr;
    node* p = head;
    ptr = new node;
    int i=0;

    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node* insertatEnd(node* head, int data){
    node* ptr;
    ptr = new node;
    node* p = head;

    while (p->next!=NULL)
    {
        p = p->next;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node* insertafterNode(node *head, node* prevnode, int data){
    node* ptr;
    ptr = new node;

    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

int main()
{
    int element;

    node* head;
    node* second;
    node* third;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    display(head);
    cout<<endl;

    // head = insertatFirst(head, 0);
    // head = insertatIndex(head, 2, 2);
    // head = insertatEnd(head, 5);
    head = insertafterNode(head, third, 3);

    display(head);
    cout<<endl;


    return 0;
}