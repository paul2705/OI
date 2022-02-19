#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=1e3;
const int mod=1e3;
int n,m,q;
int main(){
	freopen("seg.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%modn+1,m=rand()%modn+1,q=rand()%mod+1;
	cout<<n<<" "<<m<<" "<<q<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			int x=rand()%mod+1;
			int x=0;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	for (int i=1;i<=q;i++){
		int op=rand()%2+1,sx=rand()%n+1,sy=rand()%m+1;
		int lx=rand()%(n-sx+1),ly=rand()%(m-sy+1);
		printf("%d %d %d %d %d",op,/*(op==1)?1:*/sx,/*(op==1)?1:*/sy,/*(op==1)?1:*/(sx+lx),/*(op==1)?1:*/(sy+ly));
		if (op==1){
			int x=rand()%10+1;
//			int x=1;
			printf(" %d",x);
		}
		cout<<endl;
	}
	fclose(stdout);
	return 0;
}
