#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinB");
		system("./B");
		system("./B_bl");
		if (system("diff cowpatibility.out cowpatibility1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
