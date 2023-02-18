

int auth(char *login, unsigned int serial)
{
    int i = 0;
    i =strcspn(login, "\n");
    serial += i;

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