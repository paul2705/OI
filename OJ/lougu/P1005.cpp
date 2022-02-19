#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=85;
const ull A=1e15;
struct bint{
	ll s[10];
	bint(){ *this=0ll; }
	void clear(){ memset(s,0,sizeof(s)); }
	bint operator = (ll num){
		memset(s,0,sizeof(s)); s[0]=num;
		return *this;
	}
	bint operator + (const bint& b) const{
		bint c; ull g=0;
		for (int i=0;i<9;i++){
			ull x=g;
			x+=(ull)s[i]+b.s[i]; c.s[i]=x%A;
			g=x/A;
		}
		return c;
	}
	bint operator* (const bint& b) const{
		bint c; ull g=0;
		for (int i=0;i<9;i++){
			ull x=g;
			for (int j=0;j<=i;j++){
				int k=i-j;
				x+=(ull)s[k]*b.s[j];
			}
			c.s[i]=x%A; g=x/A;
		}
		return c;
	}
	bool operator < (const bint& b) const{
		for (int i=9;i>=0;i--){
			if (s[i]<b.s[i]) return 1;
			if (s[i]>b.s[i]) return 0;
		}
		return 0;
	}
	bool operator > (const bint& b) const{
		for (int i=9;i>=0;i--){
			if (s[i]>b.s[i]) return 1;
			if (s[i]<b.s[i]) return 0;
		}
		return 0;
	}
	void print(){
		char buf[200];
		for (int i=9;i>=0;i--){
			sprintf(buf+(9-i)*15,"%015lld",s[i]);
		}
		bool flag=0;
		for (int i=0;i<150;i++){
			if (buf[i]>'0'&&buf[i]<='9') flag=1;
			if (flag) printf("%c",buf[i]);
		}
		if (!flag) printf("0");
		cout<<endl;
	}
};
bint a[100],f[100][100];
bint ans,two[90],zero;
int n,m;
void ini(){
	two[0]=1; two[1]=2;
	for (int i=2;i<90;i++) two[i]=two[i-1]*two[1];
}
bint Max(bint a,bint b){ return a<b?b:a; }
bint dp(int l,int r){
	if (f[l][r]>zero) return f[l][r]; 
	int k=l+m-r;
	if (r-l>=1) f[l][r]=Max(dp(l+1,r)+two[k]*a[l],dp(l,r-1)+two[k]*a[r]);
	else f[l][r]=a[l]*two[k];
	return f[l][r];
}
int main(){
	ini();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1,x;j<=m;j++){
			scanf("%d",&x); a[j]=x;
		}
		for (int l=1;l<=m;l++){
			for (int r=l;r<=m;r++) f[l][r].clear();
		}
		dp(1,m);
		ans=ans+f[1][m];
	}
	ans.print();
	return 0;
} 
