include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue {
    int *array;       
    int capacity;    
    int front;        
    int rear;         
    int count;        
};
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->array = (int*)malloc(q->capacity * sizeof(int));
    return q;
}


bool isEmpty(struct Queue* q) {
    return (q->count == 0);
}

bool isFull(struct Queue* q) {
    return (q->rear == q->capacity - 1);
}
int size(struct Queue* q) {
    return q->count;
}
void enqueue(struct Queue* q, int customerID) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot add Customer %d.\n", customerID);
        return;
    }
    q->rear++;              
    q->array[q->rear] = customerID;
    q->count++;
    
    printf("Customer %d joined the queue.\n", customerID);
}
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! No customers to serve.\n");
        return;
    }
    int servedCustomer = q->array[q->front];
    q->front++;                 // Move front pointer forward
    q->count--;
    
    printf("Served customer: %d\n", servedCustomer);
}
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->array[q->front];
}
int main() {
    struct Queue* ticketCounter = createQueue(5);
    printf("--- Ticket Counter Opened ---\n");
    enqueue(ticketCounter, 101);
    enqueue(ticketCounter, 102);
    enqueue(ticketCounter, 103);
    printf("\nTotal waiting: %d\n", size(ticketCounter));
    printf("Next customer: %d\n", peek(ticketCounter));
    printf("-----------------------------\n");
    dequeue(ticketCounter);
    printf("\n--- After Serving First Customer ---\n");
    printf("Next customer: %d\n", peek(ticketCounter)); 
    printf("Total waiting: %d\n", size(ticketCounter));
    free(ticketCounter->array);
    free(ticketCounter);
    return 0;
}