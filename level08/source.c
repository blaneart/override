#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void log_wrapper(FILE *fd, char *status, char *filename)
{
    //118 fd
    //120 status
    //128 filename
    int i;
    char log_line[100]; //110
    strcpy(log_line, status);

    // Possible additional exploit ;)
    snprintf(log_line+strlen(log_line), 254-strlen(log_line), status);

    log_line[strcspn(log_line, "\n")] = '\0';
    fprintf(fd,"LOG: %s\n", log_line);
}

int main(int argc, char **argv) {
    FILE *fd; // 0x88
    FILE *second_file; // 0x80
    int fd_3 = 0;
    int fetched_char = -1;

    if (argc >= 2) {
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
        while((fetched_char = fgetc(second_file)) != -1) {
            write(fd_3, &fetched_char, 1);
        }
        log_wrapper(fd,  "Finished back up ", argv[1]);
        fclose(second_file);
        close(fd_3);
    }

    return(0);
}