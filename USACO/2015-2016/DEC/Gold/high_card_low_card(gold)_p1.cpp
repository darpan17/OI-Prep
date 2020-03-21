#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> e_low,e_high,b_low,b_high;
    for(int i = 0; i < n/2; i++) e_high.push_back(a[i]);
    for(int i = n/2; i < n; i++) e_low.push_back(a[i]);
    bool done[n*2+1];
    memset(done,false,sizeof(done));
    for(auto i:a) done[i] = true;
    vector<int> bessie;
    for(int i = 1; i <= n*2; i++) {
        if(!done[i]) {
            bessie.push_back(i);
        }
    }
    for(int i = 0; i < n/2; i++) b_low.push_back(bessie[i]);
    for(int i = n/2; i < n; i++) b_high.push_back(bessie[i]);
    int ans = 0;
    sort(e_low.begin(),e_low.end());
    int idx = 0;
    for(int i = 0; i < n/2; i++) {
        if(b_low[idx] < e_low[i]) {
            ans++;
            idx++;
        }
    }
    sort(b_high.rbegin(),b_high.rend());
    sort(e_high.rbegin(),e_high.rend());
    idx = 0;
    for(int i = 0; i < n/2; i++) {
        if(b_high[idx] > e_high[i]) {
            ans++;
            idx++;
        }
    }
//    cout << "elow "; for(auto i:e_low) cout << i << " ";cout << endl;
//    cout << "blow "; for(auto i:b_low) cout << i << " ";cout << endl;
//    cout << "ehi "; for(auto i:e_high) cout << i << " ";cout << endl;
//    cout << "bhi "; for(auto i:b_high) cout << i << " ";cout << endl; 
    cout << ans;
}
