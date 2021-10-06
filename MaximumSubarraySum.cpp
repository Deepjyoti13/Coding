#include "io.h"

int maxSum(int* arr, int size) {
    int maxHere = arr[0];
    int res = arr[0];
    for(int i=1; i<size; i++) {
        maxHere = max(arr[i], maxHere+arr[i]);
        res = max(maxHere, res);
    }
    return res;
}

int dp[1000];
// int sum=INT_MIN, res=INT_MIN;
// int maxSum2(int* arr, int N) {
//     if(N==0) return N;
//     if(N==1) return arr[N-1];
//     if(dp[N]) return dp[N];
//     if(dp[N-1]+arr[N-1]>dp[N-1])
//         return dp[N] = dp[N-1]+arr[N-1];
//     return dp[N] = max(dp[N-1], arr[N-1]);
//     sum = max(maxSum2(arr, N-1)+arr[N-1], arr[N-1]);
//     res = max(res, sum);
//     return res;
// }

int maxSum3(int* arr, int N) { //Does not work when all elements are negative
    int dp[10000] = {0};
    dp[0] = arr[0]>0?arr[0]:0;
    int res = arr[0];
    for(int i=1; i<N; i++) {
        dp[i] = dp[i-1] + arr[i];
        if(dp[i]<0) dp[i] = arr[i];
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    for(int i=0; i<1000; i++) dp[i] = 0;
    inputOutput();
    int size; cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<maxSum(arr, size)<<"\n"<<maxSum3(arr, size);
    delete[] arr;
}