#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int f,i=0,page[MAX],fr=0,p_fault=0;

int FIFO_add(int frame[f])
{
    int data,j,set;
    printf("Enter page Number\t:");
    scanf("%d",&data);
    page[i]=data;
    set=0;
    for(j=0;j<f;j++)
    {
        if(frame[j]==data)
        {
            printf("Page no %d  is already present in frame %d\n",data,j);
            set++;
        }
    }
    if(set==0)
    {
        if(frame[fr]==-1)
        {
            printf("Page no %d is accomodated in frame %d\n",data,fr);
        }
        else
        {
            printf("Page no %d is accomodated in frame %d after removing page no %d\n",data,fr,frame[fr]);
        }
        frame[fr]=data;
        fr=(fr+1)%f;
        p_fault++;
    }
    printf("\n");
    i++;
}

int STOP()
{
    printf("Number of page faults => %d\n",p_fault);
    printf("Page fault ratio => %.2f\n",(float)p_fault/i);
}

int fifo_main()
{
    int choice=1,j;
    printf("Enter the number of frames\t:");
    scanf("%d",&f);
    int frame[f];
    for(j=0;j<f;j++)
    {
        frame[j]=-1;
    }
    while(choice!=2)
    {
        printf("Choose one of the option\n1.add pages into frame\n2.stop adding\n");
        printf("Enter the option\t:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    FIFO_add(frame);
                    break;
            case 2:
                    STOP();
                    break;
            default:
                    printf("Invalid Input\n");
                    break;
        }
    }
}