#include<bits/stdc++.h>
using namespace std;
#define C 1
#define H 2
#define side 3
#define cmove 'O'
#define hmove 'X'
void display(char a[][side])
{
    cout<<endl<<endl;
    cout<<"\t\t\t"<<a[0][0]<<" | "<<a[0][1]<<" | "<<a[0][2]<<endl;
    cout<<"\t\t\t--------------\n";
    cout<<"\t\t\t"<<a[1][0]<<" | "<<a[1][1]<<" | "<<a[1][2]<<endl;
    cout<<"\t\t\t--------------\n";
    cout<<"\t\t\t"<<a[2][0]<<" | "<<a[2][1]<<" | "<<a[2][2]<<endl;
    return;
}
void init(char a[][side],int b[])
{
    srand(time(NULL));
    for(int i=0;i<side;++i)
    {
        for(int j=0;j<side;++j)
            a[i][j]=' ';
    }
    for(int i=0;i<(side*side);++i)
        b[i]=i;
    random_shuffle(b,b+(side*side));
    return;
}
void winner(int turn)
{
    if(turn==C)
    {
        cout<<"Computer wins!!"<<endl;
    }
    else
    {
        cout<<"Human wins!!"<<endl;
    }
    return;
}
bool row(char a[][side])
{
    for(int i=0;i<side;++i)
    {
        if(a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][0]!=' ')
            return (true);
    }
    return (false);
}
bool column(char a[][side])
{
    for(int i=0;i<side;++i)
    {
        if(a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[0][i]!=' ')
            return (true);
    }
    return (false);
}
bool diagonal(char a[][side])
{
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]!=' ')
        return (true);
    if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]!=' ')
        return (true);
    return (false);
}
bool st(char a[][side])
{
    return(row(a)||column(a)||diagonal(a));
}
void TicTacToe(int turn)
{
    char a[side][side];
    int b[side*side];
    init(a,b);
    int move=0,x,y;
    while(st(a)==false && move!=(side*side))
    {
        if(turn == C)
        {
            x=b[move]/side;
            y=b[move]%side;
            a[x][y]=cmove;
            display(a);
            ++move;
            turn=H;
        }
        else if(turn == H)
        {
            x=b[move]/side;
            y=b[move]%side;
            a[x][y]=hmove;
            display(a);
            ++move;
            turn=C;
        }
    }
    if(st(a)==false && move==(side*side))
    {
        cout<<"It's a tie!!"<<endl;
    }
    else
    {
        if(turn==C)
            turn=H;
        else if(turn==H)
            turn=C;
        winner(turn);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TicTacToe(C); //The computer starts the game
    return (0);
}
