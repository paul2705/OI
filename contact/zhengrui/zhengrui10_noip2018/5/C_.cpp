#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll n,T;
int a[MAXN],b[MAXN];
int main(){
	scanf("%lld%lld",&T,&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		a[i]=c-'0';
	}
	while (T--){
		b[1]=a[2],b[n]=a[n-1];
		for (int i=2;i<n;i++) b[i]=(a[i-1]+a[i+1])%2;
		for (int i=1;i<=n;i++) a[i]=b[i];
//		/*if (T<=0){*/for (int i=1;i<=n;i++) printf("%d ",a[i]);
//		cout<<endl;
	}
	for (int i=1;i<=n;i++) printf("%d",a[i]);
	cout<<endl;
	return 0;
}
