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

int t[1001][1001];//assuming maximum length of rod be 1000
int rodCutting(int size,int n,int length[],int profit[]){//size is the size of the arrays given
    if(size==0 || n==0) return 0;
    if(t[size][n]!=-1) return t[size][n];
    if(length[size-1]<=n){
        return t[size][n]=maximum(profit[size-1]+rodCutting(size,n-length[size-1],length,profit),
        rodCutting(size-1,n,length,profit));
    }
    else return t[size][n]=rodCutting(size-1,n,length,profit);
}

int main(){

    //case 1: when length array is not given
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //create length array if not given
    int* length=createLengthArray(size);

    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++) t[i][j]=-1;
    }
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
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++) {
            t[i][j]=-1;
        }
    }
    int maxprofit=rodCutting(sizeOfGivenArrays,sizeOfRod,lengthPermissible,price);
    printf("Maximum Obtainable Value is %d",maxprofit);

    return 0;
}