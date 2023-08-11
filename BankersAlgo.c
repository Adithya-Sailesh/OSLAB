#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,r,i,j,k,index=0,flag,allo[10][10],max[10][10],need[10][10],avail[10],finish[10],order[10];
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Enter the number of resource");
    scanf("%d",&r);
    printf("Enter the allocated values");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&allo[i][j]);
        }
    }
    printf("\nEnter the max matrix");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    for(i=0;i<n;i++){
        finish[i]=-1;
    }
    printf("\nEnter the available");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            flag=0;
            if(finish[j]==-1){
                for(k=0;k<r;k++){
                    if(need[j][k]>avail[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    finish[j]=1;
                    order[index++]=j;
                    for(int y=0;y<r;y++){
                        avail[y]=avail[y]+allo[j][y];
                    }
                }
            }
        }
    }
    int check=0;    //printing
    for(i=0;i<n;i++){
        if(finish[i]==-1){
            check=1;
            printf("System Not in safe state");
            break;
        }
    }
    if(check==0){
        printf("System in safe state \n");
        for(i=0;i<n;i++){
            printf("%d ->",order[i]);
        }
    }
}
