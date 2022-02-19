#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1000;
int n,m;
int main(){
	freopen("1014.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=1000,m=5000;
	for (int i=1;i<=n;i++){
		char c=rand()%26+'a';
//		if (i%3<=1) cout<<'a';
//		else cout<<c;
		cout<<'a';
	}
	cout<<endl<<m<<endl;
	for (int i=1;i<=m;i++){
		int op=rand()%3,x=rand()%n+1,y=rand()%n+1;
		char c=rand()%26+'a';
		if (op==0) printf("Q %d %d\n",x,y);
		if (op==1) printf("R %d %c\n",x,c);
		if (op==2) printf("I %d %c\n",x-1,c);
	}
	fclose(stdout);
	return 0;
}
