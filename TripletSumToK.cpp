#include "io.h"

int dp[100][100];

// Getting error while printing (Does not give all the OP)
// int sumK(int* arr, int N, int val, int K, vector<int> output) {
//     if(val==0 && K==0) {
//         for(int i=0; i<output.size(); i++) cout<<output[i]<<" ";
//         cout<<endl;
//         return 1;
//     }
//     if(val==0 || N==0 || K==0) return 0;
//     if(dp[N][val]) return dp[N][val];
//     if(arr[N-1]<=val) {
//         int opt1 = sumK(arr, N-1, val, K, output);
//         output.push_back(arr[N-1]);
//         int opt2 = sumK(arr, N-1, val-arr[N-1], K-1, output);
//         return dp[N][val] = opt1 + opt2;
//     }
//     return dp[N][val] = sumK(arr, N-1, val, K, output);
// }


int sumK(int* arr, int N, int val, int K) {
    if(val==0 && K==0) return 1;
    if(val==0 || N==0 || K==0) return 0;
    if(dp[N][val]) return dp[N][val];
    if(arr[N-1]<=val)
        return dp[N][val] = sumK(arr, N-1, val-arr[N-1], K-1) + sumK(arr, N-1, val, K);
    return dp[N][val] = sumK(arr, N-1, val, K);
}

int main() {
    for(int i=0; i<100; i++) for(int j=0; j<100; j++) dp[i][j]=0;
    inputOutput();
    int size; cin>>size;
    int *arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    int val; cin>>val;
    cout<<sumK(arr, size, val, 3); // Replace 3 with 2 or 4 or anything to get doublet / quadruplet / etc.
    delete[] arr;
}