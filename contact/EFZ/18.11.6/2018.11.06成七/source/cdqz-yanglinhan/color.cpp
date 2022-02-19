/*
	Name: t2 30pts 
	Copyright: CYLC
	Author: DJ
	Date: 06/11/18 10:15
	Description: 
*/

#define PEOPLE std
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<vector>
#include<bitset>
#include<set>
#include<map>
#include<queue>

using namespace PEOPLE;

int n,m;
int col[105];
struct edgetype{
	int to,next;
}e[205],newe[20005];
int tote,last[105],totnewe,lastnew[105];
struct rdtype{
	int fr,to,lc;
}rd[105];
vector<int>v[105];

int ceng[105],fa[105][24];
int vis[105];//用于统计拓扑序时避免算重 
int in[105];//用于统计入度 
int cz[105],totcz;//用于逆序输出 

void addedge(int fr,int to){
	tote++;
	e[tote].to=to;e[tote].next=last[fr];
	last[fr]=tote;return;
}

void assassin(){
	scanf("%d%d",&n,&m);
	for(int i1=1;i1<=n;i1++){
		scanf("%d",&col[i1]);
		v[col[i1]].push_back(i1);
	}
	for(int i1=1;i1<n;i1++){
		int fr,to;scanf("%d%d",&fr,&to);
		addedge(fr,to),addedge(to,fr);
	}
	return;
}

void dfs(int d1,int d0){
	fa[d1][0]=d0;
	ceng[d1]=ceng[d0]+1;
	for(int i1=1;i1<=20;i1++){
		fa[d1][i1]=fa[fa[d1][i1-1]][i1-1];
		if(!fa[d1][i1])break;
	}
	for(int i1=last[d1];i1;i1=e[i1].next){
		int to=e[i1].to;
		if(to==d0)continue;
		dfs(to,d1); 
	}
	return;
}

int lca(int l1,int l2){
	if(ceng[l1]<ceng[l2])swap(l1,l2);
	for(int i1=20;~i1;i1--)
	if(ceng[fa[l1][i1]]>=ceng[l2])
	l1=fa[l1][i1];
	if(l1==l2)return l1;
	for(int i1=20;~i1;i1--)
	if(fa[l1][i1]!=fa[l2][i1])
	l1=fa[l1][i1],l2=fa[l2][i1];
	return fa[l1][0];
}

void adde(int fr,int to){
	totnewe++;in[to]++;
	newe[totnewe].to=to;
	newe[totnewe].next=lastnew[fr];
	lastnew[fr]=totnewe;
	return;
}

void preprd(){
	for(int i1=1;i1<=m;i1++){
		int lc=v[i1][0];
		for(int i2=1;i2<v[i1].size();i2++){
			lc=lca(lc,v[i1][i2]);
		}
		rd[i1].fr=rd[i1].to=rd[i1].lc=lc;
		for(int i2=0;i2<v[i1].size();i2++){
			if(lca(v[i1][i2],rd[i1].fr)==rd[i1].fr){//可以更新左侧 
				rd[i1].fr=v[i1][i2];
			}
			else{
				if(lca(v[i1][i2],rd[i1].to)==rd[i1].to)
				rd[i1].to=v[i1][i2];
			}
		}
		for(int i2=rd[i1].fr;i2!=fa[rd[i1].lc][0];i2=fa[i2][0]){
			int nowc=col[i2];
			if(nowc!=i1){
				if(vis[nowc]!=i1)
				vis[nowc]=i1,adde(nowc,i1);
			}
		}
		for(int i2=rd[i1].to;i2!=fa[rd[i1].lc][0];i2=fa[i2][0]){
			int nowc=col[i2];
			if(nowc!=i1){
				if(vis[nowc]!=i1)
				vis[nowc]=i1,adde(nowc,i1);
			}
		}
	}
	return;
}

queue<int>q;

void dotp(){
	for(int i1=1;i1<=m;i1++)
	if(in[i1]==0)q.push(i1);
	while(q.size()){
		int nowpos=q.front();q.pop();
		totcz++;cz[totcz]=nowpos;
		for(int i1=lastnew[nowpos];i1;i1=newe[i1].next){
			int to=newe[i1].to;
			in[to]--;			
			if(in[to]==0)q.push(to);
		}
	}
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	assassin();
	dfs(1,0);
	preprd();
	dotp();//拓扑； 
	for(int i1=totcz;i1;i1--)
	printf("%d %d %d\n",cz[i1],rd[cz[i1]].fr,rd[cz[i1]].to);
	return 0;
} 

