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
/*--1------------------------------------------*/
 int create_List(List *L , type x);
/*--2------------------------------------------*/
 int insert_front(List *L ,type x);
/*--3------------------------------------------*/
 int insert_rear(List *L,type x);
/*--4------------------------------------------*/
 int insert_pos(List *L,type x , int pos);
/*--5------------------------------------------*/
int insert_inorder(List* L , type x);
/*--6------------------------------------------*/
 int delete_front(List *L);
/*--7------------------------------------------*/
 int delete_rear(List *L);
/*--8------------------------------------------*/
 int delete_pos(List *L , int pos);
/*--9------------------------------------------*/
 void print(List *L);
/*-10------------------------------------------*/
 void printReverse(List *L);
/*-11------------------------------------------*/
 type print_node(List *L, int pos);
/*-12------------------------------------------*/
 int search_node(List *L, type x);
/*-13------------------------------------------*/
 Node* get_first(List*L);
/*-14------------------------------------------*/
 Node* get_Last(List* L);
/*-15------------------------------------------*/
 int size(List*L);
/*-16------------------------------------------*/ 
void SelectioSort(List*L);
/*---------------------------------------------*/ 
 
////////////////////////////////////////////////////////////////////////////////

int main(){
  
 List L;
 

 create_List(&L, 8);
 insert_inorder(&L, 6);
 insert_inorder(&L, 1);
 insert_inorder(&L, 3);
 insert_inorder(&L, 2);
 insert_inorder(&L, 5);
 insert_inorder(&L, 9);
 insert_inorder(&L, 7);
 insert_inorder(&L, 4);
 
 

 cout<<"List         : ";print(&L);cout<<"\n";
 cout<<"List Reverse : ";printReverse(&L);cout<<"\n\n";
  
  

  cout<<"List         : ";print(&L);cout<<"\n";
 cout<<"List Reverse : ";printReverse(&L);cout<<"\n\n";

 cout<<"Size of List : "<<size(&L)<<"\n\n";

 //cout<<"Sorted       : ";SelectioSort(&L);cout<<"\n\n"; 
  


 cout<<"First : "<<get_first(&L)->data<<"\n";
 cout<<"Last  : "<<get_Last(&L)->data<<"\n\n";

 cout<<"Pos Node     : "<<print_node(&L,0)<<"\n";
 cout<<"Pos Node     : "<<print_node(&L,5)<<"\n";
 cout<<"Pos Node     : "<<print_node(&L,7)<<"\n";

 cout<<search_node(&L,17);
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
  Node*p , *temp ;
  temp=*L;
  p=(Node*)malloc(sizeof(Node));
   if(p==NULL)
   {return 0;}
   p->data=x;
   p->next=temp;
   temp->prev=p;
   p->prev=NULL;
   *L=p;
   return 1;
}

/*=============================================================*/

int insert_rear(List *L,type x){
  Node *p ,*temp ;
  temp=*L;

   while(temp->next!=NULL){
     temp=temp->next;
   }

   p=(Node*)malloc(sizeof(Node));
   if(p==NULL)
   {return 0;}
   p->data=x;
   p->next=NULL;
   temp->next=p;
   p->prev=temp;
  return 1;
}

/*=============================================================*/

int insert_pos(List *L,type x , int pos){
  Node *p , *temp;
  int count = 0;

  p=*L;

  while(p!=NULL){
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
   for (int i = 0 ; i <pos-1 ; i++)
   {p=p->next;}  
   temp->data=x;                         //Storing the data
   temp->next=p->next;                   // link Temp to the rest of the list
   p->next=temp;                         // link the first of list to the second
   temp->prev=p;                         // link temp to first part by prev
   temp->next->prev=temp;                // link the second part by first by prev
   
   return 1;
  }

}

/*=============================================================*/

int insert_inorder(List* L , type x){
   Node* temp = *L;

   Node *p = (Node*)malloc(sizeof(Node));
   if(p==NULL){return 0;}
   
   if(x <= get_first(L)->data)
   {insert_front(L, x);}
   else if(x >= get_Last(L)->data)
   {insert_rear(L, x);}
   else{
      int count = 1; 
       for(int i = 1 ; i < size(L) ; i++){
         if( x >= temp->data && x <= temp->next->data ){
              insert_pos(L, x, count);
             return 1;
         }
         count++;
         temp=temp->next;
        }
      }
      return 1;
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
  Node *p , *temp;
  int count = 0 ;
  p=*L;
  while(p!=NULL){
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
   temp=p->next;
   p->next=temp->next;
   temp->next->prev=p;
   free(temp);
   return 1;
  }
}

/*=============================================================*/

void print(List *L){
   Node* p;
   p=*L;
   while(p!=NULL){
     cout<<p->data<<" ";
     p=p->next;
   }
}

/*=============================================================*/
void printReverse(List *L){
  Node* p = get_Last(L);
  while(p!=NULL){
   cout<<p->data<<" ";
   p=p->prev;
 }
}
/*=============================================================*/
type print_node(List *L,int pos){
  if(pos==0)
  { return get_first(L)->data;}

  else if(pos==size(L))
  {return get_Last(L)->data;}
  
  else if(pos>size(L) || pos<0)
  {
     cout<<"out of position  between ( 0 - "<<size(L)<<" )\n"; 
     return 0;
  }
  else
  {
     Node *p = *L;
   for (int i = 0 ; i < pos-1 ; i++)
       {p=p->next;}  
   return p->data;
  }
  return -1;

}
/*=============================================================*/
  int search_node(List *L , type x){
     Node* temp = *L;
     while(temp!=NULL){
       if(temp->data==x)
       {return 1;}
       temp=temp->next;
     }
     return 0;
  }

/*=============================================================*/
Node* get_Last(List* L){
    Node *p = *L;
    while(p->next!=NULL){
      p=p->next;
    }
  return p;
}
/*=============================================================*/
Node* get_first(List* L){
    Node *p = *L;
    return p;
}
/*=============================================================*/
void SelectioSort(List *L){
  Node* temp = (Node*)malloc(sizeof(Node));

for(int i = 0 ; i<size(L) ; i++){
  Node* first = *L;
  Node* second = first->next;
  for(int j = 1 ; j<size(L) ; j++ ){
    if(first->data<second->data){
       temp->data=second->data;
       second->data=first->data;
       first->data=temp->data;
    }
    first=first->next;
    second=second->next;
  }
}   
   print(L);
}
/*=============================================================*/
int size(List*L){
   Node *p ;
   int count = 0 ;
   p=*L;
   while(p!=NULL){
    p=p->next;
    count++;
  }
  return count;
}
/*=============================================================*/



