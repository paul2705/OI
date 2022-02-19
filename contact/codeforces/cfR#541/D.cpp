#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXM=2e6+5;
const int MAXN=2e3+5;
int n,m;
//a[MAXN][MAXN];
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int d[MAXN],rd[MAXN];
bool use[MAXN];
queue<int> q;
void add(int u,int v,int W){
	swap(u,v);// W*=-1;
	rd[v]++;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='>'&&c!='='&&c!='<') c=getchar();
			if (c=='>') add(i,n+j,1);
			if (c=='<') add(n+j,i,1);
			if (c=='=') add(i,n+j,0),add(n+j,i,0),cnt++;
		}
	}
	int mn=1e9,pos=0;
    for (int j=1;j<=n+m;j++) d[j]=-1e9;
    for (int j=1;j<=n+m;j++) use[j]=0;
    for (int j=1;j<=n+m;j++){
        if (rd[j]==0) d[j]=1,use[j]=1,q.push(j);
    }
    while (!q.empty()){
        int u=q.front(); q.pop(); use[u]=0;
        for (int e=head[u];e;e=nex[e]){
            int v=tail[e];
            if (d[v]<d[u]+w[e]){
            	d[v]=d[u]+w[e];
            	if (!use[v]) q.push(v),use[v]=1;
			}
        }
    }
    int res=0;
    for (int j=1;j<=n+m;j++) res=max(res,d[j]);
    if (cnt==n*m){
    	res=1;
    	for (int i=1;i<=n+m;i++) d[i]=1;
	}
    if (res==1e9) return printf("No\n"),0;
	printf("Yes\n");
	for (int i=1;i<=n;i++) printf("%d ",d[i]);
	cout<<endl;
	for (int i=n+1;i<=n+m;i++) printf("%d ",d[i]);
	cout<<endl;
	return 0;
}
