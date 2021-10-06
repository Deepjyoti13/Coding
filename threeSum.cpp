#include "io.h"

int threeSum(int* arr, int N) {
    if(N==0) return 0;
    return threeSum(arr, N-1) + arr(arr)
}

int main() {
    inputOutput();
    int size; cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<threeSum(arr, size);
}