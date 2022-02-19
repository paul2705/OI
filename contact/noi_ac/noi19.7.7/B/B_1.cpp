#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=35;
const int MAXM=13;
const int MAXS=1<<13;
ll f[MAXN][MAXS],g[MAXN][MAXS],mod;
int n,m;
bool ub(int x,int y){
	return x<1||x>n||y<0||y>=m;
}
int main(){
	scanf("%d%d%lld",&n,&m,&mod);
	if (n<m) swap(n,m);
	g[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int s=0;s<(1<<m);s++){
			if (!g[i-1][s]) continue;
			for (int s1=0;s1<(1<<m);s1++){
				int st=0,cnt=0; bool fl=0;
				for (int l=0;l<m;l++){
					if (s&(1<<(m-l-1))) st<<=1;
					else if (fl) st<<=1,fl=0;
					else if (s1&(1<<(m-l-1))){
						int nx=i,ny=l+1;
						if (ub(nx,ny)){
							nx=i+1,ny=l;
							if (ub(nx,ny)) st<<=1;
							else st=(st<<1)+1,cnt++;
						}
						else if (s&(1<<(m-l-2))){
							nx=i+1,ny=l;
							if (ub(nx,ny)) st<<=1;
							else st=(st<<1)+1,cnt++;
						}
						else if (l<m-1) st<<=1,fl=1,cnt++;
						else st<<=1;
					}
					else {
						int nx=i+1,ny=l;
						if (ub(nx,ny)){
							nx=i,ny=l+1;
							if (ub(nx,ny)) st<<=1;
							else if (s&(1<<(m-l-2))){
								nx=i+1,ny=l;
								if (ub(nx,ny)) st<<=1;
								else st=(st<<1)+1,cnt++;
							}
							else if (l<m-1) st<<=1,fl=1,cnt++;
							else st<<=1;
						}
						else st=(st<<1)+1,cnt++;
					}
				}
				bitset<4> t1=s,t2=s1,t3=st;
//				cout<<i<<" "<<t1<<"+"<<t2<<"->"<<t3<<endl;
				f[i][st]=((f[i][st]+f[i-1][s])%mod+cnt*g[i-1][s]%mod)%mod;
				g[i][st]=(g[i][st]+g[i-1][s])%mod;
			}
		}
	}
//	for (int i=0;i<(1<<m);i++){
//		printf("%lld\n",g[n][i]);
//	}
	printf("%lld\n",f[n][0]);
	return 0;
}
