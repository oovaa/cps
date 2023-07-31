#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char P = 'X';
const char C = 'O';

void resetBoard();
void printBoard();
int check();
void playmove();
void compmove();
char checkwin();
void printwin(char);

int main() {
  char winner = ' ';

  resetBoard();
  while (winner == ' ' && check() != 0) {
    printBoard();
    playmove();
    winner = checkwin();
    if (winner != ' ' && check() == 0) {
      break;
    }
    compmove();
    winner = checkwin();
    if (winner != ' ' && check() == 0) {
      break;
    }
  }
  printBoard();
  printwin(winner);

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

  printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}
int check() {
  int freespace = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        freespace--;
      }
    }
  }
  return freespace;
}
void playmove() {
  int x;
  int y;

  do {
    printf("enter row #1-3:");
    scanf("%d", &x);
    x--;

    printf("enter columns #1-3:");
    scanf("%d", &y);
    y--;

    if (board[x][y] != ' ') {
      printf("invalid move!!\n");
    } else {
      board[x][y] = P;
      break;
    }
  } while (board[x][y] != ' ');
}
void compmove() {
  srand(time(0));
  int x;
  int y;
  if (check() > 0) {
    do {
      x = rand() % 3;
      y = rand() % 3;
    } while (board[x][y] != ' ');
    board[x][y] = C;

  } else {
    printwin(' ');
  }
}
char checkwin() {
  // check row
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    }

  } // check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    }
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[0][0] == board[2][0]) {
    return board[0][2];
  }

  return ' ';
}
void printwin(char winner) {
  if (winner == P) {
    printf("YOU WIN");
  } else if (winner == C) {
    printf("YOU LOSE!!!");
  } else {
    printf("IT'S A TIE");
  }
}