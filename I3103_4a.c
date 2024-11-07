Prathamesh Balasaheb Amrutkar
Roll  no : I3103 Div-1
A. Thread synchronization using counting semaphores. Application to
demonstrate: producer- consumer problem with counting semaphores
and mutex.

#include<stdio.h>
#include<stdlib.h>
#include<sys/syscall.h>
#include<pthread.h>
#include <unistd.h>
#include<semaphore.h>
void *producer();
void *consumer();
typedef struct{
        int buff[20];
        sem_t full,empty;
        
}shared;
shared sh;
int item;
int in=0,out=0;
sem_t mutex;
int main()
{
        pthread_t ptid1,ptid2,ctid1;
        sem_init(&sh.empty,0,20);
        sem_init(&sh.full,0,0);
        sem_init(&mutex,0,1);
        
        pthread_create(&ptid1,NULL,producer,NULL);
        pthread_create(&ptid2,NULL,producer,NULL);
        pthread_create(&ctid1,NULL,consumer,NULL);
        
        pthread_join(ptid1,NULL);
        pthread_join(ctid1,NULL);
        pthread_join(ptid2,NULL);
        
        return 0;
}

        void *producer()
        {
                int ptid;
                while(1)
                {
                        item=in;
                        sem_wait(&sh.empty);
                        sem_wait(&mutex);
                       
                       
                        sh.buff[in++]=item;
                         printf("\n producer thread id and producer item:%d,%d\n", syscall(SYS_gettid,ptid),item);
                        sem_post(&mutex);
                        sem_post(&sh.full);
                        sleep(2);
                }
        }
        
        void *consumer()
        {
                int ctid;
               //sleep(1);
                while(1)
                {
                        while(out<=in)
                        {
                             sem_wait(&sh.full);
                             sem_wait(&mutex); 
                             item=sh.buff[out++];
                             printf("\nconsumer thread id and consumer item:%d,%d\n",syscall(SYS_gettid,ctid),item);
                                    
                            sem_post(&mutex);
                            sem_post(&sh.empty);
                                    sleep(2);
                        }
                }
        }
        
/*
(base) student@ubuntu:~/Desktop$ ./a

producer thread id and producer item:4303,0

consumer thread id and consumer item:4304,0

producer thread id and producer item:4302,0

consumer thread id and consumer item:4304,0

producer thread id and producer item:4303,2

producer thread id and producer item:4302,3

consumer thread id and consumer item:4304,2

producer thread id and producer item:4302,4

producer thread id and producer item:4303,4

producer thread id and producer item:4303,6

consumer thread id and consumer item:4304,3

producer thread id and producer item:4302,3

consumer thread id and consumer item:4304,4

producer thread id and producer item:4303,8

producer thread id and producer item:4302,8

consumer thread id and consumer item:4304,4

producer thread id and producer item:4302,10

producer thread id and producer item:4303,11

producer thread id and producer item:4302,12

consumer thread id and consumer item:4304,6

producer thread id and producer item:4303,6

consumer thread id and consumer item:4304,3

producer thread id and producer item:4303,14

producer thread id and producer item:4302,14

consumer thread id and consumer item:4304,8

producer thread id and producer item:4303,16

producer thread id and producer item:4302,16

producer thread id and producer item:4302,18

producer thread id and producer item:4303,19

consumer thread id and consumer item:4304,8

producer thread id and producer item:4302,20

producer thread id and producer item:4303,21

consumer thread id and consumer item:4304,10

consumer thread id and consumer item:4304,11

producer thread id and producer item:4303,22

*/
