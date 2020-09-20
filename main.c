#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define THREADS_NUM 6

void *allocateMemmory();

int main(int argc, char const *argv[])
{
    pthread_t ids[THREADS_NUM];
    int i = 0;
    for (; i < THREADS_NUM; ++i)
    {
        int ret = pthread_create(&ids[i], NULL, allocateMemmory, NULL);
        // For Debug
        printf("%d\n", ret);
    }

    pthread_exit(NULL);
    return 0;
}

void *allocateMemmory()
{
    void *a;
    // Allocate memory without releasing it
    a = malloc(1024);
    fork();
    memset(a, 0, 1024);
    allocateMemmory();
}