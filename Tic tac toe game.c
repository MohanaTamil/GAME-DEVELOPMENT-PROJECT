#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int checkwin ();
int drawboard ();
int game[10] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };

int main ()
{
  system ("color 4f");
  int i, choice, Player = 1;
  char mark;			//X,O;
  do
    {
      drawboard ();
      Player = (Player % 2 != 0) ? 1 : 2;
      printf ("\nPlayer %d,Enter your choice: ", Player);
      scanf ("%d", &choice);
      mark = (Player == 1) ? 'X' : 'O';
      if (choice > 0 && choice < 10)
	{
	  if (game[choice] == '*')
	    game[choice] = mark;
	}
      else
	{
	  printf ("\nInvalid option\n");
	  Player--;
	  getch ();
	}
      i = checkwin ();
      Player++;
    }
  while (i == -1);
  drawboard ();
  if (i == 1)
    {
      printf ("\n\nPLAYER %d WON\n\n", --Player);
      printf ("Congratulations!!!\n\n");
    }
  else if (i == 0)
    {
      printf ("\n\nMATCH DRAW\n\n");
    }
  else
    {
      printf ("\n\nGAME OVER\n\n");
    }
  getch ();
  return 0;
}

int checkwin ()
{
  if (game[1] == 'X' && game[2] == 'X' && game[3] == 'X' || game[4] == 'X' && game[5] == 'X' && game[6] == 'X' || game[7] == 'X' && game[8] == 'X' && game[9] == 'X' || game[1] == 'X' && game[4] == 'X' && game[7] == 'X' || game[2] == 'X' && game[5] == 'X' && game[8] == 'X' || game[1] == 'X' && game[5] == 'X' && game[9] == 'X' || game[3] == 'X' && game[5] == 'X' && game[7] == 'X')
    return 1;
  else if (game[1] == 'O' && game[2] == 'O' && game[3] == 'O' || game[4] == 'O' && game[5] == 'O' && game[6] == 'O' || game[7] == 'O' && game[8] == 'O' && game[9] == 'O' || game[1] == 'O' && game[4] == 'O' && game[7] == 'O' || game[2] == 'O' && game[5] == 'O' && game[8] == 'O' || game[1] == 'O' && game[5] == 'O' && game[9] == 'O' || game[3] == 'O' && game[5] == 'O' && game[7] == 'O')
    return 1;
  else if (game[1] != '*' && game[2] != '*' && game[3] != '*' && game[4] != '*' && game[5] != '*' && game[6] != '*' && game[7] != '*' && game[8] != '*' && game[9] != '*')
    return 0;
  else
    return -1;
}

int drawboard ()
{
  system ("cls");
  printf ("\n\n\tTIC TAC TOE GAME\n\n");
  printf ("\nPlayer 1(X) - Player 2(O)\n\n\n");
  printf ("     |     |     \n");
  printf ("  %c  |  %c  |  %c  \n", game[1], game[2], game[3]);
  printf ("_____|_____|_____\n");
  printf ("     |     |     \n");
  printf ("  %c  |  %c  |  %c  \n", game[4], game[5], game[6]);
  printf ("_____|_____|_____\n");
  printf ("     |     |     \n");
  printf ("  %c  |  %c  |  %c  \n", game[7], game[8], game[9]);
  printf ("     |     |     \n");
  return 0;
}
