#include "COMMON.h"

void* threadfunc(void* arg)
{
    int n = (int)arg;
    int i;

    for(i=0;i<n;i++)
    {
        printf("threadfunc %d\n", i);
        sleep(1);
    }

    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t thread;
    int n, i;

    if(argc > 1)
        n = atoi(argv[1]);
    else
        n = 1;

    if(pthread_create(&thread, NULL, threadfunc, (void*)n) != 0)
    {
        puts("thread create faild");
        exit(1);
    }

    for(i=0;i<5;i++)
    {
        printf("main %d\n", i);
        sleep(1);
    }

    printf("end");

    return 0;
}
