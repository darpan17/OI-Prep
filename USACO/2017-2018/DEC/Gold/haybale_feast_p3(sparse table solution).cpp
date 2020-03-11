#include <iostream>
#include <iomanip>
#include <cstdio>

#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <cstring>

#include <cassert>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <complex>
#include <random>
#include <utility>
 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define ll long long 

#define vi vector<int>
#define vl vector<ll>

#define pi pair<int,int>
#define pl pair<ll,ll>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template <class P,class Q>
void operator << (ostream& out, pair<P,Q> p) {
    out << "(" << p.first << ", " << p.second << ")";
}
template <class T>
void operator << (ostream& out, vector<T> v) {
    bool f = true;
    out << "{";
    for(auto i:v) {
        if(!f) out << ", "; 
        out << i;
        f = false;
    }
    out << "}";
}
void solve();
signed main() {
    #ifdef LOCAL
    freopen("inp.txt","r",stdin);
    #else 
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1; //  cin >> t;
    while(t--) solve();
    return 0;
}

const int MAXN = 1e5+5;
ll a[MAXN];
ll f[MAXN];
ll sparse[MAXN][25];
int n;

void build_sparse() {
    for(int i = 0; i < n; i++) sparse[i][0] = a[i];
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; (i + (1 << j) - 1) < n; i++) {
            sparse[i][j] = max(sparse[i][j-1], sparse[i+(1<<j-1)][j-1]);
        }
    }
}

ll query(int lower, int upper) {
    int len = upper - lower + 1;
    int lo = log2(len);
    return max(sparse[lower][lo], sparse[lower+len-(1<<lo)][lo]);
}

void solve() {
    ll m; cin >> n >> m;
    ll ans = 1e18+5;
    for(int i = 1; i <= n; i++) cin >> f[i] >> a[i];
    build_sparse();
    ll pre[n+5];
    pre[0] = 0;
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + f[i];
    for(int i = 1; i <= n; i++) {
        if(pre[i] < m) continue;
        int lowerb = 1, upperb = i, mid = 0;
        while(lowerb <= upperb) {
            mid = lowerb + upperb >> 1;
            if(pre[i] - pre[mid-1] == m) {
                ans = min(ans, query(mid, i));
                break;
            } else if(pre[i] - pre[mid-1] < m) {
                upperb = mid - 1;
            } else {
                if(pre[i] - pre[mid] < m) {
                    ans = min(ans, query(mid, i));
                    break;
                } else {
                    lowerb = mid + 1;
                }
            }
        }
    }
    cout << ans;
}
