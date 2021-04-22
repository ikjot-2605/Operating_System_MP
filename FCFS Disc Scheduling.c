#include<stdio.h> 
void main() 
{ 
int n, i, j, h, tot=0; 
float avhm; 
printf("enter the no.of tracks:\n"); 
scanf("%d",&n);  
printf("enter the head position:\n");
    scanf("%d",&h);
int t[n],tohm[n];
printf("enter the tracks to be traversed:\n"); 
for(i=0;i<n;i++) 
    scanf("%d",&t[i]);
if((t[0]-h)>0)
    tohm[0]=t[0]-h;
else
    tohm[0]=h-t[0];
for(i=1;i<n+1;i++) 
{   
    tohm[i]=t[i]-t[i-1]; 
    if(tohm[i]<0)   
        tohm[i]=tohm[i]*(-1); 
} 
for(i=0;i<n;i++) 
    tot+=tohm[i]; 
avhm=(float)tot/n; 
printf("Disc head moves from %d to %d\n",h,t[0]);
for(i=0;i<n-1;i++) 
    printf("Disc head moves from %d to %d\n",t[i],t[i+1]); 
printf("Seek Time:%d",tot);
printf("\nAverage header movements:%f",avhm); 
}