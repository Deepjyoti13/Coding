#include "io.h"
int dp[1000];
int fib(int n) {
    if(n <= 1) return n;
    if(dp[n]) return dp[n];
    int res = fib(n-1)+fib(n-2);
    return dp[n] = res;
}

int main() {
    inputOutput();
    for(int i=0; i<1000; i++) dp[i]=0;
    int N;
    cin>>N;
    cout<<fib(N);
}