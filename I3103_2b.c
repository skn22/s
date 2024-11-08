Assignment 02(b)

Problem Statement:-
				Process Control system calls. The demonstratiion of FORK,EXECVE and WAIT system calls along with zombieand orphan states.

b. Implement the C program in which main program accepts an integer array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an integer array and passes the sorted array to child process through the command line arguments of EXECVE system call. The child process uses EXECVE system call to load new program that uses this sorted array for performing the binary search to search the particular item in the array.

*/
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



## second code 

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

##OUTPUT-


student@student-OptiPlex-390:~/nitin111$ gcc execve.c -o execve
student@student-OptiPlex-390:~/nitin111$ gcc dsc11.c -o dsc
student@student-OptiPlex-390:~/nitin111$ ./execve dsc 2 5 4 7 9

Sorted Array is:
2
4
5
7
9

I am Child Process,my pid is 2815 
I am Parent Process,my pid is 2814 

Pid of the 2nd program is:2815

Sorted Array is:
9
7
5
4
2

I am Parent Process,my pid is 2814 
I am Parent's Parent Process,my pid is 2666 

