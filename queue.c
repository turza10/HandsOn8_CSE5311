#include <stdio.h>
#define QUEUE_LIMIT 100

typedef struct {
    int entries[QUEUE_LIMIT];
    int first, last, count;
} CircularQueue;

void queueInitialize(CircularQueue *q) {
    q->first = 0;
    q->last = -1;
    q->count = 0;
}

int queueIsEmpty(CircularQueue *q) {
    return q->count == 0;
}

int queueIsFull(CircularQueue *q) {
    return q->count == QUEUE_LIMIT;
}

void enqueue(CircularQueue *q, int item) {
    if (queueIsFull(q)) {
        printf("Queue overflow error!\n");
    } else {
        q->last = (q->last + 1) % QUEUE_LIMIT;
        q->entries[q->last] = item;
        q->count++;
    }
}

int dequeue(CircularQueue *q) {
    if (queueIsEmpty(q)) {
        printf("Queue underflow error!\n");
        return -1; // Indicate error if queue is empty
    } else {
        int item = q->entries[q->first];
        q->first = (q->first + 1) % QUEUE_LIMIT;
        q->count--;
        return item;
    }
}

int queueFront(CircularQueue *q) {
    if (queueIsEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return q->entries[q->first];
    }
}

//With an example usage
int main() {
    CircularQueue q;
    queueInitialize(&q);

    printf("Enqueuing elements...\n");
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);

    printf("Front element is: %d\n", queueFront(&q));

    printf("Dequeuing elements...\n");
    while (!queueIsEmpty(&q)) {
        printf("%d\n", dequeue(&q));
    }

    return 0;
}
