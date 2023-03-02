#include <stdio.h>
#include <string.h>

char a_user_name[256];

int verify_user_name(char *username)
{
    puts("verifying username....\n");
    return strcmp(username, "dat_wil");
}

int verify_user_pass(char *password)
{
    return memcmp(password, "admin", 5);
}

int main(){
    char password[64]; // Assuming by the memset
    int is_correct = 0;

    memset(password, 0, 64);
    puts("********* ADMIN LOGIN PROMPT *********\n");
    printf("Enter Username: ");
    fgets(a_user_name, 256, stdin);
    is_correct = verify_user_name(a_user_name);
    if (is_correct != 0) {
        puts("nope, incorrect username...\n");
        return 1;
    }
    puts("Enter Password: ");
    fgets(password, 100, stdin);
    is_correct = verify_user_pass(password);
    
    // Here, assembly doesn't make any sense at all
    if (is_correct == 0) {
        puts("nope, incorrect password...\n");
        return 1;
    } else {
        if (is_correct == 0) {
           return 0; 
        }
        puts("nope, incorrect password...\n");
        return 1;
    }
}