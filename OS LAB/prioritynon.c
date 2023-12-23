// #include <stdio.h>
// #define max 30
// void main()
// {
//     int n, i, j, k = 1, t, b = 0, min, temp[max], bt[max], wt[max], at[max], pr[max], tat[max];
//     float awt = 0, atat = 0;
//     printf("Enter the number of process\n");
//     scanf("%d", &n);
//     printf("Enter the burst time, arrival time & priority of the process\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d %d %d", &bt[i], &at[1], &pr[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (at[i] < at[j])
//             {
//                 t = at[j];
//                 at[j] = at[i];
//                 at[i] = t;

//                 t = bt[j];
//                 bt[j] = bt[i];
//                 bt[i] = t;
//             }
//         }
//     }
//     for (int j = 0; j < n; j++)
//     {
//         b = b + bt[j];
//         min = bt[k];
//         for (int i = k; i < n; ++i)
//         {
//             min = pr[k];
//             if (b >= at[i])
//             {
//                 if (pr[i] < min)
//                 {
//                     t = at[k];
//                     at[k] = at[i];
//                     at[i] = t;

//                     t = bt[k];
//                     bt[k] = bt[i];
//                     bt[i] = t;

//                     t = pr[k];
//                     pr[k] = pr[i];
//                     pr[i] = t;
//                 }
//             }
//         }
//         k++;
//     }
//     temp[0] = 0;
//     printf("process\t burst time\t arrival time\t priority\t waiting timelt turn around time\n");
//     {
//         wt[i] = 0;
//         tat[i] = 0;
//         temp[i + 1] = temp[i] + bt[i];
//         wt[i] = temp[i] - at[i];
//         wt[i] = temp[i] - at[i];
//         tat[i] = wt[i] + bt[i];
//         awt = awt + wt[i];
//         atat = atat + tat[i];
//         printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],pr[i],wt[i],tat[i]);
//     }
//     awt=awt/n;
//     atat=atat/n;
//     printf("Average waiting time=%f\n",awt);
//     printf("average turned around time=%f",awt);
// }
// #include <stdio.h>

// int main() {
//     int n, i, j, temp, pid[20], bt[20], wt[20], ct[20], pt[20], at[20];

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter the burst time and arrival time for each process:\n");
//     for (i = 0; i < n; i++) { 
//         printf("P %d: ", i + 1); 
//         scanf("%d %d", &bt[i], &at[i]);
//         pid[i] = i + 1; 
//     }

//     printf("Enter the priority for each process:\n");
//     for (i = 0; i < n; i++) {
//         printf("P %d: ", i + 1); 
//         scanf("%d", &pt[i]);
//     }

//     // Sorting processes based on arrival time
//     for (i = 0; i < n; i++) {
//         for (j = i + 1; j < n; j++) {
//             if (at[i] > at[j]) {
//                 temp = at[i];
//                 at[i] = at[j];
//                 at[j] = temp;

//                 temp = bt[i];
//                 bt[i] = bt[j];
//                 bt[j] = temp;

//                 temp = pt[i];
//                 pt[i] = pt[j];
//                 pt[j] = temp;

//                 temp = pid[i];
//                 pid[i] = pid[j];
//                 pid[j] = temp;
//             }
//         }
//     }

//     wt[0] = 0;
// for (i = 1; i < n; i++) {
//     wt[i] = ct[i - 1] - at[i];
//     if (wt[i] < 0) {
//         wt[i] = 0;
//     }
// }


//     for (i = 0; i < n; i++) {
//         ct[i] = bt[i] + wt[i];
//     }

//     printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tCompletion Time\n");
//     for (i = 0; i < n; i++) {
//         printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], at[i], pt[i], wt[i], ct[i]);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <limits.h>

// int main() {
//     int n, i, j, temp, pid[20], bt[20], wt[20], ct[20], pt[20], at[20];

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter the burst time and arrival time for each process:\n");
//     for (i = 0; i < n; i++) { 
//         printf("P %d: ", i + 1); 
//         scanf("%d %d", &bt[i], &at[i]);
//         pid[i] = i + 1; 
//     }

//     printf("Enter the priority for each process:\n");
//     for (i = 0; i < n; i++) {
//         printf("P %d: ", i + 1); 
//         scanf("%d", &pt[i]);
//     }

