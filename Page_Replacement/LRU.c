#include<stdio.h>
#include<stdlib.h>
void main(){
     int i,j,k,n,f,fault=0,next=0,min,rs[20],m[20],count[20],flag[20];
    printf("Enter the number of pages");
    scanf("%d",&n);
    printf("Enter the pages");
    for(int i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("Enter the frame size");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        m[i]=-1;
        count[i]=0;
    }
    for(i=0;i<n;i++){
          flag[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(rs[i]==m[j]){
                flag[i]=1;
                count[j]=next;
                next++;
                break;
            }
        }if(flag[i]==0){
            if(i<f){
                m[i]=rs[i];
                count[i]=next;
                next++;
            }
            else{
                min=0;
                for(int k=0;k<f;k++){
                    if(count[min]>count[k]){
                        min=k;
                    }
                }
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
         fault++;   
        }for(k=0;k<f;k++){
            printf("%d \t",m[k]);
        }
        if(flag[i]==0){
            printf("Page Fault no %d",fault);
            printf("\n");
        }
        else{
            printf("Page Hit");
            printf("\n");
        }
    }printf("Total Page hit =%d",fault);
}
