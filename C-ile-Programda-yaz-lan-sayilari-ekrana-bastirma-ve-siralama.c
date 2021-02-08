#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int data;
    struct _node * next;
    struct _node * prev;
}node;

typedef struct _l5{
    struct _node * head;
}k;

void initk(k * l5)
{
    l5->head = NULL;
}

int addItem(k * l5, int data)
{
    node * newItem = malloc(sizeof(node));

    if (newItem == NULL)
    {
        return EXIT_FAILURE;
    }

    newItem->data = data;
    newItem->next = NULL;
    newItem->prev = NULL;

    if (l5->head == NULL)
    {
        l5->head = newItem;

        return EXIT_SUCCESS;
    }

    node * iter = l5->head;

    while(iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = newItem;
    newItem->prev = iter;

    return EXIT_SUCCESS;
}

int getSize(k * l5)
{
    node * iter = l5->head;
    int count = 0;

    while(iter != NULL)
    {
        iter = iter->next;
        count++;
    }

    return count;
}

void swapNodes(k * l5, int firstIndex, int secondIndex)
{
    node * iter1 = l5->head;

    while(firstIndex--)
    {
        iter1 = iter1->next;
    }

    node * iter2 = l5->head;

    while(secondIndex--)
    {
        iter2 = iter2->next;
    }

    int temp = iter2->data;

    iter2->data = iter1->data;
    iter1->data = temp;
}

void selectionSort(k * l5)
{
	int i,j;
    for(i = 0; i < getSize(l5) - 1; i++)
    {
        for(j = i + 1; j < getSize(l5); j++)
        {
            node * iter1 = l5->head;
            node * iter2 = l5->head;

            int a = i;
            int c = j;

            while(a--)
            {
                iter1 = iter1->next;
            }
            while(c--)
            {
                iter2 = iter2->next;
            }
            if(iter1->data > iter2->data)
            {
                swapNodes(l5, i, j);
            }
        }
    }
}
void printNodes(k l5)
{
    node * iter = l5.head;

    while(iter->next != NULL)
    {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("%d\n", iter->data);
}

int main()
{
    k l5;
    initk(&l5);

    addItem(&l5, 4);
    addItem(&l5, 2);
    addItem(&l5, 7);
    addItem(&l5, 15);
    addItem(&l5, 26);
    addItem(&l5, 8);
    addItem(&l5, 3);
    addItem(&l5, 5);
    printNodes(l5);
    selectionSort(&l5);
    printNodes(l5);
}
