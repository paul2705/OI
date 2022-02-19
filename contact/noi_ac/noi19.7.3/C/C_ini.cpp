#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;;
typedef long long ll;
ll n,K,A[MAXN];
struct rec{
	ll w,cnt,id;	
} a[MAXN];
bool cmp(rec a,rec b){ return a.w*a.cnt<b.w*b.cnt; }
int main(){
	freopen("x2.in","r",stdin);
	scanf("%lld%lld",&n,&K);
	for (int i=1;i<=10;i++) scanf("%lld",&A[i]);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].w,&a[i].cnt);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	ll s=0;
	for (int i=1;i<=n;i++){
		s+=a[i].w*a[i].cnt;
		cout<<a[i].id<<" ";
		if (s>=K){
			printf("%d %lld\n",i,s);
			break;;
		}
	}
	cout<<s<<endl;
	fclose(stdin);
	return 0;
}
