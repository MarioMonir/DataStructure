#include <iostream>
using namespace std;

typedef int type;

typedef  struct node{
 type data ;
 struct node* next;
}Node;

typedef node* Stack; 

/*Functions*/

int push(Stack *s, type x);
int pop(Stack *s);
void print(Stack *s);
int IsEmpty(Stack *s);


int main(){

Stack s;

push(&s, 1);
push(&s, 2);
push(&s, 3);
push(&s, 4);
pop(&s);
push(&s ,5);



print(&s);

  return 0;
}
/*================================================*/
int push(Stack *s, type x){
  
  Node *p , *q; 
  p=*s;
  q=(Node*)malloc(sizeof(Node));
  if(q!=NULL){
    q->data=x;
    q->next=p;
    *s=q;
    return 1;
  }
 return 0;
}
/*================================================*/
int pop(Stack *s){
  Node *p;
  p=*s;
  if(p->next==NULL)
  {cout<<"the stack is empty\n";return 0;}
  *s=p->next;
  free(p);
  return 1;
}
/*================================================*/
void print(Stack *s){
 Node *p;
 p=*s;
 if(p==NULL){cout<<"The stack is empty\n";}
 else{
   while(p!=NULL){
     cout<<p->data<<" ";
     p=p->next;
     }
 }
}
/*================================================*/
int IsEmpty(Stack s){ 
  Node* p;
  p=s;
  return(p==NULL);
   }
/*================================================*/