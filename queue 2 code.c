#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 

typedef struct {
    char jobs[MAX][10]; 
    int front;
    int rear;
    int size;
} PrintQueue;
void init(PrintQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
int isEmpty(PrintQueue *q) {
    return q->size == 0;
}
void enqueue(PrintQueue *q, char jobID[]) {
    if (q->size == MAX) {
        printf("Queue Overflow: Cannot add %s\n", jobID);
        return;
    }
    q->rear = (q->rear + 1) % MAX; 
    strcpy(q->jobs[q->rear], jobID);
    q->size++;
    printf("Job added: %s\n", jobID);
}
void dequeue(PrintQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: No jobs to print.\n");
        return;
    }
    printf("Job printed → %s\n", q->jobs[q->front]);
    q->front = (q->front + 1) % MAX;
    q->size--;
}
void front(PrintQueue *q) {
    if (isEmpty(q)) {
        printf("No pending jobs.\n");
    } else {
        printf("Next job → %s\n", q->jobs[q->front]);
    }
}
int main() {
    PrintQueue q;
    init(&q);
    enqueue(&q, "J1");
    enqueue(&q, "J2");
    enqueue(&q, "J3");

    dequeue(&q);    
    front(&q); 
    
    printf("Pending jobs: %d\n", q.size);

    return 0;
}