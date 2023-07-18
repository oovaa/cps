#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char plyer = 'X';
const char com = 'O';

void resetBoard();
void printBoard();
int checkfreeSpaces();
void playermove();
void computermove();
char checkwin();
void printwinner(char);
bool isfree(int r, int c);

int main(int argc, char const *argv[]) {

  char winner = ' ';
  char response;

  do {
    winner = ' ';
    response = ' ';
    resetBoard();

    while (checkfreeSpaces() != 0 && winner == ' ') {
      printBoard();
      // printf("printBoard();\n");

      playermove();
      // printf("playermove();\n");

      winner = checkwin();
      if (winner != ' ' || checkfreeSpaces() == 0) {
        printBoard();

        printwinner(winner);
        break;
      }
      // printf("checkwin();\n");

      computermove();
      // printf("computermove();\n");
      winner = checkwin();
      if (winner != ' ' || checkfreeSpaces() == 0) {
        printBoard();

        printwinner(winner);

        break;
      }
      // printf("checkwin();\n");
    }
    printBoard();
    printwinner(winner);

    printf("wanna play again ?? (y/n)\n");
    // scanf(" %c");
    scanf(" %c", &response);
    response = toupper(response);

  } while (response == 'Y');

  printf("Thanks for playing\n");

  return 0;
}

void resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard() {
  printf("\n");

  //   printf("_____________\n");
  printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
  printf("|---|---|---|\n");
  printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
  printf("|---|---|---|\n");
  printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
  printf("|---|---|---|\n");
  //   printf("|___________|\n");

  printf("\n");
}
int checkfreeSpaces() {
  int count = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        count++;
      }
    }
  }

  return count;
}
void playermove() {
  int r;
  int c;

  do {
    printf("enter row num #1-3 : ");
    scanf("%d", &r);
    r--;
    printf("enter column num #1-3 : ");
    scanf("%d", &c);
    c--;
    if (!isfree(r, c)) {
      printf("this place is full");
    } else {
      board[r][c] = plyer;
      break;
    }
  } while (!isfree(r, c));
}
void computermove() {
  if ((checkfreeSpaces() > 0)) {

    srand(time(0));
    int r;
    int c;

    do {
      r = rand() % 3;
      c = rand() % 3;
    } while (board[r][c] != ' ');
    board[r][c] = com;
  } else {
    printwinner(' ');
    return;
  }
}
char checkwin() {
  // h
  if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
    return board[0][0];
  if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
    return board[1][0];
  if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
    return board[2][0];

  // v
  if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
    return board[0][0];
  if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
    return board[0][1];
  if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
    return board[0][2];

  // cross
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    return board[0][0];
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return board[1][1];
  //   if (board[2][0] == board[2][1] && board[2][0] == board[2][2])return
  //   board[2][0];
  return ' ';
}
void printwinner(char winner) {
  if (winner == plyer) {
    printf("U WIN!!\n");
  } else if (winner == com) {
    /* code */ printf("U LOSE !!\n");

  } else {
    printf("it's a TIE\n");
  }
}

bool isfree(int r, int c) {
  if (r > 3 || c > 3 || r < 0 || c < 0) {
    printf("INVALID INBUT \n");
    return false;
  }

  return board[r][c] == ' ';
}
