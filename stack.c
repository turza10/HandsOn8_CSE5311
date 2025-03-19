#include <stdio.h>
#define STACK_CAPACITY 100

struct IntStack {
    int itemCount;
    int elements[STACK_CAPACITY];
};

void stackInit(struct IntStack* stk) {
    stk->itemCount = 0;
}

int stackIsEmpty(struct IntStack* stk) {
    return stk->itemCount == 0;
}

int stackIsFull(struct IntStack* stk) {
    return stk->itemCount == STACK_CAPACITY;
}

void stackPush(struct IntStack* stk, int value) {
    if (stackIsFull(stk)) {
        printf("Stack has reached its capacity!\n");
    } else {
        stk->elements[stk->itemCount++] = value;
    }
}

int stackPop(struct IntStack* stk) {
    if (stackIsEmpty(stk)) {
        printf("Attempt to pop from an empty stack!\n");
        return -1; // Indicate error if stack is empty
    } else {
        return stk->elements[--stk->itemCount];
    }
}

int stackTop(struct IntStack* stk) {
    if (stackIsEmpty(stk)) {
        printf("Attempt to peek into an empty stack!\n");
        return -1;
    } else {
        return stk->elements[stk->itemCount - 1];
    }
}

//With an example of usage
int main() {
    struct IntStack stk;
    stackInit(&stk);

    printf("Pushing elements onto stack...\n");
    stackPush(&stk, 10);
    stackPush(&stk, 20);
    stackPush(&stk, 30);

    printf("Top element is: %d\n", stackTop(&stk));

    printf("Popping elements from stack...\n");
    while (!stackIsEmpty(&stk)) {
        printf("%d\n", stackPop(&stk));
    }

    return 0;
}
