#include "io.h"

string longestCommonPrefix(string* strs, int N) {
    string ans = "";
    for(int j=0; j<strs[0].length(); j++) {
        for(int i=1; i<3; i++) {
            if(strs[i][j] != strs[0][j])
                return ans;
        }
        ans = ans + strs[0][j];                
    }
    return ans;
}

int main() {
    inputOutput();
    string strs[] = {"flower", "flow", "flat"};
    cout<<longestCommonPrefix(strs, 3);
}