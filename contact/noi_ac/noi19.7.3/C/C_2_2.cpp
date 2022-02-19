#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1e4+5;
int n,K,A[MAXN];
struct rec{
	int w,cnt,id;
} a[MAXN],b[MAXN];
int mn,pos;
bool cmp(rec a,rec b){ return a.w*a.cnt<b.w*b.cnt; }
int main(){
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	freopen("x2.in","r",stdin);
	scanf("%d%d",&n,&K);
	mn=K;
	for (int i=1;i<=10;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].w,&a[i].cnt);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
//	for (int i=1;i<=2000;i++) random_shuffle(a+1,a+n+1);
	int cnt=100000;
	while (cnt--){
		random_shuffle(a+1,a+n+1);
		int s=0;
		for (int i=1;i<=n;i++){
			s+=a[i].w*a[i].cnt;
			if (abs(K-s)<mn){
				mn=abs(K-s);
				for (int j=1;j<=n;j++) b[j]=a[j];
				pos=i;
			}
		}
	}
	printf("pos: %d\n",pos);
	for (int i=1;i<=pos;i++){
		printf("%d ",b[i].id);
	}
	printf("mn: %d\n",mn);
	return 0;
}
