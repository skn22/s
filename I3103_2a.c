NAME :  Prathamesh Amrutkar
Roll no :I3103

Assignment 02(a)

A. Implement the C program in which main program accepts the
integers to be sorted. Main program
uses the FORK system call to create a new process called a child
process. Parent process sorts the integers using sorting algorithm and
waits for child process using WAIT system call to sort the integers
using any sorting algorithm. Also demonstrate zombie and orphan
states.


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void bubble_acs(int a[50],int n)
{
	int i,j,temp;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}	
	}
}

void bubble_dcs(int a[50],int n)
{
	int i,j,temp;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}	
	}
}

int main()
{
	int pid,i,n,a[50],j;
	printf("\nEnter the Number of elements:");
	scanf("%d",&n);
	printf("\nEnter List of Numbers:\n");
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
	}
	pid=fork();
	if(pid==0)
	{
		/* ORPHAN STATE */
		
		sleep(5);
		printf("\n");
		system("ps -el|grep init");
		
		printf("\nI am Child Process,my pid is %d \n",getpid());
		printf("\nI am Parent Process,my pid is %d \n",getppid());
		bubble_acs(a,n);
		printf("\nList of Numbers in Ascending Order:\n");
		for(j=0;j<n;j++)
		{
			printf("%d\n",a[j]);
		}
	}
	else
	{
	   	/* ZOMBIE STATE */
	   	
	   	system("ps -el|grep Z");
		i=wait(0);
		printf("\nPID of the terminated child process is %d\n",i);
		
		printf("\nI am Parent Process,my pid is %d \n",getpid());
		printf("\nI am Parent's Parent Process,my pid is %d \n",getppid());
		bubble_dcs(a,n);
		printf("\nList of Numbers in Descending Order:\n");
		for(j=0;j<n;j++)
		{
			printf("%d\n",a[j]);
		}
	}
	return 0;
}

OUTPUT:

ORPHAN STATE:

Enter the Number of elements:1 2 3 4 5 6

Enter List of Numbers:
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD

I am Parent Process,my pid is 6430 

I am Parent's Parent Process,my pid is 6280 

List of Numbers in Descending Order:
2
prathamesh@linux:~/Desktop$ 

I am Child Process,my pid is 6431 

I am Parent Process,my pid is 1051 

List of Numbers in Ascending Order:
2


ZOMBIE STATE:


Enter the Number of elements:1 2 3 5 6

Enter List of Numbers:

I am Child Process,my pid is 6391 

I am Parent Process,my pid is 6386 

List of Numbers in Ascending Order:
2
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
1 Z  1000    6391    6386  0  80   0 -     0 -      pts/0    00:00:00 Ass2 <defunct>

PID of the terminated child process is 6391

I am Parent Process,my pid is 6386 

I am Parent's Parent Process,my pid is 6280 

List of Numbers in Descending Order:
2


