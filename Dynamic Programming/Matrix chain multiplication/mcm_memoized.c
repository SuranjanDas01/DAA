//by SURANJAN DAS
#include <stdio.h>
#include <limits.h>

int min(int a,int b){return a<b?a:b;}

int t[100][100]; //assuming max length to be 100
int mcm(int i,int j,int arr[]){
    if(i>=j) return 0;
    //checking if present
    if(t[i][j]!=-1) return t[i][j];
    //variable to store the minimum number of ops
    int mini=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+mcm(i,k,arr)+mcm(k+1,j,arr);
        mini=min(mini,steps);
    }
    return t[i][j]=mini;
}

// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    //filling up with -1
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            t[i][j]=-1;
        }
    }

    int minops=mcm(1, N - 1,arr);
    // Function call
    printf("Minimum number of multiplications is %d ",minops);
    
    return 0;
}