#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>

using namespace std;


//Convert infix to postfix
string postfixer(string infix);

//Evaluate Expression to it's result
int eval(string postfix);

//convert + and - to actual operators and calcualte operations
int calc(char postfixchar , int operand1 , int operand2);

/*=============================================================================*/

/*=============================================================================*/

////////////////////////////////////////////////////////////////////////////////
int main(){

//String in Infix Form
string infix = "3+2-4+1" ;
cout<<"Infix   : "<<infix<<"\n";

//Convert to Postfix and print it 
///////////////////////////////////////////////
 string postfix = postfixer(infix);          //
  cout<<"Postfix : ";                        //
   cout<<postfix<<"\n";                      //
///////////////////////////////////////////////


///////////////////////////////////////////////
                                             //
cout<<eval(postfix)<<"\n";                   //
                                             //
///////////////////////////////////////////////



 
}
////////////////////////////////////////////////////////////////////////////////

/*=============================================================================*/


string postfixer( string infix){

  stack<char> myStack;


  char postfix[infix.length()]; 
  int count = 0 ;
  for(int i = 0 ; i <= infix.length(); i++){


     if ( infix[i] == '+' || infix[i] == '-') 
       {
         if(myStack.empty())
         {
           myStack.push(infix[i]);
         }
         else
         {
           postfix[count] = myStack.top();
           myStack.pop();
           myStack.push(infix[i]);
           count++;
         }
      }
    else if (count==(infix.length()-1))
       {
        postfix[count]=myStack.top();
        count++;
       }

     else 
       {
         postfix[count]=infix[i];
         count++;
        
       }
      
  }
   
   //Debugging code//
    /*
       cout<<"infix\n";    
       for(int i = 0 ; i <= infix.length() ; i++){
        cout<<infix[i];
       }
        cout<<"\n\n";
     
        cout<<"postfix\n";
       for(int i = 0 ; i <= infix.length() ; i++){
         cout<<postfix[i];
       }
       cout<<"\n";
    */

   
   string post = postfix;
    return post;
}

/*=============================================================================*/
 
 int eval(string postfix){
  
  stack<int> evStack;
  
  cout<<"\n\n"; 
  cout<<"is the stack empty"<<evStack.empty()<<endl;
  
  for(int i = 0 ; i<postfix.length() ; i++){
        
         cout<<"char "<<postfix[i]<<endl;

          //if postfix[i] is operator 
         if(postfix[i]=='+' || postfix[i]=='-')
         {
             char operand2 = evStack.top();
             evStack.pop();
             char operand1 = evStack.top();
             evStack.pop();
             int result=calc(postfix[i],(int)operand1,(int)operand2);
             evStack.push((int)result);
         }
        

         // postfix[i] is number
         else //if(postfix[i] >='0' && postfix[i]<='9')
         {
           evStack.push((int)postfix[i]);
         }
         cout<<"top of stack  : "<<evStack.top()<<"\n";

     }    
         
      /*
     for(int i = 0 ; i < postfix.length(); i++){
       if(postfix[i]!='+' && postfix[i] !='-' )
       {
       evStack.push((int)(postfix[i]-'0'));
       cout<<"top of stack "<<evStack.top()<<"\n\n";
       }
       
     }
 */
   

  return (int)evStack.top();
 }

/*=============================================================================*/

int calc(char postfixchar , int operand1 , int operand2) {

   if(postfixchar=='+'){
      return ( operand1 + operand2 );
   } 
   else if (postfixchar=='-'){
      return ( operand1-operand2 );
   }
    return 0;
}
/*=============================================================================*/