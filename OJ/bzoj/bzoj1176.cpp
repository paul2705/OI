#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e6+6;
const int MAXQ=2e5+5;
int S,n,cntq,cnt,tim;
int t[MAXN],ans[MAXQ];
struct rec{
	int t,x,y,w,tp,id;
	bool operator < (const rec& b) const {
		if (x!=b.x) return x<b.x;
		if (y!=b.y) return y<b.y;
		return t<b.t;
	}
} q[MAXQ],tmp[MAXQ];
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
//	cout<<__func__<<" "<<ret<<endl;
	return ret;
}
void cdq(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	for (int i=l;i<=r;i++){
		if (q[i].t<=mid&&q[i].tp==1) add(q[i].y,q[i].w);
		if (q[i].t>mid&&q[i].tp==2) ans[q[i].id]+=q[i].w*sum(q[i].y);
	}
	for (int i=l;i<=r;i++){
		if (q[i].t<=mid&&q[i].tp==1) add(q[i].y,-q[i].w);
	}
	int t1=l,t2=mid+1;
	for (int i=l;i<=r;i++){
		if (q[i].t<=mid) tmp[t1++]=q[i];
		else tmp[t2++]=q[i];
	}
	for (int i=l;i<=r;i++) q[i]=tmp[i];
	cdq(l,mid); cdq(mid+1,r);
}
int main(){
	scanf("%d%d",&S,&n);
	while (true){
		int op,x1,y1,x2,y2,val;
		scanf("%d",&op);
		if (op==3) break;
		if (op==1){
			scanf("%d%d%d",&x1,&y1,&val);
			q[++cnt]=(rec){++tim,x1,y1,val,1,0};
		}
		else {
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ans[++cntq]=(y1-y2+1)*(x2-x1+1)*S;
			q[++cnt]=(rec){++tim,x1-1,y1-1,1,2,cntq};
			q[++cnt]=(rec){++tim,x1-1,y2,-1,2,cntq};
			q[++cnt]=(rec){++tim,x2,y1-1,-1,2,cntq};
			q[++cnt]=(rec){++tim,x2,y2,1,2,cntq};
		}
	}
	sort(q+1,q+cnt+1);
	cdq(1,cnt);
	for (int i=1;i<=cntq;i++) printf("%d\n",ans[i]);
	return 0;
}
