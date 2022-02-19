#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1005;
int n,m;
bitset<N> a[N];
bitset<N> b[N];
bool rev;
bitset<N> mat[N];
char str[N];
bool ma[N];
int rt[N][N];
int rp[N][N];
int lk[N];
int fat[N];
int ji=0;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%s",str+1);
		rep(j,1,m)a[i][j]=(str[j]=='1');
	}
	if(n<m){
		rev=1;
		rep(i,1,n)rep(j,1,m)b[i][j]=a[i][j];
		rep(i,1,n)rep(j,1,m)a[j][i]=b[i][j];
		swap(n,m);
	}
	rep(i,1,n)mat[i][i]=1;
	int pre=0;
	rep(i,1,m){
		int t=-1;
		rep(j,pre+1,n)if(a[j][i]){
			t=j;
			break;
		}
		if(t==-1)continue;
		++pre;
		ma[i]=1;
		lk[i]=pre;
		swap(a[t],a[pre]);
		swap(mat[t],mat[pre]);
		rep(j,1,n)if(j^pre)if(a[j][i]){
			a[j]^=a[pre];
			mat[j]^=mat[pre];
		}
	}
	ji=pre;
	rep(i,1,pre)rep(j,1,m)if(a[i][j]&&(!ma[j]))fat[i]=1;
	rep(i,1,n){
		int t=0;
		rep(j,1,n)if(mat[j][i])t=j;
		rep(j,1,m){
			if(!ma[j]){
				if(t>pre)rt[i][j]=1;
				else rt[i][j]=0;
			}
			else{
				if(mat[lk[j]][i]){
					rt[i][j]=-1;
					if(t>pre)rt[i][j]++;
					if(fat[lk[j]])rt[i][j]++;
				}
				else{
					if(t>pre){
						if(fat[lk[j]])rt[i][j]=1;
						else rt[i][j]=0;
					}
					else{
						rt[i][j]=0;
					}
				}
			}
		}
	}
	int ans=0;
	int P=998244353;
	if(rev){
		rep(i,1,n)rep(j,1,m)rp[j][i]=rt[i][j];
		swap(n,m);
		rep(i,1,n)rep(j,1,m)rt[i][j]=rp[i][j];
	}
	rep(i,1,n)rep(j,1,m){
		int t=i*j;
		int w=ji+rt[i][j];
		ans=(ans+t*1ll*w)%P;
	}
	printf("%d\n",ans);
	return 0;
}
