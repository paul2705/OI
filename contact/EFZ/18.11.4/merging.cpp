#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<bitset>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=20;
const int MAXS=(1<<9);
int g[MAXN][MAXS],f[MAXN][MAXS];
int n,m,ans;
bitset<10> st;
int a[MAXN][MAXM],stat[MAXN];
int use[MAXN][MAXS];
bool ok(int s){
	bool f=1;
	int l=0,r=m-1;
	for (int j=0;j<m;j++,l++){
		if (s&(1<<j)) break;
	}
	for (int j=m-1;j>=0;j--,r--){
		if (s&(1<<j)) break;
	}
	for (int j=l;j<=r;j++){
		if (!(s&(1<<j))) f=0;
	}
	if (l>r) return 0;
	return f;
}
int main(){
	freopen("merging.in","r",stdin);
//	freopen("merging.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			stat[i]=stat[i]*2+a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int s=stat[i];s;s=(s-1)&stat[i]){
			if (!ok(s)) continue;
			g[i][s]=g[i-1][s]^1;
			f[i][s]=1e9;
		}
		f[i][0]=0;
		for (int s=1;s<=stat[i];s++){
			bool fl=1;
			for (int j=0;j<=m;j++){
				if (s&(1<<j)&&!(stat[i]&(1<<j))) fl=0;
			}
			if (!fl) continue;
			st=s; cout<<" : "<<st<<endl;
			if (ok(s)) f[i][s]=f[i-1][s]+g[i][s],g[i][s]=1;
			else f[i][s]=1e9;
//			cout<<f[i][s]<<endl;
			for (int s1=s;s1;s1=(s1-1)&s){
				int s2=s^s1;
				if (!ok(s2)) continue;
				if (f[i][s]>f[i][s1]+f[i-1][s2]+g[i][s2]){
					f[i][s]=f[i][s1]+f[i-1][s2]+g[i][s2];
					g[i][s2]=1;
//					st=s; cout<<st<<" ";
//					st=s1; cout<<st<<" ";
//					st=s2; cout<<st<<" ";
//					cout<<g[i][s2]<<" "<<f[i][s]<<endl;
					use[i][s]=s1;
				}
			}
			int s2=stat[i-1];
			for (int j=0;j<m;j++){
				if ((stat[i-1]&(1<<j))&&(s&(1<<j))) s2-=(1<<j);
			}
			f[i][s]+=f[i-1][s2];
			cout<<" , "<<f[i][s]<<" "<<f[i-1][s2]<<endl;
		}
//		for (int s=0;s<=stat[i];s++) g[i][s]=0;
//		for (int s=stat[i];s;s=use[i][s]){
//			int s1=use[i][s];
//			int s2=s^s1;
//			g[i][s2]=1;
//		}
		for (int s=0;s<=stat[i];s++){
			if (g[i][s]==0) continue;
			st=s;
//			cout<<st<<" "<<f[i][s]<<endl;
		}
//		cout<<i<<" "<<f[i][stat[i]]<<endl;
		bool fl=0;
//		for (int j=0;j<m;j++){
//			if (stat[i]&(1<<j)) fl=1;
//		}
//		if (fl) ans+=f[i][stat[i]];
//		ans+=f[i][stat[i]];
//		cout<<"ans: "<<ans<<endl;
		cout<<f[i][stat[i]]<<endl;
	}
//	cout<<f[1][10]<<endl;
	printf("%d\n",f[n][stat[n]]);
	fclose(stdin); fclose(stdout);
	return 0;
}
