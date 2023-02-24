

int auth(char *login, unsigned int serial)
{
    unsigned int i = 0;
    int length;
    int ret;
    i = strcspn(login, "\n");
    serial += i;
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
        serial += 3;
    }
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

    scanf("%u", serial);

    if (auth(login, serial))
        system("/bin/sh");
    else
        return 1;

    return 0;

}

0x1e240


0x005f1e94

0x5f0143

0x005f160a