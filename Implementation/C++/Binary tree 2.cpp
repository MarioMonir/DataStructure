#include<iostream>
#include<stdlib.h>

using namespace std;

/*=============================================================================*/
/*Structs & DataTypes*/

typedef int type;                         // Type of Data Element 

//Node of the tree
typedef struct tnode 
{  
  type data ;                             // data of the node       
  struct tnode* left;                     // left of the node
  struct tnode* right;                    //right of the node
}Tnode;

typedef struct tnode* Btree; //pointer point on type of tnode

/*=============================================================================*/
/*Functions*/

//Sort in preorder
void preorder(Btree T);

//Sort in inorder
void inorder(Btree T);

//Sort in postorder
void postorder(Btree T);

//Insert Binary Search
Tnode* insert_bs(Btree T , type x);

//Insert Left
Tnode* insert_left(Btree T , type x);

//Insert Right
Tnode* insert_right(Btree T , type x);

//find minumum Node value
type find_min(Btree T);

//find maximum Node value
type find_max(Btree T);

//find by binary Search
Tnode* find_bs(Btree T , type x);

//Heght of the Tree
int height(Btree T);

/*=============================================================================*/

////////////////////////////////////////////////////////////////////////////////
int main(){


Btree T;
T=NULL;
Tnode* temp;
temp=T;

T=insert_bs(T, 5);
T=insert_bs(T, 3);
T=insert_bs(T, 8);
T=insert_bs(T, 7);
T=insert_bs(T, 9);
T=insert_bs(T, 4);
T=insert_bs(T, 2);

cout<<"inorder   :  ";
inorder(T);
cout<<"\n\n";
cout<<"preorder  :  ";
preorder(T);
cout<<"\n\n";
cout<<"postorder :  ";
postorder(T);
cout<<"\n\n";
cout<<"Maximum   :  "<<(find_max(T));
cout<<"\n\n";
cout<<"minimum   :  "<<(find_min(T));
  return 0;
}
////////////////////////////////////////////////////////////////////////////////

/*=============================================================================*/

void preorder(Btree T){
   if(T!=NULL){
   cout<<T->data;
   preorder(T->left);
   preorder(T->right);
   }
}

/*=============================================================================*/

void inorder(Btree T){
    if(T!=NULL){
     inorder(T->left);
     cout<<T->data;
     inorder(T->right);
    }
}

/*=============================================================================*/

  void postorder(Btree T){
      if(T!=NULL){
   postorder(T->left);
   postorder(T->right);
   cout<<T->data;
      }
  }
  
/*=============================================================================*/
Tnode* insert_bs(Btree T , type x){

 Tnode* tmp;
 tmp = (Tnode*)malloc(sizeof(Tnode));
  if (tmp == NULL)
  {return tmp;}
  else
  {
    tmp->data = x;
    tmp->left = tmp->right = NULL;
  }
  if (T == NULL)
  {T=tmp;}
  else if (x < T->data) {T->left = insert_bs(T->left,x);}
  else if (x > T->data) {T->right = insert_bs(T->right,x);}
 
 return(T);
}

/*=============================================================================*/

Tnode* insert_left(Btree T , type x){
  Tnode* tmp;
  tmp = (Tnode*)malloc(sizeof(Tnode));
  if(tmp==NULL){
    return T;
  }
  tmp->left=tmp->right=NULL;              //because it will be last child 
  tmp->data=x;

  if(T==NULL){                            //tree has no nodes (First Node)
    T=tmp;
  }
  else if(T->left==NULL){                 //reach to the last one
   T->left=tmp;
  }
  else
  {T->left=insert_left(T->left,x);}       //recursive call
    return T;
}
/*=============================================================================*/

Tnode* insert_right(Btree T , type x){
  Tnode* tmp;
  tmp = (Tnode*)malloc(sizeof(Tnode));
  if(tmp!=NULL){
    return T;
  }
  tmp->left=tmp->right=NULL;             //because it will be last child 
  tmp->data=x;

  if(T==NULL){                           //tree has no nodes (First Node)
    T=tmp; 
  }
  else if(T->right==NULL){               //reach to the last one
   T->left=tmp;
  }
  else
  {T->right=insert_right(T->right,x);}   //recursive call
    return T;
}
/*=============================================================================*/

type find_min(Btree T){
 if(T==NULL)
 {return 0000;}
 while(T->left!=NULL){
   T=T->left;
 }
 return T->data;
}
/*=============================================================================*/
type find_max(Btree T){
  if(T==NULL)
  {return 0000;}
 while(T->right!=NULL){
   T=T->right;
 }
 return T->data;
}
/*=============================================================================*/
Tnode* find_bs(Btree T , type x){
  Tnode*temp=T;
  if(temp==NULL){return temp;}
  if(temp->data==x){return temp;}
  else if(x>temp->data){return find_bs(temp->right , x);}   // go Right
  else if(x<temp->data){return find_bs(temp->left , x);}    // go Left
  return temp;
}
/*=============================================================================*/
int height(Btree T)
{
 int h, max;
 if (T == NULL)
 {return -1;}
 else
 {
  h = height(T->left);
  max = height(T->right);
   if (h > max)
   {max = h;}
   return(max+1);
  }
} 
/*=============================================================================*/

