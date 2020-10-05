#include <COMMON.h>

#define DATASIZE 10000
#define THEADS 10

int data[DATASIZE];

typedef struct {
    size_t startIndex;
    size_t endIndex;
} ThreadContext;

void setRanddomData()
{
    int i;
    for(i = 0; i <DATASIZE; i++)
        data[i] = rand();
}


int getMax(ThreadContext* ctx)
{
    int max = data[ctx->startIndex];
    size_t index;
    for(index = ctx->startIndex + 1 ; index <= ctx->endIndex; index++)
        if(max < data[index])
            max = data[index];

    return max;
}

void* threadFunc(void* arg)
{
    int n = (int)arg;
    ThreadContext ctx;
    ctx.startIndex = (DATASIZE/THEADS) * n;
    ctx.endIndex = ctx.startIndex + (DATASIZE/THEADS) - 1;
    int max = getMax(&ctx);
    
    return (void*)max;
}

int main()
{
    pthread_t thread[THEADS];
    int res[THEADS];
    int i, max;

    srand(time(NULL));
    setRanddomData();

    for(i = 0; i < THEADS; i++)
        pthread_create(&(thread[i]), NULL, threadFunc, (void*)i);

    for(i = 0; i < THEADS; i++)
        pthread_join(thread[i], (void**)&(res[i]));

    max = res[0];
    for(i = 1; i <THEADS; i++)
        if(max < res[i])
            max = res[i];

    printf("max is %d\n", max);

    return 0;
}
