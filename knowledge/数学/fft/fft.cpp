#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<complex>
using namespace std;
const int MAXN=4194304;
typedef double db;
typedef complex<db> cd;
const db pi=acos(-1);
int n,m,bit,s,rev[MAXN];
cd a[MAXN],b[MAXN];
void fft(cd* a,int n,int dft){
	for (int i=0;i<n;i++){
		if (i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for (int stp=1;stp<n;stp<<=1){
		cd wn=exp(cd(0,dft*pi/stp));
		for (int j=0;j<n;j+=stp<<1){
			cd wnk(1,0);
			for (int k=j;k<j+stp;k++){
				cd x=a[k],y=wnk*a[k+stp];
				a[k]=x+y; a[k+stp]=x-y;
				wnk*=wn;
			}
		}
	}
	if (dft==-1){
		for (int i=0;i<n;i++) a[i]/=n;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,x;i<=n;i++){
		scanf("%d",&x);
		a[i]=x;
	}
	for (int i=0,x;i<=m;i++){
		scanf("%d",&x);
		b[i]=x;
	}
	s=2,bit=1;
	for (bit=1;(1<<bit)<=n+m+1;bit++) s<<=1;
	bit++; s<<=1;
	for (int i=0;i<(1<<bit);i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
	fft(a,s,1); fft(b,s,1);
	for (int i=0;i<s;i++) a[i]*=b[i];
	fft(a,s,-1);
	for (int i=0;i<n+m+1;i++){
		long long x=round(a[i].real());
		printf("%lld ",x);
	}
	cout<<endl;
	return 0;
}
