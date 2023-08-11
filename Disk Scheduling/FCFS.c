#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,ar[10],intial,totalheadmovement,order[10];
    printf("Enter the number of request\n");
    scanf("%d",&n);
    printf("Enter the requests \n");
    for(int i=0;i<n;i++){
        printf("Enter the %d request = ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter the intial head position\n");
    scanf("%d",&intial);
    for(int k=0;k<n;k++){
        totalheadmovement=totalheadmovement+abs(ar[k]-intial);
        intial=ar[k];
        order[k]=ar[k];
    }
    printf("Total head movement = %d \n",totalheadmovement);
    printf("Order is");
    for(int i=0;i<n;i++){
        printf("%d -> ",order[i]);
    }
    return 0;
