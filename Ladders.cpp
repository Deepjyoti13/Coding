#include "io.h"

int dp[1000][1000];
int tmp[1000];
int laddersCombination(int N, int K) {
    if(N==0) return 1;
    if(K==0) return 0;
    if(N==1) return N;
    if(dp[N][K]) return dp[N][K];
    if(K<=N)
        return dp[N][K] = laddersCombination(N-K, K) + laddersCombination(N, K-1);
    return dp[N][K] = laddersCombination(N, K-1);
}

int laddersPermutation(int N, int K) {
    if(N==0) return 1;
    if(K==0) return 0;
    if(tmp[N]) return tmp[N];
    int res = 0;
    for(int i=1; i<=K; i++) if(N-i>=0) res+=laddersPermutation(N-i, K);
    return tmp[N] = res;
}

int main() {
    inputOutput();
    for(int i=0; i<1000; i++) for(int j=0; j<1000; j++) dp[i][j] = 0;
    for(int i=0; i<1000; i++) tmp[i] = 0;
    int N, K;
    cin>>N>>K;
    cout<<laddersCombination(N, K)<<"\n"<<laddersPermutation(N, K);
}