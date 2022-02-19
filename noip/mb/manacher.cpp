#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e7+2e6+5;
char s[2*MAXN],s1[2*MAXN];
int len[2*MAXN],n;
void readln() {scanf("%*[^\n]");getchar();}
bool Eoln(char ch) {return ch==10||ch==13||ch==EOF;}
int reads(char *x)
{
    int len=0;char ch=getchar();if (ch==EOF) return EOF;
    s[++len]=ch;while (!Eoln(s[len])) s[++len]=getchar();s[len--]=0;
    return len;
}
int main(){
	freopen("manacher.in","r",stdin);
	freopen("manacher.out","w",stdout);
    reads(s);
//	cout<<s<<endl;
//	n=0;
//	s1[n++]='(';
//	cout<<"fuck"<<endl;
	int l=strlen(s+1);
	for (int i=1;i<=l;i++) s1[2*i-1]='%',s1[2*i]=s[i];
	s1[n=strlen(s+1)*2+1]='%'; //s1[n++]=')';
	int pos=0,lim=0;
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++){
//		cout<<pos<<" "<<lim<<endl;
		if (i<lim) len[i]=min(lim-i,len[2*pos-i]);
		else len[i]=1;
//		cout<<i<<" "<<len[i]<<endl;
		while (i>len[i]&&i+len[i]<=n&&s1[i+len[i]]==s1[i-len[i]]) len[i]++;
//		cout<<len[i]<<endl;
		if (i+len[i]>lim) pos=i,lim=i+len[i];
//		cout<<len[i]<<endl;
	}
//	for (int i=0;i<n;i++) cout<<s1[i]<<" ";
//	cout<<endl;
//	for (int i=0;i<n;i++) cout<<len[i]<<" ";
//	cout<<endl;;
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,len[i]-1);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
