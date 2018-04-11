#include<iostream>
#include<unistd.h>
using namespace std;
int time=0;
class Scheduling
{	public:
	int arrival_time[20],at[20],burst_time[20],bt[20],waiting_time[20],cpu_assign_time[20];
	int process_completion_time[20],flag[20],stop[20],process[20];
};

int q[100];
int front=-1,rear=-1;
void push(int i)
{
if(rear==100)
printf("overflow");
rear++;
q[rear]=i;
if(front==-1)
front=0;
}

int pop()
{
if(front==-1)
printf("underflow");
int temp=q[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}

main()
{
	system("color f3");
	Scheduling a[10];
	int i,j,k,n,time_quantum;
	cout<<"\n============================================= ROUND ROBIN SCHEDULING ===================================================\n";
	cout<<"\nEnter number of Process:-\n";
	cin>>n;
	cout<<"\nEnter Time Quantum for all process:\n";
	cin>>time_quantum;
	cout<<"\n================================================= ARRIVAL TIME =========================================================\n";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter Arrival Time for Process-"<<i+1<<":\n";
		cin>>a[i].arrival_time[i];
		a[i].process[i]=i;
	}
	cout<<"\n================================================ CPU BURST TIME ========================================================\n";
	int sum_bt=0;
	for(j=0;j<n;j++)
	{
		cout<<"Enter CPU Burst for Process-"<<j+1<<":\n";
		cin>>a[j].burst_time[j];
		a[j].bt[j]=a[j].burst_time[j];
		a[j].flag[j]=0;
		a[j].stop[j]=0;
		sum_bt+=a[j].burst_time[j];
	}
	cout<<"\n"<<sum_bt<<"\n";
	
	int temp;	
	for (i=1;i<n;i++)
	{
		for (j=0;j<n-i;j++)
		{
			if (a[j].arrival_time[j]>a[j+1].arrival_time[j+1])
			{
				temp=a[j].arrival_time[j];
				a[j].arrival_time[j]=a[j+1].arrival_time[j+1];
				a[j+1].arrival_time[j+1]=temp;
				
				temp=a[j].burst_time[j];
				a[j].burst_time[j]=a[j+1].burst_time[j+1];
				a[j+1].burst_time[j+1]=temp;
				
				temp=a[j].process[j];
				a[j].process[j]=a[j+1].process[j+1];
				a[j+1].process[j+1]=temp;
				
			}
		}
	}

	for(i=0;i<n;i++)
	{
		a[i].bt[i]=a[i].burst_time[i];
	}	
	
	int max=a[0].bt[0],index=0;
	for(i=1;i<n;i++)
	{
		if(max<a[i].bt[i])
		{
			max=a[i].bt[i];
			index=i;	
		}
	}	
if(time_quantum!=0)
{	
cout<<"\n\n================================================= FINAL RESULT =========================================================\n";
cout<<"Time Quantum:- "<<time_quantum<<"\n";
cout<<"Gantt Chart:-\n\n";
cout<<"  ";
if(a[0].arrival_time[0]!=0)
{
cout<<"0__ - __";
}

int count=1;
int jump=1;
int r;
push(0);
while(a[index].burst_time[index]!=0)
{
	for(k=0;k<n;k++)
	{
		r=pop();
		if((a[r].burst_time[r]<time_quantum)&&(a[r].burst_time[r]!=0))
		{
			if(a[r].flag[r]==0)
			{
				if(a[r].arrival_time[r]<=time)
				{
					a[r].cpu_assign_time[r]=time;
				}
				else
				{
					a[r].cpu_assign_time[r]=a[r].arrival_time[r];
					time=a[r].arrival_time[r];
				}
				a[r].flag[r]=1;
			}
			cout<<time;
			time=time+a[r].burst_time[r];
			system("color 2B");
			cout<<"___|P"<<a[r].process[r]+1<<"|___";
			sleep(a[r].burst_time[r]);
			a[r].burst_time[r]=0;
		}
			
		if(a[r].burst_time[r]>=time_quantum)
		{
			system("color f3");
			if(a[r].flag[r]==0)
			{
				if(a[r].arrival_time[r]<=time)
				{
					a[r].cpu_assign_time[r]=time;
				}
				else
				{
					a[r].cpu_assign_time[r]=a[r].arrival_time[r];
					time=a[r].arrival_time[r];
				}
				a[r].flag[r]=1;
			}
			cout<<time;
			if(a[r].burst_time[r]!=0)
			{
				a[r].burst_time[r]-=time_quantum;
				time+=time_quantum;
			}
			cout<<"___|P"<<a[r].process[r]+1<<"|___";
			sleep(time_quantum);		
		}
	
		if(a[r].burst_time[r]==0&&a[r].stop[r]==0)
		{
			system("color 2B");
			a[r].process_completion_time[r]=time;
			a[r].stop[r]=1;	
		}
				
		for(int s=jump;s<n;s++)
		{
			if(a[s].arrival_time[s]<=time&&a[s].stop[s]!=1)
			{
				push(s);
				count++;
			}
				
		}	
		
		push(r);
		jump=count;	
	}
}
system("color f3");
cout<<time;

for(j=0;j<n;j++)
{
	a[j].waiting_time[j]=a[j].process_completion_time[j]-a[j].bt[j]-a[j].arrival_time[j];
}

cout<<"\n\nPROCESS\t"<<"  ARRIVAL TIME\t"<<" CPU BURST TIME\t"<<"  CPU ASSING TIME\t"<<"COMPLETION TIME\t"<<"  WAITING TIME\n";
for(i=0;i<n;i++)
{
	cout<<"P"<<a[i].process[i]+1<<"\t\t"<<a[i].arrival_time[i]<<"\t\t"<<a[i].bt[i]<<"\t\t"<<a[i].cpu_assign_time[i]<<"\t\t\t"<<a[i].process_completion_time[i]<<"\t\t"<<a[i].waiting_time[i]<<"\n";
}

}

}
