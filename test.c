/* Name: Ayush Mahant
   Roll_Number: 2019353 */


#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char** argv)
{  
char as[500];
//char ss[550];
//printf("Enter pid");
int pid;
scanf("%d%s",&pid,as);
//printf("ssd");
//printf(ss);

//int pid=atoi(ss);

//scanf("%d\n",&pid);
	//int pid=atoi(scanf(");
	
	//printf("Enter filename : ");
	
	//pid=atoi(argv[1]);
	//strcpy(as,argv[2]);
	//printf(as);
	char cwd[1000];
if(getcwd(cwd,sizeof(cwd)) !=NULL)
{strcat(cwd,"/");
strcat(cwd,as);
}
	strcat(cwd,"\0");
	long int status = syscall(548, pid, cwd); 
	if(status == 0) 
printf("System call is executed correctly , use dmesg\n ");

	else 
	{
printf("System did not execute correctly\n");
perror("Error ");
printf("Error No. is : %d\n", errno);
	}
return 0;
}
