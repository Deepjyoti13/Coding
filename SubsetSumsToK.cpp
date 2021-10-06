#include "io.h"
int dp[1000][1000];
int subsetSum(int* arr, int N, int K, vector<int> output) {
    if(K==0) {
        for(int i=0; i<output.size(); i++) cout<<output[i]<<" ";
        cout<<endl;
        return 1;
    } 
    if(N==0) return 0;
    if(dp[N][K]) return dp[N][K];
    if(arr[N-1]<=K) {
        int tmp = arr[N-1];
        int opt1 = subsetSum(arr, N-1, K, output);
        output.push_back(arr[N-1]);
        int opt2 = subsetSum(arr, N-1, K-arr[N-1], output);
        return dp[N][K] = opt1 + opt2; // not adding arr[N-1] to the first part because we are checking for number of ways to K not summing to K (like minimum steps to K).
    }
    return dp[N][K] = subsetSum(arr, N-1, K, output);
}

int main() {
    inputOutput();
    vector<int> output;
    for(int i=0; i<1000; i++) for(int j=0; j<1000; j++) dp[i][j] = 0;
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    int K; cin>>K;
    cout<<subsetSum(arr, size, K, output);
    delete[] arr;
}