#include "io.h"

void permutation(string input, string output) {
    if(input.empty()) {
        cout<<output<<endl;
        return;
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        permutation(input.substr(0,i)+input.substr(i+1), output+input[i]);
    }
    
}

int main() {
    inputOutput();
    string input; cin>>input;
    string output="";
    permutation(input, output);
}