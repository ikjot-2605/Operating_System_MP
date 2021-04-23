#include <bits/stdc++.h>

using namespace std;

//declaring semaphores writer and reader.
int wrt,rd;

//initialising reader count 
int r_cnt=0;

//to keep track of time when more than one readers are accessing the critical section.
int max_time=0;
//initialising time to 0.
int ti=0;

//declaring each reader/writer as a structure.
struct rdr_wtr{
    int ta; // arrival time.
    int tb; // burst time.
    char c; //  w for writer,r for reader.
    int s_no; // serial number of the writer/reader.
};

//this function helps us to find the waiting people when the current writer is writing.  
void funwaitw(rdr_wtr a[],int i, int n){
    int j;
    
    //counting the number of waiting people.
    int cnt=0;
    for(j=i+1;j<n&&a[j].ta<ti+a[i].tb;j++){
        if(a[j].ta!=-1)cnt++;
    }
    //return if nobody is waiting.
    if(cnt==0)return;
    
    cout<<"and ";
    for(j=i+1;j<n&&a[j].ta<ti+a[i].tb;j++){
        if(a[j].ta!=-1)cout<<a[j].c<<a[j].s_no<<" ";
    }
    cout<<"will wait\n";
    cout<<"\n";
    
    //incrementing time.
    ti+=a[i].tb;
}

//this function helps us to find the waiting people when the current reader is reading.
void funwaitr(rdr_wtr a[],int i, int n){
    int j;
    //counting of the number of waiting people.
    int cnt=0;
    for(j=i+1;j<n&&a[j].ta<max_time;j++){
        if(a[j].c=='w')cnt++;
    }
    //return if nobody is waiting.
    if(cnt==0)return;
    
    cout<<"and ";
    for(j=i+1;j<n&&a[j].ta<max_time;j++){
        if(a[j].c=='w')cout<<a[j].c<<a[j].s_no<<" ";
    }
    cout<<"will wait\n";
    cout<<"\n";
}

//function for reading process.
int reader(rdr_wtr a[],int i, int n){
    int j;
    rd=0;//wait(rd);
    r_cnt++;
    if(r_cnt==1){
        wrt=0;//wait(wrt);
    }
    rd=1;//signal(rd);
    
    max_time=-1;
    max_time=ti+a[i].tb;
    
    //reading operation
    cout<<"r"<<a[i].s_no<<" ";
    
    for(j=0;j<n;j++){
        if(j==i)continue;
        //checking is other readers can access critical section along with the present ones  
        if(a[j].ta<=max_time&&a[j].c=='r'){
            
        if(a[j].ta!=-1){
            cout<<"r"<<a[j].s_no<<" ";
            
            if(max(a[j].ta,ti)+a[j].tb>max_time){
                max_time=max(a[j].ta,ti)+a[j].tb;
            }
            //marking that this person has finished
            a[j].ta=-1;
        }
        
        }
    }
    cout<<"will read from "<<ti<<" to "<<max_time<<"\n";
    
    //finding the waiting people.
   
    funwaitr(a,i,n);
     ti=max_time; //updating time
     
    //reading operation
    
    rd=0;//wait(rd);
    r_cnt--;
    if(r_cnt==0){
        wrt=1;//signal(wrt);
    }
    rd=1;//signal(rd);
    
    return 0;
}

//function for writing process.
int writer(rdr_wtr a[],int i,int n){
    wrt=0;//wait(wrt);
    
    //writing operation
    cout<<"from "<<ti<<" to "<<ti+a[i].tb<<" w"<<a[i].s_no<<" is writing\n";
    
    //finding the waiting people.
    funwaitw(a,i,n);
    //marking that this person has finished
    a[i].ta=-1;
    
    //writing operation
    
    wrt=1;//signal(wrt)
    return 0;
}

//function to process the readers and writers
void process(rdr_wtr a[],int n){
    int i,j,k;
    
    //initialising time with the arrival time of first person 
    ti=a[0].ta;
    
    for(i=0;i<n;i++){
        //if this person is done
        if(a[i].ta==-1)continue;
        
        //incresing time if lesser than the current arrival time.
        if(ti<a[i].ta){
            ti=a[i].ta;
        }
        
        //calling the reader or writer based on the character a[i].c
        if(a[i].c=='w')writer(a,i,n);
        else reader(a,i,n);
    }
    
}

int reader_writer_main(){
   int n,m,i,j,k;
   
   cout<<"enter the number of writers\n";
   cin>>n;
   cout<<"enter the number of readers\n";
   cin>>m;
   
   int total=n+m;
   
   rdr_wtr a[total];
   
   cout<<"enter the arrival times of the writers\n";
   for(i=0;i<n;i++){
       cin>>a[i].ta;
       a[i].c='w';
       a[i].s_no=i+1;
   }
   
   
   cout<<"enter the burst times of the writers\n";
   for(i=0;i<n;i++){
       cin>>a[i].tb;
   }
   
   cout<<"enter the arrival times of the readers\n";
   for(i=0;i<m;i++){
        cin>>a[i+n].ta;
        a[i+n].c='r';
        a[i+n].s_no=i+1;
   }
   
   cout<<"enter the burst times of the readers\n";
   for(i=0;i<m;i++){
        cin>>a[i+n].tb;
   }
   //initialising semaphores.
   rd=1;
   wrt=1;
   r_cnt=0;
   
   
   rdr_wtr t;
  //sorting according to arrival time
  //giving preference to writer.
  for(i=0;i<total-1;i++){
      for(j=i+1;j<total;j++){
           if(a[i].ta>a[j].ta){
               t=a[i];
               a[i]=a[j];
               a[j]=t;
           }
       }
   }
   
   //calling the function to process readers and writers.
   process(a,total);
   
   cout<<"\nexecution finished\n";
   return 0;
}
