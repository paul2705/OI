#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
int bin[75];
ll m;
int main(){
	scanf("%d%lld",&n,&m);
	bin[0]=1;
	for (int i=1;i<=70;i++) bin[i]=bin[i-1]*2%n;
	for (int i=0;i<n;i++) scanf("%d",&a[2*i]),a[2*i]--;
	int cnt=0;
	int tp=m&1; m>>=1;
	while (m){
		if (m&1){
			for (int i=0;i<n;i++) b[2*i]=a[((i-bin[cnt])%n+n)%n*2]^a[(i+bin[cnt])%n*2];
			for (int i=0;i<n;i++) a[2*i]=b[2*i];
		}
		m>>=1; cnt++;
	}
	if (tp==1){
		for (int i=0;i<n;i++) b[2*i+1]=a[2*i]^a[(2*i+2)%(2*n)];
		for (int i=1;i<(n<<1);i+=2) printf("0 %d ",b[i]+1);
	}
	else for (int i=0;i<(n<<1);i+=2) printf("%d 0 ",a[i]+1);
	cout<<endl;
	return 0;
}
