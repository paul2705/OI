#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m,a[MAXN],b[MAXN],t[MAXN];
int ans,res[MAXN],cnt;
bool use[MAXN];
int f[MAXN];
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
int oper(){
	for (int i=1;i<=n;i++) t[i]=0;
	int ret=0;
	for (int i=n;i>=1;i--){
		f[i]=sum(a[i]-1);
//		cout<<a[i]-1<<" "<<sum(a[i]-1)<<" ";
		add(a[i],1);
	}
	for (int i=1;i<=n;i++) ret+=f[i];
//	cout<<endl;
	return ret;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
//	cout<<nn<<endl;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	int ans=oper();
	for (int i=1,pos;i<=m;i++){
		scanf("%d",&pos);
		memset(use,0,sizeof(use));
		int x=a[pos]; cnt=0;
		if (f[pos]==0){
			printf("%d\n",ans);
			continue;
		}
		for (int j=pos;j<=n;j++){
			if (a[j]<=x) res[cnt++]=a[j],use[j]=1;
		}
		sort(res,res+cnt); cnt=0;
		for (int j=pos;j<=n;j++){
			if (use[j]) a[j]=res[cnt++];
		}
//		for (int j=1;j<=n;j++) cout<<a[j]<<" "; cout<<endl;
		ans=oper();
		printf("%d\n",ans);
	}
	fclose(stdout);
	return 0;
}
