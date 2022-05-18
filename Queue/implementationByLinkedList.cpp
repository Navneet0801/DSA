#include<iostream>
using namespace std;

struct node * f;
struct node * r;

struct node{
    int data;
    node * next;
};

void queueTraversal(node * ptr){
    while(!(ptr == NULL)){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

void enQueue(int val){
    node * tmp = new node();
    if(tmp == NULL)
        cout<<"\nQueue is already full";

    else{
        tmp->data = val;
        tmp->next = NULL;
        if(f == NULL){
            f = r = tmp;
        }
        else{
            r->next = tmp;
            r=tmp;
        }
    } 
}

void deQueue(){
    int val;
    node * ptr = f;
    if(f == NULL){
        cout<<"\nQueue is already empty";
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
        cout<<"\n"<<val<<" is dequeued from the queue";
    }
}

int main()
{
    cout<<endl;
    deQueue();
    enQueue(34);
    enQueue(4);
    enQueue(7);
    enQueue(17);
    deQueue();
    cout<<endl;
    queueTraversal(f);
    return 0;
}