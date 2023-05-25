//by SURANJAN DAS
#include <stdio.h>
#include <limits.h>

int min(int a,int b){return a<b?a:b;}

int mcm(int arr[],int n){
    int dp[n][n];
    //Initialisation
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }

    //filling up
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j;k++){
                int mini=INT_MAX;
                mini=min(mini,arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                dp[i][j]=mini;
            }
        }
    }
    //returning answer
    return dp[1][n-1];
}

// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    int minops=mcm(arr,N);
    // Function call
    printf("Minimum number of multiplications is %d ",minops);
    
    return 0;
}