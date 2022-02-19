#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1e3+5;
int n,m,a[MAXN][MAXN],b[MAXN][MAXN];
int ro[MAXN],li[MAXN];
int roi[MAXN],lii[MAXN];
int f[1<<16];
//bitset<10> t1,t2;
void solve2(){
	for (int i=1;i<=max(n,m);i++) ro[i]=li[i]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]!=a[i][j]) ro[i]=0;
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){ 
			if (b[j][i]!=a[j][i]) li[i]=0;
		}
	}
	bool flag=1;
	for (int i=1;i<=n;i++){
		int ret=m;
		for (int j=1;j<=m;j++) ret-=b[i][j];
		if (ret==1){
			int pos=0;
			for (int j=1;j<=m;j++){
				if (b[i][j]==0){
					pos=j;
					break;
				}
			}
			int cnt=n;
			for (int j=1;j<=n;j++) cnt-=b[j][pos];
//			cout<<pos<<" "<<cnt<<endl;
			if (cnt==1) lii[pos]=roi[i]=1;
			else if (!ro[i]) flag=0;
		}
//		cout<<i<<" "<<flag<<endl;
	}
//	cout<<flag<<endl;
	for (int i=1;i<=m;i++){
		int ret=n;
		for (int j=1;j<=n;j++) ret-=b[j][i];
		if (ret==1){
			int pos=0;
			for (int j=1;j<=n;j++){
				if (b[j][i]==0){
					pos=j;
					break;
				}
			}
			int cnt=m;
			for (int j=1;j<=m;j++) cnt-=b[pos][j];
//			cout<<pos<<endl;
			if (cnt==1) lii[i]=roi[pos]=1;
			else if (!li[i]&&!ro[pos]) flag=0;
		}
	}
//	cout<<flag<<endl;
	for (int i=1;i<=n;i++){
		if (roi[i]) continue;
		for (int j=1;j<=m;j++){
			if (lii[j]) continue;
			if (a[i][j]!=b[i][j]) flag=0;
		}
	}
//	cout<<flag<<endl;
	for (int i=1;i<=m;i++){
		if (lii[i]) continue;
		for (int j=1;j<=n;j++){
			if (roi[j]) continue;
			if (a[j][i]!=b[j][i]) flag=0;
		}
	}
//	cout<<flag<<endl;
	if (flag) printf("1\n");
	else printf("0\n");
}
int T=0;
int Get(int x,int y){ return x*m+y; }
int dfs(int s){
	if (f[s]>-1&&f[s]<=10) return f[s];
	if (f[s]>10) return 0;
	f[s]=11;
//	cout<<s<<endl;
	int now=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
//			cout<<i<<" "<<j<<endl;
			int pos=Get(i,j);
			int st=s; 
			if (st&(1<<pos)) st^=(1<<pos);
			else continue;
			int stp=pos-m;
			while (stp>=0){
				st|=(1<<stp);
				stp-=m;
			}
			stp=pos+m;
			while (stp<n*m){
				st|=(1<<stp);
				stp+=m;
			}
			stp=pos-1;
			while (pos%m!=0&&stp%m!=0){
				st|=(1<<stp);
				stp--;
			}
			if (pos%m!=0) st|=(1<<stp);
			stp=pos+1;
			while (stp%m!=0){
				st|=(1<<stp);
				stp++;
			}
//			t1=s; t2=st;
//			cout<<t1<<endl<<t2<<endl<<endl;
			if (s!=st) now|=dfs(st);
		}
	}
	return f[s]=now;
}
void solve1(){
	int res=0;
	for (int s=0;s<(1<<(n*m));s++) f[s]=-1;
	for (int i=n;i>=1;i--){
		for (int j=m;j>=1;j--){
			res=res*2+a[i][j];
		}
	}
	T=0;
	for (int i=n;i>=1;i--){
		for (int j=m;j>=1;j--) T=T*2+b[i][j];
	}
	f[T]=1;
	dfs(res);
//	t1=res; t2=T; 
//	cout<<t1<<endl<<t2<<endl<<endl;
//	for (int s=0;s<(1<<(n*m));s++){
//		t1=s; cout<<t1<<" "<<f[s]<<endl;
//	}
	printf("%d\n",f[res]);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='O'&&c!='X') c=getchar();
			a[i][j]=(c=='O');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='O'&&c!='X') c=getchar();
			b[i][j]=(c=='O');
		}
	}
//	if (max(n,m)<=4) solve1();
//	else solve2();
	solve2();
	fclose(stdin); fclose(stdout);
	return 0;
}
