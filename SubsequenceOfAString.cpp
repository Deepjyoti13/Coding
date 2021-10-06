#include "io.h"
string output[1000];

int subsequence(string input) {
    if(input.empty()) {
        output[0] = "";
        return 1;
    }
    string substring = input.substr(1);
    int outputSize = subsequence(substring);
    for (size_t i = 0; i < outputSize; i++)
    {
        output[i+outputSize] = input[0] + output[i];
    }
    return outputSize*2;
}

int main() {
    inputOutput();
    string str;
    cin>>str;
    // cout<<str;
    int size = subsequence(str);
    for (size_t i = 0; i < size; i++)
    {
        cout<<output[i]<<endl;
    }
    
}