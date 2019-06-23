//double Linked List 

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int type ;

typedef struct node {
 type data;
 struct node* next;
 struct node* prev;
}Node; 

typedef Node* List;

/*Functions*/
int create_List(List *L , type x);
int insert_front(List *L ,type x);
int insert_rear(List *L,type x);
int insert_pos(List *L,type x , int pos);
int delete_front(List *L);
int delete_rear(List *L);
int delete_pos(List *L , int pos);
int Is_Last(List *L);
void print(List *L);

////////////////////////////////////////////////////////////////////////////////

int main(){
  
 List L;

 create_List(&L, 1);
 
 insert_rear(&L, 2);
 insert_rear(&L, 3);
 insert_rear(&L, 4);
 insert_front(&L,8);
 insert_rear(&L, 5); 

 print(&L);
 cout<<"\n";

 delete_front(&L);

 print(&L);
 cout<<"\n";

 insert_pos(&L, 6 , 0);

 print(&L);
 cout<<"\n";
 insert_pos(&L, 5 , 1);

 print(&L);
 cout<<"\n";

 delete_pos(&L,2);
 delete_rear(&L);

 print(&L);
 cout<<"\n";

  return 0; 
}
////////////////////////////////////////////////////////////////////////////////

/*=============================================================*/

int create_List(List *L , type x){
   Node* p;
   p=(Node*)malloc(sizeof(Node));
   if(p==NULL)
   {return 0;}
   p->data=x;
   p->next=NULL;
   p->prev=NULL;
   *L = p;
  return 1;
}

/*=============================================================*/

int insert_front(List *L ,type x){
  Node*p , *Q ;
  Q=*L;
  p=(Node*)malloc(sizeof(Node));
   if(p==NULL)
   {return 0;}
   p->data=x;
   p->next=Q;
   Q->prev=p;
   p->prev=NULL;
   *L=p;
   return 1;
}

/*=============================================================*/

int insert_rear(List *L,type x){
  Node *p ,*Q ;
  Q=*L;

   while(Q->next!=NULL){
     Q=Q->next;
   }

   p=(Node*)malloc(sizeof(Node));
   if(p==NULL)
   {return 0;}
   p->data=x;
   p->next=NULL;
   Q->next=p;
   p->prev=Q;
  return 1;
}

/*=============================================================*/

int insert_pos(List *L,type x , int pos){
  Node *p , *temp;
  int count = 0;

  p=*L;

  while(p->next!=NULL){
    count++;
    p=p->next;
  }
  if(pos==0)
  {int y = insert_front(L,x);return y;}

  else if(pos==count)
  {int y = insert_rear(L, x);return y;}
  
  else if(pos>count || pos<0)
  {
     cout<<"out of position  between ( 0 - "<<count<<" )\n"; 
     return 0;
  }
  else
  {
   temp=(Node*)malloc(sizeof(Node));
   if(temp==NULL)
   {return 0;}
   p=*L;
   for (int i = 0 ; i < pos-1 ; i++)
   {p=p->next;}
   temp->data=x;
   temp->next=p->next;
   p->next=temp;
   //p->prev=Q;
   //p->next->prev=p;
   return 1;
  }

}

/*=============================================================*/

int delete_front(List *L){
  Node* p;
  p=*L;
  p->next->prev=NULL;
  *L=p->next;
  free(p);
  return 1;
}

/*=============================================================*/

int delete_rear(List *L){
Node *p1 , *p2 ;
p1=*L;
p2=p1->next;
while(p2->next!=NULL){
  p1=p1->next;
  p2=p2->next;
}
free(p2);
p1->next=NULL;
return 1;
}

/*=============================================================*/

int delete_pos(List *L , int pos){
  Node *p , *Q;
  int count = 0 ;

  p=*L;

  while(p->next!=NULL){
    p=p->next;
    count++;
  }

   
  if(pos==0)
  {int y = delete_front(L);return y;}

  else if(pos==count)
  {int y = delete_rear(L);return y;}
  
  else if(pos>count || pos<0)
  {
     cout<<"out of position  between ( 0 - "<<count<<" )\n"; 
     return 0;
  }
  else
  {
   p=*L;
   for (int i = 0 ; i < pos-1 ; i++){
     p=p->next;
   }
   Q=p->next;
   p->next=Q->next;
   Q->next->prev=p;
   free(Q);
   return 1;
  }
}

/*=============================================================*/

int Is_Last(List *L){
     Node *p;
     p=*L;
     return p==NULL;
}

/*=============================================================*/

void print(List *L){
   Node* p;
   p=*L;
   while(p->next!=NULL){
     cout<<p->data<<" ";
     p=p->next;
   }
}

/*=============================================================*/