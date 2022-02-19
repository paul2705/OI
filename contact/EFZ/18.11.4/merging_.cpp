#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=10;
const int MAXS=(1<<9);
int f[MAXN][MAXS];
int n,m,a[MAXN][MAXM];
int ans=1e9;
int use[MAXN][MAXM],res[MAXM],ct=0;
int sum[MAXM];
bitset<10> st;
bool ok(int id,int s){
	bool afl=1;
	ct=0; res[ct++]=-1;
	for (int i=0;i<m-1;i++){
		if (s&(1<<i)) res[ct++]=i;
	}
	res[ct++]=m-1;
	sum[0]=0;
	for (int i=1;i<=m;i++) sum[i]=sum[i-1]+a[id][i];
	for (int i=0;i<ct-1;i++){
		int l=res[i]+2,r=res[i+1]+1;
//		cout<<l<<" "<<r<<endl;
		int x=sum[r]-sum[l-1];
		if (x>0&&x<r-l+1) afl=0;
	}
	st=s;
//	cout<<"bd: "<<id<<" "<<st<<" "<<afl<<endl;
	return afl;
}
bool ful(int id,int l,int r){
	l++;
	bool fl=1;
	for (int i=l;i<=r;i++){
		if (a[id][i]==0) fl=0;
	}
	return fl;
}
int main(){
	freopen("merging.in","r",stdin);
	freopen("merging.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	if (n==1&&m==1){
		printf("%d\n",a[1][1]);
		fclose(stdin); fclose(stdout);
		return 0;
	}
	int all=(1<<(m-1));
	memset(f,63,sizeof(f));
	for (int s=0;s<all;s++) f[0][s]=0;
//	cout<<f[1][5]<<" "<<f[2][4]<<endl;
	for (int i=1;i<=n;i++){
		for (int s=0;s<all;s++){
			if (!ok(i,s)) continue;
//			cout<<f[i][s]<<endl;
			for (int s1=0;s1<all;s1++){
				if (!ok(i-1,s1)) continue;
				int cnt=0,cnt1=0;
				memset(use,0,sizeof(use));
				use[1][0]=use[2][0]=++cnt;
				cnt1++;
				use[1][m]=use[2][m]=++cnt;
				cnt1++;
				for (int j=0;j<m-1;j++){
					if (s&(1<<j)) use[1][j+1]=++cnt;
					if (s1&(1<<j)) use[2][j+1]=++cnt1;
				}
				int las=0; cnt--;
				for (int j=1;j<=m;j++){
					if (use[1][j]){
						if (!ful(i,las,j)) cnt--;
						las=j;
					}
				}
//				cout<<cnt<<endl;
				for (int j=0;j<=m;j++){
					if (use[1][j]&&use[2][j]){
						int l=j,r1=j+1,r2=j+1;
						while (r1<m&&!use[1][r1]) r1++;
						while (r2<m&&!use[2][r2]) r2++;
//						cout<<l<<" "<<r1<<" "<<r2<<endl;
						if (r1==r2){
							j=r1-1;
							if (ful(i,l,r1)&&ful(i-1,l,r2)) cnt--;
						}
					}
				}
//				st=s1; cout<<st<<" ";
//				st=s; cout<<st<<" ";
//				cout<<cnt<<" "<<f[i][s]<<" "<<f[i-1][s1]+cnt<<endl;
				f[i][s]=min(f[i][s],f[i-1][s1]+cnt);
			}
			if (i==n) ans=min(ans,f[i][s]);
		}
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
