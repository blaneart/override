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

int read_number(char *buf)
{
    int i = 0; //c
    printf("Index: ");
    i = get_unum();
    printf(" Number at data[%u] is %u\n", i, buf[i]);
    return 0;
}

int store_number(buf)
{
    int i = 0;//-10
    int j = 0;//-c

    printf("Number: ");

    i = get_unum();
    printf("Index: ");
    j = get_unum();
    if (j % 3 == 0 || i == 3070230528)
    {
        puts(" *** ERROR! ***");
        puts("This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }
    buf[j] = i;
}


int main(int argc, char *argv[], char *envp[]) {
    int alpha = 0;    // 1b4
    char bravo[20] = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};  //1b8

    char buf[100]; //0x24
    bzero(buf, 100);

    // Clean args
    while (*argv != NULL){
        memset(argv, 0, strlen(argv));
        argv++;
    }

    // Clean the environment
    while (*envp != NULL)
    {
        memset(envp, 0, strlen(envp));
        envp++;
    }
    
    puts("----------------------------------------------------\n\
  Welcome to wil's crappy number storage service!   \n\
----------------------------------------------------\n\
 Commands:                                          \n\
    store - store a number into the data storage    \n\
    read  - read a number from the data storage     \n\
    quit  - exit the program                        \n\
----------------------------------------------------\n\
   wil has reserved some storage :>                 \n\
----------------------------------------------------\n");
    while(true)
    {
        printf("Input command: ");
        alpha = 1;
        fgets(bravo, 20, stdin);
        strlen(bravo);
        if (strncmp(bravo, "store", 5) == 0)
            alpha = store_number(buf);
        if (strncmp(bravo, "read", 4) == 0)
            alpha = read_number(buf)
        if (strncmp(bravo, "quit", 4) == 0)
            return 0;
        if (alpha == 0)
            printf("Completed %s command successfully\n", bravo);
        else
            printf(" Failed to do %s command\n", bravo);
        bravo[20] = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"}; 
    }
    return 0;
}