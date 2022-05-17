#include <iostream>
using namespace std;

class Queue{
    public:
    int front, rear, size;
    unsigned capacity;
    int * arr;
};

Queue * createQueue(unsigned capacity){
    Queue * queue = new Queue();
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->arr = new int[queue->capacity];
    return queue;
}

int frontElement(Queue * queue){
    return(queue->arr[queue->front]);
}

int rearElement(Queue * queue){
    return(queue->arr[queue->rear]);
}

int isFull(Queue * queue){
    return(queue->size == queue->capacity);
}

int isEmpty(Queue * queue){
    return(queue->size == 0);
}

void enQueue(Queue * queue, int data){
    if(isFull(queue)){
        cout<<"\nQueue is already full";
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
    queue->size++;
    cout<<"\n"<<data<<" is enqueued in the queue.";
    if(queue->front == -1) queue->front++;
 }

void deQueue(Queue * queue){
    if(isEmpty(queue)){
        cout<<"\nqueue is already empty";
        return;
    }
    int tmp = queue->arr[queue->front];
    queue->front++;
    queue->size--;
    if(queue->front > queue->rear){
        queue->front = queue->rear = -1;
    }
    cout<<"\n"<<tmp<<" is dequeued from the queue.";
}

int main() {
    Queue * queue = createQueue(10);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    cout<<"\nFront is: "<<frontElement(queue);
    cout<<"\nRear is: "<<rearElement(queue);
    cout<<endl;
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    cout<<"\nFront is: "<<frontElement(queue);
    cout<<"\nRear is: "<<rearElement(queue);

    return 0;
}