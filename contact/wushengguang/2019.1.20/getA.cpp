#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=5e2;
int n,m,k;
char a[modn+5][modn+5];
int main(){
	freopen("robot.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
//	n=rand()%modn+1,m=rand()%modn+1;
	n=500; m=500;
	k=9;
	cout<<k<<" "<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=rand()%15;
			if (x==0) a[i][j]='x';
			else if (x>0&&x<=2) a[i][j]='A';
			else if (x>2&&x<=4) a[i][j]='C';
			else a[i][j]='.';
		}
	}
	for (int i=1;i<=k;i++){
		int x=rand()%n+1,y=rand()%m+1;
		while (a[x][y]>='1'&&a[x][y]<='9'){
			x=rand()%n+1,y=rand()%m+1;
		}
		a[x][y]='0'+i;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cout<<a[i][j];
		cout<<endl;
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++){
//			if (a[i][j]>='1'&&a[i][j]<='9') cout<<a[i][j]<<" ";
//		}
//	}
	fclose(stdout);
	return 0;
}
