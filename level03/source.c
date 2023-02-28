#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void decrypt(int input)
{
    char *key = "Q}|u`sfg~sf{}|a3";
    int len = strlen(key);
    int counter = 0;

    while (len < counter) {
        key[counter] = key[counter] ^ input;
        counter += 1; 
    }
    if (strncmp(key, "Congratulations!", 11) == 0) {
        system("/bin/sh");
    }
    else {
        puts("\nInvalid Password");
    }   
}

void test(int i, int answer)
{
    int param1 = i;
    int param2 = answer;
    param2 -= param1;

    switch (param2) {
    case 0:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        decrypt(rand());
        return;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 16:
    case 17:
    case 18:
    case 19:
    case 21:
        decrypt(answer);
        return;
    default:
        decrypt(rand());
        return;
    }
}

int main()
{
    int i = 0;

    srand(time(NULL));
    puts("***********************************\n");
    puts("*		level03		**\n");
    puts("***********************************\n");
    printf("Password:");
    scanf("%d", &i);
    printf("%d", i);
    test(i, 0x1337d00d);
    return 0;
}