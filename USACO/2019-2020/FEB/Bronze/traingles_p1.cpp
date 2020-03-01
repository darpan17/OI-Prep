#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
    //~ freopen("inp.txt","r",stdin);
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    pair<int,int> a[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[j].first == a[i].first && a[j].second == a[k].second) {
                    int temp = abs(a[j].second-a[i].second)*abs(a[j].first-a[k].first);
                    if(temp < 0) temp *= -1;
                    //~ cout << "temp = " << temp << endl;
                    ans = max(ans,temp);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
