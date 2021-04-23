#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

struct partition{
    int num;
    int mem;
    int alloc;
    int acc;
    int int_frag;
};

struct process{
    int num;
    int mem;
    int alloc;
};

int main()
{
    struct process proc[MAX];
    int size,n,s,p=0;
    int i,j,min;
    
    printf("Enter the total size of total memory in KB\t:");
    scanf("%d",&size);
    s=size;
    min=size;
    printf("Enter the number of partitions\t:");
    scanf("%d",&n);
    printf("\n");
    struct partition part[n];
    for(i=0;i<n;i++)
    {
        part[i].int_frag=0;
        part[i].num = i+1;
        part[i].acc =0;
        printf("Enter the size of partition %d\t:",part[i].num);
        scanf("%d",&part[i].mem);
        if(part[i].mem <= s)
        {
            part[i].alloc =1;
            s = s-part[i].mem;
            p++;
        }
        else
        {
            part[i].alloc =0;
            printf("Partition %d cannot be given space as only %dKB space is remaining\n",part[i].num,s);
        }
    }
    printf("\n\n");
    int m,ext_frag=0,count =0,excess =0,p_c=0,number,temp,t;
    int choice =5;
    for(i=0;i<MAX;i++)
    {
        proc[i].alloc =0;
    }
    i=0;
    while(choice!=3)
    {
        printf("Please select from the given choices\n1.Insert\n2.Delete\n3.Stop\nEnter your choice\t:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                p_c++;
                proc[i].num = i+1;
                printf("Enter the size of process %d\t:",proc[i].num);
                scanf("%d",&proc[i].mem);
                proc[i].alloc =0;
                min = size;
                excess =0;
                for(j=0;j<n;j++)
                {
                    if(part[j].alloc==1 && part[j].acc ==0)
                    {
                        if(proc[i].mem <= part[j].mem && part[j].mem - proc[i].mem < min)
                        {
                            min = part[j].mem - proc[i].mem;
                            excess =1;
                        }
                    }
                }
                if(excess ==1)
                {
                    for(j=0;j<n;j++)
                    {
                        if(part[j].mem-proc[i].mem == min)
                        {
                            proc[i].alloc = part[j].num;
                            part[j].acc =1;
                            part[j].int_frag= part[j].mem-proc[i].mem;
                            ext_frag+=part[j].int_frag;
                            count++;
                            printf("Process %d is accomodated in partition %d\n",proc[i].num,part[j].num);
                            break;
                        }
                    }
                }
                if(excess ==0)
                {
                    int c=0;
                    for(j=0;j<n;j++)
                    {
                        c=0;
                        if(part[j].alloc ==1 && part[j].acc ==1)
                        {
                            if(part[j].int_frag >= proc[i].mem)
                            {
                                printf("Process %d cannot be given memory due to internal fragmentation\n",proc[i].num);
                                c++;
                                break;
                            }
                        }
                    }
                    if(c==0)
                    {
                        if(proc[i].mem <= ext_frag)
                        {
                            printf("Process %d cannot be accomodated due to external fragmentation\n",proc[i].num);
                        }
                        else
                        {
                            printf("Process %d doesnot fit in any of the idle partitions\n",proc[i].num);
                        }
                    }
                }
                i++;
                break;}
            case 2:
            {
                printf("Enter the process you want to delete\t:");
                scanf("%d",&number);
                for(j=0;j<p_c;j++){
                    if(proc[j].num ==number)
                    {
                        t=j;
                        break;
                    }
                }
                if(proc[t].alloc !=0)
                {
                    temp=proc[t].alloc;
                    for(j=0;j<n;j++)
                    {
                        if(part[j].alloc ==1 && part[j].acc ==1 && temp ==part[j].num)
                        {
                            part[j].acc =0;
                            ext_frag-=part[j].int_frag;
                            printf("Process %d is deleted\n",number);
                            break;
                        }
                    }
                }
                else
                {
                    printf("The process is not even accomodated to any partition\n");
                }
                break;}
            case 3:
                printf("Unused space is %d",s);
                break;
            default:
                printf("INVALID CHOICE\n");
                break;
        }
    }
}