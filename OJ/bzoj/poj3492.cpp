#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=505;
const int MAXE=5005;
int n,a[MAXN],dis[MAXE];
bool vis[MAXE];
bool pd(){
	for (int i=1;i<=n-1;i++) if (a[i]%a[0]!=0) return 0;
	return 1;
}
void dijastra(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[0]=0; queue<int> q; q.push(0); vis[0]=1;
	while(!q.empty())
        {
            int u=q.front();
            for(int i=1;i<=n-1;i++)
                if(dis[(u+a[i])%a[0]]>dis[u]+a[i])
                {
                    dis[(u+a[i])%a[0]]=dis[u]+a[i];
                    if(!vis[(u+a[i])%a[0]])
                    {
                        vis[(u+a[i])%a[0]]=1;
                        q.push((u+a[i])%a[0]);
                    }
                }
            q.pop();
            vis[u]=0;
        }
}
int main(){
	while (scanf("%d",&n)==1){
		for (int i=0;i<=n-1;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		if (pd()){
			printf("INF\n");
			continue;
		}
		int ans=0;
		dijastra();
		for (int i=1;i<=a[0]-1;i++) ans=max(ans,dis[i]);
		printf("%d\n",ans-a[0]);
	}
	return 0;
}
