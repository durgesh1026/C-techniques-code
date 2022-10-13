#include<bits/stdc++.h>
using namespace std;

struct SJF // struct is used to group the information of a process like processid,at,bt,ct,wt,tat
{
  int processId;
  int at;
  int bt;
  int ct,wt,tat,st;
}process[100];//array of structure to store info of each process

int main(){
    int n;
    int runningTime = 0;//track the time of the completion of the various processes

    int process_comp_count = 0;//tells how many processes have been completed till a particular time
    cout<<"Enter number of processes: ";
    cin>>n;   
    bool completed[n]={false},check_process=true; //completed[] will store that process which become completed
    int sumTat=0,sumWt=0;
    int prev=0;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival time of process "<<i<<" : ";
        cin >> process[i].at;
        process[i].processId=i;
        cout<<"Enter Burst time of process "<<i<<" : ";
        cin >> process[i].bt;
        cout<<endl;
    }
    
    while(process_comp_count!=n) //run this while till all n process are not completed
    {
        //find process with minimum cpu burst from the ready queue till current time
        int minIdx = -1;//telling me the index of that process which is having the least burst time
        int min = INT_MAX;//storing that particular cpu burst time ....initialising with the maximum value
        for(int i = 0; i < n; i++) {
            if(process[i].at <= runningTime && completed[i] == false) {//checking  till current time that has not been visited or completed
                if(process[i].bt < min) {
                    min = process[i].bt;
                    minIdx = i;
                }
                if(process[i].bt== min) {//when two process have equal burst time
                    if(process[i].at < process[minIdx].at) {
                        min= process[i].bt;
                        minIdx = i;
                    }
                }
            }
        }

        if(minIdx==-1)
        {
            runningTime++;
        }
        else
        {
        process[minIdx].st = runningTime;
        process[minIdx].ct = process[minIdx].st + process[minIdx].bt;
        process[minIdx].tat = process[minIdx].ct - process[minIdx].at;
        process[minIdx].wt = process[minIdx].tat - process[minIdx].bt;
                
        sumTat +=process[minIdx].tat;
        sumWt += process[minIdx].wt;
        
        process_comp_count++;
        completed[minIdx]=true;//marking process as completed
        runningTime = process[minIdx].ct;//current_time=ct
        prev= runningTime;
        check_process = false;  
        }
    }

    cout<<"\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t\t"<<process[i].at<<"\t\t"<<process[i].bt<<"\t\t\t"<<process[i].ct<<"\t\t"<<process[i].tat<<"\t\t\t"<<process[i].wt<<endl;
        cout<<endl;  
    }
    cout<<"\nAverage Turn Around Time= "<< (float)sumTat/n;
    cout<<"\nAverage Waiting Time= "<<(float)sumWt/n;
    
    return 0;
}
