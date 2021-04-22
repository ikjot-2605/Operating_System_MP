#include<stdio.h>
int sstf_main()
{
    struct di
    {
        int num;
        int flag;
    };
    int i,j,sum=0,n,min,loc,x,y;
    struct di d[20];
    int disk;
    int ar[20],a[20];
    printf("enter position of head\t");
    scanf("%d",&disk);
    printf("enter number of tracks\t");
    scanf("%d",&n);
    printf("enter elements of disk queue\n");
    for(i=0;i<n;i++)
    {

        scanf("%d",&d[i].num); 
        d[i]. flag=0;
    }
    for(i=0;i<n;i++)
    { 
        x=0; 
        min=0;
        loc=0;
        for(j=0;j<n;j++)
        {
            if(d[j].flag==0)
            {
                if(x==0)
                {
                    ar[j]=disk-d[j].num;
                    if(ar[j]<0)
                    { 
                        ar[j]=d[j].num-disk;
                    }
                    min=ar[j];
                    loc=j;
                    x++; 
                }
                else
                {
                    ar[j]=disk-d[j].num;
                    if(ar[j]<0)
                    { 
                        ar[j]=d[j].num-disk;
                    }
                }
                if(min>ar[j]) 
                { 
                    min=ar[j]; 
                    loc=j;
                }
            }
        }
        d[loc].flag=1;
        a[i]=d[loc].num-disk;
        if(a[i]<0)
        {
            a[i]=disk-d[loc].num;
        }
        disk=d[loc].num;
    }
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("\nseek time %d",sum);

    return 0;
}