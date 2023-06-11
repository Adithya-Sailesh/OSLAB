#include<stdio.h>
struct rr{
    int pid;
    int atime;
    int btime;
    int ctime;
    int tat;
    int wtime;
}p[10],temp;
void main(){
    int n,i,ts,rt[10],time=0,flag=0,remain;
    float ttat=0,twt=0;
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Enter the time slice process");
    scanf("%d",&ts);
    for(int i=0;i<n;i++){
        p[i].pid=i;
        printf("Enter the arival time of P%d",i);
        scanf("%d",&p[i].atime);
        printf("Enter the burst time of P%d",i);
        scanf("%d",&p[i].btime);
        rt[i]=p[i].btime;
    }remain=n;
    for(int i=0;i<n;i++){
        printf("%d \t",rt[i]);
    }
    for(time=0,i=0;remain!=0;){
        if(rt[i]<=ts && rt[i]>0){
            time=time+rt[i];
            rt[i]=0;
            flag=1;
        }else if(rt[i]>0){
            rt[i]=rt[i]-ts;
            time=time+ts;
        }
        if(rt[i]==0 && flag==1){
            remain=remain-1;
            p[i].ctime=time;
            p[i].tat=time-p[i].atime;
            ttat=ttat+p[i].tat;
            p[i].wtime=p[i].tat-p[i].btime;
            twt=twt+p[i].wtime;
            flag=0;
            }
        if(i==n-1){
            i=0;
        }else if(p[i+1].atime<=time){
            i=i+1;
        }else{
            i=0;
        }
    }
    printf("\n --------------------Table is ---------------------\n ");
  printf("\n pid \t atime \t Btime \t ctime \t tat \t wating \t \n");
  for(int i=0;i<n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].tat,p[i].wtime);
  } 
  printf("\n  TurnAroundTime %f \n  Waiting Time %f\n",ttat,twt);
    printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n",ttat/n,twt/n);
}
