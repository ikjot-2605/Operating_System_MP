// optimal page replacement algorithm
#include<bits/stdc++.h>
using namespace std;

int optimal_main()
{
    int i,j,k;
    int flag1=0;            // to check if frame is empty for a page, so no replacement is needed
    int flag2=0;            // to check if a page has to replaced
    int flag3=0;
    int page_fault=0;       //count page faults
    int nos_page;           //total number of pages
    int frame_size;         //total number of frames
    int pos;              //to maintain which page should be removed next
    int maxm;

    //User input
    cout<<"Enter total number of pages : ";
    cin>>nos_page;
    int page[nos_page];

    cout<<"Enter pages : ";
    for(int i=0;i<nos_page;i++)
        cin>>page[i];

    cout<<"\nEnter frame size: ";
    cin>>frame_size;
    int frame[frame_size];
    int temp[frame_size];

    for(i=0;i<frame_size;i++)
        frame[i]=-1;                //empty frame store -1

    cout<<"\n---OUTPUT---";
    for(j=0;j<nos_page;j++)
    {
        flag1=0;
        flag2=0;
        for(i=0;i<frame_size;i++)
        {
            if(frame[i]==page[j])
            {
                flag1=1;
                flag2=1;
                cout<<"\npage "<<page[j]<<" already exists in frame "<<i<<"\t\t\t\t\t\t";
                break;
            }
        }
        if(flag1==0)
        {
            for(i=0;i<frame_size;i++)
            {
                if(frame[i]==-1)
                {
                    cout<<"\npage "<<page[j]<<" inserted into frame "<<i<<"\t\t\t\t\t\t\t";
                    frame[i]=page[j];
                    flag2=1;
                    page_fault++;
                    break;
                }
            }
        }
        if(flag2==0)
        {
            flag3=0;
            for(i=0;i<frame_size;i++)
            {
                temp[i]=-1;
                for(k=j+1;k<nos_page;k++)
                {
                    if(frame[i]==page[k])
                    {
                        temp[i]=k;
                        break;
                    }
                }
            }
            for(i=0;i<frame_size;i++)
            {
                if(temp[i]==-1)
                {
                    pos=i;
                    flag3=1;
                    break;
                }
            }
            if(flag3==0)
            {
                maxm=temp[0];
                pos=0;

                for(i=0;i<frame_size;i++)
                {
                    if(temp[i]>maxm)
                    {
                        maxm=temp[i];
                        pos=i;
                    }
                }
            }
            cout<<"\npage "<<page[j]<<" inserted into frame "<<pos<<" after replacing page "<<frame[pos]<<"\t\t";
            frame[pos]=page[j];
            page_fault++;
        }

        for(int k=0;k<frame_size;k++)
        cout<<frame[k]<<"\t";
    }
    cout<<"\n\nNumber of page faults : "<<page_fault<<endl;
    cout<<"Page fault ratio = "<<page_fault/float(nos_page)<<endl;
}
