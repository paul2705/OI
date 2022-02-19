#include<bits/stdc++.h>
#define MAXN 901
using namespace std;

int h1,w1,h2,w2;
int m1[MAXN][MAXN];
int m2[MAXN][MAXN];
int p1[MAXN][MAXN];
int p2[MAXN][MAXN];

int gcd(int x,int y){
	if(y==0)
		return x;
	return gcd(y,x%y);
}

int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);

	scanf("%d%d",&h1,&w1);

	string s;

	cin>>s;

	for(int i=1;i<=h1;i++)
		for(int j=1;j<=w1;j++)
			m1[i][j]=s[(i-1)*w1+j-1]-'0';
	
	scanf("%d%d",&h2,&w2);

	cin>>s;

	for(int i=1;i<=h2;i++)
		for(int j=1;j<=w2;j++)
			m2[i][j]=s[(i-1)*w2+j-1]-'0';

	int h,w;

	h=h1*h2/gcd(h1,h2);
	w=w1*w2/gcd(w1,w2);
	
	for(int i=1;i<=h1;i++){
		for(int j=1;j<=w1;j++){
			int x=(i-1)*(h/h1);
			int y=(j-1)*(w/w1);
			for(int a=1;a<=h/h1;a++)
				for(int b=1;b<=w/h1;b++)
					p1[x+a][y+b]=m1[i][j];
		}
	}

	for(int i=1;i<=h2;i++)
		for(int j=1;j<=w2;j++){
			int x=(i-1)*(h/h2);
			int y=(j-1)*(h/w2);
			for(int a=1;a<=h/h2;a++)
				for(int b=1;b<=w/w2;b++)
					p2[x+a][y+b]=m2[i][j];
		}

	long long ans=0;

	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(p1[i][j]==p2[i][j])
				ans++;
	
	printf("%lld\n",ans);
	
	return 0;
}
