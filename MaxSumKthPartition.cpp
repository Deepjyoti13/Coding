#include "io.h"
int dp[1000] = {0};
int maxSum(int* arr, int N, int K) {
    dp[0] = arr[0]>0?arr[0]:0;
    int max_1 = 0;
    int max_2 = 0;
    for (size_t i = 1; i < N; i++)
    {
        if(max_1<arr[i]) {
            max_1 = i;
        }
        if
        dp[i] = arr[i] + dp[i-(i%K+1)];
    }
    
}

int main() {
    int N; cin>>N;
    int* arr = new int[N];
    for(int i=0; i<N; i++) cin>>arr[i];
    int K; cin>>K;
    cout<<maxSum(arr, N, K);
    delete[] arr;
}