#include <bits/stdc++.h>
using namespace std;
#define int long long 

int ans;

pair<int,int> ask(int x) {
    cout << x << endl;
    pair<int,int> res;
    cin >> res.first >> res.second;
    return res;
}

void print() {
    cout << "Answer " << ans << endl;
}

void doo(int x) {
    pair<int,int> res = ask(x);
    if(res.first == 0 && res.second == 0) return;
    ans = max(ans,res.first);
    ans = max(ans,res.second);
    if(res.first != 0) doo(res.first);
    if(res.second != 0) doo(res.second);
}

void solve() {
    doo(1);
    print();
}

int32_t main() {
    solve();
    return 0;
}