//     // Sort processes based on arrival time
//     for (i = 0; i < n; i++) {
//         for (j = i + 1; j < n; j++) {
//             if (at[i] > at[j]) {
//                 temp = at[i];
//                 at[i] = at[j];
//                 at[j] = temp;

//                 temp = bt[i];
//                 bt[i] = bt[j];
//                 bt[j] = temp;

//                 temp = pt[i];
//                 pt[i] = pt[j];
//                 pt[j] = temp;

//                 temp = pid[i];
//                 pid[i] = pid[j];
//                 pid[j] = temp;
//             }
//         }
//     }

//     wt[0] = 0;
//     ct[0] = bt[0];

//     for (i = 1; i < n; i++) {
//         int highestPriorityIndex = i;
//         for (j = 0; j < i; j++) {
//             if (pt[j] < pt[highestPriorityIndex]) {
//                 highestPriorityIndex = j;
//             }
//         }
//         wt[i] = ct[highestPriorityIndex];
//         ct[i] = wt[i] + bt[i];
//         pt[highestPriorityIndex] = INT_MAX;  // Set the priority of the completed process to a large value to exclude it from future consideration
//     }

//     printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tCompletion Time\n");
//     for (i = 0; i < n; i++) {
//         printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], at[i], pt[i], wt[i], ct[i]);
//     }

//     return 0;
// }






// #include <stdio.h>
// void main()
// {
// int i,j,n, tat[10],wt[10], bt [10],pid[10], pr[10],t, twt=0, ttat=0;
// float awt, atat;
// printf("\n------- --PRIORITY SCHEDULING- --\n");
// printf("Enter the No of Process: ");
// scanf("%d", &n);
// for (i=0;i<n;i++)
// {
// pid[i] = 1;
// printf("Enter the Burst time of Pid %d",i);
// scanf("%d",&bt[1]);
// printf("Enter the Priority of Pid %d ",i);
// scanf("%d",&pr[1]);
// }
// for(i=0;i<n;i++)
// for(j=i+1;j<n;j++)
// {
// if(pr[i] > pr[j])
// {
// t = pr[i];
// pr[i] = pr[j];
// pr[j] = t;
// t = bt[i];
// bt[i] = bt[j];
// bt[j] = t;
// t = pid[i];
// pid[i] = pid[j];
// pid[j] = t;
// }
// }
// tat[0] = bt[0];
// wt[0] = 0;
// for (i=1;i<n;i++)   
// {
//     wt[i] = wt[i-1] + bt[i-1];
// tat[i] = wt[i] + bt[i];
// }
// printf("\n----------------------------------------------------\n");
// printf("Pid\t Priority\tburst time\t WaitingTime\tTurnArroundTime \n");
// printf("\n-----------------------------------------------------\n");
// for(i=0;i<n;i++)
// { 
//     printf("\n%d\t\t%d\t%d\t\t%d\t\t%d",pid[i],pr[i],bt[i],wt[i],tat[i]);
// }
// for(i=0;i<n;i++)
// {
// ttat = ttat+tat[i];
// twt = twt + wt[i];
// }
// awt = (float) twt / n;
// atat = (float)ttat / n;
// printf("\n\nAvg.Waiting Time: %f\nAvg. Turn Around Time: %f\n", awt, atat);
// }




