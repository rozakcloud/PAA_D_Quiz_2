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

void take_path()
{
    int result,temp;
    int x=-1,y=-1;
    result = MIN;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==empty){
                board[i][j] = comp;
                temp = minimax(player);
                if(temp>result)
                {
                    result = temp;
                    x = i;
                    y = j;
                }
                board[i][j] = empty;
            }
        }
    }
    board[x][y] = comp;
    return;
}

void play()
{
    system("cls");
    printf("Let's play Tic Tac Toe:\nYou: O, Computer: X\n");
    printf("Press any key to continue");
    getch();
    int score;
    for(int i=0;i<9;i++){
        system("cls");
        score = score_eval();
        if(score!=0) break;
        if(!(i%2)){
            printf("Your Turn:\n");
            debugc(board);
            int x,y;
            printf("Input row and column: ");
            scanf("%d %d",&x,&y);
            x--;y--;
            while(x>2 || y>2 || board[x][y]!=empty){
                system("cls");
                printf("Your Turn:\n");
                debugc(board);
                printf("Input is invalid or it's already filled\n");
                printf("Raw Column: ");
                scanf("%d %d",&x,&y);
                x--;y--;
            }
            board[x][y]=player;
            system("cls");
            printf("Your turn:\n");
            debugc(board);
            Sleep(500);
            printf("Press any key to continue");
            getch();
        }
        else{
            for(int k=3;k>=1;k--){
                system("cls");
                printf("Computer's Turn:\n");
                debugc(board);
                printf("Computer still loading %d\n",k);
                Sleep(1000);
            }
            take_path();
            system("cls");
            printf("Computer's Turn:\n");
            debugc(board);
            Sleep(500);
            printf("Press any key to continue");
            getch();
        }
    }
    system("cls");
    printf("The result is:\n");
    debugc(board);
    if(score == 10) printf("Computer win!\n");
    if(score == -10) printf("You win!\n");
    if(score == 0) printf("It's a draw!\n");
}

int main()
{
    play();  
    return 0; 
}
