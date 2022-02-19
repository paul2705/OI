#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++;
		system("./getinan");
		system("./anomalies");
		system("./anomalies_");
		if (system("diff anomalies.out anomalies1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
