#include <bits/stdc++.h>
#include "combo.h"
using namespace std;
/*
int press(string x) {
    cout << x << endl;
    int r; cin >> r;
    return r;
}
*/
string guess_sequence(int n) {
    string ans = "";
    int oup;
    oup = press("AB");
    if(oup) { 
        oup = press("A");
        if(oup) ans += 'A';
        else ans += 'B';
    } else {
        oup = press("X");
        if(oup) ans += 'X';
        else ans += 'Y';
    }
    if(n == 1) return ans;
    const string oof = "ABXY";
    string ask = "";
    for(int i = 0; i < 4; i++) {
        if(ans[0] != oof[i]) ask += oof[i];
    }
    for(int i = 1; i < n-1; i++) {
        string s1 = ans+ask[0];
        string s2 = ans+ask[1]+ask[0];
        string s3 = ans+ask[1]+ask[1];
        string s4 = ans+ask[1]+ask[2];
        oup = press(s1+s2+s3+s4);
        if(oup == i) ans += ask[2];
        else if(oup == i+1) ans += ask[0];
        else ans += ask[1];
    }
    oup = press(ans+ask[0]+ans+ask[1]);
    if(oup != n) {
        ans += ask[2];
    } else {
        oup = press(ans+ask[0]);
        if(oup == n) ans += ask[0];
        else ans += ask[1];
    }
    return ans;
}
/*
int main() {
    cout << guess_sequence(3) << endl;
}
