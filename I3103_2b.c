NAME :  Prathamesh Amrutkar
Roll no :I3103
Assignment 02(b)

Problem Statement:-B. Implement the C program in which main program accepts an array.
Main program uses the FORK
system call to create a new process called a child process. Parent
process sorts an array and passes the
sorted array to child process through the command line arguments of
EXECVE system call. The child
process uses EXECVE system call to load new program which display
array in reverse order.


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void bubble_sort(int a[50],int n)
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
	printf("\nSorted Array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

int main(int argc,char *argv[])
{
	int i,j=2,l,k;
	
 	int n=argc-2;
	int a[n];
	char *args[n+1];
	args[0]=argv[1];
	
	for(i=1;i<=n;i++,j++)
	{
		args[i]=argv[j];
	}
	args[i]=(char*)0;
	
	for(l=0,i=1;i<=n;i++,l++)
	{
		a[l]=atoi(args[i]);
	}
	bubble_sort(a,n);
	
	for(l=0,i=1;i<=n;i++,l++)
	{
		sprintf(args[i],"%d",a[l]);
	}
	
	pid_t pid;
	pid=fork();
	
	if(pid==0)
	{
		printf("\nI am Child Process,my pid is %d \n",getpid());
		printf("I am Parent Process,my pid is %d \n",getppid());
		execve(argv[1],args,NULL);
	}
	else
	{
		k=wait(0);
		printf("\nI am Parent Process,my pid is %d \n",getpid());
		printf("I am Parent's Parent Process,my pid is %d \n\n",getppid());		
	}
	
	return 0;
}

#include<stdio.h>


void bubble_sort(int a[50],int n)
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
	printf("\nSorted Array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
int main(int argc,char *argv[])
{	
	int i,j=1,l,key;
	
	int n=argc-1;
	int a[n];
	char *args[n+1];
	
	printf("\nPid of the 2nd program is:%d\n",getpid());
	
	for(i=0;i<=n;i++,j++)
	{
		args[i]=argv[j];
	}
	args[i]=(char*)0;
	
	for(l=0,i=0;i<n;i++,l++)
	{
		a[l]=atoi(args[i]);
	}
	
	bubble_sort(a,n);
}



OUTPUT:

prathamesh@linux:~/Desktop$ ./First second 2 3 5 4 1

Sorted Array is:
1
2
3
4
5

I am Child Process,my pid is 3052 
I am Parent Process,my pid is 3051 

I am Parent Process,my pid is 3051 
I am Parent's Parent Process,my pid is 2923 

