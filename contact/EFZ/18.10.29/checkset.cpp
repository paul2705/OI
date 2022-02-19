#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./leset");
		system("./leset_cgf");
		if (system("diff leset.out leset1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
