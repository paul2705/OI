#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#define LL long long
#define N (100005)
using namespace std;
template <typename T> void read(T&t) {
	t=0;
	bool fl=true;
	char p=getchar();
	while (!isdigit(p)) {
		if (p=='-') fl=false;
		p=getchar();
	}
	do {
		(t*=10)+=p-48;p=getchar();
	}while (isdigit(p));
	if (!fl) t=-t;
}
int h1,w1,h2,w2;
int main(){
	freopen("picture.in","w",stdout);
	srand(time(0));
	h1=rand()%30+1,w1=rand()%30+1,h2=rand()%30+1,w2=rand()%30+1;
	printf("%d %d\n",h1,w1);
	for (int i=1;i<=h1*w1;i++) printf("%d",rand()%2);
	puts("");
	printf("%d %d\n",h2,w2);
	for (int i=1;i<=h2*w2;i++) printf("%d",rand()%2);
	puts("");
	return 0;
}

