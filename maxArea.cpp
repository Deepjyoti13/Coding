#include "io.h"

int maxArea(int* height, int N) {
    int l=0, r=N-1;
    int water=0;
    while(l<r) {
        // cout<<height[r]<<" ";
        int vol = (r-l)*min(height[l], height[r]);
        if(height[l]<height[r]) l++;
        else r--;
        water = max(vol, water);
    }
    cout<<endl;
    return water;
}

int main() {
    inputOutput();
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int N = 9;
    cout<<maxArea(arr, N);
}