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

  char winnre = ' ';
  resetBoard();

  while (checkfreeSpaces() != 0 && winnre == ' ') {
    printBoard();
    playermove();
    checkwin();
    if (winnre != ' ' || checkfreeSpaces() == 0) {
      break;
    }

    computermove();
    checkwin();
    if (winnre != ' ' || checkfreeSpaces() == 0) {
      break;
    }
  }

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
  printf("enter row num #1-3");
  scanf("%d", &r);
  printf("enter column num #1-3");
  scanf("%d", &c);
  r--;
  c--;
  do {
    printf("this place is full");

    printf("enter row num #1-3");
    scanf("%d", &r);
    printf("enter column num #1-3");
    scanf("%d", &c);

  } while (!isfree(r, c));
  board[r][c] = plyer;
}
void computermove() {
  if (!(checkfreeSpaces() > 0)) {
    printwinner(' ');
    return;
  }

  srand(time(0));
  int r = rand() % 3;
  int c = rand() % 3;

  do {
    int r = rand() % 3;
    int c = rand() % 3;
  } while (!isfree(r, c));
  board[r][c] = com;
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
    printf("U WIN!!");
  } else if (winner == com) {
    /* code */ printf("U LOSE");

  } else {
    printf("it's a TIE");
  }
}
bool isfree(r, c) { return board[r][c] == ' '; }
