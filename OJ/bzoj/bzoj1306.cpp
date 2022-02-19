#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10;
const int mk[5]={3,1,0,0};
int n,m,a[MAXN];
int ans;
void dfs(int x,int y){
	if (a[x]>(n-y+1)*3) return;
	if (a[x]<0) return;
	if (x==n-1&&y==n){
		bool flag=1;
		cout<<__func__<<endl;
		for (int i=1;i<=n;i++){
			flag&=(a[i]==0);
			printf("%d ",a[i]);
		}
		if (flag) ans++;
		return;
	}
	else if (y==n){
		if (a[x]!=3&&a[x]!=1&&a[x]!=0) return;
		int tmp=a[x];
		if (tmp==3){ 
			a[x]=0; dfs(x+1,x+2); a[x]=tmp;
		}
		if (tmp==1){
			a[x]=0; a[y]--; dfs(x+1,x+2); a[x]=tmp; a[y]++;
		}
		if (tmp==0){
			a[y]-=3; dfs(x+1,x+2); a[y]+=3;
		}
	}
	else{
		if (a[x]>=3){
			a[x]-=3; dfs(x,y+1); a[x]+=3;
		}
		if (a[x]>=1&&a[y]>=1){
			a[x]--; a[y]--; dfs(x,y+1); a[x]++; a[y]++;
		}
		if (a[y]>=3){
			a[y]-=3; dfs(x,y+1); a[y]+=3;
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,2);
	printf("%d\n",ans);
	return 0;
}
