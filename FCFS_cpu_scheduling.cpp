// FCFS CPU scheduling
#include<bits/stdc++.h>
using namespace std;

class Process // each process will have the following attributes
{
    public:
    int no;		//process number
    int atime;	//arrival time
    int btime;	//burst time
    int ctime;	//completion time
    int stime;  //start time
    int wtime;	//waiting time
    int rtime;  //response time
    int ttime;	//turn around time
};

bool comp_atime(Process P, Process Q) //to sort according to arrival time
{
    if(P.atime==Q.atime)
        return P.no<Q.no;
    return (P.atime<Q.atime);
}


int main()
{
	int n;
	float sum_wtime=0.0,sum_ttime=0.0,sum_rtime=0.0;

	cout<<"Enter the no. of process to be performed : ";
	cin>>n;
	vector<Process> P(n);	//creating array for the class

	for(int i=0;i<n;i++)
	{
	    P[i].no=i+1;
		cout<<"\nEnter the Arrival time and Burst Time for Process "<<i+1<<":\n";
		cin>>P[i].atime >>P[i].btime;
	}

    sort(P.begin(),P.end(),comp_atime); //sorting the processes according to arrival time

	int time=0;		//for calculating the start time of a process

	// this loop will calculate Completion time, turn around time, waiting time of each process
	for(int i=0;i<n;i++)
	{
		time=max(time,P[i].atime);
		P[i].stime=time;
		time=time+P[i].btime;
		P[i].ctime=time;
		P[i].ttime=P[i].ctime-P[i].atime;
		P[i].wtime=P[i].ttime-P[i].btime;
		P[i].rtime=P[i].stime-P[i].atime;
		sum_rtime += P[i].rtime;
		sum_wtime+=P[i].wtime;
		sum_ttime+=P[i].ttime;
	}

	//Displaying the times in tabular form
	cout<<"\n\nP.no.\tAT\tBT\tCT\tTAT\tWT\tRT\n"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<P[i].no<<"\t";
        cout<<P[i].atime<<"\t";
        cout<<P[i].btime<<"\t";
        cout<<P[i].ctime<<"\t";
        cout<<P[i].ttime<<"\t";
        cout<<P[i].wtime<<"\t";
        cout<<P[i].rtime<<"\t"<<"\n";
    }
    cout<<"\nAverage Turnaround Time = "<<sum_ttime/n<<endl;
    cout<<"Average Waiting Time = "<<sum_wtime/n<<endl;
    cout<<"Average Response Time = "<<sum_rtime/n<<endl;
}
