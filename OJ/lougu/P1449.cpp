#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int st[MAXN],tp;
int n;
char s[MAXN];
int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++){
		if (s[i]>='0'&&s[i]<='9'){
			int tmp=0;
			while (s[i]!='.'){
				tmp=tmp*10+s[i]-'0';
				i++;
			}
			st[tp++]=tmp;
		}
		if (s[i]=='-'){
			st[tp-2]-=st[tp-1];
			tp--;
		}
		if (s[i]=='+'){
			st[tp-2]+=st[tp-1];
			tp--;
		}
		if (s[i]=='*'){
			st[tp-2]*=st[tp-1];
			tp--;
		}
		if (s[i]=='/'){
			st[tp-2]/=st[tp-1];
			tp--;
		}
	}
	printf("%d\n",st[tp-1]);
	return 0;
}
