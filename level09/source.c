

void set_msg()
{
    char *local[128];
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(msg, 1024, stdin);
    strncpy(msg, local, 180);
}

void set_username(char *username)
{

    int i
    bzero(username);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(username ,128, stdin);
    while ()
    printf(">: Welcome, %s", );
}

void handle_msg()
{
    char username[40] = {0,0,0,0,0}
    set_username(username);
    set_msg();
    put(">: Msg sent!");
}

int main(){
    
    puts("\n|   ~Welcome to l33t-m$n ~    v1337        |\n");
    handle_msg();
    return 0;
}