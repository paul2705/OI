#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5e4+5;
int n,m;
char s[MAXN*2];
int main(){
	freopen("1014.in","r",stdin);
	freopen("1014.ans","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		char op=getchar(); while (op!='Q'&&op!='R'&&op!='I') op=getchar();
		int x; scanf("%d",&x);
		if (op=='Q'){
			int y,l; scanf("%d",&y);
			for (l=0;max(l+x,l+y)<=n;l++){
				if (s[l+x]!=s[l+y]) break;
			}
			printf("%d\n",l);
		}
		if (op=='R'){
			char y=getchar(); while (y<'a'||y>'z') y=getchar();
			s[x]=y;
		}
		if (op=='I'){
			char y=getchar(); while (y<'a'||y>'z') y=getchar();
			for (int i=n;i>x;i--) swap(s[i],s[i+1]);
			s[x+1]=y;
			n++;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
			
