#include<iostream>
using namespace std;
int time=0;
main()
{
	int arrival_time[10],burst_time[10],bt[10],i,j,k,n,time_quantum,comming_time[10],flag[10];
	cout<<"enter no of process\n";
	cin>>n;
	cout<<"Enter Time Quantum for all process:\n";
	cin>>time_quantum;
	cout<<"================================ARRIVAL TIME==============================================\n";
	for(i=0;i<n;i++)
	{
		cout<<"Arrival time for Process-"<<i+1<<":\n";
		cin>>arrival_time[i];
	}
	cout<<"================================CPU BURST TIME=============================================\n";
	for(j=0;j<n;j++)
	{
		cout<<"CPU burst for Process-"<<j+1<<":\n";
		cin>>burst_time[j];
	
	}

	for(k=0;k<n;k++)
	{
		if(burst_time[k]>=time_quantum)
		{
			burst_time[k]-=time_quantum;
			if(flag[k]==0)
			{
				if(arrival_time[k]<time)
				{
					comming_time[k]=time;
				}
				else
				{
					comming_time[k]=arrival_time[k];
					time=arrival_time[k];
				}
				flag[k]=1;
			}
			time+=time_quantum;
		}
		else
		{
			time=burst_time[k];
			burst_time[k]=0;
		}	
	}
}
