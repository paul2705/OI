#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getingwyx");
		system("./gwyx");
		system("./gwyx_bl");
		if (system("diff gwyx.out gwyx1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
