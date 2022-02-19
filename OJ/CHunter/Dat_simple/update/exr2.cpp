#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e6+6;
char s[MAXN];
int n,top;
double pow(double x,int n){
	double ret=1;
	while (n){
		if (n&1) ret=ret*x;
		x=x*x;
		n>>=1;
	}
	return ret;
}
void modify(double& a,double b,int op){
//	cout<<__func__<<" "<<a<<" "<<b<<" "<<op<<endl;
	if (op==1) a+=b;
	if (op==2) a-=b;
	if (op==3) a*=b;
	if (op==4) a/=b;
	if (op==5) a=pow(a,b);
//	cout<<"result: "<<a<<endl;
}
int get(char c){
	switch (c){
		case '+': return 1;
		case '-': return 2;
		case '*': return 3;
		case '/': return 4;
		case '^': return 5;
	}
	return 0;
}
double dfs(int l,int r){
	double ret=0;
//	cout<<__func__<<" "<<l<<" "<<r<<endl;
	vector<int> a,op; a.clear(); op.clear();
	if (s[l]=='-') op.push_back(get(s[l++]));
	else op.push_back(1);
	for (int i=l;i<=r;i++){
		if (s[i]=='('){
			int cnt=0,nl=i+1;
			while (i<=r&&(s[i]=='('||s[i]==')')){
//				cout<<l<<" "<<r<<" "<<i<<endl;
				if (s[i]=='(') cnt++;
				else cnt--;
				if (cnt==0) break;
				i++;
				while (i<=r&&s[i]!='('&&s[i]!=')') i++;
			}
			if (i>r) i=r;
			int nr=i-1;
			if (s[i]!=')') nr=i;
//			cout<<i<<" "<<l<<" "<<rr<<endl;
//			modify(ret,dfs(nl,nr),op);
			a.push_back(dfs(nl,nr));
		}
		else if ((s[i]>='0'&&s[i]<='9')){
			int tmp=0;
			while (s[i]>='0'&&s[i]<='9') tmp=tmp*10+(s[i++]-'0');
			i--;
//			modify(ret,tmp,op);
			a.push_back(tmp);
		}
		else op.push_back(get(s[i]));
	}
	if (a.size()==1){
//		cout<<a[0]<<" "<<op[0]<<endl;
		if (op.size()==0) return a[0];
		else if (op[0]==2) return -a[0];
		else if (op[0]==1) return a[0];
	}
//	cout<<"stp1 "<<a.size()<<" "<<op.size()<<endl;
	vector<int> b,op1; b.clear(); op1.clear();
	for (int i=0;i<op.size();i++){
		int x=op[i];
//		cout<<i<<" "<<a[i]<<" "<<op[i]<<endl;
		if (x==5){
			int sz=b.size();
			b[sz-1]=pow(b[sz-1],a[i]);
		}
		else op1.push_back(x),b.push_back(a[i]);
	}
//	cout<<"stp2 "<<b.size()<<" "<<op1.size()<<endl;
	a.clear(); op.clear();
	for (int i=0;i<op1.size();i++){
		int x=op1[i];
//		cout<<i<<" "<<b[i]<<" "<<op1[i]<<endl;
		if (x==3){
			int sz=a.size();
			a[sz-1]*=b[i];
		}
		else if (x==4){
			int sz=a.size();
			a[sz-1]/=b[i];
		}
		else op.push_back(x),a.push_back(b[i]);
	}
//	cout<<"stp3 "<<a.size()<<endl;
	for (int i=0;i<a.size();i++) ret+=a[i]*(op[i]==1?1:-1);
//	cout<<"result: "<<ret<<endl;
	return ret;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	printf("%.0lf\n",dfs(1,n));
	return 0;
}
