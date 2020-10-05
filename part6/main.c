#include <COMMON.h>

void procFunc()
{
    const char* msg = "procFunc writes to standerd output\n";

    write(1 , msg, strlen(msg));
    close(1);
    open("fdProc.txt", O_WRONLY | O_TRUNC, 644);
    msg = "procFunc writes to fdProc.txt\n";
    write(1, msg, strlen(msg));
    sleep(2);

    exit(0);
}

int main()
{
    pid_t proc;
    if((proc = fork()) == 0)
    {
        procFunc();
    }
    sleep(1);

    const char* msg = "main writes to standerd optput\n";
    write(1, msg, strlen(msg));

    waitpid(proc, NULL, 0);

    return 0;
}
