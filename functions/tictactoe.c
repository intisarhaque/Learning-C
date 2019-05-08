 #include <stdio.h>
 #include <stdlib.h>
 //#include <conio.h>

void printBoard(char board[]);
void markBoard(char board[], int i);
_Bool gameEnded(char board[]);

int main()
{
  printf("TIC TAC TOE\n");
  printf("Player 1 - X\tPlayer 2 - O\n");
  _Bool gameNotEnded = 1;
  char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
  int playerWon;
  printBoard(board);
  for (int i=1;i<=9;i+=1)
  {
    if (gameNotEnded==0)
    {
      break;
    }
    int whichPlayer = i%2==0?2:1;
    markBoard(board, whichPlayer);
    printBoard(board);
    gameNotEnded = gameEnded(board);
    if (i==9 && gameNotEnded==1)
    {
      printf("Yous are shit... draw");
    }
  }

}

void printBoard(char board[])
{
  //system("cls");
  printf("   |   |   \n");
  printf(" %c | %c | %c \n", board[1], board[2], board[3]);
  printf("___|___|___\n");
  printf("   |   |   \n");
  printf(" %c | %c | %c \n", board[4], board[5], board[6]);
  printf("___|___|___\n");
  printf("   |   |   \n");
  printf(" %c | %c | %c \n", board[7], board[8], board[9]);
  printf("   |   |   \n");
}

void markBoard(char board[],int whichPlayer)
{
  char mark = whichPlayer==1?'X':'O';
  printf("Player %d turn: Enter a number\t", whichPlayer);
  int numEntered;
  scanf("%d", &numEntered);
  board[numEntered] = mark;
}

_Bool gameEnded(char board[])
{
  if (board[1]=='X')
  {
    if (board[2]=='X' && board[3]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
    if (board[4]=='X' && board[7]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
    if (board[5]=='X' && board[9]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
  }
  if (board[9]=='X')
  {
    if (board[7]=='X' && board[8]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
    if (board[3]=='X' && board[6]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
  }
  if (board[5]=='X')
  {
    if (board[4]=='X' && board[6]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
    if (board[2]=='X' && board[8]=='X')
    {
      printf("Congrats Player 1 Won\n");
      return 0;
    }
  }
  if (board[1]=='O')
  {
    if (board[2]=='O' && board[3]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
    if (board[4]=='O' && board[7]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
    if (board[5]=='O' && board[9]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
  }
  if (board[9]=='O')
  {
    if (board[7]=='O' && board[8]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
    if (board[3]=='O' && board[6]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
  }
  if (board[5]=='O')
  {
    if (board[4]=='O' && board[6]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
    if (board[2]=='O' && board[8]=='O')
    {
      printf("Congrats Player 2 Won\n");
      return 0;
    }
  }
  return 1;
}
