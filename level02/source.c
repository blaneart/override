

int main(int argc, char **argv)
{

    char buf[2600];
    char *filename = "/home/users/level03/.pass";
    char username[12];
    int fd; 
    int num_read;
    char password[]
    int size_before_endl;
    fd = fopen(filename, 'r');
    if (fd < 0)
        write(1, "ERROR: failed to open password file\n", 36);
    num_read = fread(buf, 1, 41, fd);
    size_before_endl = strcspn(buf, "\n");
    buf[size_before_endl] = '\0';
    if (num_read != 41)
        write(1, "ERROR: failed to read password file\n", 36);
    fclose(fd)
    puts("===== [ Secure Access System v1.0 ] =====");
    fgets(username, 100);
    fgets(password, 100);
// To do finish with printf and system call
    if (strncmp())
    return 0;
}

