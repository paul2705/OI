#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=25;
int a[MAXN],b[MAXN];
int lcp=1000,rcp=1000;
map<int,int> mp;
int ans;
void dfs(int d){
	if (d==2){
		if (mp[lcp]>0) return;
		mp[lcp]++; ans++; 
//		cout<<lcp<<endl;
		return;
	}
	for (int i=1;i<=10;i++){
		for (int j=1;j<=10;j++){
			int x=a[i],y=b[j];
			lcp+=y-x; rcp+=x-y;
			swap(a[i],b[j]);
			dfs(d+1);
			swap(a[i],b[j]);
			lcp-=y-x; rcp-=x-y;
		}
	}
}
int main(){
	freopen("backforth.in","r",stdin);
	freopen("backforth.out","w",stdout);
	for (int i=1;i<=10;i++) scanf("%d",&a[i]);
	for (int i=1;i<=10;i++) scanf("%d",&b[i]);
	dfs(0);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
