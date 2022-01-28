#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};
Node *head = NULL, *tail = NULL;

Node* Create(int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    return newNode;
}

void Add(int data)
{
    Node *newNode = Create(data);

    if(head == NULL) // empty LinkedList
    {
        head = tail = newNode;
    }
    else
    {
        newNode->Prev = tail;
        tail->Next = newNode;
        tail = newNode;

    }

}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d \t", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}
int GetDataByIndex(int index)
{
    Node *current = head;
    int count =0;
    while(current != NULL)
    {
        if(count == index)
            return current->Data;
            count++;
        current = current->Next;
    }
    assert(0);
    //printf("\nthis index doesn't exist\n");
}

int main()
{
    Add(3);
    Add(5);
    Add(7);
    Add(9);
    Add(11);
    Display();
    printf("\nThe Data at this index = %d\n",GetDataByIndex(5));
}
