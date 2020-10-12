#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n, b;
    scanf("%d%d", &n, &b);
    ll a[n];
    for(int i=0;i<n;i++) scanf("%lld", &a[i]);

    vector<pair<ll, int>> v;
    for(int i=0;i<n;i++) v.push_back(make_pair(a[i], i));
    sort(v.begin(), v.end());

    
    vector<pair<pair<ll, int>, int>> q(b);
    for(int i=0;i<b;i++) {
        q[i].S = i;
        scanf("%lld%d", &q[i].F.F, &q[i].F.S);
    }
    sort(q.begin(), q.end());

    int ans[b];
    memset(ans, false, sizeof(ans));

    multiset<int> gaps;
    set<int> idxs;
    idxs.insert(0);
    idxs.insert(n-1);
    gaps.insert(n-1);
    int nidx = 0;
    for(int i=0;i<b;i++) {
        while(nidx<n && v[nidx].F<=q[i].F.F) {
            // perform the job
            idxs.insert(v[nidx].S);
            int ridx = v[nidx].S, lidx = v[nidx].S;
            auto iter = idxs.find(v[nidx].S);
            ++iter;
            if(iter!=idxs.end())ridx = *iter;
            --iter; 
            if(iter!=idxs.begin()) {
                --iter;
                lidx = *iter;
            }
            gaps.erase(gaps.find(ridx-lidx));
            gaps.insert(ridx-v[nidx].S);
            gaps.insert(v[nidx].S-lidx);
            ++nidx;
        }
    
        // perform the query
        int maxgap = *gaps.rbegin();
        ans[q[i].S] = q[i].F.S>=maxgap;

    }

    for(int i=0;i<b;i++) printf("%d\n", (int)ans[i]);

}
