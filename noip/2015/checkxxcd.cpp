#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int cnt=0;
	while (1){
		cnt++;
		system("./getinxxcd");
		system("./xxcd");
		system("./xxcd_bl");
		if (system("diff message.out message1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
