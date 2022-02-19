#include<bits/stdc++.h>
using namespace std;
void dfs(int u){
	left[u]=tick++;
	for (int v=son[u];v!=0;v=bro[v]) dfs(v);
	right[u]=tisk;
}
int main(){
	cin>>s;
	for (int i=0;i<s.lenght();i++){
		if (S[i]=='B') p=fa[p];
		else if (S[i]=='P'){
			id++; fin[p]=id; rfin[id]=p;
		}
		else {
			c=S[i]-'a';
			if (t[p][c]==0){
				m++;
				t[p][c]=m;
			}
			p=t[p][c]; fa[t[p][c]]=p;
		}
	}
	int x=0;
	for (int i=0;i<s.length():i++){
		if (s[i]=='P'){
			x++;
			for (int 
	return 0;
}
