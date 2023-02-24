int main(void)
{
    char username[48]; // 0x70
    char password[20]; // 0xa0
    
    // The actual length of these buffers is not
    // precisely known from the source.
    // Buf might contain up to 112 bytes judging
    // by the address of the next local variable, password, at 0xa0.
    // However, we know that it is bzero'd to 48 bytes at the beginning
    // of the program.
    char buf[48] // 0x110;


    char *filename = ;
    int fd = 0; // 0x8 
    int num_read = 0; // 0xc
    int size_before_endl;

    bzero(username, 48);
    bzero(password, 20);
    bzero(buf, 48);

    fd = fopen("/home/users/level03/.pass", 'r');
    if (fd == NULL)
    {
        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
    }
    
    num_read = fread(password, 1, 41, fd);
    size_before_endl = strcspn(password, "\n");
    password[size_before_endl] = '\0';
    if (num_read != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        // sic!
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
    }
    fclose(fd)
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\***************************************/");
    
    printf("--[ Username: ");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0';
    
    printf("--[ Password: ");
    fgets(buf, 100, stdin);
    buf[strcspn(buf, "\n")] = '\0';

    puts("*****************************************");

    if (strncmp(password,buf,41) == 0) {
        printf("Greetings, %s!\n", username);
        system("/bin/sh");
        return 0;
    }
    printf(username);
    puts(" does not have access!");
    exit(1);
}

