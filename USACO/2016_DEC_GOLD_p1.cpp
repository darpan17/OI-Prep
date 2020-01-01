#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define ps puts
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vl vector<double>
#define pll pair<double,double>
#define pb push_back
#define mp make_pair
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define LOCAL freopen("inp.txt","r",stdin);
#define TC int T; sf("%d",&T); while(T--)
using namespace std;
const int MAXN = 1e6+5;
const double MOD = 1e9+7;
const int INF = (1<<23);
const double LINF = (1ULL<<56);

double dp[2005][2005];
pii a[2005];

inline double dist(int i,int j){
    double res = (double)sqrt((a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second));
    return res;
}

double DP(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i>j) return 0;
    if(i==j) return dp[i][j] = 0;
    else if(i == j-1) return dp[i][j] = dist(i,j);
    double res = 0;
    res = min(DP(i+1,j),DP(i,j-1));
    return dp[i][j] = res;
}

int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n; sf("%d",&n);
    for(int i = 0; i < n; i++) sf("%d%d",&a[i].first,&a[i].second);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }
    DP(0,n-1);
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans,dp[i][j]);
        }
    }
    ll finalans = floor(ans*ans);
    pf("%lld",finalans);
    return 0;
}
