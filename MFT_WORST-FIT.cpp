//MFT with worst fit

#include <bits/stdc++.h>
using namespace std;

int main (){
    int total_size, n, i,prs ,p = 0,counter1 = 0,counter2 = 0,max,k;
    cout << "Enter total memory size: ";
    cin >> total_size;
    int y = total_size;
    cout << "Enter total number of Partitions: ";
    cin >> n;
    int Partition[n][3];
    for (i = 0; i < n; i++){
      cout << "Enter Partition " << i +1<<" size :";
      cin >> Partition[i][0]; // stores the size of partiton
      if (total_size >= Partition[i][0]){
	    total_size = total_size - Partition[i][0];
	    Partition[i][1] = 0; // stores the alloted process number
	    Partition[i][2] = i+1; // stores partiton number
	    ++counter1;
	}
	else{
	    cout << "Partition "<<i+1<<" cant't be given space as only "<< total_size<< "KB space is remaining";
	    Partition[i][2] = 0;
	    Partition[i][0] = y + 3;
	    Partition[i][1] = 1;
	     }
    }
    cout<<"\n";
    cout << "Enter total number of Process: ";
    cin >> prs;
    int a[prs][2],ifs = 0;
    for(int j = 0; j < prs; j ++){
        cout << "Enter Process " << j +1<<" size :";
        cin >> a[j][0]; // stores process size
        a[j][1] = 0;
        p = 0; // flag to check if a partion is alloted or not, 0 = partion not alloted 1 = partion alloted 
        max = 0;
        for(i = 0; i < n; i++){ // checks for the partiton and allots based on worst fit method
            if(max < Partition[i][0] && Partition[i][1] == 0  && Partition[j][2] != 0){
                max = Partition[i][0];
                k = i;
            }
        }
        if(a[j][0] <= max){
            Partition[k][1] = j+1;
            a[j][1] = Partition[k][2];
            ifs+= Partition[j][0]- a[j][0]; // calculates internal frgamentation
            ++counter2;
            p = 1;
        }
        
        
        if(counter2 <= counter1 && a[j][1] == 0)
            cout <<"No partion avilabale for the process "<<endl;
        else if(a[j][1] == 0)
            cout << "Process "<<j+1 <<" cannot be alloted as there are only " << counter1<<" number of Partitions "<<endl;
      }
    cout<<"Space with no Partitions "<<total_size<<" KB"<<endl;
    cout<<"Total internal Fragmentation: "<<ifs<<endl;
    for(i = 0; i < n ; i++){
        if(a[i][1] > 0)
            cout << "Process" << i+1 <<" is in Partition " << a[i][1]<<endl;
    }
}
        
     
        
        
   
