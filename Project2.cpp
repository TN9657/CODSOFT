/*
Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
*/

#include<iostream>
#include<math.h>
using namespace std;
int main(){
int Num1,Num2;
char C;
cout<<"Enter the First Number: ";
cin>>Num1;
cout<<"Enter the Second Number: ";
cin>>Num2;
 char S;
do
{
cout<<"Enter the Operation you Want to Perform: ";
cin>>C;
switch (C)
{
case '+':
        cout<<Num1<<" + "<<Num2<<" = "<<(Num1+Num2)<<endl;
    break;
case '-':
        cout<<Num1<<" - "<<Num2<<" = "<<(Num1-Num2)<<endl;
    break;
case '*':
        cout<<Num1<<" * "<<Num2<<" = "<<(Num1*Num2)<<endl;
    break;
case '/':
        if (Num1==0 || Num2==0)
        {
            cout<<"Cannot Divide by Zero"<<endl;
        }
        
        cout<<Num1<<" / "<<Num2<<" = "<<(Num1/Num2)<<endl;
    break;
case '^':
        cout<<Num1<<" ^ "<<Num2<<" = "<<pow(Num1,Num2)<<endl;
    break;

default:
cout<<"You are Enter wrong opeartion\nTry again...."<<endl;
    break;
}
 cout<<"Do you want to perform any operation(Y/N): ";
 cin>>S;
    }while (S =='Y');
    
return 0;
}
