#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
void printmessage (string message, bool top = true, bool bottom = true)
{
  if (top)
    {
      cout << "+---------------------------------+" << endl;
      cout << "|";
    }
  else
    {
      cout << "|";
    }
  bool front = true;
  for (int i = message.length (); i < 33; i++)
    {
      if (front)
	{
	  message = " " + message;
	}
      else
	{
	  message = message + " ";
	}
      front = !front;
    }
  cout << message;
  if (bottom)
    {
      cout << "|" << endl;
      cout << "+---------------------------------+" << endl;

    }
  else
    {
      cout << "|" << endl;
    }
}

void draw (int guesscount = 0)
{
  if (guesscount >= 1)
    {
      printmessage ("|", false, false);
      printmessage ("|", false, false);
      printmessage ("0", false, false);
    }
  else
    printmessage ("", false, false);
  if (guesscount >= 2)
    {
      printmessage ("/|\\", false, false);
      printmessage ("|", false, false);
      printmessage ("|", false, false);
    }
  else
    printmessage ("", false, false);
  if (guesscount >= 3)
    {
      printmessage ("/ \\", false, false);
      printmessage ("+----------+", false, false);
      printmessage ("|          |", false, false);
      printmessage ("You lost");
    }
}

int main ()
{
  system ("color 5f");
  string s1[10] = { "INDIA", "PAKISTHAN", "CHINA", "SRILANKA", "NEPAL", "BHUTAN", "BANGLADESH", "TIBET", "FRANCE", "AMERICA" };
  string s2;
  int chance = 3, len, n, r, i, j, pos, flag, x, y = 1, k;
  cout << "\t\t" << "Hi!!!!" << " Welcome to Hangman Game!!! " << endl << endl;
  cout << "\n\t\t" << "A game by MOHANAPRIYA" << endl;
  cout << "\nRULES:" << endl << "1.Here totally 10 countries names are in the game." << endl << "2.You need to choose one number from 1 to 10." << endl;
  cout << "3.To find the name , you will be given 3 chances." << endl;
  cout << "4.****NOTE****The letters must be in capital or else you will lose the game." << endl;
  cout << "4.If you failed to find the word within 3 chances,then you will lose the game.You can try it after some time." << endl;
  cout << "5.Your score will be displayed at the end of the game." << endl;
  cout << "\nPress 1 to continue : ";
  cin >> n;
  if (n == 1)
    {
      while (y == 1)
	{
	  cout << endl << "Select one number from 0 to 9  :";
	  cin >> r;
	  chance = 3;
	  if (r >= 0 && r <= 9)
	    {
	      len = s1[r].length ();
	      s2 = s1[r];
	      for (i = 0; i < len; i++)
		{
		  s2[i] = '*';
		}
	      cout << endl << "\tThe word you need to find:\n\t" << endl << "\t\t" << s2 << endl << endl;
	      char c;
	      while (chance > 0)
		{
		  cout << endl;
		  cout << "Enter a letter to find the word :  ";
		  cin >> c;
		  flag = 0;
		  for (i = 0; i < len; i++)
		    {
		      if (c == s1[r][i])
			{
			  pos = i;
			  for (j = 0; j < len; j++)
			    {
			      if (j == pos && s2[j] == '*')
				{
				  s2[j] = c;
				  flag = 1;
				}
			    }
			}
		    }
		  if (flag == 1)
		    {
		      cout << "\tIt's a correct letter!!!" << endl;
		      cout << "\tThe word is : " << s2 << endl;
		      cout << "\tYou have " << chance << " chances" << endl;
		      if (s1[r] == s2)
			{
			  cout << "\n\tCONGRATULATIONS!!!!" << endl;
			  cout << "\n\tYou won the game!!!" << endl;
			  if (chance == 1)
			    {
			      cout << "\tYour score is: " << 5 << "/10"<< endl;
			    }
			  else if (chance == 2)
			    {
			      cout << "\tYour score is: " << 7 << "/10"<<  endl;
			    }
			  else if (chance == 3)
			    {
			      cout << "\tYour score is: " << 10 << "/10"<< endl;
			    }
			  goto x;
			}
		    }
		  else
		    {
		      chance = chance - 1;
		      cout << "\n\tWrong guess!!!" << endl << endl;
		      int z = 3 - chance;
		      if (z > 0)
			{
			  printmessage ("HANG MAN GAME");
			  draw (z);
			}
		      cout << "\n\tThe word is : " << s2 << endl;
		    }
		}
	      if (chance == 0)
		{
		  cout << "\n\tYou failed to find the word!!!" << "\n\tYou lost the game!!!" << "\n\tBetter luck next time!!" << endl;
		  cout << "\tThe correct word is : " << s1[r] << endl;
		  cout << "\tYour score is: " << 0 << "/10"<<  endl;
		}
	    x:
	      cout << "\tPress 1 to continue!!!\n\tPress any key to exit!!" << endl;
	      int k;
	      cin >> k;
	      y = k;
	    }
	  else
	    {
	      cout << endl << "Please enter a valid number!!!" << endl;
	    }
	  getchar ();
	}
    }
  else
    cout << endl << "Invalid choice.Please try again!!!" << endl;
  return 0;
}
