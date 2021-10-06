#include "io.h"

int main() {
    inputOutput();
    string arr = "22323";
    string ch = "C";
    string str[] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
    int s = 12;
    map<int, string> myMap;
    for(int i=0; i<s; i++) {
        myMap[i] = str[i];
    }
    int index;
    for(int i=0; i<s; i++) {
        if(str[i]==ch) {
            index = i;
            break;
        }
    }
    string ouputStr = "";
    ouputStr = ouputStr+str[index];
    for (int i = 0; i < 5; i++)
    {
        index+=(arr[i]-'0');
        ouputStr = ouputStr+str[index];
        // index = i+index;
    }
    cout<<ouputStr;
}