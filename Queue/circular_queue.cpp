#include<iostream>
using namespace std;

class Queue{
    public:
    int front, rear, size;
    unsigned capacity;
    int * arr;
};

Queue * createQueue(unsigned capacity){
    Queue * queue = new Queue();
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    queue->arr = new int[queue->capacity];
    return queue;
}

int isFull(Queue * queue){
    return((queue->rear+1)%queue->capacity == queue->front);
}

int isEmpty(Queue * queue){
    return(queue->size == 0);
}

void enQueue(Queue * queue, int data){
    if(isFull(queue)){
        cout<<"\nQueue is already full";
        return;
    }
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear] = data;
    queue->size++;
    cout<<"\n"<<data<<" is enqueued in the queue";
    if(queue->front == -1) queue->front++;
}

void deQueue(Queue * queue){
    if(isEmpty(queue)){
        cout<<"\nQueue is already empty";
        return;
    }
    int tmp = queue->arr[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
    cout<<"\n"<<tmp<<" is dequeued from the queue";
    // if(queue->front > queue->rear){
    //     queue->front = queue->rear = -1;
    // }
}

int main()
{
    Queue * queue = createQueue(10);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    cout<<endl;
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    
    return 0;
}