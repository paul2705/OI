#pragma GCC optimze(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int inf=5e5;
const int MAXN=5e5+5;
const int MAXT=MAXN*8;
int f[MAXN];
struct tnode{
	int l,r,cl,cr,dat,lb,rb;
	vector<int> lis;
	void push(int x){
		int las=rb;
		while (rb>=lb&&f[lis[rb]]>f[x]) rb--;
		if (las>rb) lis[++rb]=x;
		else rb++,lis.push_back(x);
	}
	int mn(){ return rb>=lb?f[lis[lb]]:inf; }
	void pop(int x){
		while (rb>=lb&&lis[lb]<=x) lb++;
	}
} t[MAXT];
int n,L,M,rt,lim;
int x[MAXN],y[MAXN],d[MAXN];
int q[MAXN],l,r;
int b[MAXN],cnt;
int newnode(int l,int r,int cl,int cr){
	t[++M]=(tnode){l,r,cl,cr,inf,0,-1};
	return M;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[0].dat=inf;
	t[id].dat=min(t[id].mn(),min(t[cl].dat,t[cr].dat));
}
void modify(int a,int b,int id,int pos,int op){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	ll mid=(ll)((ll)l+(ll)r)>>1ll;
	if (l>b||r<a) return;
	if (l==r){
		if (op==1) t[id].push(pos);
		else t[id].pop(pos);
		update(id);
		return;
	}
//	cout<<__func__<<" "<<l<<" "<<mid<<" "<<r<<endl;
//	if (!cl) t[id].cl=cl=newnode(l,mid,0,0);
//	if (!cr) t[id].cr=cr=newnode(mid+1,r,0,0);
	if (a<=l&&r<=b){
		if (op==1) t[id].push(pos);
		else t[id].pop(pos);
		update(id);
		return;
	}
	if (mid>=a){
		if (!cl) t[id].cl=cl=newnode(l,mid,0,0);
		modify(a,b,cl,pos,op);
	}
	if (mid+1<=b){
		if (!cr) t[id].cr=cr=newnode(mid+1,r,0,0);
		modify(a,b,cr,pos,op);
	}
	update(id);
}
int qry(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	ll mid=(ll)((ll)l+(ll)r)>>1ll;
	if (l>b||r<a) return inf;
	int ans=t[id].mn();
//	cout<<__func__<<" "<<a<<" "<<b<<" "<<l<<" "<<r<<" dat:"<<t[id].dat<<endl;
	if (a<=l&&r<=b) return min(ans,t[id].dat);
	if (cl&&mid>=a) ans=min(ans,qry(a,b,cl));
	if (cr&&mid+1<=b) ans=min(ans,qry(a,b,cr));
	return ans;
}
int main(){
	freopen("bzoj1171.in","r",stdin);
	freopen("bzoj1171.out","w",stdout);
	scanf("%d%d",&n,&L);
	for (int i=2;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&d[i]);
		b[++cnt]=x[i]; b[++cnt]=y[i];
		f[i]=inf;
	}
	sort(b+1,b+cnt+1);
	int nn=unique(b+1,b+cnt+1)-b-1;
	for (int i=2;i<=n;i++){
		x[i]=lower_bound(b+1,b+nn+1,x[i])-b;
		y[i]=lower_bound(b+1,b+nn+1,y[i])-b;
		lim=max(lim,max(x[i],y[i]));
	}
	rt=newnode(0,lim,0,0);
	f[1]=0; modify(0,lim,rt,1,1);
	l=1,r=1; q[1]=1; x[1]=0; y[1]=lim;
	for (int i=2;i<=n;i++){
//		cout<<i<<" "<<x[i]<<" "<<y[i]<<" "<<y[i]-x[i]<<endl;
		while (r>=l&&d[i]-d[q[l]]>L){
//			cout<<l<<" "<<q[l]<<endl;
			modify(x[q[l]],y[q[l]],rt,q[l],-1);
			l++;
		}
		f[i]=qry(x[i],y[i],rt)+1;
		modify(x[i],y[i],rt,i,1);
		q[++r]=i;
//		cout<<i<<": "<<f[i]<<endl;
	}
	for (int i=2;i<=n;i++) printf("%d\n",f[i]>=inf?-1:f[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}


