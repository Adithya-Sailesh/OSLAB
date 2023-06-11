#include<stdio.h>
void main(){
    printf("--------------------Best FIT-------------------------\n");
    int p[10],b[10],alloc[10],np,nb,index,occu[10];
    printf("Enter the number of blocks\n");
    scanf("%d",&nb);
    for(int i=0;i<nb;i++){
        printf("Enter the size of %d Block",i);
        scanf("%d",&b[i]);
    }
    printf("Enter the number of process\n");
    scanf("%d",&np);
    for(int i=0;i<np;i++){
        printf("Enter the size of %d Process",i);
        scanf("%d",&p[i]);
    }
    for(int i=0;i<np;i++){
            alloc[i]=-1;
    }
    for(int i=0;i<np;i++){
            occu[i]=0;
    }
    for(int i=0;i<np;i++){
        index=-1;
        for(int j=0;j<nb;j++){
            if(b[j]>p[i] && occu[j]==0){
                if(index==-1){
                    index=j;
                }
                else if(b[j]<b[index]){
                        index=j;
                }
            }
        }
        if(index!=-1){
            alloc[i]=index;
            occu[index]=1;
        }
    }
    printf("\n---------------AFTER ALLOCATION-------------------\n");
    printf("PROCESS ID \t PROCESS SIZE \t BLOCK ID \n");
    for(int i=0;i<np;i++){
        if(alloc[i]==-1){
            printf("%d \t %d \t NOT ALLOCATED \t \n",i+1,p[i]);
        }
        else{
            printf("%d \t %d \t %d \t \n",i+1,p[i],alloc[i]+1);
        }
    }
}
