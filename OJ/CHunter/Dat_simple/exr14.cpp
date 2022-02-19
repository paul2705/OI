#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
int n,m,a[MAXN*50];
struct rec{
	int val,aval,pos;
	bool operator < (const rec& b) const{
		return aval>b.aval;
	}
};
priority_queue<rec> q;
int cnt,ans,tot;
int pre[MAXN],nxt[MAXN];
bool use[MAXN*50];
int sgn(int x){ return x<0?-1:1; }
int main(){
	scanf("%d%d",&n,&m);
	int op=0; cnt=1;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		if (x==0) continue;
		else if (!a[cnt]) a[cnt]=x,op=sgn(x);
		else if (op*x>=0) a[cnt]+=x,op=sgn(x);
		else a[++cnt]=x,op=sgn(x);
	}
	for (int i=1;i<=cnt;i++){
		if (a[i]>0) ans+=a[i],tot++;
		q.push((rec){a[i],abs(a[i]),i});
		pre[i]=i-1; nxt[i]=i+1;
	}
	nxt[0]=1; pre[cnt+1]=cnt;
	int M=cnt+1;
	while (tot>m){
		rec x=q.top(); q.pop();
		while (use[x.pos]) x=q.top(),q.pop();
//		cout<<x.val<<endl;
		if (pre[x.pos]==0){
			if (x.val>0) ans-=x.val,tot--;
			pre[nxt[x.pos]]=0;
			use[x.pos]=1;
			continue;
		}
		if (nxt[x.pos]==cnt+1){
			if (x.val>0) ans-=x.val,tot--;
			nxt[pre[x.pos]]=cnt+1;
			use[x.pos]=1;
			continue;
		}
		ans-=x.aval;
		rec tmp;
		tmp.val=x.val+a[pre[x.pos]]+a[nxt[x.pos]];
		tmp.aval=abs(tmp.val);
		tmp.pos=++M; a[M]=tmp.val;
		nxt[tmp.pos]=nxt[nxt[x.pos]]; pre[nxt[tmp.pos]]=tmp.pos;
		pre[tmp.pos]=pre[pre[x.pos]]; nxt[pre[tmp.pos]]=tmp.pos;
		use[x.pos]=use[pre[x.pos]]=use[nxt[x.pos]]=1;
		q.push(tmp); tot--;
	}
	printf("%d\n",ans);
	return 0;
}
