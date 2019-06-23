//Queue
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int type ;

typedef struct {
  type* content;
  //type data;
  int size;
  int count;
  int front;
  int rear;

}Queue_t;

/*Fuhnctions*/
//create - enqueue - dequeue - isEmpty - isfull - print - print reverse - destroy - size
int createQueue(Queue_t* q, int size);
int Enqueue(Queue_t* q , type x);
int Dequeue(Queue_t* q);
void printQueue(Queue_t* q);
int IsEmpty(Queue_t q);
int IsFull(Queue_t q);
////////////////////////////////////////////////////////////////////////////////
int main(){
   Queue_t q;
   
   //debug code 
   createQueue(&q, 5);
   cout<<"fornt = "<<q.front<<endl;
   cout<<"rear  = "<<q.rear<<endl;
   cout<<"count = "<<q.count<<endl;
   cout<<"conten  "<<q.content[q.rear]<<"\n";
   cout<<"is Empty "<<IsEmpty(q)<<"\n\n";

   Enqueue(&q, 1);
   Enqueue(&q, 2);
   Enqueue(&q, 3);
   Enqueue(&q, 4);
   Enqueue(&q, 5);

   cout<<"fornt = "<<q.front<<endl;
   cout<<"rear  = "<<q.rear<<endl;
   cout<<"count = "<<q.count<<endl;
   cout<<"conten front  "<<q.content[q.front]<<"\n";
   cout<<"conten rear   "<<q.content[q.rear]<<"\n";
   cout<<"is Full "<<IsFull(q)<<"\n\n";


   printQueue(&q);
   cout<<"\n";

   Dequeue(&q);
   cout<<"fornt = "<<q.front<<endl;
   cout<<"rear  = "<<q.rear<<endl;
   cout<<"count = "<<q.count<<endl;
   cout<<"conten front  "<<q.content[q.front]<<"\n";
   cout<<"conten rear   "<<q.content[q.rear]<<"\n\n";
  
   printQueue(&q);
   cout<<"\n";

   Enqueue(&q, 6);

   printQueue(&q);
   Dequeue(&q); 
   
   Enqueue(&q, 7);
   cout<<"fornt = "<<q.front<<endl;
   cout<<"rear  = "<<q.rear<<endl;
   cout<<"count = "<<q.count<<endl;
   cout<<"conten front  "<<q.content[q.front]<<"\n";
   cout<<"conten rear   "<<q.content[q.rear]<<"\n\n";
  
   printQueue(&q);

  return 0; 
}
////////////////////////////////////////////////////////////////////////////////


int createQueue(Queue_t* q, int size){
   
   q->content=(type*)malloc(sizeof(type)*size);
   if(q->content==NULL)
   {return 0;}
   q->size  = size;
   q->count =  0;
   q->front = -1;
   q->rear  = -1;
   return 1;
}

int Enqueue(Queue_t* q , type x){

   if(!IsFull(*q)){
     if(IsEmpty(*q))  {q->front++;}
   q->count++;       
   q->rear++;
   q->rear%=q->size;
   q->content[q->rear]=x;  cout<<"success Enqueue\n";
   return 1;
   }
}

int Dequeue(Queue_t* q) 
{
   if(IsEmpty(*q))
   {return 0 ; cout<<"Queue is empty \n";}
   q->front++;
   q->front%=q->size;
   q->count--;  cout<<"Dequeue success \n";
   return 1;
}


int IsEmpty(Queue_t q){return q.count<=0;}

int IsFull(Queue_t q){return q.count>=q.size;}


void printQueue(Queue_t* q){
    if(IsEmpty(*q))
    {cout<<"The Queue is Empty\n";}
    else
    {
      int x = q->front;
      for(int i = 0 ; i<q->count;  i++){
        cout<<q->content[x]<<" ";
        x++;x%=q->size;

      }
    }
}