#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinseq");
		system("./sequence3");
		system("./sequence_bl");
		if (system("diff sequence.out sequence1.out")) break;
		cout<<cnt<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
