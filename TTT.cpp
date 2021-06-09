#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define MAX 1000
#define MIN -1000
#define debugc(p) for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%c ",p[i][j]);}printf("\n");}
#define debugi(p) for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%d ",p[i][j]);}printf("\n");}
using namespace std;

char board[3][3] = 
{ 
    { '_', '_', '_' }, 
    { '_', '_', '_' }, 
    { '_', '_', '_' } 
}; 

char player='o',comp='x',empty='_';

int score_eval()
{
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==player) return -10;
        else if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]==player) return -10;
        else if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==comp) return 10;
        else if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]==comp) return 10;
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]==player) return -10;
    else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]==player) return -10;
    else if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]==comp) return 10;
    else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]==comp) return 10;
    return 0;
}

char other(char pawns)
{
    if(pawns == player) return comp;
    else return player;
}

bool StillPlay()
{
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++){
            if(board[i][j]==empty) return true;
        }
    }
    return false;
}

int max(int a,int b)
{
    return a>b ? a:b;
}

int min(int a,int b)
{
    return a<b ? a:b;
}

int minimax(char pawns)
{
    int score = score_eval();
    if(score!=0){
        return score;
    }
    if(!StillPlay()){
        return 0;
    }
    int result;
    if(pawns==comp){
        result = MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==empty){
                    board[i][j] = pawns;
                    result = max(result,minimax(other(pawns)));
                    board[i][j]=empty;
                }
            }
        }
    }
    else{
        result = MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==empty){
                    board[i][j] = pawns;
                    result = min(result,minimax(other(pawns)));
                    board[i][j]=empty;
                }
            }
        }
    }
    return result;
}

void play()
{
    system("cls");
    printf("Let's play Tic Tac Toe':\nYou: O, Computer: X\n");
    printf("Press any key to continue");
    getch();
    system("cls");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        	printf(" %c ", board[i][j]);
    	}
    	printf("\n");
    }
}

int main()
{
    play();  
    return 0; 
}
