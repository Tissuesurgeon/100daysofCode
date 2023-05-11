#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//declaring global Variables

char board[3][3];    // this creates a 2D array 
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

//declaring prototypes for the program

void resetBoard();         //This function will reset board
void printBoard();        // This function will display the game board
int checkFreeSpaces();   // This function will check for free spaces on the board
void player1Move();     // This function is responsible for player 1 move
void player2Move();     // This function is responsible for player 2 move
void computerMove();      // This function is responsible for computer AI move
char checkWinner();      // This function checks for a winner
void printWinner(char winner);  //This function prints out the winner




int main ()
{   
    printf("TIC TAC TOE GAME\n");

    char winner = ' ';
    char response;
    char option;

    printf("\n Are you playing with a friend? (Y/N): ");
    scanf("%c", &option);
    option = toupper(option);

    do
    {
        winner = ' ';
        response = ' ';

        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            
            
            


            if(option == 'Y')
            {
                printBoard();

                player1Move();

                winner = checkWinner();

                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }

                printBoard();

                player2Move();

                winner = checkWinner();

                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }
            }
            else if(option == 'N')
            {
                printBoard();

                player1Move();

                winner = checkWinner();

                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }

                computerMove();

                winner = checkWinner();

                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }
            }
            

            
        }

        printBoard();
        printWinner(winner);

        printf("\n Would you like to play again? (Y/N): ");

        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);

    } while (response == 'Y');
    

   
    printf("Thanks for playing!\n");
    return 0;
}


void resetBoard()   
{
    for(int i = 0; i < 3; i++) // for the rows of the 2D board
    {
        for(int j = 0; j < 3; j++) // for the columns of the 2D board
        {
            board[i][j] = ' ';
        }
    }
}


void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}


int checkFreeSpaces()  
{
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void player1Move()    
{
    int x;

    int y;

    do
    {
        printf("Player1 Enter row #(1-3): ");
        scanf("%d", &x);

        x--;

        printf("Player1 Enter column #(1-3): ");
        scanf("%d", &y);
    
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER1;
            break;
        }
    } while (board[x][y] != ' ');
    
}

void player2Move()  
{
    int x;

    int y;

    do
    {
        printf("Player2 Enter row #(1-3): ");
        scanf("%d", &x);

        x--;

        printf("Player2 Enter column #(1-3): ");
        scanf("%d", &y);
    
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER2;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()    
{
    // create a seed based on the current time 

    srand(time(0));

    int x;
    int y;

    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3 ;
            y = rand() % 3 ;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;   
    }

    else
    {
        printWinner(' ');
    }
    
}

char checkWinner()
{
    //check rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    //check columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //check diagonals

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';

}   


void printWinner(char winner)
{

    if(winner == PLAYER1)
    {
        printf("\nPlayer 1 wins!\n");
    }
    else if(winner == PLAYER2)
    {
        printf("\nPlayer 2 wins!\n");
    }
    else if(winner == COMPUTER)
    {
        printf("\nYOU LOSE \n");
    }
    else
    {
        printf("\n IT'S A  TIE!! \n");
    }
}

