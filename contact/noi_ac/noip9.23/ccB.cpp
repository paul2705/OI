#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e3+5;
const int mod=1e9+9;
int g[31][31][31][2];
vector<int> v[MAXN*20];
int n,h,tot,f[MAXN][MAXN*20];
void pre(){
	tot=0;
	for (int i=h;~i;i--){
		for (int j=i;~j;j--){
			for (int k=j;~k;k--){
				for (int l=1;~l;l--) g[i][j][k][l]=tot++;
			}
		}
	}
	for (int i=h;~i;i--){
		for (int j=i;~j;j--){
			for (int k=j;~k;k--){
				for (int l=1;~l;l--){
					int t=g[i][j][k][l];
					v[t].push_back(g[min(i+1,h)][min(j+1,h)][min(k+1,h)][l]);
					if (l){
						v[t].push_back(g[h][min(j+1,h)][min(k+1,h)][i==h]);
						v[t].push_back(g[h][min(i+1,h)][min(k+1,h)][j==h]);
						v[t].push_back(g[h][min(i+1,h)][min(j+1,h)][k==h]);
						}
					else {
						v[t].push_back(g[min(j+1,h)][min(k+1,h)][1][i==h]);
						v[t].push_back(g[min(i+1,h)][min(k+1,h)][1][j==h]);
						v[t].push_back(g[min(i+1,h)][min(j+1,h)][1][k==h]);
						}
				}
			}
		}
	}
}
void solve(){
	int ans=0;
	f[0][g[0][0][0][0]]=1;
	for (int i=0;i<n;i++){
		for (int j=1;j<tot;j++){
			if (f[i][j]){
				for (int k=0;k<v[j].size();k++){
					f[i+1][v[j][k]]=(f[i+1][v[j][k]]+f[i][j])%mod;
				}
			}
		}
	}
	for (int j=1;j<tot;j++) ans=(ans+f[n][j])%mod;
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&h);
	pre(); solve();
	return 0;
}
