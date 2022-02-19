#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=50;
struct rec{
	ll a[MAXN];
	rec(){
		for (int i=0;i<MAXN;i++) a[i]=0;
	}
	void operator = (const rec& b){
		for (int i=0;i<MAXN;i++) a[i]=b.a[i];
	}
	void update(){
		int x=0;
		while (a[x+1]){
			ll tmp=a[x]/10;
			a[x+1]+=tmp;
			a[x]%=10;
		}
		a[0]=x;
	}
	rec operator * (const rec& b){
		rec c;
		for (int i=0;i<MAXN;i++) c.a[i]=a[i];
		for (int i=1;i<=b.a[0];i++){
			for (int j=1;j<=c.a[0];j++) c.a[j]*=b.a[i];
			for (int j=1;j<=c.a[0];j++){
				ll tmp=c.a[j]/10;
				c.a[j+1]+=tmp;
				c.a[j]%=10;
			}
			c.update();
		}
		return c;
	}
	bool operator < (const rec& b){
		if (a[0]<b.a[0]) return 1;
		if (a[0]>b.a[0]) return 0;
		for (int i=1;i<=a[0];i++){
			if (a[i]<b.a[i]) return 1;
			if (a[i]>b.a[i]) return 0;
		}
		return 0;
	}
	void prt(){
		for (int i=a[0];i>0;i--) printf("%lld",a[i]);
		printf("\n");
	}
} ans1,ans2,t1,t2;
ll a[15],b[15],ansl,ansr;
void solve(ll x,ll y){
	t1.a[1]=x; t1.update();
	t2.a[1]=y; t2.update();
	if (ans<t1*t2){
		ans=t1*t2;
		ansl=x; ansr=y;
	}
}
int main(){
	for (int i=1;i<=4;i++) scanf("%lld",&a[i]);
	sort(a+1,a+5);
	for (int i=1;i<=4;i++){
		for (int j=i+1;j<=4;j++){
			int cnt=0;
			for (int k=1;k<=4;k++){
				if (i==k) continue;
				if (k!=j) b[++cnt]=a[k];
				else b[++cnt]=a[k]-a[j];
			}
			sort(b+1,b+cnt+1);
			ll tmp=max(b[2],b[3]/2);
			solve(a[i],tmp);
		}
	}
	for (int i=1;i<=4;i++){
		for (int j=1;j<=4;j++){
			if (i==j) continue;
			ll tmp=a[j]/2;
			int cnt=0;
			for (int k=1;k<=4;k++){
				if (k==i||k==j) continue;
				b[++cnt]=a[k];
			}
			sort(b+1,b+cnt+1);
			if (tmp>=b[1]) solve(tmp,tmp);
			else 
