#include<stdio.h>
struct sched{
    int pid;
    int atime;
    int btime;
    int priority;
    int ctime;
    int ttime;
    int wtime;
}p[10],most;
void main(){
    int i,j,n,finish[10],ttat=0,time=0,index;
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Enter the arival time btime priority\n");
    for(i=0;i<n;i++){
        p[i].pid=i;
        printf("Enter the details of %dProcess",i);
        scanf("%d %d %d",&p[i].atime,&p[i].btime,&p[i].priority);
    }
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    int remain=n;
    while (remain!=0)
    {   index=-1;
        for(i=0;i<n;i++){
            if(p[i].atime<=time && finish[i]==0){
                if(index==-1){
                    index=i;
                }
                else{
                    if(p[i].priority<p[index].priority){
                        index=i;
                    }
                }
            }
        }
        if(index==-1){
            //no process arrived
            time=time+1;
        }else{
            printf("\n test 4");
            finish[index]=1;
            remain=remain-1;
            time=time+p[index].btime;
            printf("\n time %d",time);
            p[index].ctime=time;
            p[index].ttime=p[index].ctime-p[index].atime;
            ttat=ttat+p[index].ttime;
            p[index].wtime=p[index].ttime-p[index].btime;
        }
    }
    printf("\n --------------------Table is ---------------------\n ");
  printf("\n pid \t atime \t Btime \t ctime \t tat \t wating \t \n");
  for(int i=0;i<n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);
  } 
  printf("total tat =%d",ttat);
}
