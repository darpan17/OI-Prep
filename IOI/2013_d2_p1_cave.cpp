/*
SOLUTION: (help taken) kill each door one by one
binsrch for some state and then see for the current switch 
switch states except for those that are fixed
do this until you reach the final switch for each door
*/
 
#include <bits/stdc++.h>
#include "cave.h"
 
#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define pb push_back
#define mp make_pair
 
using namespace std;
 
const int MAXN = 5001;
int n;
int querySwitch[MAXN],answerSwitch[MAXN],door[MAXN];
bool fixedSwitch[MAXN];
 
int findState(int k) {
	F0R(i,n) {
		if(fixedSwitch[i]) continue;
		querySwitch[i] = 1;
	}
	int x = tryCombination(querySwitch);
	if(x == -1 || x > k) return 1;
	else return 0;
}
 
void findSwitch(int k,int lo,int hi,int switchState) {
	if(lo == hi) {
		fixedSwitch[lo] = true;
		querySwitch[lo] = answerSwitch[lo] = switchState;
		door[lo] = k;
		return;
	}
	int mid = lo+hi>>1;
	F0R(i,n) {
		if(fixedSwitch[i]) querySwitch[i] = answerSwitch[i];
		else if(i >= lo and i <= mid) querySwitch[i] = switchState;
		else querySwitch[i] = switchState^1;
	}
	int x = tryCombination(querySwitch);
	if(x == -1 || x > k) {
		// opens door k
		findSwitch(k,lo,mid,switchState);
	} else {
		findSwitch(k,mid+1,hi,switchState);
	}
}
 
void exploreCave(int nn) {
	n = nn;
	F0R(i,n) {
		int switchState = findState(i);
		findSwitch(i,0,n-1,switchState);
	}
	answer(answerSwitch,door);
}
