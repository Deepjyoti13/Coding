#include "io.h"
int dp[1000];
int countWays(int N, int last) {
    if(N==1 && last==0) return 2;
    if(N==1 && last==1) return 1;
    if(dp[N]) return dp[N];
    if(last==0) return dp[N] = countWays(N-1, 0) + countWays(N-1, 1);
    return dp[N] = countWays(N-1, 0);
}

int main() {
    inputOutput();
    for(int i=0; i<1000; i++) dp[i]=0;
    int N;
    cin>>N;
    cout<<countWays(N, 0);
}