#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
double t[3][MAXN];
// 1: \frac{1}{M_i}
// 2: \frac{i}{M_i}
int n;
double a,m[MAXN];
void add(int id,int x,double val){
	for (;x<=n;x+=x&-x) t[id][x]+=val;
}
double sum(int id,int x){
	double ans=0;
	for (;x;x-=x&-x) ans+=t[id][x];
	return ans;
}
int main(){
	scanf("%d%lf",&n,&a);
	for (int i=1;i<=n;i++) scanf("%lf",&m[i]);
	for (int i=1;i<=n;i++){
		int r=(int)floor(a*i);
		if (r==0) printf("0.00\n");
		else {
			double ret=sum(1,r)*i-sum(2,r);
			printf("%.6lf\n",1.0/ret*m[i]);
		}
		add(1,i,1.0/m[i]);
		add(2,i,(double)i/m[i]);
	}
	return 0;
}
