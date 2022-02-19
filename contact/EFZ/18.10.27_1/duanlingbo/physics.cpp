#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e3+5;
double ang,v,d,g;
int T;
int main(){
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%lf%lf%lf%lf",&ang,&v,&d,&g); ang*=2.0;
		printf("%.5lf\n",v*v*1.0/(1.0-d*d)*sin(ang*acos(-1)/180.0)/g);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
