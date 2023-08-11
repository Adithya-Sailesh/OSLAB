#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,ar[10],intial,size,thm,mode,temp,index;
    printf("Enter the total number of requests");
    scanf("%d",&n);
    printf("Enter the requests\n");
    for(int i=0 ;i<n;i++){
        printf("Enter the %d request",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter the intial position");
    scanf("%d",&intial);
    printf("Enter the size");
    scanf("%d",&size);
    printf("Enter the mode (1 for right 2 for left )");
    scanf("%d",&mode);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    for(int i=0 ;i<n;i++){
        if(intial<ar[i]){
            index=i;
            break;
        }
    }
    if(mode ==1){
        for(int i=index;i<n;i++){
            thm=thm+abs(ar[i]-intial);
            intial=ar[i];
        }
        thm=thm+abs(size-intial-1);
        thm=thm+abs(size-1);
        intial=0;
        for(int i=0;i<index;i++){
            thm=thm+abs(ar[i]-intial);
            intial=ar[i];
        }
    }
    else{
        for(int i=index-1;i>=0;i--){
            thm=thm+abs(ar[i]-intial);
            intial=ar[i];
        }
        thm=thm+abs(intial-0);
        thm=thm+abs(size-0-1);
        intial=size-1;
        for(int i=n;i>=index;i--){
            thm=thm+abs(ar[i]-intial);
            intial=ar[i];
        }
    }printf("Total Head Movement %d",thm);
}