// #include<stdio.h>
// int choice;
// int finish[10], process_name[10], arrival_time [10], burst_time [10], waiting_time [10], turn_around_time[10];
// int avg_wait_time, avg_turn_around_time; 
// int n, pending, remain_burst_time [10], time, count,;
// void input()
// {
// int i;
// printf("\nEnter number of processes");
// scanf("%d", &n);
// for(i=0;i<n;i++)
// {
// process_name[i]=i;
// printf("\n Enter Burst Time of Process %d:", process_name[i]);
// scanf("%d", &burst_time[i]);
// remain_burst_time[i]=burst_time[i];
// printf("\n Enter arrival time of Process %d:", process_name[i]);
// scanf("%d", &arrival_time[i]); 
// }
// }
// void menu()
// {
// printf("\n\n\n\n* *******MENU**********");
// printf("\n 1. Round Robin");
// printf("\n 2. Sjf Preemptive");
// printf("\n 3. exit");
// printf("\n Enter your choice");
// scanf("%d", &choice);
// }
// void output()
// {
// int i;
// printf("\n\n\nProcess A.T. B.T. W.T. T.A.T");
// for(i=0;i<n;i++) 
// {
// printf("\n P%d \t%d \t%d \t%d \t%d\t%d", process_name[i], arrival_time[i], burst_time[i], waiting_time[i], turn_around_time[i]);
// }
// }
// void round_robin()
// {
// int time_quantam, i;
// input();
// pending=n;
// printf("\n Enter time Quantam");
// scanf("%d", &time_quantam);
// printf("\n\n\nGantt Chart==> ");
// //initialize finish and wati time for all processes to 0 
// for(i=0;i<n;i+++)
// {
// finish[i]=0;
// waiting_time[i]=0; 
// }
// //Start execution.
// for (time=0, count=0;pending>0;) 
// {
// //case for remaining burst time less than or equal to time quantum 
// if(finish[count]=0 && arrival_time[count]<=time && remain_burst_time[count] <=time_quantam) 
// {
// time+=remain_burst_time [count];
// //Complete process and decalre as finshed
// pending--;
// finish [count]=1;
// waiting_time [count] -=arrival_time[count];
// turn_around_time [count]=waiting_time [count]+burst_time [count];
// //output (count);
// //Print gant chart
// for (i=0;i<n;i++) 
// {
// printf("P%d ", process_name [count]);
// }
// for (i=0;i<n;i++) 
// {
// if(i==count || finish[i]==1)
// continue;
// waiting_time[i] +=remain_burst_time [count]; 
// }
// remain_burst_time [count]=0; 
// }
// //case 2 burst time greater than time quantam
// else if(finish [count]!=1 && arrival_time [count] <=time && remain_burst time [count] >=time_quantam)
// remain_burst_time [count]--time_quantam;
// time+=time_quantam;
// for(i=0;i {
// if(i==count || finish[i]==1)
// continue;
// waiting time [i]+-time_quantam;

// #include <stdio.h>
 
// //Function to swap two variables
// void swap(int *a,int *b)
// {
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main()
// {
//     int n;
//     printf("Enter Number of Processes: ");
//     scanf("%d",&n);
 
//     // b is array for burst time, p for priority and index for process id
//     int b[n],p[n],index[n];
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
//         scanf("%d %d",&b[i],&p[i]);
//         index[i]=i+1;
//     }
//     for(int i=0;i<n;i++)
//     {
//         int a=p[i];
//         int m=i;
 
//         //Finding out highest priority element and placing it at its desired position
//         for(int j=i;j<n;j++)
//         {
//             if(p[j] > a)
//             {
//                 a=p[j];
//                 m=j;
//             }
//         }
 
//         //Swapping processes
//         swap(&p[i], &p[m]);
//         swap(&b[i], &b[m]);
//         swap(&index[i],&index[m]);
//     }
 
//     // T stores the starting time of process
//     int t=0;
 
//     //Printing scheduled process
//     printf("Order of process Execution is\n");
//     for(int i=0;i<n;i++)
//     {
//         printf("P%d is executed from %d to %d\n",index[i],t,t+b[i]);
//         t+=b[i];
//     }
//     printf("\n");
//     printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
//     int wait_time=0;
//     for(int i=0;i<n;i++)
//     {
//         printf("P%d\t\t %d\t\t %d\t\t %d\n",index[i],b[i],wait_time,wait_time + b[i]);
//         wait_time += b[i];
//     }
//     return 0;
// }
// */
// implementation of prority based scheduling algorithm using array .
// calculate . 
// a. CT , TAT , 
// b execution order 
// c. AWT ,ATAT 
// */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],tat[n],wt[n],pr[n],i,j,temp;
    float awt=0,atat=0;
    printf("Enter the process number , arrival time , burst time and priority of each process : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&p[i],&at[i],&bt[i],&pr[i]);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(pr[j]>pr[j+1])
            {
                temp=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
    for(i=1;i<n;i++)
    {
        if(at[i]>ct[i-1])
        {
            ct[i]=at[i]+bt[i];
        }
        else
        {
            ct[i]=ct[i-1]+bt[i];
        }
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        awt+=wt[i];
        atat+=tat[i];
    }
    awt/=n;
    atat/=n;
    printf("Average waiting time : %f\n",awt);
    printf("Average turn around time : %f\n",atat);
    //execution order 
    printf("Execution order : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");            
    return 0;
}