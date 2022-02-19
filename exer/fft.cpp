#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<complex>
using namespace std;
const int MAXN=1<<23;
typedef long long ll;
typedef complex<double> cp;
const double pi=3.14159265358979;
int n,m,l;
cp a[MAXN],b[MAXN],tmp[MAXN];
int c[MAXN],pos[MAXN];
void fft(cp *a,int n,int inv){
	for (int i=0;i<n;i++) tmp[i]=a[pos[i]];
	for (int i=0;i<n;i++) a[i]=tmp[i];
	for (int l=2;l<=n;l*=2){
//		cout<<l<<endl;
		for (int i=0;i<n;i+=l){
			int mid=l>>1;
			for (int k=i;k<i+mid;k++){
				cp x(cos(2*pi*(k-i)/l),inv*sin(2*pi*(k-i)/l));
				cp t=a[k];
				a[k]=a[k]+x*a[k+mid]; a[k+mid]=t-x*a[k+mid];
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	int l=1; while (l<=n+m) l<<=1,cnt++;
	for (int i=0;i<=n;i++){
		ll x; scanf("%lld",&x);
		a[i]=x;
	}
	for (int i=0;i<=m;i++){
		ll x; scanf("%lld",&x);
		b[i]=x;
	}
	pos[0]=0; cnt--;
	for (int i=1;i<=l;i++) pos[i]=((i&1)<<cnt)|(pos[i>>1]>>1);
	fft(a,l,1); fft(b,l,1);
	for (int i=0;i<=l;i++) a[i]*=b[i];
	fft(a,l,-1);
	for (int i=0;i<=l;i++) c[i]=a[i].real()/l+0.5;
	for (int i=0;i<=n+m;i++) printf("%d ",c[i]);
	return 0;
}
