//by SURANJAN DAS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int maximum(int a,int b){return a>b?a:b;}

int* createLengthArray(int n){
    int* arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) arr[i]=i+1;
    return arr;
}

int rodCutting(int size,int n,int length[],int profit[]){//size is the size of the arrays given
    int dp[size+1][n+1];
    for(int i=0;i<=size;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(length[i-1]<=j) dp[i][j]=maximum(profit[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[size][n];
}

int main(){

    //case 1: when length array is not given
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //create length array if not given
    int* length=createLengthArray(size);

    //Since length array is not given we assume the size of the rod 
    //to be equal to size of the given profit or value array
    int maxprof=rodCutting(size, size, length,arr); 
    printf("Maximum Obtainable Value is %d",maxprof);

    printf("\n");
    //case 2: when length array is given but its size is less than the size of rod
    int sizeOfRod=5;
    int lengthPermissible[]={1,2,3,4};
    int price[]={2,5,7,8};
    int sizeOfGivenArrays=sizeof(price)/sizeof(price[0]);
    int maxprofit=rodCutting(sizeOfGivenArrays,sizeOfRod,lengthPermissible,price);
    printf("Maximum Obtainable Value is %d",maxprofit);

    return 0;
}