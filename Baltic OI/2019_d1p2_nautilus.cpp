#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int MAXN=505;
bool dp[MAXN][MAXN][MAXN];
int n,m,k;
char str[5005];
char grid[MAXN][MAXN];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%s",grid[i]);
	scanf("%s",str+1);

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			dp[0][i][j]=grid[i][j]=='.';
		}
	}

	for(int c=1;c<=k;c++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(grid[i][j]=='#') continue;

				if(str[c]=='N') {
					if(dp[c-1][i][j]&&i-1>=0&&grid[i-1][j]=='.') {
						dp[c][i-1][j]=true;
					}
				} else if(str[c]=='S') {
					if(dp[c-1][i][j]&&i+1<n&&grid[i+1][j]=='.') {
						dp[c][i+1][j]=true;
					}
				} else if(str[c]=='E') {
					if(dp[c-1][i][j]&&j+1<m&&grid[i][j+1]=='.') {
						dp[c][i][j+1]=true;
					}
				} else if(str[c]=='W') {
					if(dp[c-1][i][j]&&j-1>=0&&grid[i][j-1]=='.') {
						dp[c][i][j-1]=true;
					}
				} else {
					if(dp[c-1][i][j]&&i-1>=0&&grid[i-1][j]=='.') {
						dp[c][i-1][j]=true;
					}
					if(dp[c-1][i][j]&&i+1<n&&grid[i+1][j]=='.') {
						dp[c][i+1][j]=true;
					}
					if(dp[c-1][i][j]&&j+1<m&&grid[i][j+1]=='.') {
						dp[c][i][j+1]=true;
					}
					if(dp[c-1][i][j]&&j-1>=0&&grid[i][j-1]=='.') {
						dp[c][i][j-1]=true;
					}

				}


			}
		}
	}

	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			ans+=dp[k][i][j];
		}
	}

	printf("%d",ans);
}
