// priority CPU scheduling (non-preemptive)
#include<bits/stdc++.h>
using namespace std;

class priority_non_preemptive_Process  // each process will have the following attributes
{
    public:
    int no;		//process number
    int atime;	//arrival time
    int btime;	//burst time
    int stime;  //start time
    int ctime;	//completion time
    int wtime;	//waiting time
    int ttime;	//turn around time
    int rtime;  //response time
    int priority;   //priority of the process (higher number <=> higher priority)
    int is_completed;   //to flag process that is completed
};

bool comp_non_priority(priority_non_preemptive_Process  P, priority_non_preemptive_Process  Q) //to sort according to arrival time and priority
{
    if(P.atime==Q.atime && P.priority!=Q.priority)
        return P.priority>Q.priority;
    if(P.atime==Q.atime && P.priority==Q.priority)
        return P.no<Q.no;
    return (P.atime<Q.atime);
}

int priority_non_p_main()
{
    int n;
    float sum_ttime=0,sum_wtime=0,sum_rtime=0;

	cout<<"Enter the no. of Process to be performed : ";
    cin>>n;

    vector<priority_non_preemptive_Process > p(n);   //creating array for the class

    for(int i = 0; i < n; i++)
    {
        //0 is the lowest priority
		cout<<"\nEnter the Arrival time, Burst Time and Priority for Process "<<i+1<<":\n";
        cin>>p[i].atime>>p[i].btime>>p[i].priority;;
        p[i].no = i+1;
        p[i].is_completed=0;
    }

    sort(p.begin(),p.end(),comp_non_priority); //sorting the Processes according to arrival time and priority

    int current_time = 0;
    int completed = 0;

    while(completed != n)
    {
        int idx=-1;
        int high_pri=-1;
        //finding process with highest priority among the process that have arrived till now
        for(int i = 0; i < n; i++)
        {
            if(p[i].atime <= current_time && p[i].is_completed == 0)
            {
				if (high_pri < p[i].priority)
                {
                    high_pri=p[i].priority;
                    idx = i;
				}
            }
        }
        //find all times of idx
        if(idx!=-1)
        {
            p[idx].stime = current_time;
            p[idx].ctime = p[idx].stime + p[idx].btime;
            p[idx].ttime = p[idx].ctime - p[idx].atime;
            p[idx].wtime = p[idx].ttime - p[idx].btime;
            p[idx].rtime = p[idx].stime - p[idx].atime;
            p[idx].rtime = p[idx].stime - p[idx].atime;
            sum_ttime += p[idx].ttime;
            sum_wtime += p[idx].wtime;
            sum_rtime += p[idx].rtime;
            p[idx].is_completed = 1;  //flagging the process as completed
            completed++;
            current_time = p[idx].ctime;
        }
        else
            current_time++;
    }

    //Displaying the times in tabular form
    cout<<"\n\nP.no.\tAT\tBT\tCT\tTAT\tWT\tRT\n"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<p[i].no<<"\t";
        cout<<p[i].atime<<"\t";
        cout<<p[i].btime<<"\t";
        cout<<p[i].ctime<<"\t";
        cout<<p[i].ttime<<"\t";
        cout<<p[i].wtime<<"\t";
        cout<<p[i].rtime<<"\t"<<"\n";
    }
    cout<<"\nAverage Turnaround Time = "<<sum_ttime/n<<endl;
    cout<<"Average Waiting Time = "<<sum_wtime/n<<endl;
    cout<<"Average Response Time = "<<sum_rtime/n<<endl;
}
