#include "io.h"

int dp[1000];
int minSteps(int N) {
    if(N==1) return 0;
    if(dp[N]) return dp[N];
    int byTwo = INT_MAX;
    int byThree = INT_MAX;
    int minusOne = minSteps(N-1);
    if(N%3==0) byThree = minSteps(N/3);
    if(N%2==0) byTwo = minSteps(N/2);
    int res = 1 + min(byThree, min(byTwo, minusOne));
    return dp[N] = res;
}

int main() {
    inputOutput();
    for(int i=0; i<1000; i++) dp[i]=0;
    int N;
    cin>>N;
    cout<<minSteps(N);
}