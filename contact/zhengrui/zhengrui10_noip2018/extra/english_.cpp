#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define int long long
const int N=100005,L=30,M=1e9+7;
int n,opt,a[N],f[L][N][2],b[N],ff[L][N],size[N*L*2];
int ne[N*L*2][2],root[N],l[N],r[N],ans,cnt;
void insert(int x,int y,int z){
	for (int i=29;i>=0;i--){
		int k=(1<<i)&z?1:0;
		ne[y][k^1]=ne[x][k^1];
		ne[y][k]=++cnt;
		y=ne[y][k];x=ne[x][k];
		size[y]=size[x]+1;
	}
}
int find(int x,int y,int z,int l){
	int sum=0;
	for (int i=29;i>=0;i--){
		int k1=(1<<i)&z?1:0,k2=(1<<i)&l?1:0;
		if (!k1)sum+=size[ne[x][k2^1]]-size[ne[y][k2^1]];
		x=ne[x][k1^k2];y=ne[y][k1^k2];
	}
	return sum;
}
signed main(){
	scanf("%lld%lld",&n,&opt);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int tot=0;
	for (int i=1;i<=n;i++){ 
		while (tot&&a[i]>a[b[tot]])tot--;
		l[i]=b[tot]+1;
		b[++tot]=i;
	}
	b[tot=1]=n+1;a[n+1]=1e9+1;
	for (int i=n;i;i--){
		while (tot&&a[i]>=a[b[tot]])tot--;
		r[i]=b[tot]-1;
		b[++tot]=i;
	}
	if (opt&1){
		for (int i=0;i<=29;i++)
			for (int j=1;j<=n;j++){
				f[i][j][0]=f[i][j-1][0];f[i][j][1]=f[i][j-1][1];
				if ((1<<i)&a[j])f[i][j][1]++;
				else f[i][j][0]++;
			}
		for (int i=1;i<=n;i++){
			for (int j=0;j<=29;j++){
				(ans+=a[i]*(((f[j][i][1]-f[j][l[i]-1][1])*
				(f[j][r[i]][0]-f[j][i-1][0])+
				(f[j][i][0]-f[j][l[i]-1][0])*
				(f[j][r[i]][1]-f[j][i-1][1])))%M*(1<<j)%M)%=M;
			}
		}	
		printf("%lld\n",ans);
	}
	ans=0;
	if (opt&2){
		for (int i=1;i<=n;i++){
			root[i]=++cnt;
			insert(root[i-1],root[i],a[i]);
		}
		for (int i=1;i<=n;i++){
			if (i-l[i]>r[i]-i){
				for (int j=i;j<=r[i];j++)
					(ans+=find(root[i],root[l[i]-1],a[i],a[j])%M*a[i]%M)%=M;
			}
			else {
				for (int j=l[i];j<=i;j++)
					(ans+=find(root[r[i]],root[i-1],a[i],a[j])%M*a[i]%M)%=M;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
