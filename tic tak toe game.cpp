#include<iostream>
#include<ctime>
using namespace std;
void drawboard(char *spaces);
void playermove(char *spaces,char player);
void computermove(char *spaces,char computer);
bool cheakwinner(char *spaces, char player ,char computer);
bool checktie(char *spaces);

int main()
{
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='x';
    char computer='o';
    bool running =true;
    drawboard(spaces);
    while(running)
    {
        playermove(spaces,player);
        drawboard(spaces);
        if(cheakwinner(spaces,player,computer)){
            running=false;
            break;
        }
        else if(checktie(spaces))
        {
            running=false;
            break;
        }

        computermove(spaces,computer);
        drawboard(spaces);
        if(cheakwinner(spaces,player,computer)){
            running=false;
            break;
        }
        else if(checktie(spaces))
        {
            running=false;
            break;
        }
    }
    cout<<"Thanks for playing"<<endl;
}
void drawboard(char *spaces)
{
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  " << spaces[0]<<"  |  " << spaces[1] << "  |   " << spaces[2] << "  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  " << spaces[3]<<"  |  " << spaces[4] << "  |   " << spaces[5] << "  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  " << spaces[6]<<"  |  " << spaces[7] << "  |   " << spaces[8] << "  "<<endl;
    cout<<"     |     |    "<<endl;
    cout<<endl;
}
void playermove(char *spaces,char player)
{
    int num;
    do{
          cout<<"enter a spot to place a marker(1-9)";
          cin>>num;
          num--;
          if(spaces[num]==' ')
          {
              spaces[num]=player;
              break;
          }
    }while(!num>0 || num<8);

}
void computermove(char *spaces,char computer)
{
   int num;
   srand(time(0));
   while(true)
   {
       num=rand()%9;
       if(spaces[num]==' '){
        spaces[num]=computer;
        break;
       }
   }
}
bool cheakwinner(char *spaces, char player ,char computer)
{
 if((spaces[0]!=' ')&&(spaces[0]==spaces[1] )&& (spaces[1]==spaces[2]) )
 {
     spaces[0]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
 else if((spaces[3]!=' ')&&(spaces[3]==spaces[4] )&& (spaces[4]==spaces[5]) )
 {
     spaces[3]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
 else if((spaces[6]!=' ')&&(spaces[6]==spaces[7] )&& (spaces[7]==spaces[8]) )
 {
     spaces[6]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
  if((spaces[0]!=' ')&&(spaces[0]==spaces[3] )&& (spaces[3]==spaces[6]) )
 {
     spaces[0]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
 else if((spaces[1]!=' ')&&(spaces[1]==spaces[4] )&& (spaces[4]==spaces[7]) )
 {
     spaces[1]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
  else if((spaces[2]!=' ')&&(spaces[2]==spaces[5] )&& (spaces[5]==spaces[8]) )
 {
     spaces[2]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
 else if((spaces[0]!=' ')&&(spaces[0]==spaces[4] )&& (spaces[4]==spaces[8]) )
 {
     spaces[0]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
 else if((spaces[2]!=' ')&&(spaces[2]==spaces[4] )&& (spaces[4]==spaces[6]) )
 {
     spaces[2]==player?cout<<"you win"<<endl :cout<<"you loss"<<endl;
 }
 else {
    return false;
 }
 return true;
}
bool checktie(char *spaces)
{
for(int i=0;i<9;i++){
    if(spaces[i]==' '){
        return false;
}
}
cout<<"it's tie"<<endl;
return true;
}
