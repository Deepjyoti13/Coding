#include "io.h"

void subsequence(int* input, int N, vector<int> output) {
    if(N==0) {
        for(int i=0; i<output.size(); i++) cout<<output[i]<<" ";
        cout<<endl;
        return;
    }
    subsequence(input+1, N-1, output);
    output.push_back(input[0]);
    subsequence(input+1, N-1, output);
}

int main() {
    inputOutput();
    int count; cin>>count;
    int *input = new int[count];
    for(int i=0; i<count; i++) cin>>input[i];
    vector<int> output;
    subsequence(input, count, output);
    delete[] input;
}