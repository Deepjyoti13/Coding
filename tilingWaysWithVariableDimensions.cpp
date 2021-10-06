// https://www.youtube.com/watch?v=_c_R-uIi-zU for future reference
#include "io.h"

int tilingWays(int L, int B) {
    if(L==0 || B==0) return 0;
    if(L==B) return 2;
    if(L>B) return 1;
    return tilingWays(L, B-1) + tilingWays(L, B-L);
}

int main() {
    inputOutput();
    int L, B;
    cin>>L>>B;
    cout<<tilingWays(L, B);
}