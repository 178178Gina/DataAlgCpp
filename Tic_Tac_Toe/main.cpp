#include <iostream>
#include <cstdlib>
using namespace std;
void ClearBoard();
void PrintBoard();
char PrintMark(int mark);
void PutMark();
bool IsWin(int mark);
bool GetWin(int player);


const int PLAYER_O = -1, PLAYER_X = 1, EMPTY=0;
int board[3][3];
int nCurrentPlayer=-1;//PLAYER_O first;

int main()
{
    ClearBoard();
    PrintBoard();
    while(!GetWin(-nCurrentPlayer))
    {
        int nRow(0), nCol(0);
        PutMark();
        PrintBoard();
        nCurrentPlayer*=-1;
    }
    return 0;
}

void ClearBoard()
{
    cout<<"--------new game--------\n\n";
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
    {
        board[i][j]=EMPTY;
    }
    nCurrentPlayer = PLAYER_O;
}

void PrintBoard()
{
    for(int i=0; i<3; i++)
    {
        cout<<"\t";
        for(int j=0; j<3; j++)
        {
            cout<<PrintMark(board[i][j]);
            if(j<2)
                cout<<"|";
        }
        if(i<2)
            cout<<"\n\t-+-+-\n";
    }
    cout<<"\n";
}

char PrintMark(int mark)
{
    switch(mark)
    {
         case  PLAYER_O:
             return 'O';
             break;
         case  PLAYER_X:
             return 'X';
             break;
        case  EMPTY:
             return ' ';
             break;
    }
}

void PutMark()
{
    int nRow(-1), nCol(-1);
    while(nRow>2||nRow<0||nCol>2||nCol<0)
    {
        cout<<PrintMark(nCurrentPlayer)<<": put mark\n";
        cout<<"row number(0~2)\n";
        cin>>nRow;
        cout<<"\ncolumn number(0~2)\n";
        cin>>nCol;
        cout<<"\n";
    }

    board[nRow][nCol] = nCurrentPlayer;
}


bool IsWin(int mark)
{
    int win = 3*mark;
    return((board[0][0]+board[0][1]+board[0][2]==win)||
           (board[1][0]+board[1][1]+board[1][2]==win)||
           (board[2][0]+board[2][1]+board[2][2]==win)||
           (board[0][0]+board[1][0]+board[2][0]==win)||
           (board[0][1]+board[1][1]+board[2][1]==win)||
           (board[0][2]+board[1][2]+board[2][2]==win)||
           (board[0][0]+board[1][1]+board[2][2]==win)||
           (board[0][2]+board[1][1]+board[0][2]==win) );
}

bool GetWin(int player)
{
    if(IsWin(player))
    {
        switch(player)
        {
            case PLAYER_O:
                cout<<"\n-----------------------\n";
                cout<<"O WIN\n";
                break;
            case PLAYER_X:
                cout<<"\n-----------------------\n";
                cout<<"X WIN\n";
                break;
        }
        return true;
    }
    else
        return false;
}
