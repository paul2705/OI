#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=1e5*5+5;
int a[MAXN],n,ans;
stack<int> s;
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x); int t=1;
		while (s.size()&&s.top()<=x){
			if (s.top()==x) t++;
			ans++; s.pop();	
		}
		if (s.size()) ans++;
		while (t--) s.push(x);
	}
	printf("%d\n",ans);
	return 0;
}
