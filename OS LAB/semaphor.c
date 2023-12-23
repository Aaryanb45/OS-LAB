
#include<pthread.h>
#include<stdio.h>
#include <dispatch/dispatch.h>
#include<semaphore.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1; //shared variable
sem_t s; //semaphore variable
int main()
{
   sem_init(&s,0,1);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,fun1,NULL);
    pthread_create(&thread2,NULL,fun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Final value of shared is %d\n",shared);//prints the last updated value of shared variable
}
void *fun1()
{
    int x;
    sem_wait(&s); //executes wait operation on s
    x=shared; //thread1 reads value of shared variable
    printf("thread1 reads the value as %d\n",x);
    x++;  //thread1 increment its value
    printf("local updation by thread1: %d\n",x);
    sleep(1); //thread1 is preempted by thread 2
    shared=x;  //thread one updates value of shared variable 
    printf("value fo shared variable updated by thread1 is: %d\n",shared);
    sem_post(&s);
}
void *fun2()
{
    int y;
    sem_wait(&s);
    y=shared; //thread2 reads value of shared variable
    printf("thread2 reads value as %d\n",y);
    y--;
    printf("local updation by thread2: %d \n",y);
    sleep(1);
    shared=y;
    printf("value of shared variable updated by thread2 is: %d\n",shared);
    sem_post(&s);
}