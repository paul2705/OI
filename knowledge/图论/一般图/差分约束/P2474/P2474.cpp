#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
int mn[MAXN][MAXN],mx[MAXN][MAXN];
int n,A,B;
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for (int i=1;i<=n;i++){
		char c=getchar();while (c!='?'&&c!='+'&&c!='-'&&c!='=') c=getchar();
		int j=1;
		while (c=='?'||c=='+'||c=='-'||c=='='){
			if (c=='?'||i==j) mx[i][j]=2,mn[i][j]=-2;
			else if (c=='+') mx[i][j]=2,mn[i][j]=1;
			else if (c=='-') mx[i][j]=-1,mn[i][j]=-2;
			else if (c=='=') mx[i][j]=0,mn[i][j]=0;
			c=getchar(); j++;
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			if (i==k) continue;
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				mx[i][j]=min(mx[i][j],mx[i][k]+mx[k][j]);
				mn[i][j]=max(mn[i][j],mn[i][k]+mn[k][j]);
			}
		}
	}
	int c1=0,c2=0,c3=0;
	for (int i=1;i<=n;i++){
		if (i==A||i==B) continue;
		for (int j=1;j<i;j++){
			if (j==A||j==B) continue;
			c1+=(mx[i][A]<mn[B][j]||mn[B][i]>mx[j][A]);
			c3+=(mx[A][i]<mn[j][B]||mn[i][B]>mx[A][j]);
			c2+=((mn[A][i]==mx[A][i]&&mn[j][B]==mx[j][B]&&mn[A][i]==mn[j][B])||(mn[A][j]==mx[A][j]&&mn[i][B]==mx[i][B]&&mn[A][j]==mn[i][B]));
		}
	}
	printf("%d %d %d\n",c1,c2,c3);
	return 0;
}
