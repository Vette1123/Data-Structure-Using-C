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
/*
Node *newHead = NULL, *newTail = NULL;
void Reverse()
{
    if(head == NULL)
        return;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        current->Nex = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
*/

// node reverse only in printing
/*
Node* Reverse(){
  Node *current = tail;
  while(current!=NULL)
  {
      printf("%d \t",current->Data);

      current=current->Prev;
  }

};
*/
// reverse node affecting the source element

void Reverse(){

  Node *current = tail;
  head=tail;
  while(current!=NULL)
  {
      current->Next=current->Prev;
      current=current->Prev;
  }
};



int main()
{
    Add(3);
    Add(5);
    Add(7);
    Add(9);
    Add(11);
    Display();
    printf("\n~~~~~~~~~~~~~~~~~~\n");
    Reverse();
    Display();

    return 0;
}
