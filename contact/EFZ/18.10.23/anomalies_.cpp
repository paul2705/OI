#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int fir[450005],nxt[900005],to[900005];
int edge,d[450005],vis[450005];
int a[450005],b[450005],c[450005],dd[900005];
void link(int u,int v)
{
	edge++;
	nxt[edge]=fir[u];
	fir[u]=edge;
	to[edge]=v;


	edge++;
	nxt[edge]=fir[v];
	fir[v]=edge;
	to[edge]=u;
}
int cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	freopen("anomalies.in","r",stdin);
	freopen("anomalies1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[i]=x;a[i+n]=y;a[i+2*n]=z;
		b[i]=i;b[i+n]=i+n;b[i+2*n]=i+2*n;
	}
    sort(b+1,b+1+3*n,cmp);
    int cnt=0;
    for (int i=1;i<=3*n;i++){
        if (a[b[i]]!=a[b[i-1]]) ++cnt;
        c[b[i]]=cnt;
        dd[cnt]=a[b[i]];
	}
    for (int i=1;i<=n;i++){
    	link(c[i],c[i+n]);
    	link(c[i],c[i+2*n]);
    	link(c[i+2*n],c[i+n]);
	}
//    for (int i=1;i<=3*n;i++) cout<<a[i]<<" ";cout<<endl;
//    for (int i=1;i<=3*n;i++) cout<<b[i]<<" ";cout<<endl;
//    for (int i=1;i<=3*n;i++) cout<<c[i]<<" ";cout<<endl;
    
    
//        for (int i=1;i<=13;i++){
//    	cout<<i<<":";
//    	for (int e=fir[i];e;e=nxt[e]) cout<<to[e]<<" ";
//    	cout<<endl;
//	}
    
	for (int i=2;i<=450000;i++) d[i]=-1;
	queue<int> q;
	q.push(1);
	while (!q.empty()){

		int u=q.front();
		q.pop();
//		cout<<q.size()<<" "<<u<<endl;
		for (int e=fir[u];e;e=nxt[e]){
			int v=to[e];
			if (d[v]==-1||d[v]>d[u]+1){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	for (int i=1;i<=cnt;i++)
	    printf("%d %d\n",dd[i],d[i]);
	fclose(stdin);fclose(stdout);
}
