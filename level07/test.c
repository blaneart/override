#include <stdio.h>

void clear_stdin(void)
{
    char x = 0;
    while(1)
    {
        x = getchar();
        if(x == '\n' || x == EOF)
            break;
    }
}


unsigned int get_unum(void)
{
    unsigned int res = 0;
    fflush(stdout);
    scanf("%u", &res);
    clear_stdin();
    return res;
}

int main()
{
    unsigned int j = 0;
    j = get_unum();
    if (j % 3 == 0)
        printf("success");
    else
        printf("not");
    return 0;
}