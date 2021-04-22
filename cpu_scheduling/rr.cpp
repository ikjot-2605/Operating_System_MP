// Round Robin CPU scheduling
#include<bits/stdc++.h>
using namespace std;

class Process // each process will have the following attributes
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
    int burst_remaining;
    int is_completed;
};

bool comp_atime(Process P, Process Q) //to sort according to arrival time
{
    if(P.atime==Q.atime)
        return P.no<Q.no;
    return (P.atime<Q.atime);
}

int rr_main()
{
    int n,time_slice,idx;
    float sum_ttime=0,sum_wtime=0,sum_rtime=0;

	cout<<"Enter the no. of Process to be performed : ";
    cin>>n;
    cout<<"Enter time slice : ";
    cin>>time_slice;

    vector<Process> p(n);   //creating array for the class

    for(int i = 0; i < n; i++)
    {
		cout<<"\nEnter the Arrival time and Burst Time for Process "<<i+1<<":\n";
        cin>>p[i].atime>>p[i].btime;
        p[i].no = i+1;
        p[i].is_completed=0;
        p[i].burst_remaining = p[i].btime;
    }

    sort(p.begin(),p.end(),comp_atime); //sorting the Processes according to arrival time

    queue<int> q;   //ready queue
    q.push(0);      //pushing first process in the queue

    int completed=0;
    int current_time=0;

    p[0].is_completed = 1;

    while(completed != n)
    {
        idx=q.front();
        q.pop();

        if(p[idx].burst_remaining==p[idx].btime)  //for the first time the process gets to CPU
        {
            p[idx].stime = max(current_time,p[idx].atime);
            current_time = p[idx].stime;
        }

        if(p[idx].burst_remaining-time_slice>0)   //assigning time slice to the process
        {
            p[idx].burst_remaining -= time_slice;
            current_time += time_slice;
        }
        else    //the process is complete
        {
            current_time += p[idx].burst_remaining;
            p[idx].burst_remaining = 0;
            completed++;

            p[idx].ctime = current_time;
            p[idx].ttime = p[idx].ctime - p[idx].atime;
            p[idx].wtime = p[idx].ttime - p[idx].btime;
            p[idx].rtime = p[idx].stime - p[idx].atime;

            sum_ttime += p[idx].ttime;
            sum_wtime += p[idx].wtime;
            sum_rtime += p[idx].rtime;
        }

        for(int i = 1; i < n; i++) //finding the processes that have arrived till now by checking arrival time
        {
            if(p[i].burst_remaining > 0 && p[i].atime <= current_time && p[i].is_completed == 0)
            {
                q.push(i);
                p[i].is_completed = 1;
            }
        }
        if(p[idx].burst_remaining > 0) //if the process still have some burst time left we push it again in the ready queue.
        {
            q.push(idx);
        }

        if(q.empty())
        {
            for(int i = 1; i < n; i++)
            {
                if(p[i].burst_remaining > 0)
                {
                    q.push(i);
                    p[i].is_completed = 1;
                    break;
                }
            }
        }
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
