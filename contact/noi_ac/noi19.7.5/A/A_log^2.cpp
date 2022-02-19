#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
ll a[MAXN],x[MAXN],y[MAXN];
int n,M,rt;
ll f[MAXN];
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXN*8];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,0);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0);
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	if (!t[id].tag) return;
	t[id].dat=t[id].tag;
	t[cl].tag=t[cr].tag=t[id].tag;
	t[id].tag=0;
}
void modify(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag=val;
		pushdown(id);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
}
int query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return max(query(a,b,cl),query(a,b,cr));
}
ll tri(ll x){ return x*x*x; }
ll calc(int l,int r){
	return tri(abs(a[r]-x[l]))+tri(y[l]);
}
bool check(int mid,int l){
	int pos=query(mid,mid,rt);
//	cout<<" "<<pos<<" "<<l<<" "<<mid<<" "<<calc(pos+1,mid)<<" "<<calc(l+1,mid)<<endl;
	return f[pos]+calc(pos+1,mid)>=f[l]+calc(l+1,mid);
}
int main(){
	scanf("%d",&n);
	rt=build(1,n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&y[i]);
	f[0]=0;
	for (int i=1;i<=n;i++){
		int pos=query(i,i,rt);
//		cout<<i<<" "<<pos<<endl;
		f[i]=f[pos]+calc(pos+1,i);
		int l=i,r=n+1,mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (check(mid,i)) r=mid;
			else l=mid;
		}
//		cout<<i<<" "<<r<<" "<<n<<endl;
		if (r>n) continue;
		modify(r,n,rt,i);
	}
	printf("%lld\n",f[n]);
	return 0;
}
