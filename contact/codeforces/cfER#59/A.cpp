#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e2+5;
int T,n;
char s[MAXN];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			char c=getchar(); while (c<'1'||c>'9') c=getchar();
//			cout<<i<<" "<<c<<endl;
			s[i]=c;
		}
		if (n==1){
			printf("NO\n");
			continue;
		}
		else if (n==2){
			if (s[1]>=s[2]){
				printf("NO\n");
				continue;
			}
			else {
				printf("YES\n2\n");
				putchar(s[1]); printf(" ");
				putchar(s[2]);
				cout<<endl;
			}
		}
		else {
			printf("YES\n2\n");
			putchar(s[1]); printf(" ");
			for (int i=2;i<=n;i++) putchar(s[i]);
			cout<<endl;
		}
	}
	return 0;
}
