/*
TIC-TAC-TOE GAME
Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.
*/
#include<iostream>
using namespace std;

class TikTakToi{
    public:
    char A[9];

    void Assign(char A[],int itteration,int pos){
    if(itteration%2==0){
        A[pos]='X';
    }
    else{
        A[pos]='O';
    }
}
void print_table(char A[]){
char B[3][3];
int size=0;
for (int i = 0; i < 3; i++)
 {
    for (int  j = 0; j < 3; j++)
    {
       B[i][j]=A[size];
       size++;
    }
    
 }

 for (int i = 0; i < 3; i++)
 {
    for (int  j = 0; j < 3; j++)
    {
      cout<< B[i][j]<<"  |  ";
       
    }
    cout<<"\n----------------"<<endl;
 }

}

void check(char A[]){
    if (A[1]==A[4] && A[4]==A[7])
    {
        cout<<A[1]<<" Is Winner"<<endl;
    }
    else if(A[2]==A[5] && A[5]==A[8]){
        cout<<A[2]<<" Is Winner"<<endl;
    }
   else if(A[3]==A[6]&& A[6]==A[9]){
    cout<<A[3]<<" Is Winner"<<endl;
   }   
   else if(A[1]==A[2] && A[2]==A[3]){
    cout<<A[1]<<" Is Winner"<<endl;
    }
    else if(A[4]==A[5] && A[5]==A[6]){
        cout<<A[4]<<" Is Winner"<<endl;
        }
        else if(A[7]==A[8] && A[8]==A[9]){
            cout<<A[7]<<" Is Winner"<<endl;
            }
            else if(A[1]==A[5] && A[5]==A[9]){
                cout<<A[1]<<" Is Winner"<<endl;
                }
                else if(A[3]==A[5] && A[5]==A[7]){
                    cout<<A[2]<<" Is Winner"<<endl;
                    }
                    else{
                    cout<<"Draw......."<<endl;
                    }
}
};

int main(){
    TikTakToi Obj;
 int itteration=0;
 int pos;
 char A[9];

for (int i = 0; i < 9; i++)
{
    A[i]=' ';
}


 
 for (int i = 0; i < 9; i++)
 {
    cout<<"Enter the position (1-9): ";
    cin>>pos;
    if(pos<1 || pos>9){
        cout<<"Invalid position"<<endl;
        return 0;
        }
        else{
           Obj.Assign(A,itteration,pos-1);
           itteration++;
           Obj.print_table(A);
        }
 }
           Obj.check(A);
 
 
return 0;
}