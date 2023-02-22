

void log_wrapper(int fd, char *status, char *filename)
{
    //118 fd
    //120 status
    //128 filename

    char filename2[100]; //110
    strcpy(filename2, filename);
    int i = -1;
    i = strlen(filename2);

    r8 = 254 - i;
    i = strlen(filename2);
    filename2[i] = "%s";
    rsi = status;
    
    snprintf(filename2, 254-i, status);
    rax = filename2
    filename2[strcspn(filename2, "\n")] = "\0";
    ffprintf(d,"LOG: %s\n", filename2);
}

int main(int argc, char **argv) {
    // argc -> 0x94(%rbp)
    // argv -> 0xa0(%rbp)
    // stack guard -> rax
    // rax -> -0x8(%rbp)
    // -1 -> 0x71(%rb[]
    // )
    FILE *fd; // 0x88
    FILE *second_file // 0x80
    int fetched_char = -1;
    if (argc == 2) {
        fd = fopen("./backups/.log", "w");
        if (fd == NULL) {
            printf("ERROR: Failed to open %s\n", "./backups/.log");
            exit(1);
        }
        log_wrapper(fd,  "Starting back up: ", argv[1]);
        
        second_file = fopen(argv[1], "r");
        if (second_file == NULL) {
            printf("ERROR: Failed to open %s\n", argv[1]);
            exit(1);
        }
        char new_param[10] = "./backups/";
        strncat(new_param, argv[1], 99 - strlen(new_param));

        int fd_3 = open(new_param, 193, 432); // 0x78
        if (fd_3 < 0) {
            printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
            exit(1);
        }
    }

    while((fetched_char = fgetc(second_file)) != -1) {
        write(fd_3, fetched_char, 1);
    }
    log_wrapper(fd,  "Finished back up ", argv[1]);
    fclose(second_file);
    close(fd_3);
    return(0);
}