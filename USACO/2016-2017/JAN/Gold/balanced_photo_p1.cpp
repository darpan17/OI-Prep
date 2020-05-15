/*
SOLUTION: sort the cows based on their heights.
for a given index, say i, find out how many indices in the range [i+1,n) are greater than idx
from there you can find how many are indices in the range [0,i-1] are greater than idx
if min of them is less than half of max, it is good idx
*/
#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset((x),(a),sizeof(x)) 
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int MX = 1e5+5;
int n;
pll a[MX]; // idx, cow
int seg[MX];
bool good[MX];

void build(int node,int ss,int se) {
	if(ss > se)return;
	if(ss == se) { seg[node] = a[ss].F; return; }
	int mid = ss+se >> 1;
	build(node*2+1,ss,mid);
	build(node*2+2,mid+1,se);
	seg[node] = min(seg[2*node+1],seg[2*node+2]);
}

int query(int node,int ss,int se,int qs,int qe,int idx) {
	if(ss > se || qs > se || qe < ss)return 0;
	if(ss >= qs && se <= qe) {
		if(seg[node] > idx) return se-ss+1;
		if(ss == se) return 0;
	}
	int mid = ss+se >> 1;
	int q1 = query(node*2+1,ss,mid,qs,qe,idx);
	int q2 = query(node*2+2,mid+1,se,qs,qe,idx);
	return (q1+q2);
}

bool gg(int ind,int idx) {
	int rit = query(0,0,n-1,ind+1,n-1,idx);
	int lft = ((n-1)-(ind+1)+1) - rit;
	if(lft > rit) swap(lft,rit);
	return (rit > 2*lft);
}

bool cmp(const pll& a,const pll& b) {
	return (a.S < b.S);
}

int main() {
	ifstream fin("bphoto.in");
	ofstream fout("bphoto.out");
	#define cin fin
	#define cout fout
	cin >> n;
	F0R(i,n)cin >> a[i].S;
	F0R(i,n)a[i].F = i;
	sort(a,a+n,cmp);
	build(0,0,n-1);
	int ans = 0;
	F0R(i,n) ans += gg(i,a[i].F);
	cout << ans;
}	
