#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pbk push_back
using namespace std;
const int maxn = 1000 + 10;
const int mod = 1e9 + 9;
int n,h,tot;
int g[31][31][31][2];
vector<int> v[11000];
int f[maxn][11000];
inline void MODR(int &x,int a){x+=a;if(x>=mod) x-=mod;}
void pre(){
	int i1,i2,i3,i4;tot=0;
	for(i1=h;~i1;i1--)
		for(i2=i1;~i2;i2--) 
			for(i3=i2;~i3;i3--) 
				for(i4=1;~i4;i4--) g[i1][i2][i3][i4]=tot++;
	for(i1=h;~i1;i1--) 
		for(i2=i1;~i2;i2--) 
			for(i3=i2;~i3;i3--) 
				for(i4=1;~i4;i4--){
					int t=g[i1][i2][i3][i4];
					v[t].pbk(g[min(i1+1,h)][min(i2+1,h)][min(i3+1,h)][i4]);
					if(i4){
						v[t].pbk(g[h][min(i2+1,h)][min(i3+1,h)][i1==h]);
						v[t].pbk(g[h][min(i1+1,h)][min(i3+1,h)][i2==h]);
						v[t].pbk(g[h][min(i1+1,h)][min(i2+1,h)][i3==h]);
					}
					else{
						v[t].pbk(g[min(i2+1,h)][min(i3+1,h)][1][i1==h]);
						v[t].pbk(g[min(i1+1,h)][min(i3+1,h)][1][i2==h]);
						v[t].pbk(g[min(i1+1,h)][min(i2+1,h)][1][i3==h]);
					}
				}
}
void solve(){
	int i,j,k,fans=0;
	f[0][g[0][0][0][0]]=1;
	for(i=0;i<n;i++) 
		for(j=1;j<tot;j++){
			if(f[i][j]) for(k=0;k<4;k++) MODR(f[i+1][v[j][k]],f[i][j]);
		}
	for(j=1;j<tot;j++) MODR(fans,f[n][j]);
	printf("%d\n",fans);
}
int main(){
	scanf("%d%d",&n,&h);
	pre();
	solve();
	return 0;
}
