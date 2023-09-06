#include<stdio.h>
void fcfs(int arrival_time[],int burst_time[],int job_number)
{           
	    //declarating arrays of calculating required parameters.
            int completion_time[job_number],turnaround_time[job_number],
	    waiting_time[job_number];
            printf("%s","--------------------------------");
            int i,j;
            int flag=0,time=0;
            float avg_turnaround_time=0,avg_waiting_time=0;
            for(i=0;i<job_number;i++)
	    {
	        if(flag<arrival_time[i])
		{
		   time=arrival_time[i]-flag;
		}
		//flag is used to set processes according to its arrival time
	        flag=flag+burst_time[i]+time;
                time=0;	 
		//calculating completion time
	        completion_time[i]=flag;
		//calculating turn around time
	        turnaround_time[i]=completion_time[i]-arrival_time[i];
	        //calculating sum of all turn around time
	       	avg_turnaround_time=avg_turnaround_time+turnaround_time[i];
		//calculating  waiting time
	        waiting_time[i]=turnaround_time[i]-burst_time[i];
		//calculate sum of waiting_time
	        avg_waiting_time=avg_waiting_time+waiting_time[i];
	    }
            printf("\n-------------------------------\n");
                printf("\nAbbreviations Used.....\n");
    printf("\nPid   :Process ID\n");
    printf("\nAT    :Arrival TIme\n");
    printf("\nBT    :Burst Time\n");
    printf("\nCT    :Completion Time\n");
    printf("\nTAT   :Turn Around Time\n");
    printf("\nWT    :Waiting Time\n");
    printf("\nProcess Table\n");
    printf("\nPid\tAT\tBT\t CT\tTAT\tWT\n");
	    for(i=0;i<job_number;i++)
	    {
		   printf("J-%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arrival_time[i],burst_time[i],completion_time[i],turnaround_time[i],waiting_time[i]);
	     }
	    printf("Average Turnaround Time=%f",avg_turnaround_time/job_number);
	   printf("\nAverage Waiting Time=%f",avg_waiting_time/job_number); 
	   printf("\n");

}
 void sjf(int arrival_time[],int burst_time[],int job_number)
 {
   int Bt[job_number],Ct[job_number];
   int i,j;
   for(i=0;i<job_number;i++)
   {
	   Bt[i]=burst_time[i];
   }
   int count=0;
   j=0;
   while(j<job_number)
   {
     int min_limit=1000,index=-1;
     for(i=0;i<job_number;i++)
     {
	     if(Bt[i]==min_limit)
	     {
		     if(arrival_time[i]<arrival_time[index])

		     {
			     index=i;
		     }
	     }
	     else if(Bt[i]<min_limit)
	     {
	            if(arrival_time[i]<=count)
	            {
	                     min_limit=Bt[i];
	                     index=i;
	             }
             }
     }
     if(index!=-1)
     {
	Ct[index]=burst_time[index]+count;
        count+=burst_time[index];
	j++;
	Bt[index]=1001;
     }
     else
     {
	count++;
     }
  
   }
    int TAT[job_number],WT[job_number];
    for(i=0;i<job_number;i++)
    TAT[i]=Ct[i]-arrival_time[i];
    for(i=0;i<job_number;i++)
    WT[i]=TAT[i]-burst_time[i];
    float avg_var=0;
    printf("\nAbbreviations Used.....\n");
    printf("\nPid   :Process ID\n");
    printf("\nAT    :Arrival TIme\n");
    printf("\nBT    :Burst Time\n");
    printf("\nCT    :Completion Time\n");
    printf("\nTAT   :Turn Around Time\n");
    printf("\nWT    :Waiting Time\n");
    printf("\nProcess Table\n");
    printf("\nPid\tAT\tBT\t CT\tTAT\tWT\n");
    for(i=0;i<job_number;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),arrival_time[i],burst_time[i],Ct[i],TAT[i],WT[i]);	    
   
    for(i=0;i<job_number;i++)
    avg_var+=(float)TAT[i];
    printf("\nAverage Turnaround Time: %f",avg_var/job_number);
    avg_var=0;
    for(i=0;i<job_number;i++)
    avg_var+=(float)WT[i];
    printf("\nAverage Waiting Time: %f",avg_var/job_number);
    printf("\n");
}    

			     
