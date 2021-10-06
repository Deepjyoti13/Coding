#include "io.h"

int dp[100][100];

int maxProfit(int *arr, int s, int N, int y) {
    if(s>N) return 0;
    if (dp[s][N]!=-1) return dp[s][N];
    return dp[s][N] = max(arr[s]*y + maxProfit(arr, s+1, N, y+1), maxProfit(arr, s, N-1, y+1)+arr[N]*y);
}

int main() {
    inputOutput();
    for(int i=0; i<100; i++) for(int j=0; j<100; j++) dp[i][j]=-1;
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<maxProfit(arr, 0, size-1, 1);
    // cout<<endl;
    // for(int i=0; i<=5; i++) {for(int j=0; j<=5; j++) cout<<dp[i][j]<<" "; cout<<endl;}
    delete[] arr;
}