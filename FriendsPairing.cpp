#include "io.h"
int dp[1000];
int friendsPairing(int N) {
    if(N<3) return N;
    if(dp[N]) return dp[N];
    return dp[N] = friendsPairing(N-1) + (N-1)*friendsPairing(N-2);
}
int main() {
    inputOutput();
    for(int i=0; i<1000; i++) dp[i]=0;
    int N; cin>>N;
    cout<<friendsPairing(N);
}