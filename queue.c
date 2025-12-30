#include <stdio.h>

#define QUEUE_SIZE 1000
struct queue{
    int data[QUEUE_SIZE];
    int counter;
    int start;
    int end;
};

int pop(struct queue *q){
    
    if ( !q-> counter ) 
    {printf("Queue is empty");return -1;}
    int data = q->data[q->start];
    q->start = (q->start + 1 ) % QUEUE_SIZE;
    q->counter --;
    return data;

}

int push(struct queue *q,int data){
    if ( q-> counter == QUEUE_SIZE ) 
    {printf("Queue is full");return 0;}
    q->counter ++;
    q->data[q->end] = data;
    q->end= (q->end + 1 ) % QUEUE_SIZE;
    return 1;
}

void init_queue(struct queue *q) {
    q->counter = 0;
    q->start = 0;
    q->end = 0;
}


int main() {
    struct queue q;
    init_queue(&q);
    
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    
    printf("Popped: %d\n", pop(&q)); // 10
    printf("Popped: %d\n", pop(&q)); // 20
    printf("Popped: %d\n", pop(&q)); // 10
    printf("Popped: %d\n", pop(&q)); // 20
    
    return 0;
}