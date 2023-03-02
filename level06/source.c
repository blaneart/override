#include <stdio.h>
#include <aio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <stdlib.h>


u_int64_t hi(u_int64_t x) {
    return x >> 32;
}

u_int64_t lo(u_int64_t x) {
    return ((1ULL << 32) - 1) & x;
}


int auth(char *login, unsigned int serial)
{
    unsigned int i = 0;
    int length;
    int ret;
    int pass; //  ebp - 0x10
    i = strcspn(login, "\n");
    serial += i; // 0x8 + ebp
    length = strnlen(login, 32);
    if (length - 5 > 0)
    {
        if (ptrace(0,1,0,0) == -1)
        {
            puts("***********************************");
            puts("| !! TAMPERING DETECTED !!  |");
            puts("***********************************");
            return 1;
        }
        // login = login;
        int l = login[0];
        l = l ^ 0x1337;
        ret = 0;
        while (length - 1 > ret)
        {
            //https://stackoverflow.com/questions/1815367/catch-and-compute-overflow-during-multiplication-of-two-large-integers
            if (login[ret] > 31)
            {
                u_int64_t s0, s1, s2, s3; 
                int k = login[ret];
                u_int64_t a = k ^ pass; 
                u_int64_t b =  0x88233b2;
                u_int64_t x = lo(a) * lo(b);
                s0 = lo(x);
                x = hi(a) * lo(b) + hi(x);
                s1 = lo(x);
                s2 = hi(x);
                x = s1 + lo(a) * hi(b);
                s1 = lo(x);
                x = s2 + hi(a) * hi(b) + hi(x);
                s2 = lo(x);
                s3 = hi(x);
                u_int64_t result = s1 << 32 | s0;
                u_int64_t carry = s3 << 32 | s2;
                pass = result  >> 2;
                pass = pass + carry;
                pass = pass >> 10;
                pass = pass * 0x539;
                printf("%u\n", pass);

                pass = pass - carry;
                ret= ret+1;
            }
            else
            {
                printf("here");
                return 1;
            }
        }
    }
    printf("%u", pass);

    if (pass == serial)
        return 0;
    return 1;
}


int main()
{
    char login[32]; //0x2c(%esp)
    puts("***********************************");
    puts("*		level06		  *");
    puts("***********************************");
    unsigned int serial;

    printf("->Enter Login:");
    fgets(login, 32, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial:");

    scanf("%u", &serial);

    if (!auth(login, serial))
        system("/bin/sh");
    else
        return 1;

    return 0;

}
