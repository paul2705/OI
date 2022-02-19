#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<cmath>
#define LL long long
#define N (905)
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
int h1,w1,h2,w2,h,w;
char c1[N],c2[N];
int m1[N][N],m2[N][N];
int gcd(int a,int b){
	while (a%b!=0){
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return b;
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("bl.out","w",stdout);
	read(h1),read(w1);
	scanf("%s",c1+1);
	read(h2),read(w2);
	scanf("%s",c2+1);
	h=gcd(h1,h2),w=gcd(w1,w2);
	for (int i=1;i<=h1;i++){
		for (int j=1;j<=w1;j++){
			for (int k=(i-1)*(h2/h)+1;k<=i*h2/h;k++){
				for (int t=(j-1)*(w2/w)+1;t<=j*w2/w;t++) m1[k][t]=c1[i*w1-w1+j]-'0'; 
			}
		}
	}
	for (int i=1;i<=h2;i++){
		for (int j=1;j<=w2;j++){
			for (int k=(i-1)*(h1/h)+1;k<=i*h1/h;k++){
				for (int t=(j-1)*(w1/w)+1;t<=j*w1/w;t++) m2[k][t]=c2[i*w2-w2+j]-'0'; 
			}
		}
	}
	int ans=0;
	for (int i=1;i<=h1*h2/h;i++){
		for (int j=1;j<=w1*w2/w;j++){
			if (m1[i][j]==m2[i][j]) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

