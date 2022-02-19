#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=17;
int f[50000],n,k;
int a[MAXN],ans[MAXN],amx;
int mx;
int dp(int t){
//	cout<<__func__<<endl;
	memset(f,63,sizeof(f));
//	cout<<"fuck"<<endl;
	f[0]=0;
	for (int i=1;i<=t;i++){
		for (int j=a[i];j<=a[t]*n;j++){
			f[j]=min(f[j],f[j-a[i]]+1);
		}
	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=a[t]*n;i++){
		if (f[i]>n) return i-1;
	}
	return a[t]*n;
}
void dfs(int d,int mx){
//	cout<<d<<" "<<k<<endl;
	if (d==k+1){
		if (mx>amx){
			amx=mx;
			for (int i=1;i<d;i++) ans[i]=a[i];
		}
		return;
	}
	for (int i=a[d-1]+1;i<=mx+1;i++){
		a[d]=i;
//		cout<<i<<endl;
		int x=dp(d);
//		cout<<x<<endl;
		dfs(d+1,x);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	dfs(1,0);
	for (int i=1;i<=k;i++) printf("%d ",ans[i]);
	cout<<endl;
	printf("MAX=%d\n",amx);
	return 0;
}
