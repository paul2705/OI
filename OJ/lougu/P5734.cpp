#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
string s,tmp;
int n;
int main(){
	scanf("%d",&n);
	cin>>s;
	for (int i=1;i<=n;i++){
		int opt; cin>>opt;
		if (opt==1){
			cin>>tmp;
			s+=tmp;
			cout<<s<<endl;
		}
		if (opt==2){
			int l,x; scanf("%d%d",&l,&x);
			s=s.substr(l,x);
			cout<<s<<endl;
		}
		if (opt==3){
			int l; cin>>l>>tmp;
			s=s.insert(l,tmp);
			cout<<s<<endl;
		}
		if (opt==4){
			cin>>tmp;
			printf("%d\n",(int)s.find(tmp));
		}
	}
	return 0;
}
