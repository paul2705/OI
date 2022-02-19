#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
char s[MAXN];
int cnt[15];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
//		cout<<i<<": ";
		for (int j=0;j<=10;j++) cnt[j]=0;
		int x; scanf("%d",&x);
		cin>>s;
//		cout<<s<<endl;
		for (int j=0;j<x;j++){
			cnt[s[j]-'0']++;
		}
		if (cnt[1]){ printf("1\n1\n"); continue; }
		if (cnt[4]){ printf("1\n4\n"); continue; }
		if (cnt[6]){ printf("1\n6\n"); continue; }
		if (cnt[8]){ printf("1\n8\n"); continue; }
		if (cnt[9]){ printf("1\n9\n"); continue; }
		if (cnt[2]>=2){ printf("2\n22\n"); continue; }
		if (cnt[3]>=2){ printf("2\n33\n"); continue; }
		if (cnt[5]>=2){ printf("2\n55\n"); continue; }
		if (cnt[7]>=2){ printf("2\n77\n"); continue; }
		for (int st=1;st<(1<<x);st++){
			int now=0,tmp=0;
			for (int j=0;j<x;j++){
				if (st&(1<<j)) now++,tmp=tmp*10+s[j]-'0';
			}
			int fg=1;
			for (int j=2;j*j<=tmp;j++){
				if (tmp%j==0) fg=0;
			}
			if (!fg){ printf("%d\n%d\n",now,tmp); break; }
		}
//		cout<<i<<" : "<<n<<endl;
	}
	return 0;
}
