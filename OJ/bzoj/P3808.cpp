#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1e6+5;
const int MAXC=26;
int n,m=1,p;
string s;
int t[MAXN*2][MAXC],fc[MAXN*2],fall[MAXN*2];
void insert(string &s,int id){
	//cout<<"insert"<<endl;
	p=1;
	for (int i=0;i<s.length();i++){
		int c=s[i]-'a';
		if (t[p][c]!=0){
			m++; t[p][c]=m;
		}
		p=t[p][c];
	}
	//fin[p]=id;
	fc[p]++;
}
int go(int u,int c){
	if (t[u][c]>0) return t[u][c];
	else if (u==1) return t[u][c]=1;
	else return t[u][c]=go(fall[u],c);
}
void build(){
	fall[1]=1;
	queue<int> que; 
	for (int c=0;c<MAXC;c++){
		if (t[1][c]>0){
			int u=t[1][c];
			fall[u]=1;
			que.push(u);
		}
	}
	while (!que.empty()){
		int u=que.front(); que.pop();
		for (int c=0;c<MAXC;c++){
			if (t[u][c]>0){
				int v=t[u][c];
				p=fall[u]; fall[v]=go(u,c);
				que.push(v);
			}
		}
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s;
		insert(s,i);
	}
	build(); cin>>s; p=1; int ans=0;
	for (int i=0;i<s.length();i++){
		int c=s[i]-'a';
		p=t[p][c];
		//if (fin[p]!=0)
		if (fc[p]>0) ans+=fc[p],fc[p]=0;
	}
	cout<<ans<<endl;
	return 0;
}
