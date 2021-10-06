#include "io.h"
int dp[1000][1000];

int minCoinExchange(int* arr, int N, int cap) {
    if(cap==0) return 0;
    if(N==0 && cap!=0) return 0;
    if(dp[N][cap]!=0) return dp[N][cap];
    if(arr[N-1]<=cap)
        return dp[N][cap] = 1+min(minCoinExchange(arr, N, cap-arr[N-1]), minCoinExchange(arr, N-1, cap));
    return dp[N][cap] = minCoinExchange(arr, N-1, cap);
}

int main() {
    inputOutput();
    for(int i=0; i<1000; i++) for(int j=0; j<1000; j++) dp[i][j]=0;
    int N; cin>>N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        cin>>arr[i];
    int cap; cin>>cap;
    cout<<minCoinExchange(arr, N, cap);
    delete[] arr;
}