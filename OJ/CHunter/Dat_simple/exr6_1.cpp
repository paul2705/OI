#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
const int MAXN=1e4+5;
struct rec{
	int s,t,l,r;
	bool operator < (const rec& b) const{
		return t>b.t;
	}
};
priority_queue<rec> deq; // s:st_time t:ed_time l:st_pos r:ed_pos
struct bl{
	int l,r;
	bool operator < (const bl& b) const{
		return l<b.l;
	}
};
set<bl> lis; // l:st_pos r:ed_pos
struct ask{
	int t,m,p;
};
queue<ask> q;
int n,ans1,ans2;
void solve_out(rec x){
//	cout<<__func__<<" "<<x.s<<" "<<x.t<<" "<<x.l<<" "<<x.r<<endl;
//	if (lis.begin()==lis.end()) cout<<"empty"<<endl;
	bool exl=1,exr=1;
	set<bl>::iterator nxt=lis.lower_bound((bl){x.l,x.r});
	set<bl>::iterator pre=nxt;
	if (pre!=lis.begin()) pre--;
	else exl=0;
	if (nxt==lis.end()) exr=0;
	bl tmp=(bl){x.l,x.r};
	if (exl){
		if (x.l-1==(*pre).r){
			tmp.l=(*pre).l;
			lis.erase(pre);
		}
	}
	if (exr){
		if (x.r+1==(*nxt).l){
			tmp.r=(*nxt).r;
			lis.erase(nxt);
		}
	}
	lis.insert(tmp);
}
bool solve_in(ask x,int s){
	int cnt=0;
	for (set<bl>::iterator it=lis.begin();it!=lis.end();it++){
		int l=(*it).l,r=(*it).r;
		int len=r-l+1;
		if (len>=x.m){
			int nl=l+x.m;
			lis.erase(it);
			bl tmp=(bl){nl,r};
			if (nl<=r) lis.insert(tmp);
			deq.push((rec){s,s+x.p,l,nl-1});
//			cout<<x.t<<" "<<x.m<<" "<<x.p<<" "<<s<<" "<<s+x.p<<" "<<l<<" "<<nl-1<<endl;
			ans1=max(ans1,s+x.p);
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	int x,y,z; scanf("%d%d%d",&x,&y,&z);
	lis.insert((bl){1,n});
	while (true){
		if (x==0&&y==0&&z==0) break;
		while (!deq.empty()){
			rec tmp=deq.top(); 
			if (tmp.t>x) break;
			solve_out(tmp); 
			deq.pop();
			while (!deq.empty()){
				rec tmp1=deq.top();
				if (tmp.t==tmp1.t){
					solve_out(tmp1);
					deq.pop();
				}
				else break;
			}
			while (!q.empty()){
				if (solve_in(q.front(),tmp.t)) q.pop();
				else break;
			}
		}
		if (!solve_in((ask){x,y,z},x)) q.push((ask){x,y,z}),ans2++;
		scanf("%d%d%d",&x,&y,&z);
	}
	while (!deq.empty()){
		rec tmp=deq.top(); deq.pop();
		solve_out(tmp);
		while (!deq.empty()){
			rec tmp1=deq.top();
			if (tmp.t==tmp1.t){
				solve_out(tmp1);
				deq.pop();
			}
			else break;
		}
		while (!q.empty()){
			if (solve_in(q.front(),tmp.t)) q.pop();
			else break;
		}
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
