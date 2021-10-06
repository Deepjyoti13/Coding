#include "io.h"
int rotation(int* arr, int N) {
    if(N<=1) return 0;
    for(int i=1; i<N; i++) if(arr[i]<arr[i-1]) return i;
    return 0;
}
int main() {
    inputOutput();
    int size; cin>>size;
    int* arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<rotation(arr, size);
    delete[] arr;
} 