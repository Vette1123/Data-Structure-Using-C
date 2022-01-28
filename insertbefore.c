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

void InsertBefore(int data, int beforeData)
{
   Node *currentNode = GetNodeByData(beforeData);
   if (currentNode == NULL)
   {
       printf("\n%d doesn't exist\n",beforeData);
       return;
   }
   else
   {
    Node *newNode = Create(data);
    if(head == NULL) // empty LinkedList
    {
        head = tail = newNode;
    }
    else
    {
        if(currentNode == head)
        {
            head = newNode;
        }
        else
        {
            newNode->Prev = currentNode->Prev;
            currentNode->Prev->Next = newNode;
        }
            newNode->Next = currentNode;
            currentNode->Prev= newNode;
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
    InsertBefore(1,11);
    Display();

}
