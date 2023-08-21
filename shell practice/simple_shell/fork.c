#include "main.h"

int main(void)
{
    /* code */
    pid_t pid;

    printf("Before Fork 1:\n");

    printf("PID = %u\n",getpid());
    printf("PID = %u\n", getppid());

    pid = fork();
    if (pid == -1)
        perror("fork() failure");
    if (pid == 0)
    {
        printf("Before sleep:\nPID = %u\n",getpid());
        printf("Before sleep:\nPID = %u\n",getppid());
        sleep(10);
        printf("Child Process:\n");
        printf("After sleep:\nPID = %u\n",getpid());
        printf("After sleep:\nPID = %u\n",getppid());
    }

    else
    {
        printf("Parent Process exiting...\n");
    }
    return 0;
}
