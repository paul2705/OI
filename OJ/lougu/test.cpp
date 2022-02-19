#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	for (int i=1;i<=20000;i++){
		int tmp=0;
		for (int j=1;j<=20000;j+=i) tmp++;
		if (i<300) cout<<20000<<'/'<<i<<" "<<tmp<<endl;
	}
	return 0;
}
