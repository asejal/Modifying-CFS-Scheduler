/* Name: Aditi Sejal
   Roll_Number: 2019228 */
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <errno.h>

int main()
{
	struct timeval start, end;
	long flag;
	char err1[250], err2[250], err3[250];
	//Error 1
	printf("Calling system call\n");
	flag = syscall(440, getpid(), -23);			
	printf("System call rtnice returned %ld\n", flag);
	printf("Ending system call\n");
	if(flag == -1){
		sprintf(err1, "Error %d", errno);
		perror(err1);
	}
	gettimeofday(&start, NULL);
	for(int i=0;i<10000000;i++);
	gettimeofday(&end, NULL);		
	printf("Time from process with soft real-time guarante: %lf milliseconds\n",(double)(end.tv_usec-start.tv_usec)/1000 + (double)(end.tv_sec-start.tv_sec)*1000);
	//Error 2
	printf("\nCalling system call\n");
	flag = syscall(440, -34, 1000000);				
	printf("System call rtnice returned %ld\n", flag);
	printf("Ending system call\n");
	if(flag == -1){
		sprintf(err2, "Error %d", errno);
		perror(err2);
	}
	gettimeofday(&start, NULL);
	for(int i=0;i<10000000;i++);
	gettimeofday(&end, NULL);		
	printf("Time from process with soft real-time guarante: %lf milliseconds\n",(double)(end.tv_usec-start.tv_usec)/1000 + (double)(end.tv_sec-start.tv_sec)*1000);
	//Error 3
	printf("\nCalling system call\n");
	flag = syscall(440, 344, 1000000);				
	printf("System call rtnice returned %ld\n", flag);
	printf("Ending system call\n");
	if(flag == -1){
		sprintf(err3, "Error %d", errno);
		perror(err3);
	}
	gettimeofday(&start, NULL);
	for(int i=0;i<10000000;i++);
	gettimeofday(&end, NULL);		
	printf("Time from process with soft real-time guarante: %lf milliseconds\n",(double)(end.tv_usec-start.tv_usec)/1000 + (double)(end.tv_sec-start.tv_sec)*1000);
	return 0;
}