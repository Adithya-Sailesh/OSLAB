#include<stdio.h>
#include<stdio.h>
  struct fcfs
    {
        int pid;
        int atime;
        int btime;
        int ctime;
        int tat;
        int wtime;
        
    }p[10];
void main(){
int n,ttat,twt,atat,awt;
  printf("\n -------------FCFS SCHEDULING------------- \n");
  printf("\n Enter the number of process \n");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    p[i].pid=i;
    printf("\n Enter the arrival time %d ",i);
    scanf("%d",&p[i].atime);
    printf("\n Enter the burst time of %d",i);
    scanf("%d",&p[i].btime);
  }p[0].wtime=0;
  p[0].ctime=0;
  for(int i=1;i<=n;i++){
    p[i].ctime=p[i].btime+p[i-1].ctime;
    p[i].tat=p[i].ctime-p[i].atime;
    p[i].wtime=p[i].tat-p[i].btime;
  }
  printf("\n --------------------Table is ---------------------\n ");
  printf("\n pid \t atime \t Btime \t ctime \t tat \t wating \t \n");
  for(int i=1;i<=n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].tat,p[i].wtime);
  }
    
}
