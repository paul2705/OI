#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<complex>
#include<cmath>
using namespace std;
typedef long long ll;
typedef complex<double> cp;
const int MAXN=1<<23;
const double pi=3.14159265358579;
int n,m,l;
cp a[MAXN],b[MAXN];
int c[MAXN];
void fft(cp *a,int n,int inv){
	if (n==1) return;
	cp b[n]; int mid=n>>1,cnt=0;
	for (int i=0;i<n;i+=2) b[cnt++]=a[i];
	for (int i=1;i<n;i+=2) b[cnt++]=a[i];
	fft(b,mid,inv); fft(b+mid,mid,inv);
	for (int i=0;i<n;i++){
		if (i<mid){
			cp x(cos(2*pi*i/n),inv*sin(2*pi*i/n));
			a[i]=b[i]+x*b[i+mid];
		}
		else{
			cp x(cos(2*pi*(i-mid)/n),inv*sin(2*pi*(i-mid)/n));
			a[i]=b[i-mid]-x*b[i];
		}
		cout<<a[i].real()<<" ";
	}
	cout<<endl;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++){
		ll x; scanf("%lld",&x);
		a[i]=x;
	}
	for (int i=0;i<=m;i++){
		ll x; scanf("%lld",&x);
		b[i]=x;
	}
	l=1; while (l<=n+m) l*=2;
	fft(a,l,1); fft(b,l,1);
	for (int i=0;i<=l;i++) a[i]*=b[i];
	fft(a,l,-1);
	for (int i=0;i<=l;i++) c[i]=a[i].real()/l+0.5;
	for (int i=0;i<=n+m;i++) printf("%d ",c[i]);
	return 0;
}
