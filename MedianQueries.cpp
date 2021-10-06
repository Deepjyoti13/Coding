#include "io.h"

int findMedian(int* arr, int size, int L, int R) {
    int* tmp; tmp=arr;
    sort(tmp+L-1, tmp+R);
    int result = (L+R)/2 - 1;
    return arr[result];
}

int main() {
    inputOutput();
    int size; cin>>size;
    int *arr = new int[size];
    for(int i = 0; i<size;  i++) cin>>arr[i];
    int Q; cin>>Q;
    while(Q--) {
        int L, R;
        cin>>L>>R;
        cout<<findMedian(arr, size, L, R)<<endl;
    }
    return 0;
}