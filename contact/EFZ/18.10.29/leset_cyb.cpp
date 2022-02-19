#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long

const LL MOD=998244353;

struct Matrix{
	int a[3][3];
	Matrix operator * (const Matrix &b) const {
        Matrix bb=b;
        for (int i=1;i<=2;i++)
            for (int j=1;j<=2;j++) {
                bb.a[i][j]=0;
                for (int k=1;k<=2;k++)
                    bb.a[i][j]=(bb.a[i][j]+a[i][k]*b.a[k][j]%MOD)%MOD;
            }
        return bb;
    }
    friend Matrix operator ^ (Matrix x,int num) {
        Matrix y;
        for (int i=1;i<=2;i++)
            for (int j=1;j<=2;j++)
                if (i==j) y.a[i][j]=1; else y.a[i][j]=0;
        while (num) {
            if (num&1) y=y*x;
            x=x*x;
            num>>=1;
        }
        return y;
    }
}L,R,ans;

int len,now=-1,rep;
LL fz,fm,f;
int num[2];
std::string s;

void init() {
	ans.a[1][1]=0; ans.a[1][2]=1;
	ans.a[2][1]=1; ans.a[2][2]=0;
	L.a[1][1]=1; L.a[1][2]=1;
	L.a[2][1]=0; L.a[2][2]=1;
	R.a[1][1]=1; R.a[1][2]=0;
	R.a[2][1]=1; R.a[2][2]=1;
}

LL pow(LL base,LL po) {
	LL ret=1;
	while (po) {
		if (po&1) ret=ret*base%MOD;
		base=base*base%MOD;
		po>>=1;
	}
	return ret;
}

int main() {
	freopen("leset.in","r",stdin);
	freopen("leset1.out","w",stdout);
	init();
	scanf("%d",&len);
	std::cin>>s;
	while (now<len) {
		memset(num,0,sizeof(num));
		while (true) {
			now++;
			if (now>=len) break;
			if (s[now]>='0' && s[now]<='9') {
				rep=s[now]-'0';	now++;
				while (s[now]>='0' && s[now]<='9') {
					rep=rep*10+s[now]-'0';
					now++;
				}
				now--;
				break;
			}
			if (s[now]=='R') num[1]++; else num[0]++;
		}
		ans=ans*(((L^num[0])*(R^num[1]))^rep);
	}
	fz=ans.a[1][1]+ans.a[1][2];
	fm=ans.a[2][1]+ans.a[2][2];
	f=fz*pow(fm,MOD-2)%MOD;
	printf("%lld\n",f);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
