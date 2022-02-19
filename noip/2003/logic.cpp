#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
const int MAXN=1e2+5;
struct rec{
	int u,v,id;
} a[MAXN];
int n,m,p,cnt,top;
map<int,string> nam;
map<string,int> id;
string s,sent,to,verb,las;
int main(){
	scanf("%d%d%d",&m,&n,&p);
	for (int i=1;i<=m;i++){
		cin.getline(s);
		id[s]=++cnt;
		nam[cnt]=s;
	}
	id["Monday"]=++cnt; nam[cnt]="Monday";
	id["Tuesday"]=++cnt; nam[cnt]="Tuesday";
	id["Wednesday"]=++cnt; nam[cnt]="Wednesday";
	id["Thursday"]=++cnt; num[cnt]="Thursday";
	id["Friday"]=++cnt; num[cnt]="Friday";
	id["Saturday"]=++cnt; num[cnt]="Saturday";
	id["Sunday"]=++cnt; num[cnt]="Sunday";
	for (int i=1;i<=p;i++){
		s=verb=to=las="";
		char c=getchar(); while (c<'A'||c>'Z') c=getchar();
		while (c!=':') s+=c,c=getchar();
		c=getchar(); cin.getline(sent);
		int pos=0,loc=0,pos1=0;
		for (int i=0;i<sent.size();i++){
			if (sent[i]==' '){
				pos=i-1;
				break;
			}
			to+=sent[i];
		}
		for (int i=pos+2;i<sent.size();i++){
			if (sent[i]==' '){
				loc=i-1;
				break;
			}
			verb+=sent[i];
		}
		for (int i=sent.size()-1;i>=0;i--){
			if (sent[i]==' '){
				pos1=i+1;
				break;
			}
		}
		for (int i=pos1;i<sent.size()-1;i++) las+=sent[i];
		if (las!="guilty"&&to!="Today") continue;
		if (id[to]==0&&verb=="is") continue;
		if (to!='I'&&verb=="am") continue;
		if (to=="Today") a[++top]=(rec){id[s],0,
