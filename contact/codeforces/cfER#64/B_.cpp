#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
char s[105];
int cnt[30];
int main(){
	scanf("%d",&T);
	while (T--){
		memset(cnt,0,sizeof(cnt));
		cin>>s;
		int n=strlen(s),mn=30;
		for (int i=0;i<n;i++){
			cnt[s[i]-'a']++;
			mn=min(mn,s[i]-'a');
		}
		int len=1; s[0]=(char)mn+'a'; cnt[mn]--; n--;
		while (n>0){
			int pos=-1;
			for (int i=0;i<26;i++){
				if (cnt[i]>0&&i-(s[len-1]-'a')>1){
					pos=i;
//					break;
				}
			}
			if (pos==-1) break;
			s[len++]=(char)pos+'a';
			cnt[pos]--; n--;
		}
		if (!n) printf("%s\n",s);
		else printf("No answer%s\n",s);
	}
	return 0;
}
