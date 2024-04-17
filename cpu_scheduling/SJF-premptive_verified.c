#include<stdio.h>
#include<limits.h>
struct Process{
	int pid;
	int bt;
	int at;
};
typedef struct Process pros;

void findwt(pros proc[],int n,int wt[])
{
	int rt[n];
	for(int i=0;i<n;i++)
	{
		rt[i]=proc[i].bt;
	}
	int complete=0,t=0,minm=INT_MAX;
	int shortest=0,finish_time;
	int check=0;
	while(complete!=n)
	{
		for(int j=0;j<n;j++)
		{
			if((proc[j].at<=t)&&(rt[j]<minm)&&(rt[j]>0))
			{
				minm=rt[j];
				shortest=j;
				check=1;
			}
		}
		if(check==0)
		{
			t++;
			continue;
		}
		rt[shortest]--;
		minm=rt[shortest];
		if(minm==0)
			minm=INT_MAX;
		if(rt[shortest]==0)
		{
			complete++;
			check=0;
			finish_time=t+1;
			wt[shortest]=finish_time-proc[shortest].bt-proc[shortest].at;
			if(wt[shortest]<0)
			{
				wt[shortest]=0;
			}
		}
		t++;
	}
}

void findtat(pros proc[],int n,int wt[],int tat[])
{
	for(int i=0;i<n;i++)
		tat[i]=proc[i].bt+wt[i];
}

void findavgtime(pros proc[],int n)
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	findwt(proc,n,wt);
	findtat(proc,n,wt,tat);
	printf("\nProcess\tBT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		total_wt+=wt[i];
		total_tat+=tat[i];
		printf("%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].bt,wt[i],tat[i]);
	}
	printf("Avg WT = %f",((float)total_wt/(float)n));
	printf("Avg TAT = %f",((float)total_tat/(float)n));
}

int main()
{
	int i,n;
	printf("Enter the no.of process: ");
	scanf("%d",&n);
	pros proc[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the arival time and the burst time for process %d: ",i+1);
		scanf("%d %d",&proc[i].at,&proc[i].bt);
		proc[i].pid=i+1;		
	}
	findavgtime(proc,n);
	return 0;	
}
