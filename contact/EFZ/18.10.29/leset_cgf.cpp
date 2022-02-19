#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MOD = 998244353, maxn = 1e6 + 10;
int n,m;
char s[maxn];
struct matrix{
	long long x[3][3];
	matrix operator * (const matrix &a) const {
		matrix t={};
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				for (int k=0; k<3; k++)
					t.x[i][j]=(t.x[i][j]+x[i][k]*a.x[k][j])%MOD;
		return t;
	}
}e={{{1,0,0},{0,1,0},{0,0,1}}},l={{{1,0,0},{1,1,0},{0,1,0}}},r={{{0,1,0},{0,1,1},{0,0,1}}};//l={3,3,{{1,0,0},{1,1,0},{0,1,0}}},r={3,3,{{0,0,1},{0,1,1},{0,1,0}}};
int pow(long long cur,int i) {
	return i?pow(cur*cur%MOD,i/2)*(i%2?cur:1)%MOD:1;
}
matrix pow(matrix cur,int i) {
	return i?pow(cur*cur,i/2)*(i%2?cur:e):e;
}
int main() {
	freopen("leset.in","r",stdin);
	freopen("leset1.out","w",stdout);
	matrix ans = e,cur;
	scanf("%d%s",&n,s);
	for (int i=0; i<n;) {
		cur = e;
		for(;isupper(s[i]);i++) {
			if (s[i] == 'L') cur = l * cur;
			if (s[i] == 'R') cur = r * cur;
		}
		m=1;
		sscanf(s+i,"%d",&m);
		ans = pow(cur,m) * ans;
		while(isdigit(s[i])) i++;
//		printf("%d %lld %lld %lld %lld\n",i,ans.x[1][0],ans.x[1][1],ans.x[1][2]);
	}	
	printf("%lld\n",(ans.x[1][2]+ans.x[1][1])*pow(ans.x[1][1]+ans.x[1][0],MOD-2)%MOD);
}
