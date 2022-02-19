#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
ll T;
bool a[MAXN],b[MAXN];
int main(){
	scanf("%lld%d",&T,&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		a[i]=a[2*n+2-i]=c-'0';
	}
	n=2*n+2;
	int d=0;
	while (T){
		if (T&1){
			ll D=1ll<<d; D%=n;
			for (int i=1;i<=n;i++) b[i]=a[i];
			int p1=((0-D)%n+n)%n,p2=D%n;
			for (int i=0;i<n;i++){
				a[i]=b[p1]^b[p2];
				p1++; p1%=n;
				p2++; p2%=n;
			}
		}
		d++; T>>=1;
	}
	for (int i=1;i<=(n-2)/2;i++) printf("%d",a[i]);
	cout<<endl;
	return 0;
}
