#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct tnode{
	int l,r,cl,cr,mn,dat;
} t[MAXN];
int n,m,M,root,a[MAXN],b[MAXN];
int ans,f[MAXN],tr[MAXN];
void add(int x,int val){
	for (;x<=n;x+=x&-x) tr[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=tr[x];
	return ret;
}
int newnode(int l,int r,int cl,int cr,int mn,int dat){
	t[++M]=(tnode){l,r,cl,cr,mn,dat};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l],f[l]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,min(t[cl].mn,t[cr].mn),t[cl].dat+t[cr].dat);
}
int query_mn(int v,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l==r) return t[id].dat<=v?l:-1;
	if (t[cr].mn<=v) return query_mn(v,cr);
	return query_mn(v,cl);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].mn=min(t[cl].mn,t[cr].mn);
	t[id].dat=t[cl].dat+t[cr].dat;
}
void modify(int aa,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<aa) return;
	if (aa<=l&&r<=b){
		t[id].mn=val;
		a[l]=val;
		t[id].dat=0;
		return;
	}
	modify(aa,b,cl,val); modify(aa,b,cr,val);
	update(id);
}
int query_sum(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return query_sum(a,b,cl)+query_sum(a,b,cr);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
	}
	for (int i=n;i>=1;i--){
		f[i]=sum(a[i]-1);
		ans+=f[i];
		add(a[i],1);
	}
	root=build(1,n);
	for (int i=1,pos;i<=m;i++){
		scanf("%d",&pos);
		int x=query_mn(a[pos],root);
		while (a[x]<=a[pos]&&a[x]<n+10){
//			cout<<a[x]<<endl;
			modify(x,x,root,n+10);
			ans-=f[x];
			x=query_mn(a[pos],root);
		}
//		cout<<x<<" "<<a[x]<<endl;
//		int ans=query_sum(pos,n,root);
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
