#include<stdio.h>
#include<stdlib.h>
void main(){
    int i,j,k,n,f,fault=0,rs[20],m[20],count=0,flag;
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
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(rs[i]==m[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            m[count++]=rs[i];
            fault++;
        }
        for(k=0;k<f;k++){
            printf("%d \t",m[k]);
        }
        if(flag==0){
            printf("Page Fault no %d",fault);
            printf("\n");
        }
        else{
            printf("Page Hit");
            printf("\n");
        }
        if(count==f){
            count=0;
        }
    }
    printf("Total Page hit =%d",fault);
}
