#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=20000;
const int modc=9;
int n,m,fa[modn+5];
int main(){
//	freopen("revenge.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*100000+tv.tv_usec);
	n=modn; m=modc;
	n/=5; n*=5;
	printf("%d %d\n",n,m);
/*	for (int i=2;i<=n;i++){
		fa[i]=rand()%(i-1)+1;
		printf("%d %d\n",i,fa[i]);
	}
	for (int i=1;i<=n;i++){
		int x=rand()%m+1;
		if (i<n/1000) x=rand()%3+1;
		if (i>n/1000) x=rand()%3+(m-3)+1;
		printf("%d ",x);
	}
	printf("\n");
*/
	for (int i=1;i<=n;i+=n/5){
		for (int j=i;j<=i+n/5;j++){
			if (j==1) continue;
//			cout<<"in"<<endl;
			fa[j]=rand()%(j-i)+i;
			cout<<n<<" "<<j<<" "<<j-i<<" "<<fa[j]<<endl;
		}
	}
	for (int i=1;i<=n;i++){
		printf("%d %d\n",i,fa[i]);
	}
	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i+=n/5){
		for (int j=i;j<=i+n/5;j++){
			printf("%d ",i);
		}
	}
	printf("\n");
	fclose(stdout);
	return 0;
}
