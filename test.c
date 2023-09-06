#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "header.h"
int main()
{ 
  int  p=1;
  do{
  printf("-----------------------------------------");	  
  printf("\nEnter 1 for First Come First Served\n");
  printf("Enter 2 for Shortest Job First\n");
  printf("Enter 3 for Exit\n");
  printf("Enter your Choice\n");
  int n;
  scanf("%d",&n);
	if(n==3) exit(0);
  int job_number;
    printf("Total Number Of Processes: ");
    scanf("%d",&job_number);
   int arrival_time[job_number],burst_time[job_number];
    for(int i=0;i<job_number;i++)
    {     printf("\nEnter Arrival Time for Process Number %d\n",i+1);
          scanf("%d",&arrival_time[i]);
    }
    for(int j=0;j<job_number;j++)
    {     printf("\nEnter Burst Time for Process Number %d\n",j+1);
          scanf("%d",&burst_time[j]);
    }
 
    switch(n)
    {
       case 1:
        fcfs(arrival_time,burst_time,job_number);
        break;
       case 2:
        sjf(arrival_time,burst_time,job_number);
        break;
       case 3:
        p=0;
        exit(0);   
        break;
    }
  
   }while(p); 
	  
}
 
