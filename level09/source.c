
void secret_backdoor()
{
    char command[128];
    fgets(command, 128,stdin);
    system(command);
}

void set_msg(char *msg)
{
    char local[128];
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(local, 1024, stdin);
    strncpy(msg, local, 180); //180 is stored 41 byte after username
}

void set_username(char *username)
{

    char temp_user[40];
    bzero(username);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(temp_user ,128, stdin);
    while (username[i] && i < 40)
    {
        temp_user[i] = username[i];
        i++;
    }
    printf(">: Welcome, %s", temp_user);
}

void handle_msg()
{
    char username[40];
    bzero(username, 40);
    set_username(username);
    set_msg(username);
    puts(">: Msg sent!");
}

int main(){
    
    puts("\n|   ~Welcome to l33t-m$n ~    v1337        |\n");
    handle_msg();
    return 0;
}