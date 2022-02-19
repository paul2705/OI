#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e4;
const int MAXN=1e7+5;
int ans,ret;
char s[MAXN];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	ret=-1;
	for (int i=0;i<n;i++){
		int tmp=0;
		while (s[i]>='0'&&s[i]<='9'){
			tmp=(tmp*10+s[i]-'0')%mod;
			i++;
		}
		if (ret<0&&s[i]=='+') ans=(ans+tmp)%mod;
		if (s[i]=='*'&&ret<0) ret=tmp;
		else if (s[i]=='*'&&ret>=0) ret=(ret*tmp)%mod;
		if (ret>=0&&s[i]=='+'){
			ans=(ans+ret*tmp%mod)%mod;
			ret=-1;
		}
		if (i==n){
			if (ret>=0) ans=(ans+ret*tmp%mod)%mod;
			else ans=(ans+tmp)%mod;
		}
//		cout<<ans<<" "<<ret<<" "<<tmp<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
