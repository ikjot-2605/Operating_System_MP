#include <bits/stdc++.h>
using namespace std;

int bankers_main()
{
        int r,p,i,j;

        cout<<"Enter the no of processes"<<endl;
        cin>>p;
        cout<<"Enter the no of resources"<<endl;
        cin>>r;
        int resources[r],sum[r]={0};

        for(int i=0;i<r;i++){
            cout<<"Enter available resources of R"<<i+1<<": ";
            cin>>resources[i];
        }

        int order[p]; //for maintaining the sequence for running the processes
        int allocated[p][r],required[p][r],remaining[p][r];
        int available[r];//no of instances of resource available after allocating the resources to the processes

        cout<<"For each process enter the no of allocated resources:"<<endl;
        for(i=0;i<p;i++)
        {
            cout<<"Process"<<i+1<<" : "<<endl;
            for(j=0;j<r;j++)
            {
                cout<<"R"<<j+1<<": ";
                cin>>allocated[i][j];
                sum[j]+=allocated[i][j];
            }
            cout<<endl;
        }
        //checking if total allocated resources exceeds the available resources
        for(i=0;i<r;i++)
        {
            if(sum[i]>resources[i])
            {
                cout<<"The number of resources being allocated is more than the available resources, so program is terminated."<<endl;
                exit(0);
            }
        }

        cout<<"For each process enter the number of required resource:"<<endl;
        for(i=0;i<p;i++)
        {
            cout<<"Process"<<i+1<<" : ";
            for(j=0;j<r;j++)
            {
                cout<<"R"<<j+1<<": ";
                cin>>required[i][j];
                if(required[i][j]>resources[j])
                {
                    cout<<"The process is requesting for more resources than available, so program is terminated"<<endl;
                    exit(0);
                }
            }
            cout<<endl;
        }

        for(i=0;i<r;i++)
        {
            available[i]=resources[i]-sum[i];
        }

        for(i=0;i<p;i++)
        {
            for(j=0;j<r;j++)
            {
                remaining[i][j]=required[i][j]-allocated[i][j];
            }
        }

        int count=0,k;//count keeps track of how many processes have completed
        bool check;//keeps track of whether at least one process is completed in an iteration or else deadlock condition will be achieved
        bool flag[p]={false};//keep track of whether processes are finished or not

        //To find safe state if it exists
        while(count<p)
        {
            check = false;
            for(i=0;i<p;i++)
            {
                if(flag[i]){continue;}
                int l=0;
                //Checks to find whether the available resources are enough to satisfy the requirements of the process
                for(j=0;j<r;j++)
                {
                    if(available[j]>=remaining[i][j]){l++;}
                }
                //If the requirements are satisfied modify the flag, order and the number of available resources
                if(l==r)
                {
                    flag[i]=true;
                    order[count]=i+1;
                    count++;
                    check=true;
                    for(k=0;k<r;k++)
                    {
                        available[k] += allocated[i][k];
                    }
                }

            }
            if(!check)
            {
                cout<<"The is an unsafe state"<<endl;
                break;
            }

        }

        if(count==p)
        {
            cout<<"This is a safe state"<<endl;
            cout<<"The order is :" <<endl;
            for(i=0;i<p;i++)
            {
                cout<<"Process "<<order[i];
                if(i!=p-1)
                {
                    cout<<" -> ";
                }
            }

        }

return 0;
}
