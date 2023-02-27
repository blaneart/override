
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 0; //8c
    char s[100]; // 28
    int c; //1c
    fgets(s, 100, stdin);
    i = 0;

    while(strlen(s) > i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') 
            s[i] += 0x20;
        i++;
    }
    printf(s);
    exit(0);
}