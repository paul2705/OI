#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
int a[MAXN],b[MAXN],ans,n,m,x,y,mx;
bool use[MAXN];
void dfs(int d){
	if (d==n){
		int cnt=0;
		for (int i=0;i<n;i++) b[i]=a[i],cnt+=abs(i-b[i]);
//		cout<<cnt<<endl;
		cnt/=2; mx=max(mx,cnt);
		for (int i=0;i<n;i++){
			for (int j=0;j+1<n;j++){
				if (b[j]>b[j+1]) swap(b[j],b[j+1]),cnt--;
			}
		}
		if (cnt==0){
			if (a[x]==y) ans++;
//			cout<<cnt<<endl;
//			for (int i=0;i<n;i++) printf("%d ",a[i]);
//			cout<<endl;
		}
	}
	for (int i=0;i<n;i++){
		if (!use[i]){
			use[i]=1; a[d]=i;
			dfs(d+1);
			use[i]=0;
		}
	}
}
int main(){
	freopen("bubble.in","r",stdin);
	freopen("bubble.out","w",stdout);
	scanf("%d%d%d",&n,&x,&y);
	dfs(0);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
