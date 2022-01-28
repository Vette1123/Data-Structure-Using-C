#include <stdio.h>
#include <stdlib.h>

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

void InsertAfter(int data, int afterData)
{
   Node *currentNode = GetNodeByData(afterData);
   if (currentNode == NULL)
   {
       printf("\n%d doesn't exist\n",afterData);
       return;
   }
   else
   {
    Node *newNode = Create(data);
    if(currentNode == tail)
    {
        newNode->Prev = tail;
        currentNode->Next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->Next = currentNode->Next;
        currentNode->Next->Prev = newNode;
        newNode->Prev = currentNode;
        currentNode->Next=newNode;
    }
   }
}
int main()
{
    Add(3);
    Add(5);
    Add(7);
    Add(9);
    Add(11);
    InsertAfter(2,11);
    Display();

}
