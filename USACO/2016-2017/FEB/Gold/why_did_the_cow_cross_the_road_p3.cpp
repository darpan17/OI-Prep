#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SZ(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define F0R(i,n) FOR(i,0,(n)-1)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

const ll MOD = 1e9+7;
const int MAXN = 5e4+5;
const int INF = 1e9+21;
const ll LINF = 1e18+5;
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
void IO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int n,ans;
ll seg[8*MAXN];
int a[2*MAXN], fidx[MAXN];

void update(int node, int ss, int se, int idx, int v) {
	if(ss > se || idx < ss || idx > se) return;
	if(ss == se && se == idx) {
		seg[node] += v; return;
	}
	int mid = ss+se >> 1;
	update(2*node+1,ss,mid,idx,v);
	update(2*node+2,mid+1,se,idx,v);
	seg[node] = seg[2*node+1]+seg[2*node+2];
}

int query(int node, int ss, int se, int qs, int qe) {
	if(ss > se || qs > se || qe < ss || qs > qe) return 0;
	if(ss >= qs && se <= qe) return seg[node];
	int mid = ss+se >> 1;
	int q1 = query(2*node+1,ss,mid,qs,qe);
	int q2 = query(2*node+2,mid+1,se,qs,qe);
	return q1+q2;
}

int main() {
	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
	scanf("%d",&n);
	F0R(i,2*n) scanf("%d",&a[i]);
	set<int> pres;
	F0R(i,2*n) {
		int num = a[i];
		if(pres.find(num) == pres.end()) {
			fidx[num] = i;
			pres.insert(num); 
			update(0,0,2*n-1,i,1);
			continue;
		}
		pres.erase(num);
		ans += SZ(pres);
		ans -= query(0,0,2*n-1,0,fidx[num]-1);
		update(0,0,2*n-1,fidx[num],-1);
	}
	printf("%d\n",ans);
}
