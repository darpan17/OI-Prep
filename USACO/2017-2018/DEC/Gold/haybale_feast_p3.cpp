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
ll seg[4*MAXN], a[MAXN];
ll f[MAXN];

void build(int node, int ss, int se) {
    if(ss > se) return;
    if(ss == se) { seg[node] = a[ss]; return; }
    int mid = ss+se >> 1;
    build(node*2+1, ss, mid);
    build(node*2+2, mid + 1, se);
    seg[node] = max(seg[2*node+1], seg[2*node+2]);
}

ll query(int node, int ss, int se, int qs, int qe) {
    if(ss > se || qs > se || qe < ss) return 0;
    if(ss >= qs && se <= qe) return seg[node];
    int mid = ss + se >> 1; 
    int q1 = query(node*2+1, ss, mid, qs, qe);
    int q2 = query(node*2+2, mid+1, se, qs, qe);
    return max(q1, q2);
}

void solve() {
    int n; ll m; cin >> n >> m;
    ll ans = 1e18+5;
    for(int i = 1; i <= n; i++) cin >> f[i] >> a[i];
    build(1, 1, n);
    ll pre[n+5];
    pre[0] = 0;
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + f[i];
    for(int i = 1; i <= n; i++) {
        if(pre[i] < m) continue;
        int lowerb = 1, upperb = i, mid = 0;
        while(lowerb <= upperb) {
            mid = lowerb + upperb >> 1;
            if(pre[i] - pre[mid-1] == m) {
                ans = min(ans, query(1, 1, n, mid, i));
                break;
            } else if(pre[i] - pre[mid-1] < m) {
                upperb = mid - 1;
            } else {
                if(pre[i] - pre[mid] < m) {
                    ans = min(ans, query(1, 1, n, mid, i));
                    break;
                } else {
                    lowerb = mid + 1;
                }
            }
        }
        
    }
    cout << ans;
}
