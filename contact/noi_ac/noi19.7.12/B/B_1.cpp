#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=2e5+5;
int n,m,a[MAXN],b[MAXN];
int cnt[MAXN],ans,Cd;
struct rec{
	int l,r,id,ans;
} q[MAXN];
int blk;
bool fl=0;
bool cmp_bl(rec a,rec b){
	int posa=a.l/blk,posb=b.l/blk;
	return posa==posb?a.r<b.r:posa<posb;
}
bool cmp_id(rec a,rec b){ return a.id<b.id; }
void del(int x){
	if (fl&&x==1) return;
	if (cnt[x]%2==0){
		if (Cd%2==0) ans++,Cd++;
		else ans--,Cd++;
	}
	else {
		if (Cd%2==0) Cd--;
		else ans-=2,Cd--;
	}
	cnt[x]--;
}
void add(int x){
	if (fl&&x==1) return;
	if (cnt[x]%2==0){
		if (Cd%2==0) ans+=2,Cd++;
		else Cd++;
	}
	else {
		if (Cd%2==0) ans++,Cd--;
		else ans--,Cd--;
	}
	cnt[x]++;
}
void chg(int& l,int& r,int op){
//	cout<<l<<" "<<r<<" "<<op<<endl;
	if (op==1) del(a[l++]);
	if (op==2) add(a[--l]);
	if (op==3) add(a[++r]);
	if (op==4) del(a[r--]);
//	cout<<ans<<" "<<Cd<<endl;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	fl=(b[1]==0);
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	blk=sqrt(n);
	sort(q+1,q+m+1,cmp_bl);
	int l=1,r=0; chg(l,r,3);
	for (int i=1;i<=m;i++){
		while (l<q[i].l) chg(l,r,1);
		while (l>q[i].l) chg(l,r,2);
		while (r<q[i].r) chg(l,r,3);
		while (r>q[i].r) chg(l,r,4);
		q[i].ans=ans;
	}
	sort(q+1,q+m+1,cmp_id);
	for (int i=1;i<=m;i++) printf("%d\n",q[i].ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
