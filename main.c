#include<stdio.h>
//#define n 3
void findWaitingTime(int processes[], int n,   
                          int bt[], int wt[])  
{  
    wt[0] = 0;  
    
    // calculating waiting time  
    //Assuming waiting time 0 for process 1
    for (int  i = 1; i < n ; i++ )  
        wt[i] =  bt[i-1] + wt[i-1] ;  
}  
    
void findTurnAroundTime( int processes[], int n,   
                  int bt[], int wt[], int tat[])  
{  
    
    for (int  i = 0; i < n ; i++)  
        tat[i] = bt[i] + wt[i];  
}
void display(int Pid[],int bt[],int wt[],int tat[],int n)
{
    int i;
    printf("PId--BT--wt--tat");
    for(i=0;i<n;i++)
    {
        printf("\n");
        printf("  %d--%d--%d--%d",Pid[i],bt[i],wt[i],tat[i]);
    }
}
int main()  
{  
    int Pid[]={1,2,3};  
   int n = sizeof Pid / sizeof Pid[0];
    int tat[n],WaitingT[n];
    int  bt[] = {10, 5, 8};
    findWaitingTime(Pid,n,bt,WaitingT);
    findTurnAroundTime(Pid,n,bt,WaitingT,tat);
    display(Pid,bt,WaitingT,tat,n);

    return 0;  
}  