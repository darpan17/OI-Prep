/**
For all shoes, greedily find the other closest pair near it.
The number of swaps required for that move is the index of the closest pair - current index - number of used shoes in between
The number of used shoes in between can be found using a segtree
*/

#include <bits/stdc++.h>
#include "shoes.h"

#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define ll long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>

using namespace std;

const int MAXN = 2e5+5;
int seg[4*MAXN];
bool used[MAXN];
queue<int> leftShoes[MAXN],rightShoes[MAXN];

void update(int node,int ss,int se,int idx) {
	if(ss > se || idx > se || idx < ss)return;
	if(ss == se) {
		++seg[node];
		return;
	}
	int mid = ss+se >> 1;
	update(node*2+1,ss,mid,idx);
	update(node*2+2,mid+1,se,idx);
	seg[node] = seg[2*node+1]+seg[2*node+2];
}

int query(int node,int ss,int se,int qs,int qe) {
	if(ss > se || qs > se || qe < ss) return 0;
	if(ss >= qs && se <= qe) return seg[node];
	int mid = ss+se >> 1;
	int q1 = query(node*2+1,ss,mid,qs,qe);
	int q2 = query(node*2+2,mid+1,se,qs,qe);
	return q1+q2;
}

ll count_swaps(vi a) {
	int n = a.size();
	F0R(i,n) {
		if(a[i] < 0) leftShoes[abs(a[i])].push(i); 
		else rightShoes[a[i]].push(i);
	}
	ll ans = 0;
	F0R(i,n) {
		if(used[i]) continue;
		int ni = -1;
		if(a[i] < 0) {
			ni = rightShoes[abs(a[i])].front();
		} else {
			ni = leftShoes[abs(a[i])].front();
		}
		rightShoes[abs(a[i])].pop();
		leftShoes[abs(a[i])].pop();
		int swapss = ni-i;
		swapss -= query(0,0,n-1,i+1,ni-1);
		
		update(0,0,n-1,i);
		update(0,0,n-1,ni);
		if(a[i] < 0)--swapss;
		used[i] = true;
		used[ni] = true;
		ans += swapss; 
	}
	return ans;
}
