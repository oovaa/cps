#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "I am ALX\0 student ";
    printf("%ld\n",strlen(s));
    for (size_t i = 0; i < strlen(s); i++)
    {
        printf("%c\t",s[i]);
        
    }
    
     
    return 0;
}

