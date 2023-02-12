#include <unistd.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <signal.h>
#include <sys/user.h>
int main()
{
    pid_t pid; // $esp+0xac
    char buffer[32];
    pid = fork();
    // child process has pid=0
    // parent has pid=SOME_NUMBER
    bzero(buffer, 32);
    int ptrace_ret = 0; // $esp+0xa8
    int stat = 0;// $esp+0x1c

    if (pid != 0)
    {
        while(ptrace_ret != 11)
        {
            wait(&stat);
            if (WIFEXITED(stat) || WIFSIGNALED(stat))
            {
                puts("child is exiting...");
                return 0;
            }
            // It looks like the parent proccess is reading
            // the value of the RAX register, but this seems
            // to be of no practical value.
            ptrace_ret = ptrace(PTRACE_PEEKUSER, pid, 44, 0);
        }
        puts("no exec() for you");
        // Kill means no return, therefore, no way to 
        // change EIP here.
        kill(pid, 9);
    }

    prctl(PR_SET_PDEATHSIG, SIGHUP);
    ptrace(0, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(buffer);
    return 0;
}

