#include <stdio.h>
#include <stdlib.h>

 struct Node{
   int data;
   struct Node* next;
};

void add(int a);
void printlist();


struct Node* first ;
struct Node* head ;

int main(void)
{
    int count;
    int val;
    printf("how many u wanna add to the linked list?\n");
    scanf("%d",&count);

for (int i = 0; i < count; i++)
{
    printf("enter number:\n");
    scanf("%d",&val);
    add(val);
    // printf("head val = %d\n",head->data);
}
   printlist();   

    return 0;
}
void add(int a){
   struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = a;
    // head = t;
    t->next = NULL;

    if(first == NULL) { 
    first = t;
    head = t;
    } else
    {
    head->next = t;
    head = t;
    }
}


    // head = t;
    // if(first != NULL && first->next == NULL)  first->next = head;
void printlist(){
    struct Node* cur = first;
    while (cur->next != NULL)
    {
    printf("%d->",cur->data);
    cur = cur->next;
    }
    printf("%d\n",cur->data);

}