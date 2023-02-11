#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// void decrypt()
// {

// }

// void test(int i, int answer)
// {
//     int param1 = i;
//     int param2 = answer;
//     param2 -= param1;
//     if (0x15 > param2)
//     {
//         rand();
//         decrypt();
//     }
//     (param2 << 2) + 0x80489f0;

// }

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
    // test(i, 0x1337d00d);
    return 0;
}