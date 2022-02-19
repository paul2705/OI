#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
map<string,string> p;
string s,s1;
char ch;
string find_(string x){
	if (x!=p[x]) p[x]=find_(p[x]);
	return p[x];
}
int main(){
	scanf("%c",&ch);
	while (ch!='$'){
		cin>>s;
		if (ch=='#'){ s1=s; if (p[s]=="") p[s]=s; }
		else if (ch=='+') p[s]=s1;
		else cout<<s<<" "<<find_(s)<<endl;
		scanf("%c",&ch);
	}
	return 0;
}
