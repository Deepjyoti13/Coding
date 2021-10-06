#include "io.h"
int dp[1000] = {0};
int numberOfStrings(int* arr, int N) {
    if(N<=1) return N;
    // cout<<(arr[N-2]*10+arr[N-1])<<" ";
    if(N==2 && arr[N-2]*10+arr[N-1]<=26) return 2;
    if(dp[N]) return dp[N];
    if(N==2) return 2;
    int res = numberOfStrings(arr, N-1);
    int res2 = 0;
    if(arr[N-2]*10+arr[N-1]<=26)
        res2 = numberOfStrings(arr, N-2);
    return dp[N] = res+res2;
}

int main() {
    inputOutput();
    string num;
    cin>>num;
    int number[num.size()];
    for(int i=0; i<num.size(); i++) {
        number[i] = num[i]-'0';
    }
    cout<<numberOfStrings(number, num.size());
}