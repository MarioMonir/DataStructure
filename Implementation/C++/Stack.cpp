//Stack
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int type ;

typedef struct {
  type* content;
  int size;
  int top;
}Stack_t;

/*Fuhnctions*/
int createStack(Stack_t* s, int size);
int push(Stack_t* s,type x);
int pop(Stack_t* s);
void printStack(Stack_t* s);
int IsEmpty(Stack_t s);
int IsFull(Stack_t s);

////////////////////////////////////////////////////////////////////////////////

int main(){
   Stack_t s;

   createStack(&s, 5);

   cout<<"\n";

   push(&s, 1);
   cout<<"top  :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n";

   push(&s, 2);
   cout<<"top :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n";

   push(&s, 3);  
   cout<<"top :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n";

   push(&s, 4);
   cout<<"top :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n"; 

   push(&s, 5);
   cout<<"top :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n";  

   cout<<"\n";

   pop(&s);
  
   cout<<"top :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n";  

   push(&s, 6);
   cout<<"top :"<<s.top<<"\n";
   cout<<"data :"<<s.content[s.top]<<"\n\n";  

  printStack(&s);


  return 0; 
}
////////////////////////////////////////////////////////////////////////////////

/*=============================================================*/

int createStack(Stack_t* s, int size){
   s->content=(type*)malloc(sizeof(type)*size);
   if(s->content==NULL)
   {return 0;}
   s->size  = size;
   s->top   = -1;
  cout<<"Stack Created \n";
   return 1;
}

/*=============================================================*/

int push(Stack_t* s , type x){

   if(!IsFull(*s))
   {      
   s->top++;
   s->content[s->top]=x;  cout<<"success Enqueue\n";
   return 1;
   }else{cout<<"stack is full \n" ; return 0;}
   
}

/*=============================================================*/

int pop(Stack_t* s) 
{
   if(IsEmpty(*s))
   {return 0 ; cout<<"Queue is empty \n";}
   s->top--; 
   cout<<"pop success \n";
   return 1;
}

/*=============================================================*/

int IsEmpty(Stack_t s){return s.top<=-1;}

/*=============================================================*/

int IsFull(Stack_t s){return s.top>s.size-1;}

/*=============================================================*/


void printStack(Stack_t* s){
    if(s->top==-1)
    {cout<<"The Stack is Empty\n";}
    else
    { cout<<"content : ";
      for(int i = s->top ; i>=0;  i--){
        cout<<s->content[i]<<" ";
      }
    }
}