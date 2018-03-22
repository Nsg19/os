#include<iostream>
using namespace std;
int time=0;
main()
{
	int arrival_time[10],burst_time[10],i,j,time_quantum,n,bt[10],flag[10],count[10];
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
		bt[j]=burst_time[j];
		flag[j]=0;
		count[j]=0;
	}
}
