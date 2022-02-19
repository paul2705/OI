#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3e5+5;
int n,m,q,mxi,mxv;
int f[MAXN],len[MAXN],sz[MAXN];
bool use[MAXN];
vector<int> g[MAXN];
void dfs(int val,int d,int pos){
	if (d>mxi) mxi=d,mxv=val;
	for (int i=0;i<g[val].size();i++){
		if (g[val][i]!=pos) dfs(g[val][i],d+1,val);
	}
}
int calc(int val){
	mxi=-1;
	dfs(val,0,-1);
	mxi=-1;
	dfs(mxv,0,-1);
	return mxi;
}
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(sz[x]>sz[y])swap(x,y);
	sz[y]+=sz[x];
	f[x]=y;
}
int radius(int x){ return (len[x]+1)/2; }
void merge2(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	sz[y]+=sz[x];
	f[x]=y;
	len[y]=max(max(radius(x)+radius(y)+1,len[x]),len[y]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		f[i]=i;
		sz[i]=i;
		len[i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		merge(x,y);
	}
	for(int i=1;i<=n;i++){
		int p=find(i);
		if(!use[p]){
			use[p]=1;
			len[p]=calc(i);
		}
	}
    	while(q--){
        	int t,x,y;
        	scanf("%d",&t);
       		if(t==1){
            		scanf("%d",&x);
            		printf("%d\n",len[find(x)]);
        	}else{
            		scanf("%d%d",&x,&y);
            		merge2(x,y);
        	}
    	}
    	return 0;
}
