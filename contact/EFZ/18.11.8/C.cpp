#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define maxm 105
#define INF 3*maxn

using namespace std;

int n,m;
int T[maxn];
int tmp[maxn];
int P[maxm][maxn];
int q[maxn];
int id[3*maxn];

int main() {
	freopen("new.in","r",stdin);
	freopen("new1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&T[i]);
	for (int i=1;i<=m;i++) 
		for (int j=1;j<=n;j++)
			scanf("%d",&P[i][j]);
	//求第一问
	for (int i=1;i<=n;i++)
		id[T[i]]=i;
	int ans=0;
	for (int i=1;i<=m;i++) {
		int len=0;
		for (int j=1;j<=n;j++)
			tmp[j]=id[P[i][j]];
		for (int j=1;j<=n;j++) {
			if (!tmp[j]) continue;
			if (!len) q[++len]=tmp[j];
				else if (tmp[j]>q[len]) q[++len]=tmp[j];
					else {
						int pos=lower_bound(q+1,q+len+1,tmp[j])-q;
						q[pos]=tmp[j];
					}
		}
		ans=max(ans,len);
	} 
	printf("%d\n",ans);
	
	//求第二问
	ans=0;
	for (int i=1;i<=m;i++) {
		int pre=0,len=0;
		for (int j=1;j<=n;j++) {
			int pos=id[P[i][j]];
//			cout<<"fuck"<<pos-pre<<pre<<"fuck"<<endl;
			if (pre==0) {
				pre=pos;
				len=(pos>0);
				ans=max(ans,len);
			} else if (pos==pre+1){
//				cout<<"fuck"<<endl;
				pre=pos;
				len++;
				ans=max(ans,len);
			}
			else pre=pos,len=(pos>0);
		}
		ans=max(ans,len);
	} 
	
	printf("%d\n",ans);
}
