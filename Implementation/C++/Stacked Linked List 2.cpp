//Stacked Linked List 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef  int  type;

typedef struct node{
 type data ;
 struct node* next;
}Node;

typedef struct {
  Node*top;

}Stack_L;

int createStack(Stack_L *S);
int push(Stack_L *S, type x);
int pop(Stack_L *S);
int IsEmpty(Stack_L *S);
void print(Stack_L *S);
/////////////////////////////////
int main(){
 
Stack_L S;

push(&S,1);
push(&S,2);
push(&S,3);
push(&S,4);
print(&S);
pop(&S);
push(&S, 5);
print(&S);
}
////////////////////////////////

/*=================================================================*/

int createStack(Stack_L *S){
    S->top=NULL;
    return 1;
}

/*=================================================================*/

int push(Stack_L *S , type x){
    Node* node;
    node=(Node*)malloc(sizeof(Node));
    if(node==NULL)
    {return 0;}

    //Stack is Empty
    if(S->top==NULL)
    {
     node->next=NULL;
     S->top=node;
    }
    //add to the stack
    else
    {
     node->next = S->top;
     S->top=node; 
    }
    node->data=x;
    return 1;
}

/*================================================================*/

 int pop(Stack_L *S){

    if(S->top==NULL)
    {
      cout<<"Stack is empty \n";return 0;
    }
    Node* temp;
    temp=S->top;
    S->top=temp->next;
    free(temp);
    return 1;
 }

 /*================================================================*/

 int IsEmpty(Stack_L *S){
   return ( S->top==NULL );
 }

  /*================================================================*/

  void print(Stack_L *S){
    node *temp = S->top;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<"\n";
  }

  /*================================================================*/