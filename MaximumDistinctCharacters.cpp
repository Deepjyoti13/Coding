#include "io.h"

int main() {
    inputOutput();
    string str;
    cin>>str;
    map<char, int> seen;
    int s=0, e=0;
    int soFar = 0;
    int answer = 0;
    for(int i=0; i<str.length(); i++) {
        if(seen.find(str[i]) == seen.end()) {
            seen[str[i]] = i;
            e++;
            soFar++;;
        }
        else {
            s = seen[str[i]] + 1;
            e = i;
            seen[str[i]] = i;
            soFar = 1;
        }
        answer = max(soFar, answer);
    }
    cout<<answer<<endl;
    for(int i=s; i<=e; i++) cout<<str[i];
}