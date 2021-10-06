#include "io.h"

int dp[1000] = {0};
int maxSum(int* arr, int N, int K) {
    int ans = INT_MIN;
    int maxK=0;
    dp[0] = arr[0];
    for(int i=1; i<N; i++) {
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
    }
    for(int i=0; i<K; i++) {
        maxK+=arr[i];
    }
    int result = maxK;
    for(int i=K; i<N; i++) {
        maxK+=max(arr[i]-arr[i-K], arr[i]-arr[i-K]+dp[i-K]);
        result = max(result, maxK);

    }
    return result;
}

int main() {
    inputOutput();
    int N;
    cin>>N;
    int *arr = new int[N];
    for(int i=0; i<N; i++) cin>>arr[i];
    int K; cin>>K;
    cout<<maxSum(arr, N, K);
    delete[] arr;
}