#include "io.h"
int dp[1000][1000];
int coinChange(int* arr, int val, int N) {
    if(val==0) return 1;
    if(N==0) return 0;
    if(dp[N][val]) return dp[N][val];
    if(arr[N-1]<=val) return dp[N][val] = coinChange(arr, val, N-1) + coinChange(arr, val-arr[N-1], N);
    return dp[N][val] = coinChange(arr, val, N-1);
}

int main() {
    inputOutput();
    for(int i=0; i<1000; i++) for(int j=0; j<1000; j++) dp[i][j]=0;
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    int target; cin>>target;
    cout<<coinChange(arr, target, size);
}