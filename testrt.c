/* Name: Aditi Sejal
   Roll_Number: 2019228 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<errno.h>

int main()
{
	pid_t pid;	
	pid = fork();
	if(pid < 0){
		printf("Error %d\n", errno);
	}
	else if(pid == 0)
	{
		struct timeval start, end;
		syscall(440, getpid(), 100000000);
		gettimeofday(&start,NULL);	
		for(int i = 0;i<10000000;i++);
		gettimeofday(&end, NULL);
		printf("\nProcess with lower soft real-time rqmnt: %lf milliseconds\n",(double)(end.tv_usec-start.tv_usec)/1000 + (double)(end.tv_sec-start.tv_sec)*1000);
		exit(0);
	}
	else
	{
		struct timeval start, end;
		syscall(440, getpid(), 90000000000);
		gettimeofday(&start, NULL);	
		for(int i = 0;i<10000000;i++);
		gettimeofday(&end, NULL);		
		printf("\nProcess with higher soft real-time rqmnt: %lf milliseconds\n",(double)(end.tv_usec-start.tv_usec)/1000 + (double)(end.tv_sec-start.tv_sec)*1000);
		wait(NULL);
	}
	return 0;

}
