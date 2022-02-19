#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9;
const int MAXN=1e7+7;
int a[MAXN],n,m;
int f[3][4*MAXN];
char s[MAXN];
void solve1(){
	int ans=0;
	for (int l=1,r=1;l<=n;l=r+1,r++){
		while (s[l]==s[r+1]) r++;
		if (s[l]=='1') ans++;
	}
	printf("%d\n",ans);
}
void solve2(){
	for (int i=0;i<=1;i++){
		for (int j=0;j<=(m-1)*n;j++) f[i][j]=inf;
	}
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		int c=i&1; int o=c^1;
		for (int j=0;j<=(m-1)*n;j++) f[c][j]=inf;
		for (int j=0;j<=(m-1)*n;j++){
			if (f[o][j]==inf) continue;
			int tmp=f[o][j];
			f[c][j+(m-a[i])]=min(f[c][j+(m-a[i])],tmp+m-a[i]);
			if (j>=a[i]) f[c][j-a[i]]=min(f[c][j-a[i]],tmp);
		}
/*		for (int j=0;j<=(m-1)*n;j++){
			printf("%d ",f[c][j]);
		}
		cout<<endl;
*/	}
	printf("%d\n",f[n&1][0]);
}
int cnt[5]={0,0,0,0,0};
void solve3(){
	int sum=0,ans=0;
	for (int i=1;i<=n;i++){
		cnt[a[i]]++;
		sum-=a[i];
		if (sum<0){
			for (int j=m-1;sum<0;j--){
				if (cnt[j]) cnt[j]--,sum+=m,ans+=m-j;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&m);
	scanf("%s",s+1); n=strlen(s+1);
	n++;
	s[0]=s[n]='0';
	for (int i=1;i<=n;i++) a[i]=(s[i]-s[i-1]+m)%m;
//	solve1(); solve2(); solve3();
	if (m==2) solve1();
	else if (n<=1e3) solve2();
	else solve3();
}
