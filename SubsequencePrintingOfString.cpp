#include "io.h"

void subsequence(string input, string output) {
    if(input.empty()) {
        cout<<output<<endl;
        return;
    }
    subsequence(input.substr(1), output);
    subsequence(input.substr(1), output+input[0]);
}

int main() {
    inputOutput();
    string input;
    string output="";
    cin>>input;
    subsequence(input, output);
}