#include <COMMON.h>

void* threadFunc()
{
    const char* msg = "threadFunc writes to standerd output\n";

    write(1 , msg, strlen(msg));
    close(1);
    open("fdProc.txt", O_WRONLY | O_TRUNC, 644);
    msg = "threadFunc writes to fdProc.txt\n";
    write(1, msg, strlen(msg));
    sleep(2);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, threadFunc, NULL);

    sleep(1);

    const char* msg = "main writes to standerd optput\n";
    write(1, msg, strlen(msg));

    pthread_join(thread, NULL);

    return 0;
}
