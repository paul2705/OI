#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e4*2+5;
int m,n,x,p,y,ans,T;
vector<int> v[305];
int lin[MAXN];
bool vis[MAXN];
bool find(int x){
	if (x==0) return true;
	for (int i=0;i<v[x].size();i++){
		if (!vis[v[x][i]]){
			vis[v[x][i]]=1;
			if (lin[v[x][i]]==0||find(lin[v[x][i]])){
				lin[v[x][i]]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while (T--){
		memset(lin,0,sizeof(lin));
		memset(v,0,sizeof(v));
		scanf("%d%d",&p,&n);
		for (int i=1;i<=p;i++){
			scanf("%d",&m);
			for (int j=1;j<=m;j++){
				scanf("%d",&y);
				v[i].push_back(y);
			}
		}
		if (p>n){ printf("NO\n"); continue; }
		ans=0;
		for (int i=1;i<=p;i++){
			memset(vis,0,sizeof(vis));
			if (find(i)) ans++;
		}
		if (ans==p) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
