#include <stdio.h>
#define LIST_SIZE 100

typedef struct
{
    int value;
    int nextIndex;
} ListNode;

typedef struct
{
    ListNode list[LIST_SIZE];
    int headIndex;
    int freeIndex;
} ArrayLinkedList;

void initList(ArrayLinkedList *list)
{
    for (int i = 0; i < LIST_SIZE - 1; i++)
    {
        list->list[i].nextIndex = i + 1;
    }
    list->list[LIST_SIZE - 1].nextIndex = -1;
    list->headIndex = -1;
    list->freeIndex = 0;
}

int listIsEmpty(ArrayLinkedList *list)
{
    return list->headIndex == -1;
}

void addFront(ArrayLinkedList *list, int value)
{
    if (list->freeIndex == -1)
    {
        printf("List is full, cannot add more items!\n");
    }
    else
    {
        int newIndex = list->freeIndex;
        list->freeIndex = list->list[newIndex].nextIndex;
        list->list[newIndex].value = value;
        list->list[newIndex].nextIndex = list->headIndex;
        list->headIndex = newIndex;
    }
}

int removeFront(ArrayLinkedList *list)
{
    if (listIsEmpty(list))
    {
        printf("Attempt to remove from an empty list!\n");
        return -1;
    }
    else
    {
        int oldIndex = list->headIndex;
        list->headIndex = list->list[oldIndex].nextIndex;
        list->list[oldIndex].nextIndex = list->freeIndex;
        list->freeIndex = oldIndex;
        return list->list[oldIndex].value;
    }
}

//With usage:
int main() {
    ArrayLinkedList list;
    initList(&list);

    printf("Adding elements to the front of the list...\n");
    addFront(&list, 1);
    addFront(&list, 2);
    addFront(&list, 3);

    printf("Removing elements from the front of the list...\n");
    while (!listIsEmpty(&list)) {
        printf("%d\n", removeFront(&list));
    }

    return 0;
}

