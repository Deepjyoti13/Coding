#include "io.h"
bool balanced(string str) {
    stack<char> checker;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
            checker.push(str[i]);
        else if(str[i] == '}') {
            if(checker.empty() || checker.top()!='{')
                return false;
            checker.pop();
        }
        else if(str[i] == ']') {
            if(checker.empty() || checker.top()!='[')
                return false;
            checker.pop();
        }
        else if(str[i] == ')') {
            if(checker.empty() || checker.top()!='(')
                return false;
            checker.pop();
        }
    }
    return checker.empty();
}
int main() {
    inputOutput();
    string str; cin>>str;
    cout<<balanced(str);
}