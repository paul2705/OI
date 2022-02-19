#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=MAXN*4;
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXT];
int n,m,M,a[MAXN],root;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,min(t[cl].dat,t[cr].dat));
}
int query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<a||l>b) return (int)1e9;
	if (a<=l&&r<=b) return t[id].dat;
	return min(query(a,b,cl),query(a,b,cr));
}
int main(){
	freopen("cusor.in","r",stdin);
	freopen("cusor.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	root=build(1,n);
	scanf("%d",&m);
	for (int i=1,x,y,xx,yy;i<=m;i++){
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		if (x>xx) swap(x,xx),swap(y,yy);
		if (x==xx){
			printf("%d\n",abs(yy-y));
			continue;
		}
		if (y>yy) swap(y,yy);
		int ret=query(x,xx,root);
//		cout<<ret<<" ";
		if (ret>=y) printf("%d\n",yy-y+xx-x);
		else printf("%d\n",abs(y-query(x,xx,root))*2+xx-x+yy-y);
//		cout<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
