#include<bits/stdc++.h>
using namespace std;

int paging_main()
{
    unsigned int VM_size,PM_size,page_size;
    cout<<"Enter the size of Virtual Memory in KB : ";
    cin>>VM_size;
    cout<<"Enter the size of Physical Memory in KB : ";
    cin>>PM_size;
    cout<<"Enter the size of Page in KB : ";
    cin>>page_size;

    unsigned int pages_VM, frames_PM;
    pages_VM=VM_size/page_size;
    frames_PM=PM_size/page_size;
    cout<<"\nNumber of pages in Virtual memory : "<<pages_VM;
    cout<<"\nNumber of pages in Physical memory : "<<frames_PM;

    int VM[pages_VM];
    int PM[frames_PM];
    int page_table[pages_VM];

    for(int i=0;i<pages_VM;i++)
        VM[i]=i;

    for(int i=0;i<pages_VM;i++)
        page_table[i]=-1;

    for(int i=0;i<frames_PM;i++)
        PM[i]=-1;

    int choice=1;
    int page_no;
    int offset;
    int page_fault=0;
    bool rep;
    int top=0;
    int cnt=0;

    cout<<"\n\nMENU:\n";
    cout<<"1. Add pages\n";
    cout<<"2. Stop\n";
    while(choice!=2)
    {
        cout<<"\nEnter your Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Virtual Address in the format |Page no|Offset| : ";
            cin>>page_no>>offset;
            rep=true;
            cnt++;
            if(page_no>=pages_VM)
                cout<<"Invalid page number!!!\n";
            else if( offset >= (page_size*pow(2,10)) )
                cout<<"Invalid offset!!!\n";
            else
            {
                // check page table corresponding to given page number
                if(page_table[page_no]!=-1)
                {
                    cout<<"Page "<<page_no<<" is already present in Physical memory.\n";
                    cout<<"Physical address corresponding to given Virtual address is : "<<page_table[page_no]<<" | "<<offset<<endl;
                }
                else
                {
                    // check for empty frame in physical memory, if found accomodate page to that frame
                    for(int i=0;i<frames_PM;i++)
                    {
                        if(PM[i]==-1)
                        {
                            cout<<"Page "<<page_no<<" is not present in Physical Memory.\n";
                            cout<<"So, Page "<<page_no<<" is accomodated in frame "<<i<<endl;
                            PM[i]=page_no;
                            page_table[page_no]=i;
                            page_fault++;
                            rep=false;
                            break;
                        }
                    }

                    // if empty frame is not found replace the page with current frame according to FIFO
                    if(rep)
                    {
                        cout<<"Page "<<page_no<<" is not present in Physical Memory.\n";
                        cout<<"So, Page "<<page_no<<" is accomodated in frame "<<top<<" after removing Page "<<PM[top]<<" according to FIFO"<<endl;
                        page_table[PM[top]]=-1;
                        PM[top]=page_no;
                        page_table[page_no]=top;
                        top++;
                        page_fault++;
                        if(top>=frames_PM)
                            top=0;
                    }
                }
            }
            break;
        case 2 :
            cout<<"\n---FINAL OUTPUT---\n";
            cout<<"\nNumber of page faults : "<<page_fault;
            cout<<"\nPage fault ratio : "<<page_fault/(float)cnt;
            cout<<"\n\nFinal Page table\n";
            for(int i=0;i<pages_VM;i++)
                cout<<"\nPage"<<i<<" \t "<<page_table[i];

            cout<<"\n\nFinal Physical memory space\n";
             for(int i=0;i<frames_PM;i++)
                cout<<"\nFrame"<<i<<" \t "<<"Page"<<PM[i];
            cout<<endl;
        }
    }
}
