#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

void FindSubString(char* str) {
    int n = strlen(str);
    unordered_set<char> occ;
    int rp = 0, lp = 0;
    int maxstr = 0, ans = 0;
    for (; lp < n; lp++) {
        if (lp != 0) {
            occ.erase(str[lp - 1]);
        }
        while (rp + 1 < n && !occ.count(str[rp + 1])) {
            occ.insert(str[rp + 1]);
            rp++;
        }
        if (maxstr < rp - lp + 1) {
            maxstr = rp - lp + 1;
            ans = lp;
        }
    }
    for (int n = 0; n < maxstr; n++) {
        cout << str[ans + n];
    }
    cout << endl;
}

int main() {
    char s[] = "abhjkhabxk";
    FindSubString(s);
    return 0;
}