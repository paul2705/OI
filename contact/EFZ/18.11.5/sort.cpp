#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5;
int n,m,a[MAXN],b[MAXN],f[MAXN],t[MAXN];
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
//		cout<<a[i]<<" ";
	}
	for (int i=n;i>=1;i--){
		f[i]=sum(a[i]-1);
		add(a[i],1);
	}
	for (int i=1,pos;i<=m;i++){
		scanf("%d",&pos);
		int x=a[pos];
		for (int j=pos;j<=n;j++){
			if (a[j]<=x) f[j]=0;
		}
		int ans=0;
//		for (int j=n;j>=1;j--) cout<<f[j]<<" "; cout<<endl;
		for (int j=1;j<=n;j++) ans+=f[j];
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
