// SRTF CPU scheduling
#include<bits/stdc++.h>
using namespace std;

class srtf_Process // each process will have the following attributes
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
    int is_completed;   //to flag process that is completed
    int burst_remaining;
};

bool srtf_comp_atime(srtf_Process P, srtf_Process Q) //to sort according to arrival time
{
    if(P.atime==Q.atime)
        return P.no<Q.no;
    return (P.atime<Q.atime);
}

int srtf_main()
{
    int n;
    float sum_ttime=0,sum_wtime=0,sum_rtime=0;

	cout<<"Enter the no. of Process to be performed : ";
    cin>>n;

    vector<srtf_Process> p(n);   //creating array for the class

    for(int i = 0; i < n; i++)
    {
		cout<<"\nEnter the Arrival time and Burst Time for Process "<<i+1<<":\n";
        cin>>p[i].atime>>p[i].btime;
        p[i].no = i+1;
        p[i].is_completed=0;
        p[i].burst_remaining = p[i].btime;
    }

    sort(p.begin(),p.end(),srtf_comp_atime); //sorting the Processes according to arrival time

    int current_time = 0;
    int completed = 0;

    while(completed != n)   //
    {
        int idx = -1;
        int lowest_btime = INT_MAX;
        //finding the lowest burst time process among the processes those have been arrived till now
        for(int i = 0; i < n; i++)
        {
            if(p[i].atime <= current_time && p[i].is_completed == 0)
            {
                if(p[i].burst_remaining < lowest_btime)
                {
                    lowest_btime = p[i].burst_remaining;
                    idx = i;
                }
                if(p[i].burst_remaining == lowest_btime)    //if the burst time of two process are same, the process which arrived first will be executed
                {
                    if(p[i].atime < p[idx].atime)
                    {
                        lowest_btime = p[i].burst_remaining;
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1)
        {
            // if the remaining burst time is same as initial burst time, the process just started executing
            if(p[idx].burst_remaining == p[idx].btime)
                p[idx].stime = current_time;

            p[idx].burst_remaining-=1;
            current_time++;

            if(p[idx].burst_remaining == 0)
            {
                p[idx].ctime = current_time;
                p[idx].ttime = p[idx].ctime - p[idx].atime;
                p[idx].wtime = p[idx].ttime - p[idx].btime;
                p[idx].rtime = p[idx].stime - p[idx].atime;

                sum_ttime += p[idx].ttime;
                sum_wtime += p[idx].wtime;
                sum_rtime += p[idx].rtime;

                p[idx].is_completed = 1;
                completed++;
            }
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
