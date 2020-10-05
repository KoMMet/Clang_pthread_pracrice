#include "COMMON.h"

void* threadfunc(void* arg)
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("func %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main(void)
{
    pthread_t thread;
    int i;

    if(pthread_create(&thread, NULL, threadfunc, NULL) != 0)
    {
        puts("thread faild");
        exit(1);
    }

    for(i=0;i<5;i++)
    {
        printf("main %d\n", i);
        sleep(1);
    }

    return 0;
}
