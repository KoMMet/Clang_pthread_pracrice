#include "COMMON.h"

int varA;

void* threadFunc(void* arg)
{
    int n = (int)arg;
    int varB;

    varB = 4 * n;
    printf("thread %d - 1: varA:%d varB:%d\n", n, varA, varB);
    varA = 5*n;
    printf("thread %d - 2: varA:%d varB:%d\n", n, varA, varB);
    sleep(2);
    printf("thread %d - 3: varA:%d varB:%d\n", n, varA, varB);
    varB = 6*n;
    printf("thread %d - 4: varA:%d varB:%d\n", n, varA, varB);

    return NULL;
}

int main()
{
    pthread_t th1, th2;
    int varB;

    varA = 1; varB = 2;
    printf("main-1: varA=%d varB=%d\n", varA ,varB);
    pthread_create(&th1, NULL, threadFunc, (void*)1);
    sleep(1);
    varB=3;
    printf("main-2: varA=%d varB=%d\n", varA ,varB);
    pthread_create(&th2, NULL, threadFunc, (void*)2);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("main-3: varA=%d varB=%d\n", varA ,varB);

    return 0;
}
