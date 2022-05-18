#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void display(node* head){
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

struct node* deleteAtBegin(node* head){
    node * p = head;
    head = head->next;
    free(p);
    return head;
}

struct node* deleteAtIndex(node* head, int index){
    node * p = head;
    node * q = head->next;
    int i=0;

    while(i!=index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node * deleteLastNode(node * head){
    node* p = head;
    node* q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node * deleteValue(node* head, int element){
    node* p = head;
    node* q = head->next;
    while(q->data!=element && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    node* head;
    node* second;
    node* third;
    node* fourth;

    head = new node();
    second = new node();
    third = new node();
    fourth = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;
    display(head);
    cout<<endl;

    // head = deleteAtBegin(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteLastNode(head);
    head = deleteValue(head,3);

    display(head);

    return 0;
}