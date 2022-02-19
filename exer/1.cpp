#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull lim=(ull)18446744073709551615;
const int MAXN=1e2+5;
unsigned long long k,pow[MAXN];
int n;
char ans[MAXN];
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	pow[0]=1;
	for (int i=1;i<=64;i++) pow[i]=pow[i-1]*(ull)2;
//	for (int i=1;i<=64;i++) cout<<i<<" "<<pow[i]<<endl;
//	cout<<lim<<endl;
	for (int i=n;i>=1;i--){
//		cout<<k<<" "<<i<<" "<<pow[i-1]<<endl;
		if (k<pow[i-1]) ans[i]='0';
		else {
			if (i==64) k=lim-k;
			else k=pow[i]-1-k;
			ans[i]='1';
		}
	}
	for (int i=n;i>=1;i--) printf("%c",ans[i]);
	printf("\n");
	fclose(stdin); fclose(stdout);
	return 0;
}
