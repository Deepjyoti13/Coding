#include "io.h"
int dp[1000];
int tillingWays(int N) {
    if(N<=3) return 1;
    if(N==4) return 2;
    if(dp[N]) return dp[N];
    return dp[N] = tillingWays(N-1) + tillingWays(N-4);
}

int main() {
    for(int i=0; i<1000; i++) dp[i]=0;
    inputOutput();
    int breadth; //considering the height is fixed to 4 units.
    cin>>breadth;
    cout<<tillingWays(breadth);
}