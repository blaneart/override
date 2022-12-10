#include <stdio.h>
#include <string.h>


char a_user_name[256];

char true_name[10] = "dat_wil";

int verify_user_name(void)
{
    return memcmp(a_user_name, "dat_wil", 7);
}

int verify_password(char *password)
{
    return memcmp(password, "admin", 5);
}
int main(){

    char password[84];
    int is_correct;
    puts("********* ADMIN LOGIN PROMPT *********\n");
    printf("Enter Username: ");
    fgets(a_user_name, 256, 0);
    is_correct = verify_user_name();
    puts("verifying username....\n", 1);
    if (is_correct)
    {
        puts("verifying username....\n", 1);
        printf("Enter Password: ");
        fgets(password, 100, 0);
        is_correct = verify_password(password);
        if (is_correct)
            return 0;
    }

    return 0;
}