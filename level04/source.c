#include <unistd.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <signal.h>
#include <sys/user.h>
int main()
{
    pid_t kek; //(ac)
    char lol[32];
    kek = fork();
    // child process has kek=0 parent=number
    bzero(lol, 32);
    int i = 0; //(a8)
    int stat = 0;// (1c)
    user test;


    if (kek != 0)
    {
        while(i != 11)
        {
        wait(&stat);
        if (WIFEXITED(stat) || WIFSIGNALED(stat))
        {
            puts("child is exiting...");
            return 0;
        }
        i = ptrace(PTRACE_PEEKUSER, kek, 44, 0);
        }
        puts("no exec() for you");
        kill(kek, 9);
    }

    prctl(PR_SET_PDEATHSIG, SIGHUP);

    ptrace(0, 0, 0, 0);

    puts("Give me some shellcode, k");
    gets(lol);
    return 0;

}