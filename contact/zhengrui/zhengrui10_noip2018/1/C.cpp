#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e3+5;
char s[MAXN];
bool use[MAXN];
int las[MAXN],top;
bool check(int x,int y,int len){
	int rlen=len,ret=0;
	for (int i=0;i<len;i++) use[i]=0;
	for (int i=x;i<=y;i++) use[i]=1,rlen--,ret++;
	while (rlen){
//		if (x==4&&y==6) cout<<rlen<<endl;
		bool f=1;
		top=0;
		for (int i=0;i<len;i++){
			if (!use[i]){
				if (s[i]==s[x]){
					int cnt=x; bool ff=1;
					for (int j=i;cnt<=y;j++){
						if (!use[j]){
							if (s[j]==s[cnt]) cnt++;
							else ff=0,cnt=y+1;
						}
					}
					if (ff){
//						if (x==4&&y==6) cout<<"fuck"<<endl;
						las[top++]=i;
						f=0; cnt=x;
//						for (int j=i;cnt<=y;j++){
//							if (!use[j]) cnt++,use[j]=1,rlen--;
//							if (x==4&&y==6) cout<<j<<" ";
//						}
//						if (x==4&&y==6) cout<<endl;
					}
				}
			}
		}
		int cnt=x;
//		if (x==4&&y==6) cout<<top<<endl;
//		for (int i=0;i<top;i++){
//			if (x==4&&y==6) cout<<"i: "<<las[i]<<endl;
//		}
		if (top>0){   
//			if (x==4&&y==6) cout<<"in"<<endl;
			int id=0;
			if (top!=0) id=rand()%top;
			else id=0;
//			if (x==4&&y==6) cout<<top<<" "<<las[id]<<endl;
			for (int j=las[id];cnt<=y;j++){
				if (!use[j]) cnt++,use[j]=1,rlen--;
//				if (x==4&&y==6)cout<<j<<" ";
			}
//			if (x==4&&y==6)cout<<endl;
//			if (x==4&&y==6) cout<<"out"<<endl;
		}
		if (f) return 0;
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		cin>>s;
		int len=strlen(s);
		bool f=1;
		for (int l=0;l<=len;l++){
			if (!f) break;
			for (int i=0;i<len;i++){
				if (!f) break;
				int j=i+l; if (j>=len) break;
				if (s[i]!=s[0]||s[j]!=s[len-1]) continue;
//				cout<<i<<" "<<j<<" "<<len<<" "<<check(i,j,len)<<endl;
				if (check(i,j,len)){
					for (int x=i;x<=j;x++) printf("%c",s[x]);
					cout<<endl;
					f=0;
				}
			}
		}
	}
	return 0;
}
