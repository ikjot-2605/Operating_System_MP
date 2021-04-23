#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
//int f,i=0,page[MAX],fr=0,p_fault=0;

int LRU_add(int frame[])
{
    int data,j,k,set,n[f];
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
            frame[fr]=data;
            fr=(fr+1)%f;
        }
        else
        {
            for(j=0;j<f;j++)
            {
                n[j]=0;
                for(k=i-1;k>0;k--)
                {
                    if(frame[j]==page[k])
                    {
                        break;
                    }
                    else
                    {
                        n[j]++;
                    }
                }
            }
            int max=0,lrue=0;
            for(j=0;j<f;j++)
            {
                if(n[j]>max)
                {
                    max=n[j];
                    lrue=frame[j];
                }
            }
            for(j=0;j<f;j++)
            {
                if(frame[j]==lrue)
                {
                    printf("Page no %d is accomodated in frame %d after removing page no %d\n",data,j,frame[j]);
                    frame[j]=data;
                }
            }
        }
        p_fault++;
    }
    printf("\n");
    i++;
    return 0;
}

int lru_stop()
{
    printf("Number of page faults => %d\n",p_fault);
    printf("Page fault ratio => %.2f\n\n",(float)p_fault/i);
    return 0;
}

int lru_main()
{
    int choice=1,j;
    page[MAX] = {0};
    fr=0;
    p_fault=0;
    i=0;
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
                    LRU_add(frame);
                    break;
            case 2:
                    lru_stop();
                    break;
            default:
                    printf("Invalid Input\n");
                    break;
        }
    }
    return 0;
}
