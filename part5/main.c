#include "COMMON.h"

int varA;

void procFunc(int arg)
{
    int n = arg;
    int varB;

    varB = 4 * n;
    printf("proc %d - 1 : varA:%d varB:%d\n", n, varA, varB);
    varA = 5*n;
    printf("proc %d - 2 : varA:%d varB:%d\n", n, varA, varB);
    sleep(2);
    printf("proc %d - 3 : varA:%d varB:%d\n", n, varA, varB);
    varB = 6*n;
    printf("proc %d - 4 : varA:%d varB:%d\n", n, varA, varB);
}

int main()
{
    pid_t p1, p2;
    int varB;

    varA = 1; varB = 2;
    printf("main-1: varA=%d varB=%d\n", varA ,varB);
    
    if((p1 = fork()) == 0)
    {
        //forkの戻り値が0である場合、子プロセス.
        procFunc(1);
    }

    sleep(1);

    varB=3;
    printf("main-2: varA=%d varB=%d\n", varA ,varB);

    if((p2 = fork()) == 0)
    {
        procFunc(2);
    }

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    printf("main-3: varA=%d varB=%d\n", varA ,varB);

    return 0;
}
