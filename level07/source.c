
// There are some functions that look like they are from
// https://github.com/RPISEC/MBE/blob/master/include/utils.h
// Stumbled upon them while googling some names.

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

/* clear argv to avoid shellcode */
#define clear_argv(_argv) \
    for (; *_argv; ++_argv) { \
        memset(*_argv, 0, strlen(*_argv)); \
    }
#define clear_envp(_envp) clear_argv(_envp)

unsigned int get_unum(void)
{
    unsigned int res = 0;
    fflush(stdout);
    scanf("%u", &res);
    clear_stdin();
    return res;
}

int read_number(char *memory)
{
    int i = 0; //c
    printf("Index: ");
    i = get_unum();
    printf(" Number at data[%u] is %u\n", i, memory[i]);
    return 0;
}

int store_number(memory)
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
    memory[j] = i;
}


int main(int argc, char *argv[], char *envp[]) {
    int ret = 0;    // 1b4
    char input[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                      0, 0, 0, 0, 0, 0, 0, 0, 0,};  //1b8

    char memory[100]; //0x24
    bzero(memory, 100);

    clear_argv(argv);
    clear_envp(envp);
    
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
        ret = 1;
        fgets(input, 20, stdin);
        strlen(input);
        if (strncmp(input, "store", 5) == 0)
            ret = store_number(memory);
        if (strncmp(input, "read", 4) == 0)
            ret = read_number(memory)
        if (strncmp(input, "quit", 4) == 0)
            return 0;
        if (ret == 0)
            printf("Completed %s command successfully\n", input);
        else
            printf(" Failed to do %s command\n", input);
        bzero(input, 20); 
    }
    return 0;
}