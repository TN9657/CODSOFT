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
    cout<<"Enter the Priority: ";
    cin>>Priority;
    task* temp=new task(Task_name,Priority);
    if (head==nullptr)
    {
        head=temp;
        return;
    }
    task* temp1=head;
    // task*temp2;
    while (temp1!=nullptr)
    {
        if (temp1->Priority<=temp->Priority)
        {
            // temp2=temp1;
            temp1->next=temp;
            temp->next=temp1->next;
            return;
        }
        else if (temp1->Priority>temp->Priority){
             temp->next=temp1;
        }
        else{
        temp1=temp1->next;
        }
    }
    
    
}
void Display(task*head){
    if (head==nullptr)
    {
        cout<<"The Stack is Empty"<<endl;
    }
    task*temp=head;
    while (temp!=nullptr)
    {   cout<<"____________________________________________________"<<endl;
        cout<<head->Priority<<"|\t"<<head->Task<<endl;
        cout<<"----------------------------------------------------"<<endl;
        temp=temp->next;
    }
    
}

void del(task*head,string Name_task){
    if (head==nullptr)
    {
        cout<<"The Stack is Empty"<<endl;
    }
    task*tamp=head;
    task*delnode=nullptr;
     int find=0;
     while (tamp!=nullptr && tamp->Task==Name_task)
     {
        tamp=tamp->next;
          if (tamp->Task==Name_task)
          {
            find=1;
            return;

          }
          
        }
           if (find==1)
           {
             delnode=tamp;
            tamp->next=tamp->next->next;
            delete delnode;
           }
           else{
            cout<<"The Task is not in the Stack"<<endl;
           }
           
           
     }
        
int main(){
    task*head=nullptr;
  char C;
 do
 {
    int choice;
cout<<"1.Create a Task\n2.Display Task's\n3.Delete Task\nEnter the Choice: ";
  cin>>choice;

 switch (choice)
{
   case 1:
       create(head);
       break;
    case 2:
        Display(head);
        break;

    case 3:
    string name;
        cout<<"Enter the Task Name: ";
        cin>>name;
        del(head,name);
        break;
    default:
    cout<<"Invalid Choice"<<endl;
  }
  cout<<"Do You Want to add any Other Task(Y/N): ";
  cin>>C;

 } while (C=='Y');
return 0;
}