#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

//For printing of the linked list

void display(node* head){
    node * p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    } while (p!=head);   
}

//case:1 insertion inthe beginning of the linked list

struct node* InsertAtFirst(node * head, int data){
    node * ptr;
    node * q = head;
    ptr = new node();

    while(q->next!=head){
        q = q->next;
    }

    q->next = ptr;
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

//case:2 Insertion at an index in the linked list

struct node * InsertAtIndex(node * head, int data, int index){
    node* ptr;
    ptr = new node();
    int i=0;
    node * q = head;
    ptr->data = data;

    while(i!=index-1){
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    q->next = ptr;
    return head;
}

//case:3 Insertion at the last in the linked list

struct node * InsertAtLast(node * head, int data){
    node * ptr;
    ptr = new node();
    ptr->data = data;
    
    node * q = head;

    while(q->next!=head){
        q = q->next;
    }
    ptr->next = q->next;
    q->next = ptr;

    return head;
}

//case:4 Insertion after a given node in the linked list

struct node * InsertAfterNode(node * head, int data, node * n){
    node * ptr;
    ptr = new node();
    ptr->data = data;

    ptr->next = n->next;
    n->next = ptr;

    return head;
}

//DELETION

//case:1 Delete node from the beginning of the list

struct node * DeleteFromFirst(node * head){
    node * q = head;

    while(q->next!=head){
        q = q->next;
    }

    q->next = head->next;
    free(head);
    head = q->next;
    return head;
}

//case:2 Deletion at any index from the list

struct node * DeleteAtIndex(node* head, int index){
    int i = 0;
    node * q = head;
    node * p = head->next;
    while(i!=(index-1)){
        q = q->next;
        p = p->next;
        i++;
    }
    q->next = p->next;;
    free(p);
    return head;
}

//case:3 Deletion of the last node in the list

struct node * DeleteFromLast(node * head){
    node * p = head;
    node * q = head->next;
    while(q->next!=head){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//case:4 Delete the node of given value from the list

struct node * DeleteValue(node * head, int value){
    node * p = head;
    node * q = head->next;
    while(q->data!=value){
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

    head->data = 7;
    head->next = second;

    second->data =11;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = head;

    display(head);
    cout<<endl;

    //Insertion(Remove // from any case)

    // head = InsertAtFirst(head, 2);

    // head = InsertAtIndex(head, 4, 2);

    // head = InsertAtLast(head, 6);

    // head = InsertAfterNode(head, 8, second);

    //Deletion(Remove // from any case)

    // head = DeleteFromFirst(head);

    // head = DeleteAtIndex(head, 2);

    // head = DeleteFromLast(head);

    // head = DeleteValue(head, 13);

    display(head);

    return 0;
}