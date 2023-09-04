//Program to syncronize the counter between two threads

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t m;

void *thread1(void *arg)
{
    pthread_mutex_lock(&m);
    for(int i=1;i<=3;i++)
    {
        printf("\nThread 1:%d",i);
    }
    pthread_mutex_unlock(&m);
    sleep(0.1);
    pthread_mutex_lock(&m);
    for(int i=7;i<=10;i++)
    {
        printf("\nThread 1:%d",i);
    }
    pthread_mutex_unlock(&m);
}
void *thread2(void *arg)
{
    pthread_mutex_lock(&m);
    for(int i=4;i<=6;i++)
    {
        printf("\nThread 2:%d",i);
    }
    pthread_mutex_unlock(&m);
}
int main(int *args)
{
    pthread_t t1,t2;
    
    pthread_create(&t1,NULL,thread1,NULL);
    pthread_create(&t2,NULL,thread2,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}

/*
Thread 1:1
Thread 1:2
Thread 1:3
Thread 2:4
Thread 2:5
Thread 2:6
Thread 1:7
Thread 1:8
Thread 1:9
Thread 1:10
*/
