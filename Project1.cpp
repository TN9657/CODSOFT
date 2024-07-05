/* Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number
*/

#include<iostream>
#include<random>
using namespace std;
int main(){
int size;
cout<<"Enter the size of the Numbers That you want to play: ";
cin>>size;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> distribution(0, size-1);
int Number=distribution(gen);

int find=1;
int count=0;
do{
    int val;
    cout<<"Enter the Number: ";
    cin>>val;
    if (val==Number)
    {
        cout<<"You Win"<<endl;
        cout<<"You can find the Number in "<<count<<" itteration....."<<endl;
        find=0;
        
    }
    else if(val>Number){
        cout<<"Your Value you entered is Greater than the Number"<<endl;
        cout<<"Plz try Again"<<endl;
        find=1;
        count++;
    }
    else {
        cout<<"Your Value you entered is Smaller than the Number"<<endl;
        cout<<"Plz try Again"<<endl;
        find=1;
        count++;
    }
 }while (find!=0);
return 0;
}