#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN];
int n,m,x,ans=1e9;
class qx{
	private:
		int b[MAXN],q[MAXN],l,r;
	public:
		void ini(){l=1,r=0;}
		void pushin(int j,int x){ 
			while (l<=r&&b[q[r]]<=x) r--; 
			q[++r]=j; b[r]=x;
		}
		void pushout(int lim){ while (l<=r&&q[r]<lim) l++; }
		int get(){ return b[l]; }
} qx[MAXN];
class qn{
	private:
		int b[MAXN],q[MAXN],l,r;
	public:
		void ini(){l=1,r=0;}
		void pushin(int j,int x){
			while (l<=r&&b[q[r]]>=x) r--;
			q[++r]=j; b[r]=x;
		}
		void pushout(int lim){ while (l<=r&&q[r]<lim) l++; }
		int get(){ return b[l]; }
} qn[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&x); int lin=x;
	for (int i=1;i<=n;i++){
		qx[i].ini(); qn[i].ini();
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if (i<=x){
				qx[i].pushin(j,a[i][j]);
				qn[i].pushin(j,a[i][j]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			qx[n+1].pushin(j,qx[j].get());
			qn[n+1].pushin(j,qn[j].get());
			cout<<"|: "<<qx[j].get()<<" "<<qn[j].get()<<endl;
			if (j>=x){
				qx[n+1].pushout(j-x); qn[n+1].pushout(j-x);
				cout<<qx[n+1].get()<<" "<<qn[n+1].get()<<endl;
				ans=min(ans,qx[n+1].get()-qn[n+1].get());
			}
		}
		lin++; if (lin>n) break;
		for (int j=1;j<=n;j++){
			qx[j].pushin(j,a[lin][j]);
			qn[j].pushin(j,-a[lin][j]);
			qx[j].pushout(j-x); qn[j].pushout(j-x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
