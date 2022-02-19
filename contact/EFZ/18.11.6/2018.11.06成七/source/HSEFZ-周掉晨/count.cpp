#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int vis[1005],a[1005][1005];
int r[1005],c[1005],ans;
void cal()
{
	for (int i=0;i<n;i++){
		int maxn=0;
		for (int j=0;j<m;j++){
			if (a[i][j]>maxn){
				maxn=a[i][j];r[i]=j;
			}
		}
	}
	for (int j=0;j<m;j++){
		int maxn=0;
		for (int i=0;i<n;i++){
			if (a[i][j]>maxn){
				maxn=a[i][j];c[j]=i;
			}
		}
	}
	int ret=0;
	for (int i=0;i<n;i++){
		if (c[r[i]]==i) ret++;
	}
	if (ret==1) ans=(ans+1)%p;
//	for (int i=0;i<n;i++){
//	    for (int j=0;j<m;j++) cout<<a[i][j]<<" ";
//	    cout<<endl;
//	}
//	cout<<ret<<endl<<endl;
}
void search(int x)
{
	if (x==n*m)cal();
	else {
		int i=x/m;
		int j=x%m;
		for (int k=1;k<=n*m;k++)
		if (!vis[k]){
			a[i][j]=k;
			vis[k]=1;
			search(x+1);
			vis[k]=0;
		}
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	search(0);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
}
