// Soln: Use DSU to find MST in graph. The longest edge of resulting MST is the answer.
#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define ps puts
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vl vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define LOCAL freopen("inp.txt","r",stdin);
#define TC int T; sf("%d",&T); while(T--)
using namespace std;
const int MAXN = 1e6+5;
const ll MOD = 1e9+7;
const int INF = (1<<23);
const ll LINF = (1ULL<<56);

pii a[2005];
int root[2005];
int ranks[2005];

int findroot(int a){
    if(root[a]==a) return a;
    else return root[a] = findroot(root[a]);
}

bool union_(int a,int b){
    int r1 = findroot(a);
    int r2 = findroot(b);
    if(r1 == r2) return false;
    if(ranks[r1]>ranks[r2]){
        root[r2] = r1;
        ranks[r1]+=ranks[r2];
    }else{
        root[r1] = r2;
        ranks[r2]+=ranks[r1];
    }
    return true;
}

// calculating squared distance from beginning to avoid precision issues
inline ll dist(int i,int j){
    ll res = (a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second);
    return res;
}

int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n; sf("%d",&n);
    for(int i = 0; i < n; i++) sf("%d%d",&a[i].first,&a[i].second);
    vector<pair<ll,pair<int,int>>> edges;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            edges.pb(mp(dist(i,j),mp(i,j)));
        }
    }
    for(int i = 0; i < n; i++){
        root[i] = i;
        ranks[i] = 1;
    }
    sort(edges.begin(),edges.end());
    ll ans = 0;
    for(auto i:edges){
        if(union_(i.second.first,i.second.second)) ans = max(i.first,ans);
    }
    pf("%lld",ans);
    return 0;
}
