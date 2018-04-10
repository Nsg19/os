#include<iostream>
#include<unistd.h>
using namespace std;
int time=0;
class Scheduling
{	public:
	int arrival_time[10],at[10],burst_time[10],bt[10],waiting_time[10],cpu_assign_time[10];
	int process_completion_time[10],flag[10],stop[10],process[10];
};

struct node
{
    Scheduling data;
    node *next;
}*front = NULL,*rear = NULL,*p = NULL,*np = NULL;

void push(Scheduling x)
{
    np = new node;
    np->data = x;
    np->next = NULL;
    if(front == NULL)
    {
        front = rear = np;
        rear->next = NULL;
    }
    else
    {
        rear->next = np;
        rear = np;
        rear->next = NULL;
    }
}

Scheduling remove()
{
    Scheduling x;
    if(front == NULL)
    {
        cout<<"empty queue\n";
    }
    else
    {
        p = front;
        x = p->data;
        front = front->next;
        delete(p);
        return(x);
    }
}



main()
{
	system("color f3");
	Scheduling a[10];
	int i,j,k,n,time_quantum;
	cout<<"\n============================================= ROUND ROBIN SCHEDULING ===================================================\n";
	cout<<"Enter number of Process:-\n";
	cin>>n;
	cout<<"Enter Time Quantum for all process:\n";
	cin>>time_quantum;
	cout<<"================================================= ARRIVAL TIME =========================================================\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter Arrival Time for Process-"<<i+1<<":\n";
		cin>>a[i].arrival_time[i];
		a[i].process[i]=i;
	}
	cout<<"================================================ CPU BURST TIME ========================================================\n";
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
cout<<"\n================================================= FINAL RESULT =========================================================\n";
cout<<"Time Quantum:- "<<time_quantum<<"\n\n";
cout<<"Chart:-\n\n";
cout<<"  ";
if(a[0].arrival_time[0]!=0)
{
cout<<"0__ - __";
}


Scheduling r[1];

int count=1;
int nsg=1;
int z=1;

push(a[0]);
cout<<"\n\n\nMy push="<<a[0].process[0]<<"\n\n\n";
while(time<sum_bt)
{
	for(k=0;k<n;k++)
	{
		r[0]=remove();
		cout<<"\n\n\nMy Pop="<<r[0].process[0]<<"\n\n\n";
		z=1;
		if((r[0].burst_time[0]<time_quantum)&&(r[0].burst_time[0]!=0))
		{
			if(r[0].flag[0]==0)
			{
				if(r[0].arrival_time[0]<=time)
				{
					r[0].cpu_assign_time[0]=time;
				}
				else
				{
					r[0].cpu_assign_time[0]=r[0].arrival_time[0];
					time=r[0].arrival_time[0];
				}
				r[0].flag[0]=1;
			}
			cout<<time;
			time=time+r[0].burst_time[0];
			system("color 2B");
			cout<<"___|P"<<r[0].process[0]+1<<"|___";
		//	sleep(burst_time[0]);
			r[0].burst_time[0]=0;
		}
			
		if(r[0].burst_time[0]>=time_quantum)
		{
			system("color f3");
			if(r[0].flag[0]==0)
			{
				if(r[0].arrival_time[0]<=time)
				{
					r[0].cpu_assign_time[0]=time;
				}
				else
				{
					r[0].cpu_assign_time[0]=r[0].arrival_time[0];
					time=r[0].arrival_time[0];
				}
				r[0].flag[0]=1;
			}
			cout<<time;
			if(r[0].burst_time[0]!=0)
			{
				r[0].burst_time[0]-=time_quantum;
				time+=time_quantum;
			}
			cout<<"___|P"<<r[0].process[0]+1<<"|___";
		//	sleep(time_quantum);		
		}
	
		if(r[0].burst_time[0]==0&&r[0].stop[0]==0)
		{
			system("color 2B");
			r[0].process_completion_time[0]=time;
			r[0].stop[0]=1;	
		}
		
		
		for(int s=nsg;s<n;s++)
		{
			if(a[s].arrival_time[s]<=time&&a[s].stop[s]!=1)
			{
				//cout<<"\n\nNsg="<<nsg<<"\n\n\n\n";
				push(a[s]);
				cout<<"\n\n\nMy Push 2="<<a[s].process[s]<<"\n\n\n";
				count++;
			}								
		}
		
		nsg=count;
			//	cout<<"\n"<<r[0].process[0]<<"\t"<<r[0].burst_time[0]<<"\t"<<r[0].arrival_time[0]<<"\n";
		
		push(r[0]);	
			//cout<<"\n\n\nRunning\n\n";
		
		
	}

}
//system("color f3");
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
