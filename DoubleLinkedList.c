#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Node struct node
#define Mall(size) malloc(sizeof(size))

struct node{
  Node* prev;
  int data;
  Node *next;
};
void print_Data(Node *head)
{
  if(head == NULL)
       printf("Linked list is empty");
  Node *ptr = NULL;
  ptr = head;
  while (ptr != NULL){
    printf("%d\n",ptr->data);
    ptr = ptr->next;
  }
}
int count_of_nodes(Node *head)
{
  int count = 0;
  if (head == NULL)
      printf("Linked List is empty");
  Node *temp = NULL;
  temp = head;
  while (temp != NULL)
  {
      count++;
      temp = temp->next;
  }
  printf("Numero di nodi: %d \n", count);

  return count;
}

Node* add_AtBeg(Node* head,int data){
  Node* temp = Mall(Node);
  temp->prev=NULL;
  temp->data = data;
  temp->next = NULL;
  temp->next = head;
  head->prev = temp;
  head = temp;
  return head;
}
Node* add_ToEmpty(Node* head, int data){
  Node* temp = Mall(Node);
  temp->prev = NULL;
  temp->data = data;
  temp->next = NULL;
  head = temp;
  return head;
}
Node* add_AtEnd(Node* head,int data){
  Node* temp , *tp;
  temp = Mall(Node);
  temp->prev=NULL;
  temp->data = data;
  temp->next = NULL;
  tp = head;
  while (tp->next != NULL)
  {
    tp = tp->next;
  }
  tp->next = temp;
  temp->prev = tp;
  return head;
}
Node* Del_First(Node* head){
  Node* temp = head;
  head = head->next;
  free(temp);
  temp=NULL;
  head->prev = NULL;
  return head;
}
Node* Del_Last(Node* head){
  Node* temp = head;
  Node* temp2;
  while(temp->next!= NULL){
    temp = temp->next;
  }
  temp2 = temp ->prev; 
  temp2 -> next = NULL;
  free(temp);  
  return head;
}
int random_Gen(int d) 
{
  srand(time(NULL));
  int x = 0, length = 0;
  x = (rand() % d); 

  return x;
}
Node* get_Tail(Node *head)
{
  Node *curr = head;
  Node *lastnode = NULL;

  while (curr)
  {
    lastnode = curr;
    curr = curr->next;
  }
  return lastnode;
}

Node* Shuffling(Node* head)
{
  int length = count_of_nodes(head);
  int rand[200]; 
  Node *current = head;
  Node *temp = NULL;
  Node *temp2 = head;
  int index = 0;
  int counter = 0;

  for (int i = length; i > 0; i--)
  {
    temp = get_Tail(current);
    index = random_Gen(i); 
    for (int j = 0; j < index; j++)
    {
      current = current->next;
    }
    if (current->prev == NULL)
    {
      current->next->prev = NULL;
    }
    else
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
    }
    if (current->next != NULL)
    {
      current->next = NULL;
      current->prev = temp;
      temp->next = current;
    }

    for (int j = 0; j < length - 1; j++)
    {
      if (current->prev == NULL)
      {
        break;
      }
      current = current->prev;
    }
  }
  return current;
}
int main(){
  Node* head = NULL;
  Node* ptr;
  head = add_ToEmpty(head,42);
  head = add_AtBeg(head,63);
  head = add_AtEnd(head,17);
  head = add_AtEnd(head,61);
  head = add_AtEnd(head,92);
  head = add_AtEnd(head,24);
  head = Shuffling(head);
  // head = Del_First(head);
  // head = Del_Last(head);
  ptr = head;
  print_Data(head);
  return 0;
}