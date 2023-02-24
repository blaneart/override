#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void decrypt()
{
    int i =1971092817; // -0x1d(%ebp)

    long j = 1734767456; // -0x19(%ebp)

    long k = 2070311806; //-0x15(%ebp)

    long f = 862026877; //-0x11(%ebp)

    int p = 0; // -0xd(%ebp)


    int u = -1; // -0x2c(%ebp)


    if()
        system("/bin/sh");
    else
        puts("\nInvalid Password");
}

void test(int i, int answer)
{
    int param1 = i;
    int param2 = answer;
    param2 -= param1;
    if (0x15 < param2)
    {
        decrypt(rand());
        return ;
    }

    (param2 << 2) + 0x80489f0;

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