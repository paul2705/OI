#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
ll f[MAXN],a[MAXN],x[MAXN],y[MAXN];
int n;
int st[MAXN],top,L[MAXN],R[MAXN];
ll cube(ll x){ return x*x*x; }
ll calc(int l,int r){ return cube(abs(a[r]-x[l]))+cube(y[l]); }
bool check(int a,int b,int r){
	return f[a]+calc(a+1,r)>=f[b]+calc(b+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&y[i]);
	f[0]=0; st[++top]=0; L[0]=1; R[0]=n; 
	for (int i=1;i<=n;i++){
		int l=0,r=top,mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (i<=R[st[mid]]) r=mid;
			else l=mid;
		}
		f[i]=f[st[r]]+calc(st[r]+1,i);
		while (L[st[top]]>i&&check(st[top],i,L[st[top]])) top--;
		if (check(st[top],i,R[st[top]])){
			int l=L[st[top]],r=R[st[top]],mid;
			while (l+1<r){
				mid=(l+r)>>1;
				if (check(st[top],i,mid)) r=mid;
				else l=mid;
			}
			R[st[top]]=r-1;
		}
		if (R[st[top]]<n){
			L[i]=R[st[top]]+1; R[i]=n;
			st[++top]=i;
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}
