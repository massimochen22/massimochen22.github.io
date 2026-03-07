#include <stdio.h>
#include <stdlib.h>
struct node { 
  int value; 
  struct node *next; 
}; 
int main(){
  struct node *head=NULL, *tail=NULL, *pnode;
  int i = 1, count1 = 0;
  // In this while loop it gets the node from the user until it presses ctr+d
  while(1){
    pnode=(struct node *)malloc(sizeof(struct node));
    if(scanf("%d", &(pnode->value)) == EOF) break;
    pnode->next=NULL; /*ensure next pointer of last node is NULL */
    if(head==NULL) head=pnode;
    if(tail!=NULL) tail->next=pnode;
    tail=pnode;
    i++;
    count1++;
  }
  struct node *temp1=NULL;
  //bubble sort them
  int pass, count2;
  for ( pass = 0; pass < count1-1; pass++){
    pnode = head;
    for ( count2 = 0; count2 < count1-pass- 1; count2++ ){
      temp1 = pnode->next;
      if(temp1 == NULL) break;
      if ((pnode->value) > (temp1->value)){
        pnode->next=temp1->next;
        temp1->next=head;
        head = temp1;
      }
      else{
        pnode=pnode->next;
      }
    }
  }
  //printing the sorted linked list
  pnode=head;
  while(pnode!=NULL) {
    count1++;
    printf("%u\n", pnode->value);
    pnode=pnode->next;
  }
  
}