#include<math.h>
#include<stdio.h>
int main()
{
    int i,n,j=0,k=0,x=0,l,req[50],mov=0,cp,ub,end, lower[50],upper[50], temp,a[50];
    
    printf("Enter the max track limit of disc\n");
    scanf("%d",&ub);
    printf("enter the head position\n");
    scanf("%d",&cp);
    printf("enter the number of tracks\n");
    scanf("%d",&n);
    printf("enter the track order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    /*break the request array into two arrays : one with requests lower than current and other with requests higher than current position. Also sort these two new arrays*/
    for(i=0;i<n;i++)
    {
        if(req[i]<cp)
        {
            lower[j]=req[i];
            j++;
        }
        if(req[i]>cp)
        {
            upper[k]=req[i];
            k++;
        }
    }
   
    //sort the lower array in reverse order
    for(i=0;i<j;i++)
    {
        for(l=0;l<j-1;l++)
        {
            if(lower[l]<lower[l+1])
            {
                temp=lower[l];
                lower[l]=lower[l+1];
                lower[l+1]=temp;
            }
        }
    }
   
    // sort the upper array in ascending order
    for(i=0;i<=k;i++)
    {
        for(l=0;l<k-1;l++)
        {
            if(upper[l]>upper[l+1])
            {
                temp=upper[l];
                upper[l]=upper[l+1];
                upper[l+1]=temp;
            }
        }
    }
    
    for(i=0;i<k;i++)
    {       
        a[x]=upper[i];   
        x++;           
    }
    
    for(i=0;i<j;i++)
    {       
        a[x]=lower[i];
        x++;               
    }
   
    mov=mov+abs(cp-a[0]);
    printf("%d -> %d",cp,a[0]);
    for(i=1;i<x;i++)
    {
        mov=mov+abs(a[i]-a[i-1]);
        printf(" -> %d",a[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);

}