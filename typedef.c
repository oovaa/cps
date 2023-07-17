#include <stdio.h>

// typedef char name[22];

struct user {
  char name[23];
  int id;
  float gpa;
};

int main(int argc, char *argv[]) {

  struct user u1 = {"omer", 12315, 4.00};
  struct user u2 = {"tata", 35262, 2.43};
  struct user u3 = {"nana", 66231, 3.20};
  struct user u4 = {"toja", 12385, 2.80};

  struct user users[] = {u1, u2, u3, u4};
  int size = sizeof(users) / sizeof(users[1]);

  for (int i = 0; i < size; i++) {
    printf("name : %-5s , id : %d  , gpa , %.2f", users[i].name, users[i].id,
           users[i].gpa);
    printf("\n");
  }

  //   user mna = {"omer", 2315};
  //   printf("%d", mna.id);

  //   char name[22] = "omer";
  //   name mna = "omer";
  //   printf("%s",mna);

  return 0;
}