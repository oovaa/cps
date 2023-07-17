#include <stdio.h>

enum days { sun, mon, tue, wed, thu, fri, sat };

int main(int argc, char *argv[]) {

  enum days today = fri;

  switch (today) {
  case 0 ... 4: // like range in py
    printf("gotta work");
    break;

  default:
    printf("gotta rest");

    break;
  }

  return 0;
}