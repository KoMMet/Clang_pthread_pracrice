#include "COMMON.h"

char* varA;

#define STRSIZE 32

void* threadFunc(void* arg)
{
    int n = (int)arg;

    snprintf(varA, STRSIZE, "hello.%d", n);
    printf("thread %d : varA:%s\n", n, varA);
    sleep(2);
    printf("thread %d : after 2 secs. varA is :%s\n", n, varA);

    return NULL;
}

int main()
{
    pthread_t th1, th2;

    varA = (char*)malloc(STRSIZE);
    strcpy(varA, "good morning");
    printf("main-1: varA=%s\n", varA);
    pthread_create(&th1, NULL, threadFunc, (void*)1);
    sleep(1);
    printf("main-2: varA=%s\n", varA);
    pthread_create(&th2, NULL, threadFunc, (void*)2);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("main-3: varA=%s\n", varA);

    return 0;
}
