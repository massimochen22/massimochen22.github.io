#include <stdio.h>
#include <stdlib.h>
struct node { 
  int value; 
  struct node *next; 
}; 

int main(){

  struct node *head=NULL, *tail=NULL, *pnode;
  int i = 1;
  while(1){
    pnode=(struct node *)malloc(sizeof(struct node));
    printf("Input data for node %u : ",i); 
    //scanf("%d", &(pnode->value));
    if(scanf("%d", &(pnode->value)) == EOF) break;

    pnode->next=NULL; /*ensure next pointer of last node is NULL */
    if(head==NULL) head=pnode;
    if(tail!=NULL) tail->next=pnode;
    tail=pnode;
    i++;
  }

  pnode=head;
  printf("\nData entered in the list are: \n");
  while(pnode!=NULL) {
    printf("Data = %u\n", pnode->value);
    pnode=pnode->next;
  }

  struct node *prevNode = NULL;
  struct node *nextNode = NULL;
  while (head!=NULL){
    nextNode = head->next;
    head->next = prevNode;
    prevNode = head;
    head = nextNode;
  }

  head = prevNode;
  pnode=head;
  printf("The list in reverse are : \n");
  while(pnode!=NULL) {
    printf("Data = %u\n", pnode->value);
    pnode=pnode->next;
  }

}