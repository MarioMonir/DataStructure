//Queued Linked List 
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
  Node*front;
  Node*rear;
}Queue_L;

int createQueue(Queue_L* Q);
int Enqueue(Queue_L *Q , type x);
int Dequeue(Queue_L* Q);
int IsEmpty(Queue_L *Q);
void print(Queue_L *Q);
/////////////////////////////////
int main(){
 
 Queue_L Q;

 createQueue(&Q);
 Enqueue(&Q,1);
 Enqueue(&Q,2);
 Enqueue(&Q,3);
 Enqueue(&Q,4);
 Dequeue(&Q);
 print(&Q);
 cout<<"\n";
 Enqueue(&Q,5);
 print(&Q);
}
////////////////////////////////

/*=================================================================*/

int createQueue(Queue_L* Q){
    Q->front=NULL;
    Q->rear=NULL;
    return 1;
}

/*=================================================================*/

int Enqueue(Queue_L *Q , type x){
    Node* node;
    node=(Node*)malloc(sizeof(Node));
    if(node==NULL)
    {return 0;} 

    //if isEmpty
    if(Q->front==NULL && Q->rear==NULL){
     Q->front=node;
     Q->rear=node;
    }

    //add to the queue
    else
    {
      Q->rear->next=node;
    }

    Q->rear=node;
    node->data=x;
    node->next=NULL;
    return 1;
}

/*================================================================*/

 int Dequeue(Queue_L* Q ){

    if(Q->front==NULL)
    {
      cout<<"queue is empty \n";return 0;
    }

    Node* temp;
    temp=Q->front;
    Q->front=temp->next;
    free(temp);

    // if last node 
    if(Q->front==NULL){
      Q->rear=Q->front; // queue is empty now 
    }
   
    return 1;
 }

 /*================================================================*/

 int IsEmpty(Queue_L *Q){
   return ( Q->front==NULL && Q->rear==NULL );
 }

  /*================================================================*/

  void print(Queue_L *Q){
    Node* temp = Q->front;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  }

  /*================================================================*/