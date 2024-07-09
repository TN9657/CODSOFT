#include<iostream>
using namespace std;
class task{
    public:
string Task;
int Priority;
task* next;
task(string S,int a){
   Task=S;
   Priority=a;
   next=nullptr;
}
};
void create(task*head){
    string Task_name;
    int Priority;
    cout<<"Enter the Task Name: ";
    cin>>Task_name;
    cout<<"Enter the Priority: "<<endl;
    cout<<"Enter the Priority: ";
    cin>>Priority;
    task* temp=new task(Task_name,Priority);
    if (head==nullptr)
    {
        head=temp;
        return;
    }
    task* temp1=head;
    while (temp1!=nullptr)
    {
        
    }
    
    
}
int main(){


return 0;
}